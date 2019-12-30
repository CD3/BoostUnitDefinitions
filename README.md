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

CMake is used to configure, build, and install:

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
$ cmake --build . --target install
```
