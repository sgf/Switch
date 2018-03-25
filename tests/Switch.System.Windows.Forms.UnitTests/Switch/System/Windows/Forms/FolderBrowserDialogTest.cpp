#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/FolderBrowserDialog.hpp>
#include <Switch/As.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(FolderBrowserDialogTest, DefaultConstructor) {
    FolderBrowserDialog folderBrowserDialog;

    ASSERT_EQ("", folderBrowserDialog.Description);
    ASSERT_EQ(Environment::SpecialFolder::Desktop, folderBrowserDialog.RootFolder);
    ASSERT_EQ("", folderBrowserDialog.SelectedPath);
    ASSERT_TRUE(folderBrowserDialog.ShowNewFolderButton);
  }

  TEST(FolderBrowserDialogTest, Description) {
    FolderBrowserDialog folderBrowserDialog;

    folderBrowserDialog.Description = "Browse for install path";

    ASSERT_EQ("Browse for install path", folderBrowserDialog.Description);
  }

  TEST(FolderBrowserDialogTest, RootFolder) {
    FolderBrowserDialog folderBrowserDialog;

    folderBrowserDialog.RootFolder = Environment::SpecialFolder::MyDocuments;

    ASSERT_EQ(Environment::SpecialFolder::MyDocuments, folderBrowserDialog.RootFolder);
  }

  TEST(FolderBrowserDialogTest, SelectedPath) {
    FolderBrowserDialog folderBrowserDialog;

    folderBrowserDialog.SelectedPath = "Gammasoft";

    ASSERT_EQ("Gammasoft", folderBrowserDialog.SelectedPath);
  }

  TEST(FolderBrowserDialogTest, ShowNewFolderButton) {
    FolderBrowserDialog folderBrowserDialog;

    folderBrowserDialog.ShowNewFolderButton = false;

    ASSERT_FALSE(folderBrowserDialog.ShowNewFolderButton);
  }

  TEST(FolderBrowserDialogTest, Reset) {
    FolderBrowserDialog folderBrowserDialog;
    folderBrowserDialog.Description = "Browse for install path";
    folderBrowserDialog.RootFolder = Environment::SpecialFolder::MyDocuments;
    folderBrowserDialog.SelectedPath = "Gammasoft";
    folderBrowserDialog.ShowNewFolderButton = false;

    folderBrowserDialog.Reset();

    ASSERT_EQ("", folderBrowserDialog.Description);
    ASSERT_EQ(Environment::SpecialFolder::Desktop, folderBrowserDialog.RootFolder);
    ASSERT_EQ("", folderBrowserDialog.SelectedPath);
    ASSERT_TRUE(folderBrowserDialog.ShowNewFolderButton);
  }
}
