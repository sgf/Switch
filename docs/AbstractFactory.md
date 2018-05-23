[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Provide an interface for creating families of related or dependent objects without specifying their concrete classes.

Usage     ![Usage](Pictures/Usage5.png)     High

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/AbstractFactory.png)

# Sample code

This structural code demonstrates the Abstract Factory pattern creating parallel hierarchies of objects. Object creation has been abstracted and there is no need for hard-coded class names in the client code.

```c++
// Abstract Factory pattern -- Creational example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Creational {
    // The 'AbstractProductA' abstract class
    class AbstractProductA abstract_ {
    public:
      ~AbstractProductA() = 0;
    };
​
    inline AbstractProductA::~AbstractProductA() {}
​
    // The 'AbstractProductB' abstract class
    class AbstractProductB abstract_ {
    public:
      virtual void Interact(const AbstractProductA& a) const = 0;
    };
 
    // The 'AbstractFactory' abstract class
    class AbstractFactory abstract_ {
    public:
      virtual $<AbstractProductA> CreateProductA() const = 0;
      virtual $<AbstractProductB> CreateProductB() const = 0;
    };
 
    // The 'ProductA1' class
    class ProductA1 : public AbstractProductA {
    };
 
    // The 'ProductB1' class
    class ProductB1 : public AbstractProductB {
    public:
      void Interact(const AbstractProductA& a) const override {Console::WriteLine(string::Format("{0} interacts with {1}", this->GetType().Name, a.GetType().Name));}
    };
​
    // The 'ProductA2' class
    class ProductA2 : public AbstractProductA {
    };
 
    // The 'ProductB2' class
    class ProductB2 : public AbstractProductB {
    public:
      void Interact(const AbstractProductA& a) const override {Console::WriteLine(string::Format("{0} interacts with {1}", this->GetType().Name, a.GetType().Name));}
    };
 
    // The 'ConcreteFactory1' class
    class ConcreteFactory1 : public AbstractFactory {
    public:
      $<AbstractProductA> CreateProductA() const override {return new_<ProductA1>();}
      $<AbstractProductB> CreateProductB() const override {return new_<ProductB1>();}
    };
 
    // The 'ConcreteFactory2' class
    class ConcreteFactory2 : public AbstractFactory {
    public:
      $<AbstractProductA> CreateProductA() const override {return new_<ProductA2>();}
      $<AbstractProductB> CreateProductB() const override {return new_<ProductB2>();}
    };
 
    // The 'Client' class. Interaction environment for the products.
    class Client : public object {
    public:
      // Constructor
      Client(const AbstractFactory& factory) {
        this->abstractProductB = factory.CreateProductB();
        this->abstractProductA = factory.CreateProductA();
      }
 
      void Run() {this->abstractProductB->Interact(*this->abstractProductA);}
 
    private:
      $<AbstractProductA> abstractProductA;
      $<AbstractProductB> abstractProductB;
    };
 
    // MainApp startup class for Creational
    // Abstract Factory Design Pattern.
    class MainApp {
    public:
      // The main entry point for the application.
      static void Main() {
        // Abstract factory #1
        $<AbstractFactory> factory1 = new_<ConcreteFactory1>();
        Client client1(*factory1);
        client1.Run();
​
        // Abstract factory #2
        $<AbstractFactory> factory2 = new_<ConcreteFactory2>();
        Client client2(*factory2);
        client2.Run();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Creational::MainApp);
```

# Output

```
ProductB1 interacts with ProductA1
ProductB2 interacts with ProductA2​
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2018 Gammasoft.
