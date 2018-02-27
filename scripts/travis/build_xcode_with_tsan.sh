#!/bin/bash

# ______________________________________________________________________________
#                                             generate, build and install Switch
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SWITCH_TESTS=ON -DENABLE_TSAN=ON -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . -- -j8
popd

# ______________________________________________________________________________
#                                                      run registered unit tests
pushd build
ctest --output-on-failure --build-config Debug
popd
