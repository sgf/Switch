#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

class Examples {
public:
  static void Main() {

    // Create a DataFormats.Format for the Unicode data format.
    DataFormats::Format myFormat = DataFormats::GetFormat(4356);

    // Display the contents of myFormat.
    Console::WriteLine("The Format Name corresponding to the ID "_s + myFormat.Id + " is :"_s);
    Console::WriteLine(myFormat.Name);
  }
};

startup_(Examples);
