#!/bin/bash

# ______________________________________________________________________________
#                                             generate, build and install Switch
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SWITCH_TESTS=ON -DENABLE_COVERAGE=ON
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi 
popd

# ______________________________________________________________________________
#                                                      run registered unit tests
pushd build
ctest --output-on-failure --build-config Debug
if [ $? -ne 0 ]; then exit -1; fi 
popd
