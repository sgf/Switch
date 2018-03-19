#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/CommonDialog.hpp>
#include <Switch/As.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  class CommonDialog1 : public CommonDialog {
  public:
    CommonDialog1() {this->Reset();}

    void Reset() override {}
    bool RunDialog(intptr hwndOwner) override {
      this->hwndOwner = hwndOwner;
      return this->runDialogResult;
    }

    void OnHelpRequest(const EventArgs& e) override {
      this->CommonDialog::OnHelpRequest(e);
    }

    property_<intptr> HwndOwner {
      get_ {return this->hwndOwner;},
      set_ {this->hwndOwner = value;}
    };

    property_<bool> RunDialogResult {
      get_ {return this->runDialogResult;},
      set_ {this->runDialogResult = value;}
    };

  private:
    intptr hwndOwner = IntPtr::Zero;
    bool runDialogResult = false;
  };

  class Win32Window1 : public IWin32Window, public object {
  public:
    intptr GetHandle() override {return 42;}
  };

  TEST(CommonDialogTest, DefaultConstructor) {
    CommonDialog1 commonDialog1;

    ASSERT_TRUE(commonDialog1.Tag == null);
  }

  TEST(CommonDialogTest, Tag) {
    CommonDialog1 commonDialog1;
    string value = "My Tag";

    commonDialog1.Tag = value;

    ASSERT_EQ("My Tag", as<string>(commonDialog1.Tag()));
  }

  TEST(CommonDialogTest, HelpRequest) {
    CommonDialog1 commonDialog1;
    int32 result = 1;

    commonDialog1.HelpRequest += delegate_(const object & sender, const EventArgs & e) {
      result += 1;
    };

    commonDialog1.OnHelpRequest(EventArgs::Empty);

    ASSERT_EQ(2, result);
  }

  TEST(CommonDialogTest, ShowDialog) {
    CommonDialog1 commonDialog1;

    commonDialog1.RunDialogResult = false;
    ASSERT_EQ(DialogResult::Cancel, commonDialog1.ShowDialog());
    ASSERT_EQ(IntPtr::Zero, commonDialog1.HwndOwner);

    commonDialog1.RunDialogResult = true;
    ASSERT_EQ(DialogResult::OK, commonDialog1.ShowDialog());
    ASSERT_EQ(IntPtr::Zero, commonDialog1.HwndOwner);
  }

  TEST(CommonDialogTest, ShowDialogWithHwndOwner) {
    CommonDialog1 commonDialog1;

    commonDialog1.RunDialogResult = false;
    ASSERT_EQ(DialogResult::Cancel, commonDialog1.ShowDialog(Win32Window1()));
    ASSERT_EQ(42, commonDialog1.HwndOwner);

    commonDialog1.RunDialogResult = true;
    ASSERT_EQ(DialogResult::OK, commonDialog1.ShowDialog(Win32Window1()));
    ASSERT_EQ(42, commonDialog1.HwndOwner);
  }
}
