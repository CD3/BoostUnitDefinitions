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
conan install .. -s build_type=Release
cmake .. -DCMAKE_INSTALL_PREFIX=$bindir/install -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
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
find_package( Boost REQUIRED )
target_link_libraries(main BoostUnitDefinitions::BoostUnitDefinitions Boost::boost)
set_target_properties(main PROPERTIES CXX_STANDARD 11)
EOF

mkdir build1
cd build1
conan install $root -s build_type=Release
cmake .. -DBoostUnitDefinitions_DIR=${bindir}/install/cmake/ -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
./main

cd ..








echo "PASSED"

exit 0
