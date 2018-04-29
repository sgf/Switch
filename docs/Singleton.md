[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Ensure a class has only one instance and provide a global point of access to it.

Usage     ![Usage](Pictures/Usage4.png)     Medium high

# UML class diagram

![AbstractFactory](Diagrams/UML/DesignPatterns/Singleton.png)

# Sample code

This structural code demonstrates the Singleton pattern which assures only a single instance (the singleton) of the class can be created.

```c++
// Singleton pattern -- Creational example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Creational {
    // The 'Singleton' class
    class Singleton : public object {
    public:
      static Singleton& Instance() {return instance;}
 
    protected:
      // Constructor is 'protected'
      Singleton() {}
      Singleton(const Singleton&) = delete;
      Singleton& operator =(const Singleton&) = delete;
      
    private:
      static Singleton instance;
    };
 
    Singleton Singleton::instance;
    
    // MainApp startup class for Creational
    // Singleton Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Constructor is protected -- cannot use constructor
        ref<Singleton> singleton1 = Singleton::Instance();
        ref<Singleton> singleton2 = Singleton::Instance();
 
        // Test for same instance
        if (&singleton1 == &singleton2)
          Console::WriteLine("Objects are the same instance");
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Creational::MainApp);
```

# Output

```
Objects are the same instance
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
