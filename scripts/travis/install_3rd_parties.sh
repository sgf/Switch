#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                                      install 3rd parties
mkdir -p build/3rdparty
pushd build

if [[ "${TRAVIS_OS_NAME}" == "linux" ]]; then
  mkdir -p external/cmake
  pushd external/cmake
  wget https://cmake.org/files/v3.8/cmake-3.8.0-Linux-x86_64.sh
  chmod +x cmake-*-Linux-x86_64.sh
  ./cmake-*-Linux-x86_64.sh --exclude-subdir --skip-license
  export PATH="${PWD}/bin:$PATH"
  popd
else
  brew update
  brew install astyle cppcheck curl jpeg libpng zlib -y
fi
popd
