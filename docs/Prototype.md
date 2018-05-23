[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Specify the kind of objects to create using a prototypical instance, and create new objects by copying this prototype.

Usage     ![Usage](Pictures/Usage3.png)     Medium

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Prototype.png)

# Sample code

This structural code demonstrates the Factory method offering great flexibility in creating different objects. The Abstract class may provide a default object, but each subclass can instantiate an extended version of the object.

```c++
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
      
      virtual refptr<Prototype> Clone() const = 0;
 
    private:
      string id;
    };
    
    // A 'ConcretePrototype' class
    class ConcretePrototype1 : public Prototype {
    public:
      // Constructor
      ConcretePrototype1(const string& id) : Prototype(id) {}
      
      // Returns a shallow copy
      $<Prototype> Clone() const override {return as<Prototype>(this->MemberwiseClone<ConcretePrototype1>());}
    };
    
    // A 'ConcretePrototype' class
    class ConcretePrototype2 : public Prototype {
    public:
      // Constructor
      ConcretePrototype2(const string& id) : Prototype(id) {}
      
      // Returns a shallow copy
      $<Prototype> Clone() const override {return as<Prototype>(this->MemberwiseClone<ConcretePrototype2>());}
    };
    
    // MainApp startup class for Creational
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
```

# Output

```
Cloned: I
Cloned: II
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2018 Gammasoft.
