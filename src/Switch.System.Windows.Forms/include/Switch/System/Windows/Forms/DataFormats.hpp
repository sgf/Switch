/// @file
/// @brief Contains Switch::System::Windows::Forms::DataFormats class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/Property.hpp>
#include <Switch/Static.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides static, predefined Clipboard format names. Use them to identify the format of data that you store in an IDataObject.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The IDataObject and DataObject classes also use the static format list to determine the type of data that is retrieved from the system Clipboard, or that is transferred in a drag-and-drop operation.
        /// @remarks The GetFormat method allows you to:
        /// * Get a predefined DataFormats.Format object for a format name or ID number.
        /// * Add a new format name/ID number pair to the static list in this class, and to register the format with the Windows registry as a Clipboard format when you pass it the format name.
        /// @remarks You can get the Id number or format Name from the appropriate property in the DataFormats.Format instance.
        class system_windows_forms_export_ DataFormats static_ {
        public:
          /// @brief Represents a Clipboard format type.
          /// @remarks A format type consists of a text-based format name and an ID number. The format name/ID number pair can define a system Clipboard or other format.
          /// @par Examples
          ///  The following code example shows how to retrieve a DataFormats.Format representing a format name/ID pair. The UnicodeText format is requested, and the contents of the retrieved DataFormats.Format are displayed in a text box.<br><br>
          ///  This code requires that textBox1 has been created.
          /// @code
          /// void GetMyFormatInfomation() {
          ///   // Creates a DataFormats.Format for the Unicode data format.
          ///   DataFormats::Format myFormat = DataFormats::GetFormat(DataFormats::UnicodeText());
          ///   // Displays the contents of myFormat.
          ///   textBox1.Text("ID value: "_s + myFormat.Id() + '\n' + "Format name: "_s + myFormat.Name());
          /// }
          /// @endcode
          class Format : public object {
          public:
            /// @cond
            Format() : id(0) {}
            Format(const Format& format) : name(format.name), id(format.id) {}
            Format& operator=(const Format& format) = default;
            /// @endcond

            /// @remarks This API supports the product infrastructure and is not intended to be used directly from your code.
            /// @brief Initializes a new instance of the DataFormats.Format class with a Boolean that indicates whether a Win32 handle is expected.
            /// @param name The name of this format.
            /// @param id The ID number for this format.
            /// @par Examples
            /// The following code example creates a new format for a name and unique ID number. The new format does not require a Windows handle. It requires that textBox1 has been instantiated.
            /// @code
            /// void CreateMyFormat2() {
            ///   DataFormats::Format myFormat("AnotherNewFormat", 20916);
            ///
            ///   // Displays the contents of myFormat.
            ///   textBox1.Text = "ID value: "_s + myFormat.Id + '\n' + "Format name: "_s + myFormat.Name;
            /// }
            /// @endcode
            Format(const string& name, int32 id) : name(name), id(id) {}

            /// @brief Gets the ID number for this format.
            /// @return int32 The ID number for this format.
            property_<int32, readonly_> Id {
              get_ {return this->id;}
            };

            /// @brief Gets the name of this format.
            /// @return string The name of this format.
            property_<string, readonly_> Name {
              get_ {return this->name;}
            };

          private:
            string name;
            int32 id;
          };

          /// @brief Specifies a Windows bitmap format. This static field is read-only.
          /// @remarks A bitmap represents a computer graphic as an array of bits in memory, and these bits represent the attributes of the individual pixels in an image.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Bitmap;

          static property_<string, readonly_> CommaSeparatedValue;

          static property_<string, readonly_> Dib;

          static property_<string, readonly_> Dif;

          static property_<string, readonly_> EnhancedMetafile;

          static property_<string, readonly_> FileDrop;

          static property_<string, readonly_> Html;

          static property_<string, readonly_> Locale;

          static property_<string, readonly_> MetafilePict;

          static property_<string, readonly_> OemText;

          static property_<string, readonly_> Palette;

          static property_<string, readonly_> PenData;

          static property_<string, readonly_> Riff;

          static property_<string, readonly_> Rtf;

          static property_<string, readonly_> Serializable;

          static property_<string, readonly_> StringFormat;

          static property_<string, readonly_> SymbolicLink;

          static property_<string, readonly_> Text;

          static property_<string, readonly_> Tiff;

          static property_<string, readonly_> UnicodeText;

          static property_<string, readonly_> WaveAudio;

          static Format GetFormat(const string& name);

        private:
          static System::Collections::Generic::List<Format> formats;
        };
      }
    }
  }
}
