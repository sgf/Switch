[![Switch Header](../../Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

[Home](Home.md)

______________________________________________________________________________________________

# Introduction to Switch Winforms

The first part of the Switch Winforms tutorial introduces Switch Framework and the Winforms library.

## About this tutorial

This is Switch C++ Winforms tutorial. Switch Winforms tutorial is for beginner programmers. The goal of this tutorial is to teach readers basics of GUI programming in Switch Winforms. The tutorial is created and tested on macOS. Nevertheless, it can be used on other operating systems as well. Most examples should run without modification. Images used in this tutorial can be downloaded here.

## Switch

The Switch Project is an open development initiative sponsored by Gammasoft to develop an open source, native C++ version of the Microsoft .NET development platform.

Switch can be divided into four groups:

* **System** components
* **Drawing** components
* **Forms** components (Winforms)
* **TUnit** compnents

The **System** components are the libraries hat provide access to system functionality. It is the foundation on which c++ applications. The **Drawing** components support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services and also contains types that extend design-time user-interface logic and drawing. The **Forms** components contains all for creating Windows-based applications that take full advantage of the rich user interface features available in the modern operating system (Winforms). The **TUnit** components are a unit-testing framework for modern C++14.

Switch is multiplatform programming platform. It can be run on Windows, macOS, Linux, iOs and android operating systems.

### Remarks

**Drawing** and **Forms** components doesn't run on android and iOS operating systems.

## Winforms

Windows Forms is a graphical user interface application programming interface (API) included as a part of Gammasoft Switch Framework. Simply put, Winforms is a library for creating GUI applications.

## Compiling examples

Our tutorial uses the C++ language. To compile all the examples in this tutorial, we use [cmake](https://cmake.org).

``` cmake
cmake_minimum_required(VERSION 3.2)

project(Simple)
find_package(Switch REQUIRED)
add_executable(Simple ${SWITCH_GUI} Simple.cpp)
target_link_libraries(Simple Switch.System.Windows.Forms)
```

### Simple.cpp

```c++
#include <Switch/Switch>

using namespace System::Windows::Forms;

class Simple : public Form {
public:
  Simple() {
     this->Text = "Simple";
     this->Size = System::Drawing::Size(250, 200);
     this->StartPosition = FormStartösition::CenterScreen;
  }

  static void Main() {
     Application::Run(Simple());
  }
};

startup_(Simple);
```

In our simple example, we need Switch.System.Windows.Forms libraries.

### Windows command lines :

``` bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=c:/usr/local
cmake --build . --config Debug
```

### macOS command lines :

``` bash
mkdir build
cd build
cmake .. -G "Xcode"
cmake --build . --config Debug
```

### Linux command lines :

``` bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++
cmake --build . -- -j 8
```

## Reference

* [Switch web site](https://gammasoft71.wixsite.com/switch)
* [Reference Guide](https://gammasoft71.github.io/Switch-doc/)
java2s.com

This was an introduction to the Switch Winforms library.

______________________________________________________________________________________________

© 2018 Gammasoft.
