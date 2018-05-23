[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Provide a unified interface to a set of interfaces in a subsystem. Façade defines a higher-level interface that makes the subsystem easier to use.

Usage     ![Usage](Pictures/Usage5.png)     High

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Facade.png)

# Sample code

This structural code demonstrates the Facade pattern which provides a simplified and uniform interface to a large subsystem of classes.

```c++
// Facade pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Subsystem ClassA' class
    class SubSystemOne : public object {
    public:
      void MethodOne() const {Console::WriteLine(" SubSystemOne Method");}
    };
    
    // The 'Subsystem ClassB' class
    class SubSystemTwo : public object {
    public:
      void MethodTwo() const {Console::WriteLine(" SubSystemTwo Method");}
    };
    
    // The 'Subsystem ClassC' class
    class SubSystemThree : public object {
    public:
      void MethodThree() const {Console::WriteLine(" SubSystemThree Method");}
    };
    
    // The 'Subsystem ClassD' class
    class SubSystemFour : public object {
    public:
      void MethodFour() const {Console::WriteLine(" SubSystemFour Method");}
    };
    
    // The 'Facade' class
    class Facade : public object {
    public:
      Facade() {}
      
      void MethodA() const {
        Console::WriteLine("\nMethodA() ---- ");
        this->one.MethodOne();
        this->two.MethodTwo();
        this->four.MethodFour();
      }
      
      void MethodB() const {
        Console::WriteLine("\nMethodB() ---- ");
        this->two.MethodTwo();
        this->three.MethodThree();
      }
 
    private:
      SubSystemOne one;
      SubSystemTwo two;
      SubSystemThree three;
      SubSystemFour four;
    };
    
    // MainApp startup class for Structural
    // Facade Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        Facade facade;
        
        facade.MethodA();
        facade.MethodB();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);
```

# Output

```
MethodA() ----
 SubSystemOne Method
 SubSystemTwo Method
 SubSystemFour Method
​
MethodB() ----
 SubSystemTwo Method
 SubSystemThree Method
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2018 Gammasoft.
