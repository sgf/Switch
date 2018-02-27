rem ______________________________________________________________________________________
rem                                                      run registered unit tests 32 bits
if DEFINED SWITCH_BUILD_WIN32 (
  cd build32
  ctest --output-on-failure --build-config Debug
  cd ..
)

rem ______________________________________________________________________________________
rem                                                      run registered unit tests 64 bits
if DEFINED SWITCH_BUILD_WIN64 (
  cd build64
  ctest --output-on-failure --build-config Debug
  cd ..
)
