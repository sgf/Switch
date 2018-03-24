// Prototype pattern -- Creational example

#include <Switch/Switch>

using namespace System;

namespace DesignPatterns {
  namespace Creational {
    // The 'Prototype' abstract class
    class Prototype abstract_ {
    public:
      // Constructor
      Prototype(const string& id) : id(id) {}
      Prototype(const Prototype& prototype) : id(prototype.id) {}

      // Gets id
      property_<string, readonly_> Id {
        get_ {return this->id;}
      };

      virtual $<Prototype> Clone() const = 0;

    private:
      string id;
    };

    // A 'ConcretePrototype' class
    class ConcretePrototype1 : public Prototype {
    public:
      // Constructor
      explicit ConcretePrototype1(const string& id) : Prototype(id) {}

      // Returns a shallow copy
      $<Prototype> Clone() const override {return as<Prototype>(this->MemberwiseClone<ConcretePrototype1>());}
    };

    // A 'ConcretePrototype' class
    class ConcretePrototype2 : public Prototype {
    public:
      // Constructor
      explicit ConcretePrototype2(const string& id) : Prototype(id) {}

      // Returns a shallow copy
      $<Prototype> Clone() const override {return as<Prototype>(this->MemberwiseClone<ConcretePrototype2>());}
    };

    // MainApp startup_ class for Creational
    // Prototype Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create two instances and clone each

        $<ConcretePrototype1> p1 = new_<ConcretePrototype1>("I");
        $<ConcretePrototype1> c1 = as<ConcretePrototype1>(p1->Clone());
        Console::WriteLine("Cloned: {0}", c1->Id);

        $<ConcretePrototype2> p2 = new_<ConcretePrototype2>("II");
        $<ConcretePrototype2> c2 = as<ConcretePrototype2>(p2->Clone());
        Console::WriteLine("Cloned: {0}", c2->Id);
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Creational::MainApp);

// This code produces the following output:
//
// Cloned: I
// Cloned: II
