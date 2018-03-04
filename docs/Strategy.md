[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

# Definition

Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

Usage     ![Usage](Pictures/Usage4.png)     Medium high

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/strategy.gif)

# Sample code

This structural code demonstrates the Strategy pattern which encapsulates functionality in the form of an object. This allows clients to dynamically change algorithmic strategies.

```c++
// Strategy pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'Strategy' abstract class
    class Strategy abstract_ {
    public:
      virtual void AlgorithmInterface() = 0;
    };
    
    // A 'ConcreteStrategy' class
    class ConcreteStrategyA : public Strategy {
    public:
      void AlgorithmInterface() override {
        Console::WriteLine("Called ConcreteStrategyA.AlgorithmInterface()");
      }
    };
    
    // A 'ConcreteStrategy' class
    class ConcreteStrategyB : public Strategy {
    public:
      void AlgorithmInterface() override {
        Console::WriteLine("Called ConcreteStrategyB.AlgorithmInterface()");
      }
    };
    
    // A 'ConcreteStrategy' class
    class ConcreteStrategyC : public Strategy {
    public:
      void AlgorithmInterface() override {
        Console::WriteLine("Called ConcreteStrategyC.AlgorithmInterface()");
      }
    };
    
    // The 'Context' class
    class Context : public object {
    public:
      // Constructors
      Context() {}
      Context($<Strategy> strategy) : strategy(strategy) {}
      Context(const Context& context) : strategy(context.strategy) {}
      
      void ContextInterface() {
        this->strategy->AlgorithmInterface();
      }
 
    private:
      $<Strategy> strategy;
    };
    
    // MainApp startup class for Behavioral
    // Strategy Design Pattern.
    class MainApp {
    public:
      /// Entry point into console application.
      static void Main() {
        Context context;
        
        // Three contexts following different strategies
        context = Context(new_<ConcreteStrategyA>());
        context.ContextInterface();
        
        context = Context(new_<ConcreteStrategyB>());
        context.ContextInterface();
        
        context = Context(new_<ConcreteStrategyC>());
        context.ContextInterface();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
Called ConcreteStrategyA.AlgorithmInterface()
Called ConcreteStrategyB.AlgorithmInterface()
Called ConcreteStrategyC.AlgorithmInterface()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
