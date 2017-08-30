#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class InitializerListTest : public TestFixture {
  protected:
    void CreateCollectionWithInitializerList() {
      struct MyCollection {
        MyCollection(InitializerList<int> il) : values(il) {}
        Array<int> values;
      } collection = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      
      int32 i = 0;
      for (const auto& value : collection.values)
        Assert::AreEqual(value, results[i++], sw_current_information);
      Assert::AreEqual(10, i, sw_current_information);
    }

    void CreateCollectionWithInitializerListThenIterateIt() {
      struct MyCollection {
        MyCollection(InitializerList<int> il) {
          for (int value : il)
            this->values.Add(value);
        }
        System::Collections::Generic::List<int> values;
      } collection = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      
      int32 i = 0;
      for (const auto& value : collection.values)
        Assert::AreEqual(value, results[i++], sw_current_information);
      Assert::AreEqual(10, i, sw_current_information);
    }
  };
  
  sw_test(InitializerListTest, CreateCollectionWithInitializerList)
  sw_test(InitializerListTest, CreateCollectionWithInitializerListThenIterateIt)
}