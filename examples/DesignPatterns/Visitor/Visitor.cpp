// Visitor pattern -- Behavorail example

#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Behavioral {
    class Visitor;

    // The 'Element' abstract class
    class Element abstract_ {
    public:
      virtual void Accept($<Visitor> visitor) = 0;
    };

    // A 'ConcreteElement' class
    class ConcreteElementA : public Element {
    public:
      void Accept($<Visitor> visitor) override;

      void OperationA() {
      }
    };

    // A 'ConcreteElement' class
    class ConcreteElementB : public Element {
    public:
      void Accept($<Visitor> visitor) override;

      void OperationB() {
      }
    };

    // The 'Visitor' abstract class
    class Visitor abstract_ {
    public:
      virtual void VisitConcreteElementA(const ConcreteElementA& concreteElementA) = 0;
      virtual void VisitConcreteElementB(const ConcreteElementB& concreteElementB) = 0;
    };

    inline void ConcreteElementA::Accept($<Visitor> visitor) {
      visitor->VisitConcreteElementA(*this);
    }

    inline void ConcreteElementB::Accept($<Visitor> visitor) {
      visitor->VisitConcreteElementB(*this);
    }

    // A 'ConcreteVisitor' class
    class ConcreteVisitor1 : public Visitor {
    public:
      void VisitConcreteElementA(const ConcreteElementA& concreteElementA) override {
        Console::WriteLine("{0} visited by {1}", concreteElementA.GetType().Name, this->GetType().Name);
      }

      void VisitConcreteElementB(const ConcreteElementB& concreteElementB) override {
        Console::WriteLine("{0} visited by {1}", concreteElementB.GetType().Name, this->GetType().Name);
      }
    };

    // A 'ConcreteVisitor' class
    class ConcreteVisitor2 : public Visitor {
    public:
      void VisitConcreteElementA(const ConcreteElementA& concreteElementA) override {
        Console::WriteLine("{0} visited by {1}", concreteElementA.GetType().Name, this->GetType().Name);
      }

      void VisitConcreteElementB(const ConcreteElementB& concreteElementB) override {
        Console::WriteLine("{0} visited by {1}", concreteElementB.GetType().Name, this->GetType().Name);
      }
    };

    // The 'ObjectStructure' class
    class ObjectStructure : public object {
    public:
      void Attach($<Element> element) {
        this->elements.Add(element);
      }

      void Detach($<Element> element) {
        this->elements.Remove(element);
      }

      void Accept($<Visitor> visitor) {
        for ($<Element> element : this->elements)
          element->Accept(visitor);
      }
    private:
      List < $<Element >> elements;
    };

    // MainApp startup_ class for Behavioral
    // Visitor Design Pattern.
    class MainApp {
    public:
      static void Main() {
        // Setup structure
        ObjectStructure o;
        o.Attach(new_<ConcreteElementA>());
        o.Attach(new_<ConcreteElementB>());

        // Create visitor objects
        $<ConcreteVisitor1> v1 = new_<ConcreteVisitor1>();
        $<ConcreteVisitor2> v2 = new_<ConcreteVisitor2>();

        // Structure accepting visitors
        o.Accept(v1);
        o.Accept(v2);
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
// ConcreteElementA visited by ConcreteVisitor1
// ConcreteElementB visited by ConcreteVisitor1
// ConcreteElementA visited by ConcreteVisitor2
// ConcreteElementB visited by ConcreteVisitor2
