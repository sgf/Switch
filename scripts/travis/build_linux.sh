#!/bin/bash

# ______________________________________________________________________________
#                                             generate, build and install Switch
pushd build
# ENABLE_COVERAGE deactivated if not the job exceeds the maximum time limit.
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SWITCH_TESTS=ON -DENABLE_COVERAGE=OFF -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . -- -j8
popd

# ______________________________________________________________________________
#                                                      run registered unit tests
pushd build
ctest --output-on-failure --build-config Debug
popd
