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

      virtual void Execute() const = 0;

    protected:
      $<Receiver> receiver;
    };

    // The 'ConcreteCommand' class
    class ConcreteCommand : public Command {
    public:
      // Constructor
      explicit ConcreteCommand($<Receiver> receiver) : Command(receiver) {}

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

    // MainApp startup_ class for Behavioral
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

// This code produces the following output:
//
// Called Receiver.Action()
