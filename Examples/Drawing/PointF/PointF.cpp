#include <Pcf/Pcf>

using namespace System;
using namespace System::Drawing;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      PointF location = {10.5, 235.8};
      Console::WriteLine("location = {0}", location);
      
      location.X += 20.2;
      location.Y -= 15.1;
      Console::WriteLine("location = {0}", location);
      
      location = PointF(10, 10) + PointF(20.5, 50.5);
      Console::WriteLine("location = {0}", location);
      
      location.Offset({69.5, 139.5});
      Console::WriteLine("location = {0}", location);
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// location = {X=10.5,Y=235.8}
// location = {X=30.7,Y=220.7}
// location = {X=30.5,Y=60.5}
// location = {X=100,Y=200}
