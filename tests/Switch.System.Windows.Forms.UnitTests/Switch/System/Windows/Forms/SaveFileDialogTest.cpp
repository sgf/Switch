#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/SaveFileDialog.hpp>
#include <Switch/System/IO/Path.hpp>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(SaveFileDialogTest, DefaultConstructor) {
    SaveFileDialog saveFileDialog;

    ASSERT_FALSE(saveFileDialog.CreatePrompt);
  }

  TEST(SaveFileDialogTest, Reset) {
    SaveFileDialog saveFileDialog;
    saveFileDialog.AddExtension = false;
    saveFileDialog.AutoUpgradeEnabled = false;
    saveFileDialog.CheckFileExists = true;
    saveFileDialog.CheckPathExists = true;
    saveFileDialog.FileDialogCustomPlaceCollection().Add(FileDialogCustomPlace("Directory"));
    saveFileDialog.DefaultExt = "cmd";
    saveFileDialog.DereferenceLinks = false;
    saveFileDialog.FileName = "MyFile.txt";
    /// saveFileDialog.FileNames = ... readonly
    saveFileDialog.Filter = "All files (*.*)|*.*";
    saveFileDialog.FilterIndex = 2;
    saveFileDialog.InitialDirectory = "home";
    saveFileDialog.RestoreDirectory = true;
    saveFileDialog.ShowHelp = true;
    saveFileDialog.ShowHiddenFiles = true;
    saveFileDialog.SupportMultiDottedExtensions = true;
    saveFileDialog.Title = "Myopen file title";
    saveFileDialog.ValidateNames = false;
    saveFileDialog.CreatePrompt = true;

    saveFileDialog.Reset();

    ASSERT_TRUE(saveFileDialog.AddExtension);
    ASSERT_TRUE(saveFileDialog.AutoUpgradeEnabled);
    ASSERT_FALSE(saveFileDialog.CheckFileExists);
    ASSERT_FALSE(saveFileDialog.CheckPathExists);
    ASSERT_EQ(0, saveFileDialog.FileDialogCustomPlaceCollection().Count);
    ASSERT_EQ("", saveFileDialog.DefaultExt);
    ASSERT_TRUE(saveFileDialog.DereferenceLinks);
    ASSERT_EQ("", saveFileDialog.FileName);
    ASSERT_EQ(0, saveFileDialog.FileNames().Count);
    ASSERT_EQ("", saveFileDialog.Filter);
    ASSERT_EQ(1, saveFileDialog.FilterIndex);
    ASSERT_EQ("", saveFileDialog.InitialDirectory);
    ASSERT_FALSE(saveFileDialog.RestoreDirectory);
    ASSERT_FALSE(saveFileDialog.ShowHelp);
    ASSERT_FALSE(saveFileDialog.ShowHiddenFiles);
    ASSERT_FALSE(saveFileDialog.SupportMultiDottedExtensions);
    ASSERT_EQ("", saveFileDialog.Title);
    ASSERT_TRUE(saveFileDialog.ValidateNames);
    ASSERT_FALSE(saveFileDialog.CreatePrompt);
  }

  TEST(SaveFileDialogTest, CreatePrompt) {
    SaveFileDialog saveFileDialog;

    saveFileDialog.CreatePrompt = true;

    ASSERT_TRUE(saveFileDialog.CreatePrompt);
  }
}
