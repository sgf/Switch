[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

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
