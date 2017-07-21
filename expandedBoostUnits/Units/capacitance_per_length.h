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



#ifndef DRAMSPEC_CAPACITANCE_PER_LENGHT_UNIT_H
#define DRAMSPEC_CAPACITANCE_PER_LENGHT_UNIT_H

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/capacitance_per_length.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<capacitance_per_length_dimension,dramspec::system_bit>    capacitance_per_length;

BOOST_UNITS_STATIC_CONSTANT(farad_per_meter,capacitance_per_length);
BOOST_UNITS_STATIC_CONSTANT(farads_per_meter,capacitance_per_length);

// femtofarad / millimeter = picofarad / meter
typedef make_scaled_unit<capacitance_per_length,scale<10, static_rational<-12>>>::type femtofarad_per_millimeter_unit;
BOOST_UNITS_STATIC_CONSTANT(femtofarad_per_millimeter,femtofarad_per_millimeter_unit);
BOOST_UNITS_STATIC_CONSTANT(femtofarads_per_millimeter,femtofarad_per_millimeter_unit);

// nanofarad / millimeter = microfarad / meter
typedef make_scaled_unit<capacitance_per_length,scale<10, static_rational<-6>>>::type nanofarad_per_millimeter_unit;
BOOST_UNITS_STATIC_CONSTANT(nanofarad_per_millimeter,nanofarad_per_millimeter_unit);
BOOST_UNITS_STATIC_CONSTANT(nanofarads_per_millimeter,nanofarad_per_millimeter_unit);

// nanofarad / micrometer = millifarad / meter
typedef make_scaled_unit<capacitance_per_length,scale<10, static_rational<-3>>>::type nanofarad_per_micrometer_unit;
BOOST_UNITS_STATIC_CONSTANT(nanofarad_per_micrometer,nanofarad_per_micrometer_unit);
BOOST_UNITS_STATIC_CONSTANT(nanofarads_per_micrometer,nanofarad_per_micrometer_unit);

} // namespace dramspec

} // namespace units

} // namespace boost

#endif // DRAMSPEC_CAPACITANCE_PER_LENGHT_UNIT_H
