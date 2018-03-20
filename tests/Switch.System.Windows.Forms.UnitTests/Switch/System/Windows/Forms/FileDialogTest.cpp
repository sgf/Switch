#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/FileDialog.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  class FileDialog1 : public FileDialog {
  public:
    void Reset() override {}
    bool RunDialog(intptr hwndOwner) override {return false;}
    Array<System::Collections::Generic::KeyValuePair<string, Array<string>>> GetFilters() {return this->FileDialog::__get_filters__();}
  };

  TEST(FileDialogTest, DefaultConstructor) {
    FileDialog1 fileDialog1;

    ASSERT_TRUE(fileDialog1.AddExtension);
    ASSERT_TRUE(fileDialog1.AutoUpgradeEnabled);
    ASSERT_FALSE(fileDialog1.CheckFileExists);
    ASSERT_FALSE(fileDialog1.CheckPathExists);
    ASSERT_EQ(0, fileDialog1.FileDialogCustomPlaceCollection().Count);
    ASSERT_EQ("", fileDialog1.DefaultExt);
    ASSERT_TRUE(fileDialog1.DereferenceLinks);
    ASSERT_EQ("", fileDialog1.FileName);
    ASSERT_EQ(0, fileDialog1.FileNames().Count);
    ASSERT_EQ("", fileDialog1.Filter);
    ASSERT_EQ(1, fileDialog1.FilterIndex);
    ASSERT_EQ("", fileDialog1.InitialDirectory);
    ASSERT_FALSE(fileDialog1.RestoreDirectory);
    ASSERT_FALSE(fileDialog1.ShowHelp);
    ASSERT_FALSE(fileDialog1.ShowHiddenFiles);
    ASSERT_FALSE(fileDialog1.SupportMultiDottedExtensions);
    ASSERT_EQ("", fileDialog1.Title);
    ASSERT_TRUE(fileDialog1.ValidateNames);
  };

  TEST(FileDialogTest, AddExtension) {
    FileDialog1 fileDialog1;

    fileDialog1.AddExtension = false;

    ASSERT_FALSE(fileDialog1.AddExtension);
  }

  TEST(FileDialogTest, AutoUpgradeEnabled) {
    FileDialog1 fileDialog1;

    fileDialog1.AutoUpgradeEnabled = false;

    ASSERT_FALSE(fileDialog1.AutoUpgradeEnabled);
  }

  TEST(FileDialogTest, CheckFileExists) {
    FileDialog1 fileDialog1;

    fileDialog1.CheckFileExists = true;

    ASSERT_TRUE(fileDialog1.CheckFileExists);
  }

  TEST(FileDialogTest, CheckPathExists) {
    FileDialog1 fileDialog1;

    fileDialog1.CheckPathExists = true;

    ASSERT_TRUE(fileDialog1.CheckPathExists);
  }

  TEST(FileDialogTest, FileDialogCustomPlaceCollection) {
    FileDialog1 fileDialog1;

    fileDialog1.FileDialogCustomPlaceCollection().Add(FileDialogCustomPlace("directory1"));

    ASSERT_EQ(FileDialogCustomPlace("directory1").Path, fileDialog1.FileDialogCustomPlaceCollection()[0].Path);
  }

  TEST(FileDialogTest, DefaultExt) {
    FileDialog1 fileDialog1;

    fileDialog1.DefaultExt = "cmd";

    ASSERT_EQ("cmd", fileDialog1.DefaultExt);
  }

  TEST(FileDialogTest, DereferenceLinks) {
    FileDialog1 fileDialog1;

    fileDialog1.DereferenceLinks = false;

    ASSERT_FALSE(fileDialog1.DereferenceLinks);
  }

  TEST(FileDialogTest, FileName) {
    FileDialog1 fileDialog1;

    fileDialog1.FileName = "MyFile.txt";

    ASSERT_EQ("MyFile.txt", fileDialog1.FileName);
  }

  TEST(FileDialogTest, FilterWithOneFilter) {
    FileDialog1 fileDialog1;

    fileDialog1.Filter = "All files (*.*)|*.*";

    ASSERT_EQ("All files (*.*)|*.*", fileDialog1.Filter);
    ASSERT_EQ(1, fileDialog1.GetFilters().Count);
    ASSERT_EQ("All files (*.*)", fileDialog1.GetFilters()[0].Key);
    ASSERT_EQ(1, fileDialog1.GetFilters()[0].Value().Count);
    ASSERT_EQ("*.*", fileDialog1.GetFilters()[0].Value()[0]);
  }

  TEST(FileDialogTest, FilterWithTwoFilters) {
    FileDialog1 fileDialog1;

    fileDialog1.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";

    ASSERT_EQ("Text files (*.txt)|*.txt|All files (*.*)|*.*", fileDialog1.Filter);
    ASSERT_EQ(2, fileDialog1.GetFilters().Count);
    ASSERT_EQ("Text files (*.txt)", fileDialog1.GetFilters()[0].Key);
    ASSERT_EQ(1, fileDialog1.GetFilters()[0].Value().Count);
    ASSERT_EQ("*.txt", fileDialog1.GetFilters()[0].Value()[0]);
    ASSERT_EQ("All files (*.*)", fileDialog1.GetFilters()[1].Key);
    ASSERT_EQ(1, fileDialog1.GetFilters()[1].Value().Count);
    ASSERT_EQ("*.*", fileDialog1.GetFilters()[1].Value()[0]);
  }

  TEST(FileDialogTest, FilterWithTwoFiltersAndMoreThanOnePattern) {
    FileDialog1 fileDialog1;

    fileDialog1.Filter = "Image files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All files (*.*)|*.*";

    ASSERT_EQ("Image files (*.bmp;*.jpg;*.png)|*.bmp;*.jpg;*.png|All files (*.*)|*.*", fileDialog1.Filter);
    ASSERT_EQ(2, fileDialog1.GetFilters().Count);
    ASSERT_EQ("Image files (*.bmp;*.jpg;*.png)", fileDialog1.GetFilters()[0].Key);
    ASSERT_EQ(3, fileDialog1.GetFilters()[0].Value().Count);
    ASSERT_EQ("*.bmp", fileDialog1.GetFilters()[0].Value()[0]);
    ASSERT_EQ("*.jpg", fileDialog1.GetFilters()[0].Value()[1]);
    ASSERT_EQ("*.png", fileDialog1.GetFilters()[0].Value()[2]);
    ASSERT_EQ("All files (*.*)", fileDialog1.GetFilters()[1].Key);
    ASSERT_EQ(1, fileDialog1.GetFilters()[1].Value().Count);
    ASSERT_EQ("*.*", fileDialog1.GetFilters()[1].Value()[0]);
  }

  TEST(FileDialogTest, FilterWithInvalidFormat) {
    FileDialog1 fileDialog1;

    ASSERT_THROW(fileDialog1.Filter = "*.*", ArgumentException);
  }

  TEST(FileDialogTest, FilterIndex) {
    FileDialog1 fileDialog1;

    fileDialog1.FilterIndex = 2;

    ASSERT_EQ(2, fileDialog1.FilterIndex);
  }

  TEST(FileDialogTest, InitialDirectory) {
    FileDialog1 fileDialog1;

    fileDialog1.InitialDirectory = "directory";

    ASSERT_EQ("directory", fileDialog1.InitialDirectory);
  }

  TEST(FileDialogTest, RestoreDirectory) {
    FileDialog1 fileDialog1;

    fileDialog1.RestoreDirectory = true;

    ASSERT_TRUE(fileDialog1.RestoreDirectory);
  }

  TEST(FileDialogTest, ShowHelp) {
    FileDialog1 fileDialog1;

    fileDialog1.ShowHelp = true;

    ASSERT_TRUE(fileDialog1.ShowHelp);
  }

  TEST(FileDialogTest, ShowHiddenFiles) {
    FileDialog1 fileDialog1;

    fileDialog1.ShowHiddenFiles = true;

    ASSERT_TRUE(fileDialog1.ShowHiddenFiles);
  }

  TEST(FileDialogTest, SupportMultiDottedExtensions) {
    FileDialog1 fileDialog1;

    fileDialog1.SupportMultiDottedExtensions = true;

    ASSERT_TRUE(fileDialog1.SupportMultiDottedExtensions);
  }

  TEST(FileDialogTest, Title) {
    FileDialog1 fileDialog1;

    fileDialog1.Title = "FileDialog1 open";

    ASSERT_EQ("FileDialog1 open", fileDialog1.Title);
  }

  TEST(FileDialogTest, ValidateNames) {
    FileDialog1 fileDialog1;

    fileDialog1.ValidateNames = false;

    ASSERT_FALSE(fileDialog1.ValidateNames);
  }
}
