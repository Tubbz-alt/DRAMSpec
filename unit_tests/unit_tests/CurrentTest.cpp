/*
* Copyright (c) 2017, University of Kaiserslautern
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its
*    contributors may be used to endorse or promote products derived from
*    this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
* OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Authors: Omar Naji,
*          Matthias Jung,
*          Christian Weis,
*          Kamal Haddad,
*          Andre Lucas Chinazzo
*/



#ifndef CURRENTTEST_CPP
#define CURRENTTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Current.h"

BOOST_AUTO_TEST_SUITE( testCurrent )

BOOST_AUTO_TEST_CASE( checkCurrent_real_input )
{
  int sim_argc = 6;
  char* sim_argv[] = {"./executable",
                      "-t",
                      "technology_input/test_technology.json",
                      "-p",
                      "architecture_input/test_architecture.json",
                      "-term"};

  ArgumentsParser inputFileName(sim_argc, sim_argv);

  string exceptionMsg("Empty");
  try {
      inputFileName.runArgParser();
  }catch (string exceptionMsgThrown){
      exceptionMsg = exceptionMsgThrown;
  }
  string expectedMsg("Empty");
  if ( exceptionMsg != expectedMsg ) {
      BOOST_FAIL( exceptionMsg );
  }

  Current current;
  try {
      current = Current(inputFileName.technologyFileName[0],
                        inputFileName.architectureFileName[0],
                        inputFileName.IOTerminationCurrentFlag);
  }catch (string exceptionMsgThrown){
      exceptionMsg = exceptionMsgThrown;
  }
  expectedMsg = string("Empty");
  if ( exceptionMsg != expectedMsg ) {
      BOOST_FAIL( exceptionMsg );
  }

  double _mag;

  _mag = 0.6;
  BOOST_CHECK_MESSAGE( current.IDD2nPercentageIfNotDll == _mag,
                      "Accounted percentage of IDD2n if not DLL "
                      "different from the expected."
                      << "\nExpected around: " << _mag
                      << "\nGot: " << current.IDD2nPercentageIfNotDll);

  _mag = 8;
  BOOST_CHECK_MESSAGE( current.bitProCSL == _mag*drs::bits,
                      "Number of bits pro CSL "
                      "different fgrom the expected."
                      << "\nExpected around: " << _mag*drs::bits
                      << "\nGot: " << current.bitProCSL);

  _mag = 0.1;
  BOOST_CHECK_MESSAGE( current.activeBankLeakage == _mag*drs::milliamperes,
                      "Active bank leakage "
                      " different from the expected."
                      << "\nExpected around: " << _mag*drs::milliamperes
                      << "\nGot: " << current.activeBankLeakage);

  _mag = 32;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.nActiveSubarrays, 3) == _mag,
                      "Number of active subarrays "
                      "different from the expected."
                      << "\nExpected around: " << _mag
                      << "\nGot: " << current.nActiveSubarrays);

  _mag = 16384;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.nLocalBitlines, 3) == _mag,
                      "Number of local bitlines different from the expected."
                      << "\nExpected around: " << _mag
                      << "\nGot: " << current.nLocalBitlines);

  _mag = 39.664;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD3nOneACTBank, 3)
                       == _mag*drs::milliamperes,
                      "Single active bank IDD3n "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::milliamperes
                      << "\nGot: " << current.IDD3nOneACTBank);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP3nOneACTBank, 3)
                       == _mag*drs::milliamperes,
                      "Single active bank IPP3n "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::milliamperes
                      << "\nGot: " << current.IPP3nOneACTBank);

  _mag = 1.535;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD0TotalCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Total charge accounted for IDD0 "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.IDD0TotalCharge);

  _mag = 0.033;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP0TotalCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Total charge accounted for IPP0 "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.IPP0TotalCharge);

  _mag = 35;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.effectiveTrc, 3) == _mag*drs::nanoseconds,
                      "Effective Trc different from the expected."
                      << "\nExpected around: " << _mag*drs::nanoseconds
                      << "\nGot: " << current.effectiveTrc);

  _mag = 0.047;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD0ChargingCurrent, 3)
                       == _mag*drs::amperes,
                      "Part of IDD0 for charging lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::amperes
                      << "\nGot: " << current.IDD0ChargingCurrent);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP0ChargingCurrent, 3)
                       == _mag*drs::amperes,
                      "Part of IPP0 for charging lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::amperes
                      << "\nGot: " << current.IPP0ChargingCurrent);

  _mag = 6.714;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.SSAActiveTime, 3)
                       == _mag*drs::nanoseconds,
                      "Active time of secondary sense amp."
                      " different from the expected."
                      << "\nExpected around: " << _mag*drs::nanoseconds
                      << "\nGot: " << current.SSAActiveTime);

  _mag = 2.956;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD1TotalCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Total charge accounted for IDD1 "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.IDD1TotalCharge);

  _mag = 0.088;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD1ChargingCurrent, 3)
                       == _mag*drs::amperes,
                      "Part of IDD1 for charging lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::amperes
                      << "\nGot: " << current.IDD1ChargingCurrent);

  _mag = 1.456;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4TotalCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Total charge accounted for IDD4 "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.IDD4TotalCharge);

  _mag = 90.064;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.ioTermRdCurrent, 3)
                       == _mag*drs::milliampere,
                      "I/O Termination current for reading "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.ioTermRdCurrent);

  _mag = 0.292;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4ChargingCurrent, 3)
                       == _mag*drs::amperes,
                      "Part of IDD4 for charging lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::amperes
                      << "\nGot: " << current.IDD4ChargingCurrent);

  _mag = 99.071;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.ioTermWrCurrent, 3)
                       == _mag*drs::milliampere,
                      "I/O Termination current for writing "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.ioTermWrCurrent);

  _mag = 12.274;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.iDDRefreshCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Total charge accounted refreshing "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.iDDRefreshCharge);

  _mag = 46.25;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.effectiveTrfc, 3)
                       == _mag*drs::nanoseconds,
                      "Effective Trfc "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanoseconds
                      << "\nGot: " << current.effectiveTrfc);

  _mag = 0.284;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD5bChargingCurrent, 3)
                       == _mag*drs::amperes,
                      "Part of IDD5 for charging lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::amperes
                      << "\nGot: " << current.IDD5bChargingCurrent);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP5bChargingCurrent, 3)
                       == _mag*drs::amperes,
                      "Part of IPP5 for charging lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::amperes
                      << "\nGot: " << current.IPP5bChargingCurrent);

  // Main variables
  _mag = 88.772;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD0, 3) == _mag*drs::milliampere,
                      "IDD0 different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD0);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP0, 3) == _mag*drs::milliampere,
                      "IPP0 different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IPP0);

  _mag = 129.372;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD1, 3) == _mag*drs::milliampere,
                      "IDD1 different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD1);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP1, 3) == _mag*drs::milliampere,
                      "IPP1 different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IPP1);

  _mag = 423.122;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4R, 3) == _mag*drs::milliampere,
                      "IDD4R different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD4R);

  _mag = 432.129;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4W, 3) == _mag*drs::milliampere,
                      "IDD4W different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD4W);

  _mag = 37.064;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD2n, 3) == _mag*drs::milliampere,
                      "IDD2n different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD2n);

  _mag = 41.864;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD3n, 3) == _mag*drs::milliampere,
                      "IDD3n different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD3n);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP3n, 3) == _mag*drs::milliampere,
                      "IPP3n different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IPP3n);

  _mag = 325.848;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD5b, 3) == _mag*drs::milliampere,
                      "IDD5b different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IDD5b);

  _mag = 0;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.IPP5b, 3) == _mag*drs::milliampere,
                      "IPP5b different from the expected."
                      << "\nExpected around: " << _mag*drs::milliampere
                      << "\nGot: " << current.IPP5b);


  _mag = 0.003032;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.masterWordlineCharge, 6)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for master word line "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.masterWordlineCharge);

  _mag = 0.008;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.localWordlineCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for local word line "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.localWordlineCharge);

  _mag = 0.756;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.localBitlineCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for local bit line "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.localBitlineCharge);

  _mag = 0.258;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.SSACharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for secondary sense amp. "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.SSACharge);

  _mag = 0.034;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.CSLCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for column select line "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.CSLCharge);

  _mag = 0.250;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.masterDatalineCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for master data line "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.masterDatalineCharge);

  _mag = 0.904;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.DQWireCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Charge accounted for dataqueue wire "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.DQWireCharge);

  _mag = 1.445;
  BOOST_CHECK_MESSAGE( ROUND_UP(current.readingCharge, 3)
                       == _mag*drs::nanocoulombs,
                      "Total charge accounted for reading lines "
                      "different from the expected."
                      << "\nExpected around: " << _mag*drs::nanocoulombs
                      << "\nGot: " << current.readingCharge);

  _mag = (double)true;
  BOOST_CHECK_MESSAGE( current.includeIOTerminationCurrent == (bool)_mag,
                      "I/O termination current flag "
                      "different from the expected."
                      << "\nExpected: " << (bool)_mag
                      << "\nGot: " << current.includeIOTerminationCurrent);

}

BOOST_AUTO_TEST_SUITE_END()

#endif // CURRENTTEST_CPP
