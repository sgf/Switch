#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Pet : public object, public IComparable {
    public:
      Pet() : age(0) {}
      Pet(const string& name, int age) : name(name), age(age) {}
      Pet(const Pet& pet) : name(pet.name), age(pet.age) {}
      Pet& operator=(const Pet& pet) {
        this->name = pet.name;
        this->age = pet.age;
        return *this;
      }

      property_<int, readonly_> Age {
        get_ {return this->age;}
      };

      property_<string, readonly_> Name {
        get_ {return this->name;}
      };

      virtual int CompareTo(const IComparable& other) const { return Int32(this->age).CompareTo(as<Pet>(other).age); }

    private:
      string name;
      int age;
    };

  public:
    // The main entry point for the application.
    static void Main() {
      Array<Pet> pets = {
        {"Barley", 8},
        {"Boots", 4},
        {"Whiskers", 1}
      };

      Pet min = pets.Min();

      Console::WriteLine("The 'minimum' animal is {0}.", min.Name);
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// The 'minimum' animal is Whiskers.
