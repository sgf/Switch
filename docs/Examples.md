[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

The Classic first ​application "Hello World".

# Console

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

Console output:

```
Hello, World!
```

# Forms

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
​
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

Running application on Windows:

![HelloWorldForms](Pictures/Examples/Forms/HelloWorldFormW.png)

Running application on macOS:

![HelloWorldForms](Pictures/Examples/Forms/HelloWorldFormM.png)

Running application on Ubuntu:

![HelloWorldForms](Pictures/Examples/Forms/HelloWorldFormU.png)

# TUnit

HelloWorldTest.cpp:

```c++
#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class TestFixture_(HelloWorldTest) {
  protected:
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

Console output:

```
Start 2 tests from 1 test case
  Start 2 tests from HelloWorldTest
    PASSED HelloWorldTest.CreateStringFromLiteral (0 ms)
    PASSED HelloWorldTest.CreateStringFromChar32Array (0 ms)
  End 2 tests from HelloWorldTest (3 ms total)
 
  Summary :
    PASSED 2 tests.
End 2 tests from 1 test case ran. (4 ms total)
```

[Click here to see more examples](https://github.com/gammasoft71/Switch/tree/master/examples)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
