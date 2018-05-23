[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Use sharing to support large numbers of fine-grained objects efficiently.

Usage     ![Usage](Pictures/Usage1.png)     Low

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/flyweight.gif)

# Sample code

This structural code demonstrates the Flyweight pattern in which a relatively small number of objects is shared many times by different clients.

```c++
// Flyweight pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
using namespace System::Collections::Generic;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Flyweight' abstract class
    class Flyweight abstract_ {
    public:
      virtual void Operation(int extrinsicstate) const = 0;
    };
    
    // The 'ConcreteFlyweight' class
    class ConcreteFlyweight : public Flyweight {
    public:
      void Operation(int extrinsicstate) const override {
        Console::WriteLine("ConcreteFlyweight: {0}", extrinsicstate);
      }
    };
    
    // The 'FlyweightFactory' class
    class FlyweightFactory : public object {
    public:
      // Constructor
      FlyweightFactory() {
        flyweights.Add("X", new_<ConcreteFlyweight>());
        flyweights.Add("Y", new_<ConcreteFlyweight>());
        flyweights.Add("Z", new_<ConcreteFlyweight>());
      }
      
      $<Flyweight> GetFlyweight(const string& key) const {return flyweights[key];}
 
    private:
      Dictionary<string, $<Flyweight>> flyweights;
    };
    
    /// @brief The 'UnsharedConcreteFlyweight' class
    class UnsharedConcreteFlyweight : public Flyweight {
    public:
      void Operation(int extrinsicstate) const override  {Console::WriteLine("UnsharedConcreteFlyweight: {0}", extrinsicstate);}
    };
    
    // MainApp startup class for Structural
    // Flyweight Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Arbitrary extrinsic state
        int extrinsicstate = 22;
        
        FlyweightFactory factory;
        
        // Work with different flyweight instances
        $<Flyweight> fx = factory.GetFlyweight("X");
        fx->Operation(--extrinsicstate);
        
        $<Flyweight> fy = factory.GetFlyweight("Y");
        fy->Operation(--extrinsicstate);
        
        $<Flyweight> fz = factory.GetFlyweight("Z");
        fz->Operation(--extrinsicstate);
        
        refptr<UnsharedConcreteFlyweight> fu = ref_new<UnsharedConcreteFlyweight>();
        fu->Operation(--extrinsicstate);
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);
```

# Output

```
ConcreteFlyweight: 21
ConcreteFlyweight: 20
ConcreteFlyweight: 19
UnsharedConcreteFlyweight: 18
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2018 Gammasoft.
