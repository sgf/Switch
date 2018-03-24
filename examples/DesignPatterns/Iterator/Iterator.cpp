// Iterator pattern -- Behavioral example

#include <Switch/Switch>

using namespace System;
using namespace System::Collections;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Iterator' abstract class
    class Iterator abstract_ {
    public:
      virtual any First() const = 0;
      virtual any Next() const = 0;
      virtual bool IsDone() const = 0;
      virtual any CurrentItem() const = 0;
    };

    // The 'Aggregate' abstract class
    class Aggregate abstract_ {
    public:
      virtual $<Iterator> CreateIterator() = 0;
    };

    class ConcreteAggregate;

    /// The 'ConcreteIterator' class
    class ConcreteIterator : public Iterator {
    public:
      // Constructor
      explicit ConcreteIterator(const ConcreteAggregate& aggregate) : aggregate(aggregate) {}

      // Gets first iteration item
      any First() const override;

      // Gets next iteration item
      any Next() const override;

      // Gets current iteration item
      any CurrentItem() const override;

      // Gets whether iterations are complete
      bool IsDone() const override;

    private:
      const ConcreteAggregate& aggregate;
      mutable int current = 0;
    };

    // The 'ConcreteAggregate' class
    class ConcreteAggregate : public Aggregate {
    public:
      $<Iterator> CreateIterator() override {
        return new_<ConcreteIterator>(*this);
      }

      // Gets item count
      property_<int, readonly_> Count {
        get_ { return this->items.Count(); }
      };

      void Insert(int index, any item) {
        this->items.Insert(index, item);
      }

      // Indexer
      any operator [](int index) {
        return this->items[index];
      }

      // Indexer
      any operator [](int index) const {
        return this->items[index];
      }

    private:
      ArrayList items;
    };

    // Gets first iteration item
    inline any ConcreteIterator::First() const {
      return this->aggregate[0];
    }

    // Gets next iteration item
    any ConcreteIterator::Next() const {
      if (this->current < this->aggregate.Count - 1)
        return this->aggregate[++this->current];

      return null;
    }

    // Gets current iteration item
    any ConcreteIterator::CurrentItem() const {
      return this->aggregate[this->current];
    }

    // Gets whether iterations are complete
    bool ConcreteIterator::IsDone() const {
      return this->current >= this->aggregate.Count;
    }

    // MainApp startup_ class for Behavioral
    // Iterator Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        ConcreteAggregate a;
        a.Insert(0, "Item A");
        a.Insert(1, "Item B");
        a.Insert(2, "Item C");
        a.Insert(3, "Item D");

        // Create Iterator and provide aggregate
        $<Iterator> i = new_<ConcreteIterator>(a);

        Console::WriteLine("Iterating over collection:");

        any item = i->First();
        while (item != null) {
          Console::WriteLine(item);
          item = i->Next();
        }
      }
    };
  }
}

// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);

// This code produces the following output:
//
// Iterating over collection:
// Item A
// Item B
// Item C
// Item D
