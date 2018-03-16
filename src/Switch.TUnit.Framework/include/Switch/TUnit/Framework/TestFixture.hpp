/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "OneTimeSetUpAttribute.hpp"
#include "OneTimeTearDownAttribute.hpp"
#include "SetUpAttribute.hpp"
#include "TearDownAttribute.hpp"
#include "TestAttribute.hpp"
#include "../../TUnitFrameworkExport.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      /// @par Library
      /// Switch.TUnit.Framework
      struct tunit_framework_export_ TestFixture : public object {
      protected:
        void AddOneTimeTearDown(const RegisteredMethod& registeredMethod) {this->oneTimeTearDowns.Insert(0, registeredMethod);}

        void AddSetUp(const RegisteredMethod& registeredMethod) {this->setUps.Add(registeredMethod);}

        void AddTearDown(const RegisteredMethod& registeredMethod) {this->tearDowns.Insert(0, registeredMethod);}

        void AddTest(const RegisteredMethod& registeredMethod) {this->tests.Add(registeredMethod);}

      private:
        friend class Switch::TUnit::Framework::UnitTest;
        friend struct Switch::TUnit::Framework::OneTimeSetUpAttribute;
        friend struct Switch::TUnit::Framework::OneTimeTearDownAttribute;
        friend struct Switch::TUnit::Framework::SetUpAttribute;
        friend struct Switch::TUnit::Framework::TearDownAttribute;
        friend struct Switch::TUnit::Framework::TestAttribute;

        void AddOneTimeSetUp(const RegisteredMethod& registeredMethod) {this->oneTimeSetUps.Add(registeredMethod);}

        System::Collections::Generic::List<RegisteredMethod> oneTimeSetUps;
        System::Collections::Generic::List<RegisteredMethod> oneTimeTearDowns;
        System::Collections::Generic::List<RegisteredMethod> setUps;
        System::Collections::Generic::List<RegisteredMethod> tearDowns;
        System::Collections::Generic::List<RegisteredMethod> tests;
      };
    }
  }
}

using namespace Switch;
