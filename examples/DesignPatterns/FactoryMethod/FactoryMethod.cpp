// Factory Method pattern -- Creational example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'Product' abstract class
    class Product abstract_ {
    public:
      ~Product() = 0;
    };

    inline Product::~Product() {}

    // A 'ConcreteProduct' class
    class ConcreteProductA : public Product {
    };

    // A 'ConcreteProduct' class
    class ConcreteProductB : public Product {
    };

    // The 'Creator' abstract class
    class Creator abstract_ {
    public:
      virtual $<Product> FactoryMethod() const = 0;
    };

    // A 'ConcreteCreator' class
    class ConcreteCreatorA : public Creator {
    public:
      $<Product> FactoryMethod() const override {return new_<ConcreteProductA>();}
    };

    // A 'ConcreteCreator' class
    class ConcreteCreatorB : public Creator {
    public:
      $<Product> FactoryMethod() const override {return new_<ConcreteProductB>();}
    };

    // MainApp startup_ class for Creational
    // Factory Method Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // An array of creators
        Array < $<Creator >> creators(2);

        creators[0] = new_<ConcreteCreatorA>();
        creators[1] = new_<ConcreteCreatorB>();

        // Iterate over creators and create products
        for ($<Creator> creator : creators) {
          $<Product> product = creator->FactoryMethod();
          Console::WriteLine("Created {0}", product->GetType().Name);
        }
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Creational::MainApp);

// This code produces the following output:
//
// Created ConcreteProductA
// Created ConcreteProductB
