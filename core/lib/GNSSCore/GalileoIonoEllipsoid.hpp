//==============================================================================
//
//  This file is part of GNSSTk, the ARL:UT GNSS Toolkit.
//
//  The GNSSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 3.0 of the License, or
//  any later version.
//
//  The GNSSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GNSSTk; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
//
//  This software was developed by Applied Research Laboratories at the
//  University of Texas at Austin.
//  Copyright 2004-2022, The Board of Regents of The University of Texas System
//
//==============================================================================

//==============================================================================
//
//  This software was developed by Applied Research Laboratories at the
//  University of Texas at Austin, under contract to an agency or agencies
//  within the U.S. Department of Defense. The U.S. Government retains all
//  rights to use, duplicate, distribute, disclose, or release this software.
//
//  Pursuant to DoD Directive 523024
//
//  DISTRIBUTION STATEMENT A: This software has been approved for public
//                            release, distribution is unlimited.
//
//==============================================================================

/**
 * @file GalileoEllipsoid.hpp
 * Galileo model of the Ellipsoid
 * Definition from \cite galileo:iono
 */

#ifndef GNSSTK_GALILEOIONOELLIPSOID_HPP
#define GNSSTK_GALILEOIONOELLIPSOID_HPP

#include "GalileoEllipsoid.hpp"

namespace gnsstk
{
      /** @addtogroup geodeticgroup */
      //@{

      /** Define an "ellipsoid" as used by the Galileo ionospheric
       * model.  This is actually a sphere. */
   class GalileoIonoEllipsoid : public GalileoEllipsoid
   {
   public:

         /// @return semi-major axis of Earth in meters.
      virtual double a() const noexcept
      { return a_km() * 1000.0; }

         /// Defined in galileo:iono section 2.5.2 as R<sub>E</sub>
         /// @return semi-major axis of Earth in km.
      virtual double a_km() const noexcept
      { return 6371.2; }

         /// @return flattening (ellipsoid parameter).
      virtual double flattening() const noexcept
      { return 0; }

         /// Unstated in Galileo OS SIS ICD. Derived as e = sqrt(2f - f*f)
         /// based on NGA TR8350.2 Section 7.4
         /// @return eccentricity (ellipsoid parameter).
      virtual double eccentricity() const noexcept
      { return 0; }

         /// Unstated in Galileo OS SIS ICD. Derived as e^2 = 2f - f*f
         /// based on NGA TR8350.2 Section 7.4
         /// @return eccentricity squared (ellipsoid parameter).
      virtual double eccSquared() const noexcept
      { return 0; }

         /// Destructor.
      virtual ~GalileoIonoEllipsoid() noexcept {}

   }; // class GalileoIonoEllipsoid

      //@}

} // namespace

#endif
