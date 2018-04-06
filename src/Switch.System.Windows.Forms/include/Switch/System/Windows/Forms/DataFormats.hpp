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

          /// @brief Specifies a comma-separated value (CSV) format, which is a common interchange format used by spreadsheets. This format is not used directly by Windows Forms. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> CommaSeparatedValue;

          /// @brief Specifies the Windows device-independent bitmap (DIB) format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Dib;

          /// @brief Specifies the Windows Data Interchange Format (DIF), which Windows Forms does not directly use. This static field is read-only.
          /// @remarks DIF is a format consisting of ASCII codes in which database, spreadsheet, and similar documents can be structured to facilitate their use by and transfer to other programs.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          /// @par Examples
          /// The following code example demonstrates the use of this member.
          /// @code
          /// FileStream myFileStream = File::Open("Temp.dif",FileMode::Open);
          /// // Store the data into Dif format.
          /// DataObject myDataObject;
          /// myDataObject.SetData(DataFormats::Dif, myFileStream);
          ///
          /// // Check whether the data is stored or not in the specified format.
          /// bool formatPresent = myDataObject.GetDataPresent(DataFormats::Dif);
          /// if (formatPresent) {
          ///   Console::WriteLine("The data has been stored in the Dif format is:'"_s + formatPresent + "'"_s);
          /// } else {
          ///   Console::WriteLine("The data has not been stored in the specified format");
          /// }
          /// @endcode
          static property_<string, readonly_> Dif;

          /// @brief Specifies the Windows enhanced metafile format. This static field is read-only.
          /// @remarks The metafile format is a Windows file that stores an image in terms of graphic objects rather than pixels. When resized, a metafile preserves an image better than a bitmap.
          /// @note Special considerations may be necessary when using the metafile format with the clipboard. Due to a limitation in the current implementation of the DataObject class, the metafile format used by the .NET Framework may not be recognized by applications that use an older metafile format. In this case, you must interoperate with the Win32 Clipboard application programming interfaces (APIs). For more information, see article 323530, "Metafiles on Clipboard Are Not Visible to All Applications," in the Microsoft Knowledge Base at http://support.microsoft.com.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> EnhancedMetafile;

          /// @brief Specifies the Windows file drop format, which Windows Forms does not directly use. This static field is read-only.
          /// @remarks You can use this format to interact with shell file drags during drag-and-drop operations.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> FileDrop;

          /// @brief Specifies text in the HTML Clipboard format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Html;

          /// @brief Specifies the Windows culture format, which Windows Forms does not directly use. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Locale;

          /// @brief Specifies the Windows metafile format, which Windows Forms does not directly use. This static field is read-only.
          /// @remarks The metafile format is a Windows file that stores an image in terms of graphic objects rather than pixels. When resized, a metafile preserves an image better than a bitmap.
          /// @note Special considerations may be necessary when using the metafile format with the clipboard. Due to a limitation in the current implementation of the DataObject class, the metafile format used by the .NET Framework may not be recognized by applications that use an older metafile format. In this case, you must interoperate with the Win32 Clipboard application programming interfaces (APIs). For more information, see article 323530, "Metafiles on Clipboard Are Not Visible to All Applications," in the Microsoft Knowledge Base at http://support.microsoft.com.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> MetafilePict;

          /// @brief Specifies the standard Windows original equipment manufacturer (OEM) text format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> OemText;

          /// @brief Specifies the Windows palette format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Palette;

          /// @brief Specifies the Windows pen data format, which consists of pen strokes for handwriting software; Windows Forms does not use this format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> PenData;

          /// @brief Specifies the Resource Interchange File Format (RIFF) audio format, which Windows Forms does not directly use. This static field is read-only.
          /// @remarks RIFF is a broad-based specification, designed to be used in defining standard formats for different types of multimedia files.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Riff;

          /// @brief Specifies text consisting of Rich Text Format (RTF) data. This static field is read-only.
          /// @brief RTF is an adaptation of Document Content Architecture that is used for transferring formatted text documents between applications.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          /// @remarks For more information about the RTF format, see the Rich Text Format specification in the MSDN library at http://msdn.microsoft.com/library.
          static property_<string, readonly_> Rtf;

          /// @brief Specifies a format that encapsulates any type of Windows Forms object. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          /// @note The serializable format is specific to Windows Forms only and will not be recognized by applications created outside of Windows Forms.
          static property_<string, readonly_> Serializable;

          /// @brief Specifies the Windows Forms string class format, which Windows Forms uses to store string objects. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          /// @note The string class format is specific to Windows Forms only and will not be recognized by applications created outside of Windows Forms.
          static property_<string, readonly_> StringFormat;

          /// @brief Specifies the Windows symbolic link format, which Windows Forms does not directly use. This static field is read-only.
          /// @remarks A symbolic link is a disk directory entry that takes the place of a directory entry for a file, but is actually a reference to a file in a different directory. A symbolic link is also called an alias, shortcut, soft link, or symlink.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> SymbolicLink;

          /// @brief Specifies the standard ANSI text format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          /// @par Examples
          /// The following code example demonstrates the use of this member.
          /// @code
          /// try {
          ///   String myString = "This is a String from the ClipBoard";
          ///
          ///   // Sets the data into the Clipboard.
          ///   Clipboard::SetDataObject(myString);
          ///   $<IDataObject> myDataObject = Clipboard::GetDataObject();
          ///   // Checks whether the format of the data is 'UnicodeText' or not.
          ///   if(myDataObject->GetDataPresent(DataFormats::UnicodeText)) {
          ///     Console::WriteLine("Data in 'UnicodeText' format:"_s + myDataObject->GetData(DataFormats::UnicodeText));
          ///   } else {
          ///     Console::WriteLine("No String information was contained in the clipboard.");
          ///   }
          ///
          ///   // Checks whether the format of the data is 'Text' or not.
          ///   if(myDataObject->GetDataPresent(DataFormats::Text)) {
          ///     String clipString = as<String>(myDataObject->GetData(DataFormats::StringFormat));
          ///     Console::WriteLine("Data in 'Text' format:"_s + clipString);
          ///   }
          /// } catch(const Exception& e) {
          ///   Console::WriteLine(e.Message);
          /// }
          /// @endcode
          static property_<string, readonly_> Text;

          /// @brief Specifies the Tagged Image File Format (TIFF), which Windows Forms does not directly use. This static field is read-only.
          /// @remarks TIFF is a standard file format commonly used for scanning, storage, and interchanges of gray-scale graphic images.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> Tiff;

          /// @brief Specifies the standard Windows Unicode text format. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          /// @par Examples
          /// The following code example demonstrates the use of this member.
          /// @code
          /// try {
          ///   String myString = "This is a String from the ClipBoard";
          ///
          ///   // Sets the data into the Clipboard.
          ///   Clipboard::SetDataObject(myString);
          ///   $<IDataObject> myDataObject = Clipboard::GetDataObject();
          ///   // Checks whether the format of the data is 'UnicodeText' or not.
          ///   if(myDataObject->GetDataPresent(DataFormats::UnicodeText)) {
          ///     Console::WriteLine("Data in 'UnicodeText' format:"_s + myDataObject->GetData(DataFormats::UnicodeText));
          ///   } else {
          ///     Console::WriteLine("No String information was contained in the clipboard.");
          ///   }
          ///
          ///   // Checks whether the format of the data is 'Text' or not.
          ///   if(myDataObject->GetDataPresent(DataFormats::Text)) {
          ///     String clipString = as<String>(myDataObject->GetData(DataFormats::StringFormat));
          ///     Console::WriteLine("Data in 'Text' format:"_s + clipString);
          ///   }
          /// } catch(const Exception& e) {
          ///   Console::WriteLine(e.Message);
          /// }
          /// @endcode
          static property_<string, readonly_> UnicodeText;

          /// @brief Specifies the wave audio format, which Windows Forms does not directly use. This static field is read-only.
          /// @remarks This field is used by the IDataObject interface and the DataObject class to specify the data type.
          /// @remarks When adding to an IDataObject or to an implementation of DataObject, use this field as the format for the IDataObject.SetData and DataObject.SetData methods.
          /// @remarks To see if an object of this type exists, use this field as the format for the IDataObject.GetDataPresent and DataObject.GetDataPresent methods.
          /// @remarks To get an object of this type, use this as the format for the IDataObject.GetData and DataObject.GetData methods.
          static property_<string, readonly_> WaveAudio;

          /// @brief Returns a DataFormats.Format with the Windows Clipboard numeric ID and name for the specified ID.
          /// @param id The format ID.
          /// @return DataFormats::Format A DataFormats::Format that has the Windows Clipboard numeric ID and the name of the format.
          /// @remarks This member is typically used to register native Clipboard formats.
          /// @remarks Call GetFormat with an ID number when you want to retrieve a DataFormats.Format instance that contains the ID/format name pair. Typically, the ID name and number is published by the creator of the application that you are using the Clipboard to interface with. For example, the ID number for Dynamic Data Exchange (DDE) conversation information in Visual Basic is &HBF00, and the format name is vbCFLink.
          /// @remarks Call this method with any unique ID number to add the ID/format name pair to the static list of format name/ID pairs in the DataFormats class. The new name will be created by concatenating "Format" and the ID number. This pair is not registered as a new Clipboard format because you have not provided a name.
          /// @par Examples
          /// The following code example demonstrates the use of this member.
          /// @include DataFormatsGetFormat.cpp
          static Format GetFormat(int32 id);

          /// @brief Returns a DataFormats.Format with the Windows Clipboard numeric ID and name for the specified format.
          /// @param format The format name.
          /// @return DataFormats::Format A DataFormats::Format that has the Windows Clipboard numeric ID and the name of the format.
          /// @exception Win32Exception Registering a new Clipboard format failed.
          /// @remarks Call GetFormat with the format name when you need a Windows Clipboard numeric ID for an existing format.
          /// @remarks Call this method with your own format name to create a new Clipboard format type. If the specified format does not exist, this method will register the name as a Clipboard format with the Windows registry and get a unique format identifier. This new name/ID pair will be added to the static list of format name/ID pairs in the DataFormats class.
          /// @par Examples
          /// The following code example shows how to retrieve a DataFormats.Format representing a format name/ID pair. The UnicodeText format is requested, and the contents of the retrieved DataFormats.Format are displayed in a text box.<br>
          /// This code requires textBox1 has been instantiated.
          /// @code
          /// void GetMyFormatInfomation() {
          ///   // Creates a DataFormats.Format for the Unicode data format.
          ///   DataFormats::Format myFormat(DataFormats::UnicodeText);
          ///
          ///   // Displays the contents of myFormat.
          ///   textBox1.Text = "ID value: "_s + myFormat.Id + '\n' + "Format name: "_s + myFormat.Name;
          /// }
          /// @endcode
          static Format GetFormat(const string& format);

        private:
          static System::Collections::Generic::List<Format> formats;
        };
      }
    }
  }
}
