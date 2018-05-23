[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Download the latest stable Switch version

You can download latest stable version on [SourceForge](https://sourceforge.net/projects/switchpro)

[![Download Portable C++ Framework](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/switchpro/files/latest/download)

# Clone the latest Switch commit

Or clone latest development version on [GitHub](https://github.com/gammasoft71/Switch).

```shell
git clone https://github.com/gammasoft71/Switch .
```

# Installation

## Windows 7 SP1 or later

1. Install Microsoft Visual Studio 2017 Community
   
   In order to build Switch, you first need download and install Microsoft Visual Studio 2017 community from [https://www.visualstudio.com](https://www.visualstudio.com).

2. Install CMake 3.2 or later
   
   After Microsoft Visual Studio, to build Switch, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)
   
   *Remarks: Verify if you can execute cmake --version in "Command Prompt", if it's no, add cmake install directory to your path.*

3. After installing Microsoft Visual Studio and CMake, do the following in "Command Prompt" to build and install Switch :

```shell
cd C:\Users\YourName\Switch\
install.cmd
```

   *Remarks, this operation depand of your hardware and can be very long*

4. Enjoy and be creative with Switch ;-)

### Remarks

* Switch installer set cmake variable CMAKE_INSTALL_PREFIX to "/usr/local" for generate, build and install Switch.
* When install is complete you can find installed Switch files in folder "/usr/local".
* To build your own project using Switch, don't miss to set cmake variable CMAKE_INSTALL_PREFIX to "/usr/local"; otherwise cmake don't find Switch libraries and include files. See cmake documentation ([http://cmake.org/documentation](http://cmake.org/documentation)) for more information.

## macOS 10.11.5 (OS X El Capitan) or later

1. Install Xcode 8.2 or later
   
   In order to build Switch, you first need download and install Xcode from App Store and install "Commands line tools".

   *Remarks: Verify if you can execute clang --version in terminal.*

2. Install Homebrew
   
   After Xcode, to build Switch, you need to install package manager Homebrew ([http://brew.sh](http://brew.sh)).
   
```shell
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

3. After installing Xcode and Homebrew, do the following in "Terminal" to Build and install Switch :

```shell
cd /Users/YourName/Switch
./install.sh
```

   *Remarks, this operation depand of your hardware and can be very long*

4. Enjoy and be creative with Switch ;-)

## CentOS 7, Debian 9.2.1, Elementary OS 0.4, Fedora 26, LinuxMint 18.2, RedHat 7.4 and Ubuntu 16.04 (or later)

1. Do the following in "Terminal" to Build and install Switch :

```shell
cd /home/YourName/Switch
./install.sh
```

   *Remarks, this operation depend of your hardware and can be very long*

2. Enjoy and be creative with Switch ;-)

## Other linux Distribution

1. Install clang 3.9 or later
   
   In order to build Switch, you first need download and install clang 4.0.0 or later.

   *Remarks: Verify if you can execute clang --version in terminal.*

2. Install CMake 3.2 or later
   
   After clang, to build Switch, you need to install the latest version cmake from [https://cmake.org/download](https://cmake.org/download/)

   *Remarks: Verify if you can execute cmake --version in terminal.*

3. Install gtkmm 3.0 or later
   
   After installing CMake, you need to install gtkmm 3 on your system. See [https://developer.gnome.org/gtkmm-tutorial/stable/chapter-installation.html](https://developer.gnome.org/gtkmm-tutorial/stable/chapter-installation.html) for more information. The easy way is install from your linux distribution package manager like apt, yum or other.
  
4. Install libuuid
   
   After installing gtkmm, you need to install libuuid lib on your system. The easy way is install from your linux distribution package manager like apt, yum or other.
  
5. After installing clang, CMake, gtkmm and libuuid, do the following in "Terminal" to Build and install Switch :

```shell
cd /home/YourName/Switch
./install.sh
```

   *Remarks, this operation depand of your hardware and can be very long*
  
7. Enjoy and be creative with Switch ;-)

# Build and run your first Switch application

After downloading and install Switch you are ready to build and run your first application. We will call it SwitchConsole (or what you want).

This application is very simple and it composed of 2 files :

A source file SwitchConsole.cpp :

```c++
#include <Switch/Switch>

using namespace System;

namespace SwitchConsole {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("My first switch application");
      Console::WriteLine();
    }
  };
}

startup_(SwitchConsole::Program);
```

A cmake file CMakeLists.txt :

```cmake
cmake_minimum_required(VERSION 3.2)

Project(SwitchConsole)

find_package(Switch REQUIRED)
add_executable(SwitchConsole SwitchConsole.cpp)
target_link_libraries(SwitchConsole Switch.System)
```

## Build and run on Windows

To build this wonderful application, open "Command Prompt" and type following lines:

```shell
cd C:\Users\YourName\Projects\SwitchConsole
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
```

The SwitchConsle.sln file was generate, open it with VisualStudio 2017. Select SwitchConsole project and type Ctrl+F5 to build and run your first application.

## Build and run on macOS

To build this wonderful application, open "Terminal" and type following lines:

```shell
cd /Users/YourName/Projects/SwitchConsole
mkdir build
cd build
cmake .. -G "Xcode"
```

The SwitchConsle.xcodeproj file was generate, open it with Xcode. Select SwitchConsole project and type Cmd+R to build and run your first application.

## Build and run on Linux

To build this wonderful application, open "Terminal" and type following lines:

```shell
cd /home/YourName/Projects/SwitchConsole
mkdir build
cd build
export CC=clang
export CXX=clang++
cmake ..
```

The makefile was generate, in the same "Terminal" type following lines to build and run your first application:

```shell
cmake --build . --config Release
./SwitchConsole
```

### Remarks

* If your application is unit tests application, is the same procedure but you must replace the line **target_link_libraries(SwitchConsole Switch.System)** by **target_link_libraries(SwitchConsole Switch.TUnit.Main)** if you don't have your own main entry point; or **target_link_libraries(SwitchConsole Switch.TUnit.Core)** it you have your own main entry point in **CMakeLists.txt** file.
* ​If your application is GUI application, is the same procedure but you must replace the line **add_executable(SwitchConsole SwitchConsole.cpp)** by **add_executable(SwitchConsole ${SWITCH_GUI} SwitchConsole.cpp)** and replace the line **target_link_libraries(SwitchConsole Switch.System)** by **target_link_libraries(SwitchConsole Switch.System.Windows.Forms)** in **CMakeLists.txt** file.

______________________________________________________________________________________________

© 2018 Gammasoft.
