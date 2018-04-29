[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

This tutorial shows how the command line can be accessed and two ways of accessing the array of command line parameters.

# Tutorial

The following examples show two different approaches to using the command line arguments passed to an application.

# Example 1

This example demonstrates how to print out the command line arguments.

```c++
// cmdline1.cpp
// arguments: A B C
#include <Switch/Switch>
 
using namespace System;
 
class CommandLine {
public:
  static void Main(const Array<string>& args) {
    // The Length property is used to obtain the length of the array.
    // Notice that Length is a read-only property:
    Console::WriteLine("Number of command line parameters = {0}", args.Length);
    for(int i = 0; i < args.Length; i++) {
      Console::WriteLine("Arg[{0}] = [{1}]", i, args[i]);
    }
  }
};
 
startup_(CommandLine);
```

**Output** Run the program using some arguments like this: cmdline1 A B C.

```
Number of command line parameters = 3
Arg[0] = [A]
Arg[1] = [B]
Arg[2] = [C]
```

# Example 2

Another approach to iterating over the array is to use the foreach statement as shown in this example. The foreach statement can be used to iterate over an array or over a Switch Framework collection class. It provides a simple way to iterate over collections.

```c++
// cmdline2.cpp
// arguments: John Paul Mary
#include <Switch/Switch>
 
using namespace System;
 
class CommandLine2 {
public:
  static void Main(const System::Array<string>& args) {
    // The Length property is used to obtain the length of the array.
    // Notice that Length is a read-only property:
    Console::WriteLine("Number of command line parameters = {0}", args.Length);
      for (string s : args) {
        Console::WriteLine(s);
      }
   }
};
​
startup_(CommandLine2);
```

**Output** Run the program using some arguments like this: cmdline2 John Paul Mary.
The output will be:

```
Number of command line parameters = 3
John
Paul
Mary
```

# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
