#!/bin/bash

# ______________________________________________________________________________
#                                             generate, build and install Switch
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SWITCH_SYSTEM_DRAWING=OFF -DBUILD_SWITCH_SYSTEM_WINDOWS_FORMS=OFF -DBUILD_SWITCH_TESTS=ON -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . -- -j8
popd

# ______________________________________________________________________________
#                                                      run registered unit tests
pushd build
ctest --output-on-failure --build-config Debug
popd
