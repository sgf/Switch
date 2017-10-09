#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a new sorted dictionary of strings, with string keys.
      //
      SortedDictionary<string, string> openWith;
      
      // Add some elements to the dictionary. There are no
      // duplicate keys, but some of the values are duplicates.
      openWith.Add("txt", "notepad.exe");
      openWith.Add("bmp", "paint.exe");
      openWith.Add("dib", "paint.exe");
      openWith.Add("rtf", "wordpad.exe");
      
      // The Add method throws an exception if the new key is
      // already in the dictionary.
      try {
        openWith.Add("txt", "winword.exe");
      } catch (const ArgumentException&) {
        Console::WriteLine("An element with Key = \"txt\" already exists.");
      }
      
      // The Item property is another name for the indexer, so you
      // can omit its name when accessing elements.
      Console::WriteLine("For key = \"rtf\", value = {0}.", openWith["rtf"]);
      
      // The indexer can be used to change the value associated
      // with a key.
      openWith["rtf"] = "winword.exe";
      Console::WriteLine("For key = \"rtf\", value = {0}.", openWith["rtf"]);
      
      // If a key does not exist, setting the indexer for that key
      // adds a new key/value pair.
      openWith["doc"] = "winword.exe";
      
      // When a program often has to try keys that turn out not to
      // be in the dictionary, TryGetValue can be a more efficient
      // way to retrieve values.
      string value = string::Empty;
      if (openWith.TryGetValue("tif", value))
        Console::WriteLine("For key = \"tif\", value = {0}.", value);
      else
        Console::WriteLine("Key = \"tif\" is not found.");
      
      // ContainsKey can be used to test keys before inserting
      // them.
      if (!openWith.ContainsKey("ht")) {
        openWith.Add("ht", "hypertrm.exe");
        Console::WriteLine("Value added for key = \"ht\": {0}.", openWith["ht"]);
      }
      
      // When you use foreach to enumerate dictionary elements,
      // the elements are retrieved as KeyValuePair objects.
      Console::WriteLine();
      for (KeyValuePair<string, string> kvp : openWith)
        Console::WriteLine("Key = {0}, Value = {1}", kvp.Key(), kvp.Value());
      
      // To get the values alone, use the Values property.
      SortedDictionary<string, string>::ValueCollection valueColl = openWith.Values;
      
      // The elements of the ValueCollection are strongly typed
      // with the type that was specified for dictionary values.
      Console::WriteLine();
      for (string s : valueColl)
        Console::WriteLine("Value = {0}", s);
      
      // To get the keys alone, use the Keys property.
      SortedDictionary<string, string>::KeyCollection keyColl = openWith.Keys;
      
      // The elements of the KeyCollection are strongly typed
      // with the type that was specified for dictionary keys.
      Console::WriteLine();
      for (string s : keyColl)
        Console::WriteLine("Key = {0}", s);
      
      // Use the Remove method to remove a key/value pair.
      Console::WriteLine("\nRemove(\"doc\")");
      openWith.Remove("doc");
      
      if (!openWith.ContainsKey("doc"))
        Console::WriteLine("Key \"doc\" is not found.");
    }
  };
}

_startup (Examples::Program)

// This code example produces the following output:
//
// An element with Key = "txt" already exists.
// For key = "rtf", value = wordpad.exe.
// For key = "rtf", value = winword.exe.
// Key = "tif" is not found.
// Value added for key = "ht": hypertrm.exe.
//
// Key = bmp, Value = paint.exe
// Key = dib, Value = paint.exe
// Key = doc, Value = winword.exe
// Key = ht, Value = hypertrm.exe
// Key = rtf, Value = winword.exe
// Key = txt, Value = notepad.exe
//
// Value = paint.exe
// Value = paint.exe
// Value = winword.exe
// Value = hypertrm.exe
// Value = winword.exe
// Value = notepad.exe
//
// Key = bmp
// Key = dib
// Key = doc
// Key = ht
// Key = rtf
// Key = txt
//
// Remove("doc")
// Key "doc" is not found.
