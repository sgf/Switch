#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class CurrentInformationTest : public TestFixture {
  protected:
    void CreateAnEmptyCurrentInformationThenToString() {
      CurrentInformation ci;
      Assert::AreEqual("{Empty}", ci.ToString(), _current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFileName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FileName, _current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFunctionName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FunctionName, _current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetLine() {
      CurrentInformation ci;
      Assert::AreEqual(0, ci.Line);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenToString() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42}", ci.ToString(), _current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FileName, _current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("", ci.FunctionName, _current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual(42, ci.Line, _current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), _current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("MyFile.txt", ci.FileName, _current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("void MyFunction()", ci.FunctionName, _current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual(42, ci.Line, _current_information);
    }
    
    void CreateCurrentInformationByCopyConstructorThenToString() {
      CurrentInformation ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), _current_information);
    }
    
    void CreateCurrentInformationByCopyOperatorThenToString() {
      CurrentInformation ci;
      ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), _current_information);
    }
  };
  
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenToString)
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFileName)
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFunctionName)
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetLine)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenToString)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFileName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFunctionName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetLine)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine)
  _test(CurrentInformationTest, CreateCurrentInformationByCopyConstructorThenToString)
  _test(CurrentInformationTest, CreateCurrentInformationByCopyOperatorThenToString)
}
