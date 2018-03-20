#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/OpenFileDialog.hpp>
#include <Switch/System/IO/Path.hpp>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(OpenFileDialogTest, DefaultConstructor) {
    OpenFileDialog openFileDialog;

    ASSERT_FALSE(openFileDialog.Multiselect);
    ASSERT_FALSE(openFileDialog.ReadOnlyChecked);
  }

  TEST(OpenFileDialogTest, Reset) {
    OpenFileDialog openFileDialog;
    openFileDialog.AddExtension = false;
    openFileDialog.AutoUpgradeEnabled = false;
    openFileDialog.CheckFileExists = true;
    openFileDialog.CheckPathExists = true;
    openFileDialog.FileDialogCustomPlaceCollection().Add(FileDialogCustomPlace("Directory"));
    openFileDialog.DefaultExt = "cmd";
    openFileDialog.DereferenceLinks = false;
    openFileDialog.FileName = "MyFile.txt";
    /// openFileDialog.FileNames = ... readonly
    openFileDialog.Filter = "*.*";
    openFileDialog.FilterIndex = 2;
    openFileDialog.InitialDirectory = "home";
    openFileDialog.RestoreDirectory = true;
    openFileDialog.ShowHelp = true;
    openFileDialog.SupportMultiDottedExtensions = true;
    openFileDialog.Title = "Myopen file title";
    openFileDialog.ValidateNames = false;
    openFileDialog.Multiselect = true;
    openFileDialog.ReadOnlyChecked = true;

    openFileDialog.Reset();

    ASSERT_TRUE(openFileDialog.AddExtension);
    ASSERT_TRUE(openFileDialog.AutoUpgradeEnabled);
    ASSERT_FALSE(openFileDialog.CheckFileExists);
    ASSERT_FALSE(openFileDialog.CheckPathExists);
    ASSERT_EQ(0, openFileDialog.FileDialogCustomPlaceCollection().Count);
    ASSERT_EQ("", openFileDialog.DefaultExt);
    ASSERT_TRUE(openFileDialog.DereferenceLinks);
    ASSERT_EQ("", openFileDialog.FileName);
    ASSERT_EQ(0, openFileDialog.FileNames().Count);
    ASSERT_EQ("", openFileDialog.Filter);
    ASSERT_EQ(1, openFileDialog.FilterIndex);
    ASSERT_EQ("", openFileDialog.InitialDirectory);
    ASSERT_FALSE(openFileDialog.RestoreDirectory);
    ASSERT_FALSE(openFileDialog.ShowHelp);
    ASSERT_FALSE(openFileDialog.SupportMultiDottedExtensions);
    ASSERT_EQ("", openFileDialog.Title);
    ASSERT_TRUE(openFileDialog.ValidateNames);
    ASSERT_FALSE(openFileDialog.Multiselect);
    ASSERT_FALSE(openFileDialog.ReadOnlyChecked);
    ASSERT_EQ("", openFileDialog.SafeFileName);
  }

  TEST(OpenFileDialogTest, Multiselect) {
    OpenFileDialog openFileDialog;

    openFileDialog.Multiselect = true;

    ASSERT_TRUE(openFileDialog.Multiselect);
  }

  TEST(OpenFileDialogTest, ReadOnlyChecked) {
    OpenFileDialog openFileDialog;

    openFileDialog.ReadOnlyChecked = true;

    ASSERT_TRUE(openFileDialog.ReadOnlyChecked);
  }

  TEST(OpenFileDialogTest, SafeFileName) {
    OpenFileDialog openFileDialog;

    openFileDialog.FileName = Path::Combine("Directory1", "Directory2", "Directory3", "MyFile.txt");

    ASSERT_EQ("MyFile.txt", openFileDialog.SafeFileName);
  }
}
