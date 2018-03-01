#!/bin/bash

# ______________________________________________________________________________
#                                             generate, build and install Switch
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_SWITCH_SYSTEM_DRAWING=OFF -DBUILD_SWITCH_SYSTEM_WINDOWS_FORMS=OFF -DBUILD_SWITCH_TESTS=ON -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . -- -j8
if [ $? -ne 0 ]; then exit -1; fi
popd

# ______________________________________________________________________________
#                                                      run registered unit tests
pushd build
#ctest --output-on-failure --build-config Debug --fixture-exclude RegistryKeyUT
#if [ $? -ne 0 ]; then exit -1; fi

Debug/Switch.Core.UnitTest --gtest_filter=-Registry*.*
if [ $? -ne 0 ]; then exit -1; fi

Debug/Switch.System.UnitTest
if [ $? -ne 0 ]; then exit -1; fi

Debug/Switch.System.Core.UnitTest
if [ $? -ne 0 ]; then exit -1; fi

Debug/Switch.TUnit.UnitTests
if [ $? -ne 0 ]; then exit -1; fi
popd
