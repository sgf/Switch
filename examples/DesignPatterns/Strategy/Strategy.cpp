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
      explicit Context($<Strategy> strategy) : strategy(strategy) {}
      Context(const Context& context) : strategy(context.strategy) {}
      Context& operator=(const Context& context) {
        this->strategy = context.strategy;
        return *this;
      }

      void ContextInterface() {
        this->strategy->AlgorithmInterface();
      }

    private:
      $<Strategy> strategy;
    };

    // MainApp startup_ class for Behavioral
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

// This code produces the following output:
//
// Called ConcreteStrategyA.AlgorithmInterface()
// Called ConcreteStrategyB.AlgorithmInterface()
// Called ConcreteStrategyC.AlgorithmInterface()
