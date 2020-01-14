#ifndef BoostUnitDefinitions_Units_hpp
#define BoostUnitDefinitions_Units_hpp

#include <boost/units/base_units/angle/arcminute.hpp>
#include <boost/units/base_units/angle/arcsecond.hpp>
#include <boost/units/base_units/angle/degree.hpp>
#include <boost/units/base_units/imperial/foot.hpp>
#include <boost/units/base_units/imperial/inch.hpp>
#include <boost/units/base_units/imperial/yard.hpp>
#include <boost/units/base_units/metric/year.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/cgs.hpp>
#include <boost/units/systems/cgs/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>

namespace boost
{
namespace units
{

/** @brief namespace for unit types */
namespace t
{
}
/** @brief namespace for unit instances*/
namespace i
{
}
}  // namespace units
}  // namespace boost

/* A preprocessor macro for defining new units. Creates a unit types in the 't'
 * namespace and an instance of it in the 'i' namespace.
 */
#define ADD_UNIT(NAME, ...)                   \
  namespace boost                             \
  {                                           \
  namespace units                             \
  {                                           \
  namespace t                                 \
  {                                           \
  typedef __VA_ARGS__ NAME;                   \
  }                                           \
  namespace i                                 \
  {                                           \
  BOOST_UNITS_STATIC_CONSTANT(NAME, t::NAME); \
  }                                           \
  }                                           \
  }

