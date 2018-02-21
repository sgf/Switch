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
      void SetComponent(refptr<Component> component) {this->component = component;}

      void Operation() const override {
        if (component != null)
          component->Operation();
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

    // MainApp startup_ class for Structural
    // Decorator Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create ConcreteComponent and two Decorators
        refptr<ConcreteComponent> c = new_<ConcreteComponent>();
        refptr<ConcreteDecoratorA> d1 = new_<ConcreteDecoratorA>();
        refptr<ConcreteDecoratorB> d2 = new_<ConcreteDecoratorB>();

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

// This code produces the following output:
//
// ConcreteComponent.Operation()
// ConcreteDecoratorA.Operation()
// ConcreteDecoratorB.Operation()
