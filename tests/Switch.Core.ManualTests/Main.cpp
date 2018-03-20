#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/IO/SeekOrigin.hpp>
#include <Switch/System/Environment.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    /// TEST(AccessibleEventsTest, SystemSound) {
    ///   ASSERT_EQ(1, (int32)AccessibleEvents::SystemSound);
    ///  ASSERT_EQ("SystemSound", Enum<AccessibleEvents>(AccessibleEvents::SystemSound).ToString());
    /// }
    template<typename T>
    static string CreateEnumClassTest() {
      string result;
      for (auto value : Enum<>::GetValues<T>()) {
        result += string::Format("TEST({0}Test, {1}) {{\n"
            "  ASSERT_EQ({2}, (int32){3}::{1});\n"
            "  ASSERT_EQ(\"{1}\", Enum<{3}>({3}::{1}).ToString());\n"
            "}}\n\n", typeof_(value).Name, Enum<>::GetName(value), int32(value), typeof_(value).FullName().Replace("Switch::", ""));
      }

      return result;
    }
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine(CreateEnumClassTest<System::IO::SeekOrigin>());
    }
  };
}

startup_(Examples::Program);
