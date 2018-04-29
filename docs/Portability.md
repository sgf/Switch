[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

The Portability section provide informations about Operating System suported, Compilers and Development Environment tools.

# Operating System Supported

Actualy Switch run on Windows, macOS, Linux, iOS and Android Operating System.

## Windows 7 - 32 and 64 bits or later

[![Windows](Pictures/OS/Windows.png)](https://microsoft.com/windows)

## macOS 10.11.5 (OS X El Capitan) - 64 bits or later

[![macOS](Pictures/OS/macOS.jpg)](https://apple.com/macos/)

## Linux - 32 and 64 bits

### CentOS 7 or later

[![CentOS](Pictures/OS/CentOS.png)](https://centos.org)

### Debian 9.2.1 or later

[![Debuan](Pictures/OS/Debian.png)](https://debian.org)

### Elementary OS 0.4 or later

[![Elementary OS](Pictures/OS/ElementaryOS.png)](https://elementary.io)

### Fedora 26 or later

[![Fedora](Pictures/OS/Fedora.png)](https://getfedora.org)

### LinuxMint 18.2 or later

[![LinuxMint](Pictures/OS/LinuxMint.png)](https://linuxmint.com)

### Redhat 7.4 or later

[![Redhat](Pictures/OS/Redhat.png)](https://redhat.com)

### Ubuntu 16.04 or later

[![Ubuntu](Pictures/OS/Ubuntu.png)](https://ubuntu.com)

### Other distribution [manual installation]

[![Linux](Pictures/OS/Linux.png)](https://linux.org)

## iOS 11 - 64 bits or later [manual installation]

[![iOS](Pictures/OS/iOS.png)](https://apple.com/ios)

## android 6.0 (Marshmallow) - 32 and 64 bits or later [manual installation]

[![android](Pictures/OS/Android.png)](https://android.com)

# The Switch libraries portability list

| Library                     | Windows | macOS | Linux | iOS   | Android |
|-----------------------------|---------|-------|-------|-------|---------|
| Switch                      | **√**   | **√** | **√** | **√** | **√**   |
| Switch.Core                 | **√**   | **√** | **√** | **√** | **√**   |
| Switch.System               | **√**   | **√** | **√** | **√** | **√**   |
| Switch.System.Core          | **√**   | **√** | **√** | **√** | **√**   |
| Switch.System.Drawing       | **√**   | **√** | **√** | *X*   | *X*     |
| Switch.System.ServiceModel  | **√**   | **√** | **√** | **√** | **√**   |
| Switch.System.Windows.Forms | **√**   | **√** | **√** | *X*   | *X*     |
| Switch.TUnit.Core           | **√**   | **√** | **√** | **√** | **√**   |
| Switch.TUnit.Framework      | **√**   | **√** | **√** | **√** | **√**   |
| Switch.TUnit.Main           | **√**   | **√** | **√** | **√** | **√**   |

# Tests and coverage

Switch is every time tested with Continuous Integration tools.

## AppVeyor

[![AppVeyor](Pictures/CI/AppVeyor.png)](https://ci.appveyor.com)

Configurations :

* Visual Studio 2017 Win32
* Visual Studio 2017 Win64

## Travis CI

[![TravisCI](Pictures/CI/TravisCI.png)](https://travis-ci.org)

Configurations :

* macOS Xcode 9.1
* linux clang 3.9
* Reference Guide generation

## Codecov

[![Codecov](Pictures/CI/Codecov.png)](https://codecov.io)

# Development Environment Tools

With CMake, Switch support many Development Environment Tools.

## Microsoft Visual C++ 2017 or later

[![VisualStudio](Pictures/DevTools/VisualStudio.png)](https://visualstudio.com)

## XCode 8.3 or later

[![Xcode](Pictures/DevTools/Xcode.png)](https://developer.apple.com/xcode)

## CLion 2017.2 or later

[![CLion](Pictures/DevTools/CLion.png)](https://jetbrains.com/clion)

## Eclipse CDT 8.0 or later

[![EclipseCDT](Pictures/DevTools/EclipseCDT.png)](https://eclipse.org/cdt)

## Code::Blocks 13.12 or later

[![CodeBlocks](Pictures/DevTools/CodeBlocks.png)](http://codeblocks.org)

## KDevelop 3 or later

[![KDevelop](Pictures/DevTools/KDevelop.png)](https://kdevelop.org)

## CodeLite 11 or later

[![CodeLite](Pictures/DevTools/CodeLite.png)](https://codelite.org)

## Qt Creator

[![Qt](Pictures/DevTools/QtCreator.png)](https://qt.io)

## Standard Unix makefile

![LinuxMakefile](Pictures/DevTools/LinuxMakefile.png)

# Compilers

The compilers listed below are supported with Switch :

* MSVC 2015 or later
* clang 3.9 or later 
<!--* GCC 6 or later-->

# Native

Switch has a thin layer by library if needed to abstract operating system. This layer is called naturally **Native**.

For add a new Operating System, you juste have to implement Native api for the new target Operating System.

## Native API by library

[Switch.Core](../src/Switch.Core/src/Native/Api.hpp)

[Switch.System](../src/Switch.System/src/Native/Api.hpp)

[Switch.System.Drawing](../src/Switch.System.Drawing/src/Native/Api.hpp)

[Switch.System.Windows.Forms](../src/Switch.System.Windows.Forms/src/Native/Api.hpp)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
