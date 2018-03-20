/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include "../../../System/Windows/Forms/FileDialog.hpp"
#include <Switch/System/IO/File.hpp>
#include <Switch/System/IO/Path.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Displays a standard dialog box that prompts the user to open a file. This class cannot be inherited.
        /// @par Library
        /// Switch.System.Windows.Forms
        class system_windows_forms_export_ OpenFileDialog final : public FileDialog {
        public:
          /// @brief Initializes an instance of the OpenFileDialog class.
          /// @remarks This is the default, compiler-supplied constructor for the OpenFileDialog class.
          OpenFileDialog();

          /// @brief Gets or sets a value indicating whether the dialog box allows multiple files to be selected.
          /// @return bool true if the dialog box allows multiple files to be selected together or concurrently; otherwise, false. The default value is false.
          /// @remarks Use the FileNames property to access the full list of selected file names.
          /// @par Examples
          /// The following code example allows the user to select a number of images and display them in PictureBox controls on a Form. It demonstrates initializing an OpenFileDialog, setting the Title and Filter properties, and allowing the user to select multiple files by setting the Multiselect property to true. This code example assumes that your form already has an OpenFileDialog control named openFileDialog1, a Button named SelectFileButton, and a FlowLayoutPanel named flowLayoutPanel1.
          /// @code
          /// void Form1_Load(const object& sender, const EventArgs& e) {
          ///   InitializeOpenFileDialog();
          /// }
          ///
          /// void InitializeOpenFileDialog() {
          ///   // Set the file dialog to filter for graphics files.
          ///   this->openFileDialog1.Filter = "Images (*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
          ///
          ///   // Allow the user to select multiple images.
          ///   this->openFileDialog1.Multiselect = true;
          ///   this->openFileDialog1.Title = "My Image Browser";
          /// }
          ///
          /// void selectFilesButton_Click(const object& sender, const EventArgs& e) {
          ///   DialogResult dr = this->openFileDialog1.ShowDialog();
          ///   if (dr == System::Windows::Forms::DialogResult::OK) {
          ///     // Read the files
          ///     for (const String& file : openFileDialog1.FileNames) {
          ///       // Create a PictureBox.
          ///       try {
          ///         this->pictureBoxes.Add(new_<PictureBox>());
          ///         Image loadedImage = Image.FromFile(file);
          ///         this->pictureBoxes[this->pictureBoxes.Count - 1]->Height = loadedImage.Height;
          ///         this->pictureBoxes[this->pictureBoxes.Count - 1]->Width = loadedImage.Width;
          ///         this->pictureBoxes[this->pictureBoxes.Count - 1]->Image = loadedImage;
          ///         flowLayoutPanel1.Controls().Add(*this->pictureBoxes[this->pictureBoxes.Count - 1]);
          ///       }
          ///       catch (const SecurityException& ex) {
          ///         // The user lacks appropriate permissions to read files, discover paths, etc.
          ///         MessageBox::Show("Security error. Please contact your administrator for details.\n\nError message: "_s + ex.Message + "\n\nDetails (send to Support):\n\n"_s + ex.StackTrace);
          ///       }
          ///       catch (const Exception& ex) {
          ///         // Could not load the image - probably related to Windows file system permissions.
          ///         MessageBox.Show("Cannot display the image: "_s + file.Substring(file.LastIndexOf('\\')) + ". You may not have permission to read the file, or it may be corrupt.\n\nReported error: "_s + ex.Message);
          ///       }
          ///     }
          ///   }
          /// @endcode
          property_<bool> Multiselect {
            get_ {return this->multiselect;},
            set_ {this->multiselect = value;}
          };

          /// @brief Gets or sets a value indicating whether the read-only check box is selected.
          /// @return bool true if the read-only check box is selected; otherwise, false. The default value is false.
          /// @remarks The ReadOnlyChecked state does not affect the read/write mode that OpenFileDialog.OpenFile uses to open a file selected in the dialog box. OpenFile will always open the file in read-only mode.
          /// @remarks The ShowReadOnly property must be set before in order for the read-only check box to appear in the dialog box.
          /// @par Examples
          /// The following code example demonstrates the use of the ReadOnlyChecked property. This example displays the OpenFileDialog box with the ShowReadOnly property set to true. If the user clicks the option to open the file in read-only mode, the ReadOnlyChecked property evaluates to true, and the OpenFile method is used to open the file. Otherwise, the FileStream class is used to open the file in read/write mode.
          /// @code
          /// FileStream OpenFile() {
          ///   // Displays an OpenFileDialog and shows the read/only files.
          ///   OpenFileDialog dlgOpenFile;
          ///   dlgOpenFile.ShowReadOnly = true;
          ///
          ///   if(dlgOpenFile.ShowDialog() == DialogResult::OK) {
          ///     // If ReadOnlyChecked is true, uses the OpenFile method to
          ///     // open the file with read/only access.
          ///     string path;
          ///
          ///     try {
          ///       if(dlgOpenFile.ReadOnlyChecked == true) {
          ///         return dlgOpenFile.OpenFile();
          ///       } else {
          ///         // Otherwise, opens the file with read/write access.
          ///         path = dlgOpenFile.FileName;
          ///         return FileStream(path, System::IO::FileMode::Open, System::IO::FileAccess::ReadWrite);
          ///       }
          ///     } catch (const SecurityException& ex) {
          ///       // The user lacks appropriate permissions to read files, discover paths, etc.
          ///       MessageBox::Show("Security error. Please contact your administrator for details.\n\nError message: "_s + ex.Message + "\n\nDetails (send to Support):\n\n"_s + ex.StackTrace);
          ///     } catch (const Exception& ex) {
          ///       // Could not load the image - probably related to Windows file system permissions.
          ///       MessageBox::Show("Cannot display the image: "_s + path.Substring(path.LastIndexOf('\\')) + ". You may not have permission to read the file, or it may be corrupt.\n\nReported error: "_s + ex.Message);
          ///     }
          ///   }
          ///
          ///   return FileSgtream::Empty;
          /// }
          /// @endcode
          property_<bool> ReadOnlyChecked {
            get_ {return this->readOnlyChecked;},
            set_ {this->readOnlyChecked = value;}
          };

          /// @brief Gets the file name and extension for the file selected in the dialog box. The file name does not include the path.
          property_<string, readonly_> SafeFileName {
            get_ {return System::IO::Path::GetFileName(this->FileName);}
          };

          /// @brief Opens the file selected by the user, with read-only permission. The file is specified by the FileName property.
          /// @return FileStream A Stream that specifies the read-only file selected by the user.
          /// @remarks The OpenFile method is used to provide a facility to quickly open a file from the dialog box. The file is opened in read-only mode for security purposes. To open a file in read/write mode, you must use another method, such as FileStream.
          /// @par Examples
          /// The following code example uses the OpenFileDialog implementation of FileDialog and illustrates creating, setting of properties, and showing the dialog box. The example uses the Filter and FilterIndex properties to provide a list of filters for the user. The example requires a form with a Button placed on it and the System.IO namespace added to it.
          /// @code
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   OpenFileDialog openFileDialog1;
          ///
          ///   openFileDialog1.InitialDirectory = "c:\\" ;
          ///   openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*" ;
          ///   openFileDialog1.FilterIndex = 2 ;
          ///   openFileDialog1.RestoreDirectory = true ;
          ///
          ///   if (openFileDialog1.ShowDialog() == DialogResult::OK) {
          ///     try {
          ///       using_ (FileStream myStream = openFileDialog1.OpenFile()) {
          ///         // Insert code to read the stream here.
          ///       }
          ///     } catch (const Exception& ex) {
          ///       MessageBox::Show("Error: Could not read file from disk. Original error: "_s + ex.Message);
          ///     }
          ///   }
          /// }
          /// @endcode
          System::IO::FileStream OpenFile() {return System::IO::File::OpenRead(this->FileName);};

          /// @brief Resets all properties to their default values.
          void Reset() override;

        protected:
          /// @cond
          bool multiselect = false;
          bool readOnlyChecked = false;
          /// @endcond

        private:
          bool RunDialog(intptr hwndOwner) override;
        };
      }
    }
  }
}
