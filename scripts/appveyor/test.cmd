rem ____________________________________________________________________________
rem                                                    run registered unit tests
cd build
ctest --output-on-failure --build-config Debug
cd ..
