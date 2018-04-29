[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

This tutorial shows how properties are an integral part of the Switch. It demonstrates how properties are declared and used.

# Tutorial

This tutorial includes two examples. The first example shows how to declare and use read/write properties. The second example demonstrates abstract properties and shows how to override these properties in subclasses.

## Example 1

This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.

```c++
//Person.cpp
 
#include <Switch/Switch>
 
using namespace System;
 
class Person : public object {
public:
  Person() {}
  Person(const Person& person) : name(person.name), age(person.age) {}
  
  // Declare a Name property of type string:
  property_<string> Name {
    get_ {return this->name;},
    set_ {this->name = value;}
  };
  
  // Declare an Age property of type int:
  property_<int> Age {
    get_ {return this->age;},
    set_ {this->age = value;}
  };
  
  string ToString() const override {
    return "Name = " + this->Name + ", this->Age = " + this->Age;
  }
  
  static void Main() {
    System::Console::WriteLine("Simple Properties");
    
    // Create a new Person object:
    Person person;
    
    // Print out the name and the age associated with the person:
    Console::WriteLine("Person details - {0}", person);
    
    // Set some values on the person object:
    person.Name = "Joe";
    person.Age = 99;
    Console::WriteLine("Person details - {0}", person);
    
    // Increment the Age property:
    person.Age += 1;
    Console::WriteLine("Person details - {0}", person);
  }
  
private:
  string name = "N/A";
  int age = 0;
};
 
startup_(Person);
```

**Output**

```
Simple Properties
Person details - Name = N/A, Age = 0
Person details - Name = Joe, Age = 99
Person details - Name = Joe, Age = 100
```

# Code Discussion

Notice the way that the properties are declared, for example, consider the Name property: 

```c++
property_<string> Name {
  get_ {return this->name;}
  set_ {this->name = value;}
}
```


# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
