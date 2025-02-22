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


#ifndef MOPS_TROP_MODEL_HPP
#define MOPS_TROP_MODEL_HPP

#include "GCATTropModel.hpp"

namespace gnsstk
{
      /** Tropospheric model implemented in the RTCA "Minimum Operational
       *  Performance Standards" (MOPS), version C.
       *
       * This model is described in the RTCA "Minimum Operational Performance
       * Standards" (MOPS), version C (RTCA/DO-229C), in Appendix A.4.2.4.
       * Although originally developed for SBAS systems (EGNOS, WAAS), it may
       * be suitable for other uses as well.
       *
       * This model needs the day of year, satellite elevation (degrees),
       * receiver height over mean sea level (meters) and receiver latitude in
       * order to start computing.
       *
       * On the other hand, the outputs are the tropospheric correction (in
       * meters) and the sigma-squared of tropospheric delay residual error
       * (meters^2).
       *
       * A typical way to use this model follows:
       *
       * @code
       *   MOPSTropModel mopsTM;
       *   mopsTM.setReceiverLatitude(lat);
       *   mopsTM.setReceiverHeight(height);
       *   mopsTM.setDayOfYear(doy);
       * @endcode
       *
       * Once all the basic model parameters are set (latitude, height and day
       * of year), then we are able to compute the tropospheric correction as
       * a function of elevation:
       *
       * @code
       *   trop = mopsTM.correction(elevation);
       * @endcode
       *
       */
   class MOPSTropModel : public GCATTropModel
   {
   public:

         /// Empty constructor
      MOPSTropModel();


         /** Constructor to create a MOPS trop model providing just the height
          * of the receiver above mean sea level. The other parameters must be
          * set with the appropriate set methods before calling correction
          * methods.
          *
          * @param ht Height of the receiver above mean sea level, in meters.
          */
      MOPSTropModel(const double& ht)
      { setReceiverHeight(ht); };


         /** Constructor to create a MOPS trop model providing the height of
          * the receiver above mean sea level (as defined by ellipsoid model),
          * its latitude and the day of year.
          *
          * @param ht Height of the receiver above mean sea level, in meters.
          * @param lat Latitude of receiver, in degrees.
          * @param doy Day of year.
          */
      MOPSTropModel(const double& ht, const double& lat, const int& doy);


         /** Constructor to create a MOPS trop model providing the position of
          * the receiver and current time.
          *
          * @param RX Receiver position.
          * @param time Time.
          */
      MOPSTropModel(const Position& RX, const CommonTime& time);

         /// @copydoc TropModel::name()
      virtual std::string name()
         { return std::string("MOPS"); }


         /// @copydoc TropModel::correction(double) const
      virtual double correction(double elevation) const;


         /** Compute and return the full tropospheric delay, in meters,
          * given the positions of receiver and satellite.
          *
          * This version is most useful within positioning  algorithms, where
          * the receiver position may vary; it computes the elevation (and
          * other receiver location information as height and latitude) and
          * passes them to appropriate methods. You must set time using method
          * setReceiverDOY() before calling this method.
          *
          * @param RX  Receiver position.
          * @param SV  Satellite position.
          * @return The tropospheric delay (meters)
          * @throw InvalidTropModel
          */
      virtual double correction( const Position& RX,
                                 const Position& SV );


         /// @copydoc TropModel::correction(const Position&,const Position&,const CommonTime&)
      virtual double correction( const Position& RX,
                                 const Position& SV,
                                 const CommonTime& tt );


         /** Compute and return the full tropospheric delay, in meters, given
          * the positions of receiver and satellite and the day of the year.
          *
          * This version is most useful within positioning algorithms, where
          * the receiver position may vary; it computes the elevation (and
          * other receiver location information as height and latitude) and
          * passes them to appropriate methods.
          *
          * @param RX  Receiver position.
          * @param SV  Satellite position.
          * @param doy Day of year.
          * @return The tropospheric delay (meters)
          * @throw InvalidTropModel
          */
      virtual double correction( const Position& RX,
                                 const Position& SV,
                                 const int& doy );


