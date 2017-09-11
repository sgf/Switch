#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    class Data {
    public:
      Data() = default;
      Data(const Data& data) : items(data.items) {};
      
      _property<Array<int>> Items {
        _get {return this->items;},
        _set {this->items = value;}
      };
      
    private:
      Array<int> items = Array<>::CreateInstance<int>(8);
    };
    
    static void TraceMessage(string message, const CurrentInformation& currentInformation) {
      Console::WriteLine("message: "_s + message);
      Console::WriteLine("member name: "_s + currentInformation.MemberNamne);
      Console::WriteLine("source file path: "_s + currentInformation.FilePath);
      Console::WriteLine("source line number: "_s + currentInformation.LineNumber);
    }

    // The main entry point for the application.
    static void Main() {
      Data data;
      data.Items = {12, 24, 48};
      Console::WriteLine("{0} = {{{1}}}", _nameof(data.Items), _typeof(data.Items()));
      Console::WriteLine("{0} = {{{1}}}", _nameof(data.Items), string::Join(", ", data.Items()));
      TraceMessage("Hello, Me!", _current_information);
    }
  };
}

_startup (Examples::Program)