/* Create a set of base units with all of the SI prefixes. */
#define ADD_BASE_UNIT_SET(NAME, SYMB, BASE)                                    \
  ADD_UNIT(giga##NAME,                                                         \
           scaled_base_unit<BASE, scale<10, static_rational<9>>>::unit_type)   \
  ADD_UNIT(mega##NAME,                                                         \
           scaled_base_unit<BASE, scale<10, static_rational<6>>>::unit_type)   \
  ADD_UNIT(kilo##NAME,                                                         \
           scaled_base_unit<BASE, scale<10, static_rational<3>>>::unit_type)   \
  ADD_UNIT(NAME, BASE::unit_type)                                              \
  ADD_UNIT(centi##NAME,                                                        \
           scaled_base_unit<BASE, scale<10, static_rational<-2>>>::unit_type)  \
  ADD_UNIT(milli##NAME,                                                        \
           scaled_base_unit<BASE, scale<10, static_rational<-3>>>::unit_type)  \
  ADD_UNIT(micro##NAME,                                                        \
           scaled_base_unit<BASE, scale<10, static_rational<-6>>>::unit_type)  \
  ADD_UNIT(nano##NAME,                                                         \
           scaled_base_unit<BASE, scale<10, static_rational<-9>>>::unit_type)  \
  ADD_UNIT(pico##NAME,                                                         \
           scaled_base_unit<BASE, scale<10, static_rational<-12>>>::unit_type) \
  ADD_UNIT(femto##NAME,                                                        \
           scaled_base_unit<BASE, scale<10, static_rational<-15>>>::unit_type) \
  ADD_UNIT(G##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<9>>>::unit_type)   \
  ADD_UNIT(M##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<6>>>::unit_type)   \
  ADD_UNIT(k##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<3>>>::unit_type)   \
  ADD_UNIT(SYMB, BASE::unit_type)                                              \
  ADD_UNIT(c##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<-2>>>::unit_type)  \
  ADD_UNIT(m##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<-3>>>::unit_type)  \
  ADD_UNIT(u##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<-6>>>::unit_type)  \
  ADD_UNIT(n##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<-9>>>::unit_type)  \
  ADD_UNIT(p##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<-12>>>::unit_type) \
  ADD_UNIT(f##SYMB,                                                            \
           scaled_base_unit<BASE, scale<10, static_rational<-15>>>::unit_type)

/* Create a set of (not base) units with all of the SI prefixes. */
#define ADD_UNIT_SET(NAME, SYMB, UNIT)                                    \
  ADD_UNIT(giga##NAME,                                                    \
           make_scaled_unit<UNIT, scale<10, static_rational<9>>>::type)   \
  ADD_UNIT(mega##NAME,                                                    \
           make_scaled_unit<UNIT, scale<10, static_rational<6>>>::type)   \
  ADD_UNIT(kilo##NAME,                                                    \
           make_scaled_unit<UNIT, scale<10, static_rational<3>>>::type)   \
  ADD_UNIT(NAME, UNIT)                                                    \
  ADD_UNIT(centi##NAME,                                                   \
           make_scaled_unit<UNIT, scale<10, static_rational<-2>>>::type)  \
  ADD_UNIT(milli##NAME,                                                   \
           make_scaled_unit<UNIT, scale<10, static_rational<-3>>>::type)  \
  ADD_UNIT(micro##NAME,                                                   \
           make_scaled_unit<UNIT, scale<10, static_rational<-6>>>::type)  \
  ADD_UNIT(nano##NAME,                                                    \
           make_scaled_unit<UNIT, scale<10, static_rational<-9>>>::type)  \
  ADD_UNIT(pico##NAME,                                                    \
           make_scaled_unit<UNIT, scale<10, static_rational<-12>>>::type) \
  ADD_UNIT(femto##NAME,                                                   \
           make_scaled_unit<UNIT, scale<10, static_rational<-15>>>::type) \
  ADD_UNIT(G##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<9>>>::type)   \
  ADD_UNIT(M##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<6>>>::type)   \
  ADD_UNIT(k##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<3>>>::type)   \
  ADD_UNIT(SYMB, UNIT)                                                    \
  ADD_UNIT(c##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<-2>>>::type)  \
  ADD_UNIT(m##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<-3>>>::type)  \
  ADD_UNIT(u##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<-6>>>::type)  \
  ADD_UNIT(n##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<-9>>>::type)  \
  ADD_UNIT(p##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<-12>>>::type) \
  ADD_UNIT(f##SYMB,                                                       \
           make_scaled_unit<UNIT, scale<10, static_rational<-15>>>::type)

/* Add an output overload. I.e., set the string that will be output when the
 * user prints the unit.
 */
#define ADD_UNIT_IO(NAME, NSTR, SSTR)                            \
  namespace boost                                                \
  {                                                              \
  namespace units                                                \
  {                                                              \
  inline std::string name_string(const boost::units::t::NAME&)   \
  {                                                              \
    return NSTR;                                                 \
  }                                                              \
  inline std::string symbol_string(const boost::units::t::NAME&) \
  {                                                              \
    return SSTR;                                                 \
  }                                                              \
  }                                                              \
  }

// Aliases

ADD_UNIT(dimensionless, si::dimensionless)
ADD_UNIT(dimless, dimensionless)

// Base units
// these units are based on scaled base units, which is required to
// get the si unit prefixes to work correctly
ADD_BASE_UNIT_SET(meter, m, si::meter_base_unit)
ADD_BASE_UNIT_SET(gram, g, cgs::gram_base_unit)
ADD_BASE_UNIT_SET(second, s, si::second_base_unit)
ADD_BASE_UNIT_SET(kelvin, K, si::kelvin_base_unit)
ADD_BASE_UNIT_SET(ampere, A, si::ampere_base_unit)
ADD_BASE_UNIT_SET(mole, mol, si::mole_base_unit)
ADD_BASE_UNIT_SET(candela, cd, si::candela_base_unit)

// Alternate Base Units
// these units are alternate base units, i.e. they are
// units for a single dimension.

ADD_UNIT(year, metric::year_base_unit::unit_type)
ADD_UNIT(yr, year)

ADD_UNIT(degree, angle::degree_base_unit::unit_type)
ADD_UNIT(deg, degree)
ADD_UNIT(arcminute, angle::arcminute_base_unit::unit_type)
ADD_UNIT(arcmin, arcminute)
ADD_UNIT(arcsecond, angle::arcsecond_base_unit::unit_type)
ADD_UNIT(arcsec, arcsecond)

ADD_UNIT(percent,
         make_scaled_unit<dimensionless, scale<10, static_rational<-2>>>::type)
ADD_UNIT(perc, percent)

// Imperial Units
ADD_UNIT(inches, imperial::inch_base_unit::unit_type)
ADD_UNIT(inch, inches)
ADD_UNIT(in, inches)
ADD_UNIT(feet, imperial::foot_base_unit::unit_type)
ADD_UNIT(foot, feet)
ADD_UNIT(ft, foot)
ADD_UNIT(yards, imperial::yard_base_unit::unit_type)
ADD_UNIT(yard, yards)
ADD_UNIT(yd, yard)

// NOTE: These MUST be equivalent to the si:: units or the trig
// functions will not work. We CANNOT use si::radian_base_unit here.
ADD_UNIT_SET(radian, rad, si::plane_angle)
ADD_UNIT_SET(steradian, sr, si::solid_angle)

// Derived Units

ADD_UNIT(inverse_second, divide_typeof_helper<dimensionless, second>::type)
ADD_UNIT(s_n1, inverse_second)
ADD_UNIT_SET(hertz, Hz, inverse_second)
ADD_UNIT_SET(joule, J, si::energy)
ADD_UNIT_SET(watt, W, si::power)
ADD_UNIT_SET(newton, N, si::force)
ADD_UNIT_SET(coulomb, C, si::electric_charge)

// Inverse Length
ADD_UNIT(inverse_kilometer,
         divide_typeof_helper<dimensionless, kilometer>::type)
ADD_UNIT(inverse_meter, divide_typeof_helper<dimensionless, meter>::type)
ADD_UNIT(inverse_centimeter,
         divide_typeof_helper<dimensionless, centimeter>::type)
ADD_UNIT(inverse_millimeter,
         divide_typeof_helper<dimensionless, millimeter>::type)
ADD_UNIT(inverse_micrometer,
         divide_typeof_helper<dimensionless, micrometer>::type)
ADD_UNIT(inverse_nanometer,
         divide_typeof_helper<dimensionless, nanometer>::type)
ADD_UNIT(inverse_picometer,
         divide_typeof_helper<dimensionless, picometer>::type)
ADD_UNIT(inverse_femtometer,
         divide_typeof_helper<dimensionless, femtometer>::type)

ADD_UNIT(km_n1, inverse_kilometer)
ADD_UNIT(m_n1, inverse_meter)
ADD_UNIT(cm_n1, inverse_centimeter)
ADD_UNIT(mm_n1, inverse_millimeter)
ADD_UNIT(um_n1, inverse_micrometer)
ADD_UNIT(nm_n1, inverse_nanometer)
ADD_UNIT(pm_n1, inverse_picometer)
ADD_UNIT(fm_n1, inverse_femtometer)

// Area
ADD_UNIT(kilometer_squared, multiply_typeof_helper<kilometer, kilometer>::type)
ADD_UNIT(meter_squared, multiply_typeof_helper<meter, meter>::type)
ADD_UNIT(m_p2, meter_squared)
ADD_UNIT(centimeter_squared,
         multiply_typeof_helper<centimeter, centimeter>::type)
ADD_UNIT(cm_p2, centimeter_squared)
ADD_UNIT(millimeter_squared,
         multiply_typeof_helper<millimeter, millimeter>::type)
ADD_UNIT(mm_p2, millimeter_squared)

// Inverse Area

ADD_UNIT(inverse_kilometer_squared,
         divide_typeof_helper<dimensionless, kilometer_squared>::type)
ADD_UNIT(inverse_meter_squared,
         divide_typeof_helper<dimensionless, meter_squared>::type)
ADD_UNIT(inverse_centimeter_squared,
         divide_typeof_helper<dimensionless, centimeter_squared>::type)
ADD_UNIT(inverse_millimeter_squared,
         divide_typeof_helper<dimensionless, millimeter_squared>::type)

ADD_UNIT(km_n2, inverse_kilometer_squared)
ADD_UNIT(m_n2, inverse_meter_squared)
ADD_UNIT(cm_n2, inverse_centimeter_squared)
ADD_UNIT(mm_n2, inverse_millimeter_squared)

// Velocity
ADD_UNIT(meter_per_second, divide_typeof_helper<meter, second>::type)
ADD_UNIT(m_s_n2, divide_typeof_helper<m, s>::type)

// Radiant Exposure
ADD_UNIT(joule_per_centimeter_squared,
         divide_typeof_helper<joule, centimeter_squared>::type)
ADD_UNIT(millijoule_per_centimeter_squared,
         divide_typeof_helper<millijoule, centimeter_squared>::type)
ADD_UNIT(microjoule_per_centimeter_squared,
         divide_typeof_helper<microjoule, centimeter_squared>::type)
ADD_UNIT(nanojoule_per_centimeter_squared,
         divide_typeof_helper<nanojoule, centimeter_squared>::type)

ADD_UNIT(J_cm_n2, joule_per_centimeter_squared)
ADD_UNIT(mJ_cm_n2, millijoule_per_centimeter_squared)
ADD_UNIT(uJ_cm_n2, microjoule_per_centimeter_squared)
ADD_UNIT(nJ_cm_n2, nanojoule_per_centimeter_squared)

ADD_UNIT(joule_per_meter_squared,
         divide_typeof_helper<joule, meter_squared>::type)
ADD_UNIT(millijoule_per_meter_squared,
         divide_typeof_helper<millijoule, meter_squared>::type)
ADD_UNIT(microjoule_per_meter_squared,
         divide_typeof_helper<microjoule, meter_squared>::type)
ADD_UNIT(nanojoule_per_meter_squared,
         divide_typeof_helper<nanojoule, meter_squared>::type)

ADD_UNIT(J_m_n2, joule_per_meter_squared)
ADD_UNIT(mJ_m_n2, millijoule_per_meter_squared)
ADD_UNIT(uJ_m_n2, microjoule_per_meter_squared)
ADD_UNIT(nJ_m_n2, nanojoule_per_meter_squared)

ADD_UNIT_IO(joule_per_centimeter_squared, "joule per centimeter squared",
            "J cm^-2")
ADD_UNIT_IO(joule_per_meter_squared, "joule per meter squared", "J m^-2")

// Irradiance
ADD_UNIT(watt_per_centimeter_squared,
         divide_typeof_helper<watt, centimeter_squared>::type)
ADD_UNIT(milliwatt_per_centimeter_squared,
         divide_typeof_helper<milliwatt, centimeter_squared>::type)
ADD_UNIT(microwatt_per_centimeter_squared,
         divide_typeof_helper<microwatt, centimeter_squared>::type)
ADD_UNIT(nanowatt_per_centimeter_squared,
         divide_typeof_helper<nanowatt, centimeter_squared>::type)

ADD_UNIT(W_cm_n2, watt_per_centimeter_squared)
ADD_UNIT(mW_cm_n2, milliwatt_per_centimeter_squared)
ADD_UNIT(uW_cm_n2, microwatt_per_centimeter_squared)
ADD_UNIT(nW_cm_n2, nanowatt_per_centimeter_squared)

ADD_UNIT(watt_per_meter_squared,
         divide_typeof_helper<watt, meter_squared>::type)
ADD_UNIT(milliwatt_per_meter_squared,
         divide_typeof_helper<milliwatt, meter_squared>::type)
ADD_UNIT(microwatt_per_meter_squared,
         divide_typeof_helper<microwatt, meter_squared>::type)
ADD_UNIT(nanowatt_per_meter_squared,
         divide_typeof_helper<nanowatt, meter_squared>::type)

ADD_UNIT(W_m_n2, watt_per_meter_squared)
ADD_UNIT(mW_m_n2, milliwatt_per_meter_squared)
ADD_UNIT(uW_m_n2, microwatt_per_meter_squared)
ADD_UNIT(nW_m_n2, nanowatt_per_meter_squared)

ADD_UNIT_IO(watt_per_centimeter_squared, "watt per centimeter squared",
            "W cm^-2")
ADD_UNIT_IO(watt_per_meter_squared, "watt per meter squared", "W m^-2")

// Integrated Radiance
ADD_UNIT(joule_per_centimeter_squared_per_steradian,
         divide_typeof_helper<joule_per_centimeter_squared, steradian>::type)
ADD_UNIT(
    millijoule_per_centimeter_squared_per_steradian,
    divide_typeof_helper<millijoule_per_centimeter_squared, steradian>::type)
ADD_UNIT(
    microjoule_per_centimeter_squared_per_steradian,
    divide_typeof_helper<microjoule_per_centimeter_squared, steradian>::type)
ADD_UNIT(
    nanojoule_per_centimeter_squared_per_steradian,
    divide_typeof_helper<nanojoule_per_centimeter_squared, steradian>::type)

ADD_UNIT(J_cm_n2_sr_n1, joule_per_centimeter_squared_per_steradian)
ADD_UNIT(mJ_cm_n2_sr_n1, millijoule_per_centimeter_squared_per_steradian)
ADD_UNIT(uJ_cm_n2_sr_n1, microjoule_per_centimeter_squared_per_steradian)
ADD_UNIT(nJ_cm_n2_sr_n1, nanojoule_per_centimeter_squared_per_steradian)

ADD_UNIT(joule_per_meter_squared_per_steradian,
         divide_typeof_helper<joule_per_meter_squared, steradian>::type)
ADD_UNIT(millijoule_per_meter_squared_per_steradian,
         divide_typeof_helper<millijoule_per_meter_squared, steradian>::type)
ADD_UNIT(microjoule_per_meter_squared_per_steradian,
         divide_typeof_helper<microjoule_per_meter_squared, steradian>::type)
ADD_UNIT(nanojoule_per_meter_squared_per_steradian,
         divide_typeof_helper<nanojoule_per_meter_squared, steradian>::type)

ADD_UNIT(J_m_n2_sr_n1, joule_per_meter_squared_per_steradian)
ADD_UNIT(mJ_m_n2_sr_n1, millijoule_per_meter_squared_per_steradian)
ADD_UNIT(uJ_m_n2_sr_n1, microjoule_per_meter_squared_per_steradian)
ADD_UNIT(nJ_m_n2_sr_n1, nanojoule_per_meter_squared_per_steradian)

ADD_UNIT_IO(joule_per_centimeter_squared_per_steradian,
            "joule per centimeter squared per steradian", "J cm^-2 sr^-1")

// Radiance
ADD_UNIT(watt_per_centimeter_squared_per_steradian,
         divide_typeof_helper<watt_per_centimeter_squared, steradian>::type)
ADD_UNIT(
    milliwatt_per_centimeter_squared_per_steradian,
    divide_typeof_helper<milliwatt_per_centimeter_squared, steradian>::type)
ADD_UNIT(
    microwatt_per_centimeter_squared_per_steradian,
    divide_typeof_helper<microwatt_per_centimeter_squared, steradian>::type)
ADD_UNIT(nanowatt_per_centimeter_squared_per_steradian,
         divide_typeof_helper<nanowatt_per_centimeter_squared, steradian>::type)

ADD_UNIT(W_cm_n2_sr_n1, watt_per_centimeter_squared_per_steradian)
ADD_UNIT(mW_cm_n2_sr_n1, milliwatt_per_centimeter_squared_per_steradian)
ADD_UNIT(uW_cm_n2_sr_n1, microwatt_per_centimeter_squared_per_steradian)
ADD_UNIT(nW_cm_n2_sr_n1, nanowatt_per_centimeter_squared_per_steradian)

ADD_UNIT(watt_per_meter_squared_per_steradian,
         divide_typeof_helper<watt_per_meter_squared, steradian>::type)
ADD_UNIT(milliwatt_per_meter_squared_per_steradian,
         divide_typeof_helper<milliwatt_per_meter_squared, steradian>::type)
ADD_UNIT(microwatt_per_meter_squared_per_steradian,
         divide_typeof_helper<microwatt_per_meter_squared, steradian>::type)
ADD_UNIT(nanowatt_per_meter_squared_per_steradian,
         divide_typeof_helper<nanowatt_per_meter_squared, steradian>::type)

ADD_UNIT(W_m_n2_sr_n1, watt_per_meter_squared_per_steradian)
ADD_UNIT(mW_m_n2_sr_n1, milliwatt_per_meter_squared_per_steradian)
ADD_UNIT(uW_m_n2_sr_n1, microwatt_per_meter_squared_per_steradian)
ADD_UNIT(nW_m_n2_sr_n1, nanowatt_per_meter_squared_per_steradian)

ADD_UNIT_IO(watt_per_centimeter_squared_per_steradian,
            "watt per centimeter squared per steradian", "W cm^-2 sr^-1")

// Integrated Radiant Intensity
ADD_UNIT(joule_per_steradian, divide_typeof_helper<joule, steradian>::type)
ADD_UNIT(millijoule_per_steradian,
         divide_typeof_helper<millijoule, steradian>::type)
ADD_UNIT(microjoule_per_steradian,
         divide_typeof_helper<microjoule, steradian>::type)
ADD_UNIT(nanojoule_per_steradian,
         divide_typeof_helper<nanojoule, steradian>::type)

ADD_UNIT(J_sr_n1, joule_per_steradian)
ADD_UNIT(mJ_sr_n1, millijoule_per_steradian)
ADD_UNIT(uJ_sr_n1, microjoule_per_steradian)
ADD_UNIT(nJ_sr_n1, nanojoule_per_steradian)

ADD_UNIT_IO(joule_per_steradian, "joule per steradian", "J sr^-1")

// Radiant Intensity
ADD_UNIT(watt_per_steradian, divide_typeof_helper<watt, steradian>::type)
ADD_UNIT(milliwatt_per_steradian,
         divide_typeof_helper<milliwatt, steradian>::type)
ADD_UNIT(microwatt_per_steradian,
         divide_typeof_helper<microwatt, steradian>::type)
ADD_UNIT(nanowatt_per_steradian,
         divide_typeof_helper<nanowatt, steradian>::type)

ADD_UNIT(W_sr_n1, watt_per_steradian)
ADD_UNIT(mW_sr_n1, milliwatt_per_steradian)
ADD_UNIT(uW_sr_n1, microwatt_per_steradian)
ADD_UNIT(nW_sr_n1, nanowatt_per_steradian)

ADD_UNIT_IO(watt_per_steradian, "watt per steradian", "W sr^-1")

// Electric Potential
ADD_UNIT(volt, si::electric_potential)
ADD_UNIT(V, volt)

// Electric Field
ADD_UNIT(volt_per_meter, divide_typeof_helper<volt, meter>::type)
ADD_UNIT(V_m_n2, volt_per_meter)

ADD_UNIT(newton_per_coulomb, divide_typeof_helper<newton, coulomb>::type)
ADD_UNIT(N_C_n1, newton_per_coulomb)

#undef ADD_UNIT
#undef ADD_BASE_UNIT_SET
#undef ADD_UNIT_SET
#undef ADD_UNIT_IO

namespace boost
{
namespace units
{
namespace d
{
// define some dimensions
typedef t::meter::dimension_type Length;
typedef t::kilogram::dimension_type Mass;
typedef t::second::dimension_type Time;
typedef t::meter_squared::dimension_type Area;

typedef t::joule::dimension_type Energy;
typedef t::watt::dimension_type Power;
typedef t::joule_per_centimeter_squared::dimension_type RadiantExposure;
typedef t::watt_per_centimeter_squared::dimension_type Irradiance;
typedef t::joule_per_centimeter_squared_per_steradian::dimension_type
    IntegratedRadiance;
typedef t::watt_per_centimeter_squared_per_steradian::dimension_type Radiance;
typedef t::joule_per_steradian::dimension_type IntegratedRadiantIntensity;
typedef t::watt_per_steradian::dimension_type RadiantIntensity;
}  // namespace d

// function to convert from dimensionless to angle
template <typename U, typename T>
// 1. convert to dimensionless
// 2. cast to double
// 3. create radian by multiply
// 4. convert to return type
quantity<t::rad, T> d2a(quantity<U, T> a)
{
  return quantity<t::rad, T>(i::rad *
                             quantity_cast<T>(quantity<t::dimless, T>(a)));
}

// function to convert from angle to dimensionless
template <typename U, typename T>
// 1. convert to radian
// 2. cast to double
// 3. create dimensionless by multiply
// 4. convert to return type
quantity<t::dimless, T> a2d(quantity<U, T> a)
{
  return quantity<t::dimless, T>(i::dimless *
                                 quantity_cast<T>(quantity<t::radian, T>(a)));
}

}  // namespace units
}  // namespace boost

// we want to allow implicit conversions between
// units that are the same, but have differen types.
// for example, boost::units::t::radian is a scaled base unit based on
// angle::radian_base_unit, so it is not implicitly convertible to/from
// si::plane_angle, even through they represent the same unit. This is true for
// all of the base units as well. boost::units::t::second is based on
// si::second_base_unit, and cannot be implicitly converted to/from si::time.
// below are a list of conversions between types that represent the same unit
// that the user could reasonably expect to be the "same"
#define ADD_IMPLICITLY_CONVERTIBLE_UNITS(A, B)                \
  namespace boost                                             \
  {                                                           \
  namespace units                                             \
  {                                                           \
  template <>                                                 \
  struct is_implicitly_convertible<A, B> : boost::true_type { \
  };                                                          \
  template <>                                                 \
  struct is_implicitly_convertible<B, A> : boost::true_type { \
  };                                                          \
  }                                                           \
  }

// base units
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::radian,
                                 angle::radian_base_unit)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::steradian,
                                 angle::steradian_base_unit)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::meter, si::meter_base_unit)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::gram, cgs::gram_base_unit)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::second, si::second_base_unit)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::kelvin, si::kelvin_base_unit)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::ampere, si::ampere_base_unit)

// si system
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::meter, si::length)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::kilogram, si::mass)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::second, si::time)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::kelvin, si::temperature)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::ampere, si::current)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::hertz, si::frequency)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::meter_squared, si::area)

// cgs system
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::centimeter, cgs::length)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::gram, cgs::mass)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::second, cgs::time)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::ampere, cgs::current)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::hertz, cgs::frequency)
ADD_IMPLICITLY_CONVERTIBLE_UNITS(boost::units::t::centimeter_squared,
                                 cgs::area)

