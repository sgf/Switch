[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/state.gif)

# Sample code

This structural code demonstrates the State pattern which allows an object to behave differently depending on its internal state. The difference in behavior is delegated to objects that represent this state.

```c++
// State pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    class Context;
    // The 'State' abstract class
    class State abstract_ {
    public:
      virtual void Handle(Context& context) = 0;
    };
 
    // The 'Context' class
    class Context : public object {
    public:
      // Constructor
      Context($<DesignPatterns::Behavioral::State> state) {
        this->State = state;
      }
      
      // Gets or sets the state
      property_<$<DesignPatterns::Behavioral::State>> State {
        get_ { return this->state; },
        set_ {
          this->state = value;
          Console::WriteLine("State: " + this->state->GetType().Name);
        }
      };
      
      void Request() {
        this->state->Handle(*this);
      }
 
    private:
      $<DesignPatterns::Behavioral::State> state;
    };
    
    // A 'ConcreteState' class
    class ConcreteStateA : public State {
    public:
      void Handle(Context& context) override;
    };
    
    // A 'ConcreteState' class
    class ConcreteStateB : public State {
    public:
      void Handle(Context& context) override;
    };
 
    inline void ConcreteStateA::Handle(Context& context) {
      context.State = new_<ConcreteStateB>();
    }
 
    inline void ConcreteStateB::Handle(Context& context) {
      context.State = new_<ConcreteStateA>();
    }
 
    // MainApp startup class for Behavioral
    // State Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Setup context in a state
        Context c(new_<ConcreteStateA>());
        
        // Issue requests, which toggles state
        c.Request();
        c.Request();
        c.Request();
        c.Request();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
State: ConcreteStateA
State: ConcreteStateB
State: ConcreteStateA
State: ConcreteStateB
State: ConcreteStateA
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
