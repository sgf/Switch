[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/template.gif)

# Sample code

This structural code demonstrates the Template method which provides a skeleton calling sequence of methods. One or more steps can be deferred to subclasses which implement these steps without changing the overall calling sequence.

```c++
// Template Method pattern -- Bahavorial example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'AbstractClass' abstract class
    class AbstractClass abstract_ {
    public:
      virtual void PrimitiveOperation1() = 0;
      virtual void PrimitiveOperation2() = 0;
      
      // The "Template method"
      void TemplateMethod() {
        PrimitiveOperation1();
        PrimitiveOperation2();
        Console::WriteLine("");
      }
    };
    
    // A 'ConcreteClass' class
    class ConcreteClassA : public AbstractClass {
    public:
      void PrimitiveOperation1() override {
        Console::WriteLine("ConcreteClassA.PrimitiveOperation1()");
      }
      
      void PrimitiveOperation2() override {
        Console::WriteLine("ConcreteClassA.PrimitiveOperation2()");
      }
    };
    
    // A 'ConcreteClass' class
    class ConcreteClassB : public AbstractClass {
    public:
      void PrimitiveOperation1() override {
        Console::WriteLine("ConcreteClassB.PrimitiveOperation1()");
      }
      
      void PrimitiveOperation2() override {
        Console::WriteLine("ConcreteClassB.PrimitiveOperation2()");
      }
    };
    
    // MainApp startup class for Behavioral
    // Template Method Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        $<AbstractClass> aA = new_<ConcreteClassA>();
        aA->TemplateMethod();
        
        $<AbstractClass> aB = new_<ConcreteClassB>();
        aB->TemplateMethod();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
ConcreteClassA.PrimitiveOperation1()
ConcreteClassA.PrimitiveOperation2()
​
ConcreteClassB.PrimitiveOperation1()
ConcreteClassB.PrimitiveOperation2()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
