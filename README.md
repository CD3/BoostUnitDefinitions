# BoostUnitDefinitions

A collection of unit definitions for `Boost.Units`.

## Description

[`Boost.Units`](https://www.boost.org/doc/libs/1_72_0/doc/html/boost_units.html) is a great library for doing unit conversions
and dimensional analysis at compile-time. Writing "unit-enabled" functions can detect bugs in physical computations at compile-time,
but it also turns out to be very convenient because you can support automatic unit conversions between the units used internally by
your function and the units used by the caller. This library started out at a single file
in the [libGPB](https://github.com/CD3/libGBP) library (a library for doing Gaussian beam propagation calculations).

Units are represented by c++ types, and instances of these types are used to create
values, and there is support for building unit systems (for example, an SI 
and CGS system are provided).  But the naming convention used by the library is
a bit inconsistent. For example, the *type* for meter in the SI system is named `si::length`,
but the *instance* is named `si::meter`. In CGS, the *type* for centimeter is
named `cgs::length`, and the *instance* is named `cgs::centimeter`. This naming convention
mixes units and dimensions (length is a dimension, not a unit). Here is simple example:
```cpp
...
#include <boost/units/systems/si.hpp>
...
using namespace boost;
using namespace boost::units;
...
quantity<si::length> L(10*si::meter);
CHECK( quantity<cgs::length>(L).value() == 1000 );
...
```
This library provides a set of definitions that are consistently named. All *types* are
placed in a `t` namespace, and a corresponding *instance* for each is created in a `i`
namespace. Using this library, the example above can be written
```cpp
...
#include <BoostUnitDefinitions/Units.hpp>
...
using namespace boost;
using namespace boost::units;
...
quantity<t::m> L(10*i::m);
CHECK( quantity<t::cm>(L).value() == 1000 );
...
```
This library is intended to provide a convenient set of unit definitions that are useful
for doing physics calculations. Basically it's a place to put unit definitions that I
find a need for.

## Building and Installing

### Conan

You can install the library with conan from the command line

```
conan install cd3-boost-unit-definitions/0.2.2
```
or by adding the `cd3-boost-unit-definitions/0.2.2` dependency to your `conanfile.txt`/`conanfile.py`.

### From source

Use CMake to build and install from source.

```
$ git clone https://github.com/CD3/BoostUnitDefinitions.git
$ cd BoostUnitDefinitions
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
$ cmake --build . --target install
```

## Using

If you install the library with CMake, or use Conan with the CMakeDeps/CMakeToolchain generators, you can find and link against it in your CMakeLists.txt file

```
...cmake
find_package(BoostUnitDefinitions REQUIRED) # defines the BoostUnitDefinitions::BoostUnitDefinitions target
...
target_link_libraries(MyTarget PUBLIC BoostUnitDefinitions::BoostUnitDefinitions)
...
```
Then, in your code, include the (only) header file
```cpp
#include <BoostUnitDefinitions/Units.hpp>
```
The header defines a large set of units, both the _type_ and _static instance_, so you can easily work with common quantities.
```
...
using namespace boost::units;


quantity<t::cm> L1 = 10*i::cm;
quantity<t::in> L2 = 24*i::in;
quantity<t::km> L3 = 2.5*i::km;
quantity<t::ft> L4 = 10*i::ft;
quantity<t::in> L2 = 24*i::in;


quantity<t::s> T1 = 10*i::s;
quantity<t::ms> T2 = 100*i::ms;

// derived units follow a naming convention that gives the exponent (either (p)ostive or (n)egative) after each unit.
quantity<t::m_s_n1> v = 10*i::m_s_n1;    // m s^-1
quantity<t::mJ_cm_n2> H = 1*i::mJ_cm_n2  // mJ cm^-2 (radiant exposure)
```
