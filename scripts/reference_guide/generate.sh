#!/usr/bin/env sh

# ______________________________________________________________________________
#                                                               Clone switch-doc
if [ -d "build/ReferenceGuide" ]; then rm -r -f build/ReferenceGuide; fi
git clone https://github.com/gammasoft71/switch-doc build/ReferenceGuide

# ______________________________________________________________________________
#                                                       Generating documentation
mkdir -p build
pushd build
cmake --build . --target ReferenceGuide
popd

# ______________________________________________________________________________
#                                                       Publishing documentation
pushd build/ReferenceGuide
git add --all
git commit -m "Generate Reference Guide"
git push
popd
