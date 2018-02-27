#!/bin/bash

# ______________________________________________________________________________
#                                                                      setup git
git config --global user.email "gammasoft71@gmail.com"
git config --global user.name "gammasoft71"

# Clone switch-doc
if [ -d "build/ReferenceGuide" ]; then rm -r -f build/ReferenceGuide; fi
git clone https://github.com/gammasoft71/Switch-doc.git build/ReferenceGuide

# ______________________________________________________________________________
#                                                       Generating documentation
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target Switch.ReferenceGuide
popd

# ______________________________________________________________________________
#                                        check doxygen results and display error
#if [[ -s build/reference_guide/doxygen_warnings.txt ]]; then
#  echo "You must fix doxygen before submitting a pull request"
#  echo ""
#  cat build/reference_guide/doxygen_warnings.txt
#  exit -1
#fi

# ______________________________________________________________________________
#                                                       Publishing documentation
pushd build/ReferenceGuide
if [[ -e doxygen_warnings.txt ]]; then rm doxygen_warnings.txt; fi
git add --all
git commit -m "Travis CI - Generate Reference Guide - build [$TRAVIS_BUILD_NUMBER]"
git push "https://${GH_TOKEN}@github.com/gammasoft71/Switch-doc.git" master > /dev/null 2>&1 
popd