// define multiplication between int's and quantity<unit>'s
// otherwise, we can't do this
// quantity<t::m> L(3.*m);
// quantity<t::m> L2 = 3*L; // error
// quantity<t::m> L2 = 3.*L; // OK
template <typename U, typename T>
boost::units::quantity<U, T> operator*(int a, boost::units::quantity<U, T> b)
{
  return static_cast<T>(a) * b;
}

template <typename U, typename T>
boost::units::quantity<U, T> operator*(boost::units::quantity<U, T> b, int a)
{
  return static_cast<T>(a) * b;
}

// define multiplication between int's and units, so that template type
// deduction will work.
// otherwise, we can't do this
//
// template<typename U>
// void Func( quantity<U> q );
// ...
// Func(3*m); // error
// Func(3.*m); // OK
template <typename U, typename T>
boost::units::quantity<boost::units::unit<U, T>> operator*(
    int a, boost::units::unit<U, T> u)
{
  return static_cast<double>(a) * u;
}

template <typename U, typename T>
boost::units::quantity<boost::units::unit<U, T>> operator*(
    boost::units::unit<U, T> u, int a)
{
  return static_cast<double>(a) * u;
}

// define division of quantity<unit>'s by ints
// otherwise, we can't do this
// quantity<t::m> L(3.*m);
// quantity<t::m> L2 = L/3; // error
// quantity<t::m> L2 = L/3.; // OK
template <typename U, typename T>
boost::units::quantity<U, T> operator/(boost::units::quantity<U, T> b, int a)
{
  return b / static_cast<T>(a);
}

// define division of int by quantity<unit>
// otherwise, we can't do this
// quantity<t::s> T(2.*s);
// quantity<t::Hz> L2 = 1/T; // error
// quantity<t::Hz> L2 = 1./T.; // OK
template <typename U, typename T>
boost::units::quantity<typename boost::units::divide_typeof_helper<
                           boost::units::t::dimensionless, U>::type,
                       T>
operator/(int a, boost::units::quantity<U, T> b)
{
  return static_cast<T>(a) / b;
}

#endif  // include protector
