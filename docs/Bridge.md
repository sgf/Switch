[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

# Definition

Decouple an abstraction from its implementation so that the two can vary independently.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Bridge.png)

# Sample code

This structural code demonstrates the Builder pattern in which complex objects are created in a step-by-step fashion. The construction process can create different object representations and provides a high level of control over the assembly of the objects.

```c++
// Bridge pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Implementor' abstract class
    class Implementor abstract_ {
    public:
      virtual void Operation() const = 0;
    };
    
    // The 'Abstraction' class
    class Abstraction : public object {
    public:
      // Property
      property_<$<DesignPatterns::Structural::Implementor>, writeonly_> Implementor {
        set_ {this->implementor = value;}
      };
      
      virtual void Operation() const {
        this->implementor->Operation();
      }
 
    protected:
      $<DesignPatterns::Structural::Implementor> implementor;
    };
    
    // The 'RefinedAbstraction' class
    class RefinedAbstraction : public Abstraction {
    public:
      void Operation() const override {
        this->implementor->Operation();
      }
    };
    
    // The 'ConcreteImplementorA' class
    class ConcreteImplementorA : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorA Operation");
      }
    };
    
    // The 'ConcreteImplementorB' class
    class ConcreteImplementorB : public Implementor {
    public:
      void Operation() const override {
        Console::WriteLine("ConcreteImplementorB Operation");
      }
    };
    
    // MainApp startup class for Structural
    // Bridge Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        $<Abstraction> ab = ne<Rew_finedAbstraction>();
        
        // Set implementation and call
        ab->Implementor = new_<ConcreteImplementorA>();
        ab->Operation();
        
        // Change implemention and call
        ab->Implementor = new_<ConcreteImplementorB>();
        ab->Operation();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);
```

# Output

```
ConcreteImplementorA Operation
ConcreteImplementorB Operation
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
