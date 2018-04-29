[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Decorator.png)

# Sample code

This structural code demonstrates the Decorator pattern which dynamically adds extra functionality to an existing object.

```c++
// Decorator pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Component' abstract class
    class Component abstract_ {
    public:
      virtual void Operation() const = 0;
    };
    
    // The 'ConcreteComponent' class
    class ConcreteComponent : public Component {
    public:
      void Operation() const override {Console::WriteLine("ConcreteComponent.Operation()");}
    };
    
    // The 'Decorator' abstract class
    class Decorator : public Component {
    public:
      void SetComponent($<Component> component) {this->component = component;}
      
      void Operation() const override {
        if (component != null) {
          component->Operation();
        }
      }
      
    protected:
      refptr<Component> component;
    };
    
    // The 'ConcreteDecoratorA' class
    class ConcreteDecoratorA : public Decorator {
    public:
      void Operation() const override {
        Decorator::Operation();
        Console::WriteLine("ConcreteDecoratorA.Operation()");
      }
    };
    
    // The 'ConcreteDecoratorB' class
    class ConcreteDecoratorB : public Decorator {
    public:
      void Operation() const override {
        Decorator::Operation();
        AddedBehavior();
        Console::WriteLine("ConcreteDecoratorB.Operation()");
      }
      
      void AddedBehavior() const {}
    };
    
    // MainApp startup class for Structural
    // Decorator Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create ConcreteComponent and two Decorators
        $<ConcreteComponent> c = new_<ConcreteComponent>();
        $<ConcreteDecoratorA> d1 = new_<ConcreteDecoratorA>();
        $<ConcreteDecoratorB> d2 = new_<ConcreteDecoratorB>();
        
        // Link decorators
        d1->SetComponent(as<Component>(c));
        d2->SetComponent(as<Component>(d1));
        
        d2->Operation();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);
```

# Output

```
ConcreteComponent.Operation()
ConcreteDecoratorA.Operation()
ConcreteDecoratorB.Operation()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
