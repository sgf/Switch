#include <Switch/Switch.System.hpp>

using namespace System;

namespace std {
  template<> struct hash<any> {
    Switch::size operator()(any value) const {return value.GetHashCode();}
  };
}

void ToString(const string& str) {
  Console::WriteLine("\"{0}\"", str);
}

void ToString(const Tuple<string, int>& tuple) {
  Console::WriteLine("-{0}-", tuple);
}

void ToString(const System::Collections::ArrayList& array) {
  Console::WriteLine("[{0}]", string::Join(", ", array));
}

void ToString(const System::Collections::BitArray& bitArray) {
  Console::WriteLine("+{0}+", string::Join(", ", bitArray));
}

void ToString(const System::Collections::DictionaryEntry& de) {
  Console::WriteLine(":{0}:", de);
}

void ToString(const System::Collections::Hashtable& hashTable) {
  Console::WriteLine("${0}$", string::Join(", ", hashTable));
}

void ToString(System::Collections::Enumerator enumerator) {
  bool first = true;
  Console::Write("%");
  while (enumerator.MoveNext()) {
    if (!first) Console::Write(", ");
    Console::Write("{0}", enumerator.Current);
    first = false;
  }
  Console::WriteLine("%");
}

void Run(const Delegate<string>& del) {
  Console::WriteLine("{{{0}}}", del());
}

int main() {
  Environment::SetCommandLineArgs();

  std::string s = "Hello, World!";
  ToString(s);

  std::tuple<string, int> t("Hello, World!", 42);
  ToString(t);

  std::vector<any> v = {"Hello", "World!"};
  ToString(v);

  std::bitset<8> b(42);
  ToString(b);

  std::pair<any, any> p("Hello, World!"_s, 42);
  ToString(p);

  std::unordered_map<any, any> um = {{"Hello", 42}, {"World!", 24}};
  ToString(um);

  std::function<string()> f = []() {return "Hello, World!";};
  Run(f);
}