         /** Compute and return the full tropospheric delay, given the positions
          * of receiver and satellite. . You must set time using method
          * setReceiverDOY() before calling this method.
          *
          * @deprecated This method is deprecated.
          *   Use correction(const Position&,const Position&) instead
          *
          * @param RX Receiver position in ECEF cartesian coordinates (meters).
          * @param SV Satellite position in ECEF cartesian coordinates (meters).
          * @return The tropospheric delay (meters)
          * @throw InvalidTropModel
          */
      virtual double correction( const Xvt& RX,
                                 const Xvt& SV );


         /// @copydoc TropModel::correction(const Xvt&,const Xvt&,const CommonTime&)
      virtual double correction( const Xvt& RX,
                                 const Xvt& SV,
                                 const CommonTime& tt );


         /** Compute and return the full tropospheric delay, given the positions
          * of receiver and satellite and the day of the year. This version is
          * most useful within positioning algorithms, where the receiver
          * position may vary; it computes the elevation (and other receiver
          * location information as height and latitude) and passes them to
          * appropriate methods.
          *
          * @deprecated This method is deprecated.
          *   Use correction(const Position&,const Position&,const int&) instead
          *
          * @param RX Receiver position in ECEF cartesian coordinates (meters)
          * @param SV Satellite position in ECEF cartesian coordinates (meters)
          * @param doy Day of year.
          * @return The tropospheric delay (meters)
          * @throw InvalidTropModel
          */
      virtual double correction( const Xvt& RX,
                                 const Xvt& SV,
                                 const int& doy );


         /// @copydoc TropModel::dry_zenith_delay() const
      virtual double dry_zenith_delay() const;


         /// @copydoc TropModel::wet_zenith_delay()) const
      virtual double wet_zenith_delay() const;


         /** This method configure the model to estimate the weather using
          * height, latitude and day of year (DOY). It is called automatically
          * when setting those parameters.
          * @throw InvalidTropModel
          */
      void setWeather();


         /** In MOPS tropospheric model, this is a dummy method kept here just
          * for consistency.
          * @throw InvalidTropModel
          */
      virtual void setWeather( const double& T,
                               const double& P,
                               const double& H )
      {}


         /** In MOPS tropospheric model, this is a dummy method kept here just
          * for consistency.
          * @throw InvalidTropModel
          */
      virtual void setWeather(const WxObservation& wx)
      {}


         /// @copydoc TropModel::setReceiverHeight(const double&)
      virtual void setReceiverHeight(const double& ht);


         /// @copydoc TropModel::setReceiverLatitude(const double&)
      virtual void setReceiverLatitude(const double& lat);


         /// @copydoc TropModel::setDayOfYear(const int&)
      virtual void setDayOfYear(const int& doy);


         /** Set the time when tropospheric correction will be computed for, in
          * days of the year.
          *
          * @param time Time object.
          */
      virtual void setDayOfYear(const CommonTime& time);


         /** Convenient method to set all model parameters in one pass.
          *
          * @param time Time object.
          * @param rxPos Receiver position object.
          */
      virtual void setAllParameters( const CommonTime& time,
                                     const Position& rxPos );


         /** Compute and return the sigma-squared value of tropospheric delay
          * residual error (meters^2).
          *
          * @param elevation Elevation of satellite as seen at receiver,
          *   in degrees
          * @throw InvalidTropModel
          */
      double MOPSsigma2(double elevation);


   private:

      double MOPSHeight;
      double MOPSLat;
      int MOPSTime;
      bool validHeight;
      bool validLat;
      bool validTime;
      Matrix<double> avr;
      Matrix<double> svr;
      Vector<double> fi0;
      Vector<double> MOPSParameters;


         /** The MOPS tropospheric model needs to compute several extra
          * parameters.
          * @throw InvalidTropModel
          */
      virtual void prepareParameters();


         // The MOPS tropospheric model uses several predefined data tables
      virtual void prepareTables();
   };
}
#endif
