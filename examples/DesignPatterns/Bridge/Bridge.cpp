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
      property_<refptr<DesignPatterns::Structural::Implementor>, writeonly_> Implementor {
        set_ {this->implementor = value;}
      };

      virtual void Operation() const {
        this->implementor->Operation();
      }

    protected:
      refptr<DesignPatterns::Structural::Implementor> implementor;
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

    // MainApp startup_ class for Structural
    // Bridge Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        refptr<Abstraction> ab = new_<RefinedAbstraction>();

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

// This code produces the following output:
//
// ConcreteImplementorA Operation
// ConcreteImplementorB Operation
