@echo off

rem ____________________________________________________________________________
rem                                                             Clone switch-doc
if exist "build/ReferenceGuide" (
  rmdir /s /q build/ReferenceGuide
)
git clone https://github.com/gammasoft71/switch-doc build/ReferenceGuide

rem ____________________________________________________________________________
rem                                                     Generating documentation
mkdir build
cd build
cmake --build . --target ReferenceGuide
cd ..

rem_____________________________________________________________________________
rem                                                     Publishing documentation
cd build/ReferenceGuide
git add --all
git commit -m "Generate Reference Guide"
git push
cd ../..
