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
      explicit Context($<DesignPatterns::Behavioral::State> state) {
        this->State = state;
      }

      // Gets or sets the state
      property_ < $<DesignPatterns::Behavioral::State >> State {
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

    // MainApp startup_ class for Behavioral
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

// This code produces the following output:
//
// State: ConcreteStateA
// State: ConcreteStateB
// State: ConcreteStateA
// State: ConcreteStateB
// State: ConcreteStateA
