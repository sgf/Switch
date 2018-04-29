[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

Usage     ![Usage](Pictures/Usage4.png)     Medium high

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Composite.png)

# Sample code

This structural code demonstrates the Composite pattern which allows the creation of a tree structure in which individual nodes are accessed uniformly whether they are leaf nodes or branch (composite) nodes.

```c++
// Composite pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
using namespace System::Collections::Generic;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Component' abstract class
    class Component abstract_ {
    public:
      // Constructor
      Component(const string& name) : name(name) {}
      
      virtual void Add($<Component> c) = 0;
      virtual void Remove($<Component> c) = 0;
      virtual void Display(int depth) const = 0;
 
    protected:
      string name;
    };
    
    // The 'Composite' class
    class Composite : public Component {
    public:
      // Constructor
      Composite(string name) : Component(name) {}
      
      void Add($<Component> component) override {this->children.Add(component);}
      
      void Remove($<Component> component) override {this->children.Remove(component);}
      
      void Display(int depth) const override {
        Console::WriteLine(string('-', depth) + name);
        
        // Recursively display child nodes
        for ($<Component> component : this->children)
          component->Display(depth + 2);
      }
 
    private:
      List<$<Component>> children;
    };
    
    // The 'Leaf' class
    class Leaf : public Component {
    public:
      // Constructor
      Leaf(const string& name) : Component(name) {}
      
      void Display(int depth) const override {Console::WriteLine(string('-', depth) + name);}
      
    private:
      void Add(refptr<Component> c) override {throw InvalidOperationException("Cannot remove from a leaf");}
      void Remove(refptr<Component> c) override {throw InvalidOperationException("Cannot remove from a leaf");}
    };
    
    // MainApp startup class for Structural
    // Composite Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create a tree structure
        $<Composite> root = new_<Composite>("root");
        root->Add(ref_new<Leaf>("Leaf A"));
        root->Add(ref_new<Leaf>("Leaf B"));
        
        $<Composite> comp = new_<Composite>("Composite X");
        comp->Add(ref_new<Leaf>("Leaf XA"));
        comp->Add(ref_new<Leaf>("Leaf XB"));
        
        root->Add(as<Component>(comp));
        root->Add(ref_new<Leaf>("Leaf C"));
        
        // Add and remove a leaf
        $<Leaf> leaf = new_<Leaf>("Leaf D");
        root->Add(as<Component>(leaf));
        root->Remove(as<Component>(leaf));
        
        // Recursively display tree
        root->Display(1);
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);
```

# Output

```
-root
---Leaf A
---Leaf B
---Composite X
-----Leaf XA
-----Leaf XB
---Leaf C
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
