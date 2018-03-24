// Observer pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Observer' abstract class
    class Observer abstract_ {
    public:
      virtual void Update() = 0;
    };

    // The 'Subject' abstract class
    class Subject abstract_ {
    public:
      void Attach($<Observer> observer) {this->observers.Add(observer);}

      void Detach($<Observer> observer) {this->observers.Remove(observer);}

      void Notify() {
        for ($<Observer> o : this->observers)
          o->Update();
      }

    private:
      List < $<Observer >> observers;
    };

    // The 'ConcreteSubject' class
    class ConcreteSubject : public Subject {
    public:
      // Gets or sets subject state
      property_<string> SubjectState {
        get_ { return this->subjectState; },
        set_ { this->subjectState = value; }
      };

    private:
      string subjectState;
    };

    // The 'ConcreteObserver' class
    class ConcreteObserver : public Observer {
    public:
      // Constructor
      ConcreteObserver($<ConcreteSubject> subject, const string& name) : subject(subject), name(name) {}

      void Update() override {
        this->observerState = this->subject->SubjectState;
        Console::WriteLine("Observer {0}'s new state is {1}", this->name, this->observerState);
      }

      // Gets or sets subject
      property_ < $<ConcreteSubject >> Subject {
        get_ { return this->subject; },
        set_ { this->subject = value; }
      };

    private:
      string observerState;
      $<ConcreteSubject> subject;
      string name;
    };

    // MainApp startup_ class for Behavioral
    // Observer Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Configure Observer pattern
        $<ConcreteSubject> s = new_<ConcreteSubject>();

        s->Attach(new_<ConcreteObserver>(s, "X"));
        s->Attach(new_<ConcreteObserver>(s, "Y"));
        s->Attach(new_<ConcreteObserver>(s, "Z"));

        // Change subject and notify observers
        s->SubjectState = "ABC";
        s->Notify();
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
// Observer X's new state is ABC
// Observer Y's new state is ABC
// Observer Z's new state is ABC
