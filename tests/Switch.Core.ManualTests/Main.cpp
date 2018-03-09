#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Environment.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      auto a = Array<>::CreateInstance<string, 3>({2, 3, 4});
      for (int i = a.GetLowerBound(0); i <= a.GetUpperBound(0); i++)
        for (int j = a.GetLowerBound(1); j <= a.GetUpperBound(1); j++)
          for (int k = a.GetLowerBound(2); k <= a.GetUpperBound(2); k++)
            a.SetValue(Convert::ToString(i) + j + k, { i, j, k});

      // Displays the values of the Array.
      // Console::WriteLine("a = {0}", a);
      //std::cout << a << std::endl;
      
      Console::WriteLine("{");
      Array<int> lengths(a.Rank);
      for(int rank = 0; rank < a.Rank; rank++)
        lengths[rank] = a.GetLength(rank);
      
      for(int rank = 0; rank < a.Rank; rank++)
        Console::WriteLine("Lower = {0}, upper = {1}", a.GetLowerBound(rank),  a.GetUpperBound(rank));
      
      Console::WriteLine("}");

    }
  };
}

startup_(Examples::Program);

/*
{
  {
    {000, 001, 002, 003},
    {010, 011, 012, 013},
    {020, 021, 022, 023}
 
  },
  {
    {100, 101, 102, 103},
    {110, 111, 112, 113},
    {120, 121, 122, 123}
  }
}

 */
