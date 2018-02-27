#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                       generate, build and install Switch
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_SWITCH_TESTS=ON -DENABLE_COVERAGE=ON -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
#cmake --build . --config Release -- -j8
popd

# ________________________________________________________________________________________
#                                                                run registered unit tests
pushd build
#ctest --output-on-failure --build-config Release
popd
