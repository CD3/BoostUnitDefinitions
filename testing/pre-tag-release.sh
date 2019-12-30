#! /bin/bash

set -e
root=$(git rev-parse --show-toplevel)

cd $root

bindir="$PWD/build-and-test"
function cleanup()
{
  rm -r $bindir
}
trap cleanup EXIT

mkdir $bindir
cd $bindir
cmake .. -DCMAKE_INSTALL_PREFIX=$bindir/install
cmake --build .
cmake --build . --target test

# test install
cmake --build . --target install






mkdir app
cd app

cat << EOF > main.cpp
#include <iostream>
#include <BoostUnitDefinitions/Units.hpp>

using namespace boost;
using namespace boost::units;

int main()
{
  quantity<t::m> L(25*i::cm);

  return 0;
}
EOF

cat << EOF > CMakeLists.txt
cmake_minimum_required(VERSION 3.1)
add_executable( main main.cpp )
find_package( BoostUnitDefinitions REQUIRED )
target_link_libraries(main BoostUnitDefinitions::BoostUnitDefinitions)
set_target_properties(main PROPERTIES CXX_STANDARD 11)
EOF

mkdir build1
cd build1
cmake .. -DBoostUnitDefinitions_DIR=${bindir}/install/cmake/
cmake --build .
./main

cd ..








echo "PASSED"

exit 0
