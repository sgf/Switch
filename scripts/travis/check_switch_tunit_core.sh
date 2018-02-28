#!/bin/bash

# ______________________________________________________________________________
#                                                               cppcheck analyse
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DDOWNLOAD_CPPCHECK=ON -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target Check.Switch.Tunit.Core
if [ $? -ne 0 ]; then exit -1; fi
popd
