#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Pet : public object {
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

      $<IEnumerable<Pet>> query = pets.OrderBy<int>(delegate_(const Pet & pet) {return  pet.Age();});

      for (Pet& pet : *query)
        Console::WriteLine("{0} - {1}", pet.Name, pet.Age);
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// Whiskers - 1
// Boots - 4
// Barley - 8
