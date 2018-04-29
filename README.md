[![Switch](docs/Pictures/Menu/Switch.png)]()[![Switch](docs/Pictures/Menu/Gallery.png)]()[![Switch](docs/Pictures/Menu/Examples.png)]()[![Switch](docs/Pictures/Menu/Downloads.png)]()[![Switch](docs/Pictures/Menu/Documentation.png)]()[![Switch](docs/Pictures/Menu/Project.png)]()[![Switch](docs/Pictures/Menu/Sources.png)]()[![Switch](docs/Pictures/Menu/Contact.png)]()[![Switch](docs/Pictures/Menu/Gammasoft.png)]()

[![GitHub Logo](docs/Pictures/SwitchNativeC++port.png)](https://gammasoft71.github.io/Switch)
____________________________________________________________________________________

[![build status](https://travis-ci.org/gammasoft71/Switch.svg)](https://travis-ci.org/gammasoft71/Switch) 
[![Build status](https://ci.appveyor.com/api/projects/status/kjfq2sl5bc99kut6?svg=true)](https://ci.appveyor.com/project/gammasoft71/Switch)
[![Documentation](https://img.shields.io/badge/code-documented-brightgreen.svg)](https://gammasoft71.github.io/Switch-doc) 
[![codecov](https://codecov.io/gh/gammasoft71/switch/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/Switch)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=Switch%20website)](https://gammasoft71.wixsite.com/switch)
[![license](https://img.shields.io/github/license/gammasoft71/Switch.svg)](docs/License.md)
[![SourceForge Download Switch](https://img.shields.io/sourceforge/dt/switchpro.svg)](https://sourceforge.net/projects/switchpro/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/Switch.svg)](docs/C++17Ready.md)
[![os Windows](https://img.shields.io/badge/os-Windows-004080.svg)](docs/Portability.md)
[![os macOS](https://img.shields.io/badge/os-macOS-004080.svg)](docs/Portability.md)
[![os Linux](https://img.shields.io/badge/os-Linux-004080.svg)](docs/Portability.md)
[![os iOS](https://img.shields.io/badge/os-iOS-004080.svg)](docs/Portability.md)
[![os android](https://img.shields.io/badge/os-android-004080.svg)](docs/Portability.md)
[![development status](https://img.shields.io/badge/dev-status-004080.svg)](docs/SwitchStatus.md)
<!--[![HitCount](http://hits.dwyl.io/gammasoft71/switch.svg)](http://hits.dwyl.io/gammasoft71/Switch)-->
<!--[![Coverage Status](https://coveralls.io/repos/github/gammasoft71/Switch/badge.svg?branch=master)](https://coveralls.io/github/gammasoft71/Switch?branch=master)-->

# The Switch framework is...
* a collection of native C++ classes libraries, similar to the .NET Framework;
* written in efficient, modern C++14;
* and highly portable and available on many different platforms (Windows, macOS, Linux, iOS and android);

For more information see [Switch website](https://gammasoft71.wixsite.com/switch) (or [markdown Documentations](./docs/Home.md)) and [Reference Guide](https://gammasoft71.github.io/Switch-doc)

# Examples
The classic first application 'Hello World'.

## Console
HelloWorld.cpp:

```c++
#include <Switch/Switch>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

startup_(HelloWorld::Program);
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorld)
find_package(Switch REQUIRED)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld Switch.System)
```

## Forms
HelloWorldForm.cpp:

```c++
#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Application::EnableVisualStyles();
      
      Button button;
      button.Text = "Click me";
      button.Location = Point(10, 10);
      button.Click += delegate_(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World!");
      };
      
      Form form;
      form.Text = "Hello World Form";
      form.Controls().Add(button);
      form.ShowDialog();
    }
  };
}

startup_(HelloWorld::Program);
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldForm)
find_package(Switch REQUIRED)
add_executable(HelloWorldForm ${SWITCH_GUI} HelloWorldForm.cpp)
target_link_libraries(HelloWorldForm Switch.System.Windows.Forms)
```

## TUnit
HelloWorldTest.cpp:

```c++
#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  class TestFixture_(HelloWorldTest) {
    void Test_(CreateStringFromLiteral) {
      string s = "Hello, World!";
      Assert::AreEqual("Hello, World!", s);
    }

    void Test_(CreateStringFromChars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      Assert::AreEqual("Hello, World!", s);
    }
  };

  AddTest_(HelloWorldTest, CreateStringFromLiteral);
  AddTest_(HelloWorldTest, CreateStringFromChars);
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldTest)
find_package(Switch REQUIRED)
add_executable(HelloWorldTest HelloWorldTest.cpp)
target_link_libraries(HelloWorldTest Switch.TUnit.Main)
```

For more examples see [Examples](examples)

# Download and install Switch

Before running examples you must download and install Switch. To download and install it read [Downloads](https://gammasoft71.wixsite.com/switch/downloads) page or [Downloads.md](./docs/Downloads.md) file.