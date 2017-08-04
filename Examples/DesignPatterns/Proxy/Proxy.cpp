// Proxy pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Structural {
    // The 'Subject' abstract class
    class Subject pcf_abstract {
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
pcf_startup (DesignPatterns::Structural::MainApp)

// This code produces the following output:
//
// Called RealSubject.Request()