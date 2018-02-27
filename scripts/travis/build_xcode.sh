#!/bin/bash

# ________________________________________________________________________________________
#                                                       generate, build and install Switch
pushd build
# ENABLE_COVERAGE deactivated if not the job exceeds the maximum time limit.
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_SWITCH_TESTS=ON -DENABLE_COVERAGE=OFF -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . -- -j8
popd

# ________________________________________________________________________________________
#                                                                run registered unit tests
pushd build
ctest --output-on-failure --build-config Release
popd
