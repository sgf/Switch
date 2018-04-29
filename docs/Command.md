[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

# Definition

Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

Usage     ![Usage](Pictures/Usage4.png)     Medium high

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/command.gif)

# Sample code

This structural code demonstrates the Command pattern which stores requests as objects allowing clients to execute or playback the requests.

```c++
// Command pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'Receiver' class
    class Receiver : public object {
    public:
      void Action() const {Console::WriteLine("Called Receiver.Action()");}
    };
    
    // The 'Command' abstract class
    class Command abstract_ {
    public:
      // Constructor
      Command($<Receiver> receiver) : receiver(receiver) {}
      
      virtual void Execute() const =0;
 
    protected:
      $<Receiver> receiver;
    };
    
    // The 'ConcreteCommand' class
    class ConcreteCommand : public Command {
    public:
      // Constructor
      ConcreteCommand($<Receiver> receiver) : Command(receiver) {}
      
      void Execute() const override {
        receiver->Action();
      }
    };
    
    // The 'Invoker' class
    class Invoker : public object {
    public:
      void SetCommand($<Command> command) {this->command = command;}
      
      void ExecuteCommand() const {this->command->Execute();}
      
    private:
      $<Command> command;
    };
    
    // MainApp startup class for Behavioral
    // Command Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create receiver, command, and invoker
        $<Receiver> receiver = new_<Receiver>();
        $<Command> command = new_<ConcreteCommand>(receiver);
        $<Invoker> invoker = new_<Invoker>();
        
        // Set and execute command
        invoker->SetCommand(command);
        invoker->ExecuteCommand();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
Called Receiver.Action()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
