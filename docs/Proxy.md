[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Provide a surrogate or placeholder for another object to control access to it.

Usage     ![Usage](Pictures/Usage4.png)     Medium high

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/proxy.gif)

# Sample code

This structural code demonstrates the Proxy pattern which provides a representative object (proxy) that controls access to another similar object.

```c++
// Proxy pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Subject' abstract class
    class Subject abstract_ {
    public:
      virtual void Request() const = 0;
    };
    
    // The 'RealSubject' class
    class RealSubject : public Subject {
    public:
      void Request() const override {Console::WriteLine("Called RealSubject.Request()");}
    };
    
    // The 'Proxy' class
    class Proxy : public Subject {
    public:
      void Request() const override  {
        this->realSubject.Request();
      }
 
    private:
      RealSubject realSubject;
    };
    
    // MainApp startup class for Structural
    // Proxy Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create proxy and request a service
        Proxy proxy;
        proxy.Request();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Structural::MainApp);
```

# Output

```
Called RealSubject.Request()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
