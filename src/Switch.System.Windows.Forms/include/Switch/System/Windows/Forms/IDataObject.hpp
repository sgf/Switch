/// @file
/// @brief Contains Switch::System::Windows::Forms::IDataObject interface.
#pragma once

#include <Switch/Interface.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "DataFormats.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @interface IDataObject
        /// @brief Provides a format-independent mechanism for transferring data.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The IDataObject interface is used by the Clipboard class and in drag-and-drop operations.
        /// @remarks When implemented in a class, the IDataObject methods allow the user to store data in multiple formats in an instance of the class. Storing data in more than one format increases the chance that a target application, whose format requirements you might not know, can retrieve the stored data. To store data in an instance of IDataObject, call the SetData method and specify the data format in the format parameter. Set the autoConvert parameter to false if you do not want stored data to be converted to another format when it is retrieved. Invoke SetData multiple times on one instance of IDataObject to store data in more than one format.
        /// @remarks You retrieve stored data from an IDataObject by calling the GetData method and specifying the data format in the format parameter. Set the autoConvert parameter to false to retrieve only data that was stored in the specified format. To convert the stored data to the specified format, set autoConvert to true, or do not use autoConvert.
        /// @remarks To determine the formats of the data stored in an IDataObject, use the following IDataObject methods.
        /// * Call the GetFormats method to retrieve an array of all the formats in which the data is available. Set the autoConvert parameter to false to get only the formats in which the data is stored. To get all the formats in which the data is available, set autoConvert to true, or do not use this parameter.
        /// *Call the GetDataPresent method to determine whether stored data is available in a certain format. If you do not want stored data to be converted to the specified format, set the autoConvert parameter to false.
        /// @remarks See the DataObject class for an implementation of this interface. See the DataFormats class for the predefined Clipboard data formats.
        class system_windows_forms_export_ IDataObject interface_ {
        public:
          /// @brief Retrieves the data associated with the specified data format.
          /// @param format The format of the data to retrieve. See DataFormats for predefined formats.
          /// @return object The data associated with the specified format, or null.
          /// @remarks If this method cannot find data in the specified format, it attempts to convert the data to the format. If the data cannot be converted to the specified format, this method returns null.
          /// @remarks To determine whether data is associated with, or can be converted to, a format, call GetDataPresent before calling GetData. Call GetFormats for a list of valid formats for the data stored in this instance.
          /// @note Data can be converted to another format if it was stored specifying that conversion is allowed, and if the requested format is compatible with the stored format. For example, data stored as Unicode can be converted to text.
          /// @remarks For an implementation of this method, see DataObject;;GetData.
          /// @par Examples
          /// This example uses the DataObject class, which implements IDataObject, to demonstrate the use of the GetData method. The method is used to retrieve the data stored in myDataObject, which is associated with the Text format. The example assumes that you have already created a Form named Form1 and a TextBox named textBox1.
          /// @code
          /// void GetData1() {
          ///   // Creates a new data object using a string and the text format.
          ///   string myString = "My text string";
          ///   DataObject myDataObject(DataFormats::Text, myString);
          ///
          ///   // Displays the string in a text box.
          ///   textBox1.Text = myDataObject.GetData(DataFormats::Text)->ToString();
          /// }
          /// @endcode
          virtual $<object> GetData(const string& format) const = 0;

          /// @brief Retrieves the data associated with the specified data format, using a Boolean to determine whether to convert the data to the format.
          /// @param format The format of the data to retrieve. See DataFormats for predefined formats.
          /// @param autoConvert true to convert the data to the specified format; otherwise, false.
          /// @return The data associated with the specified format, or null.
          /// @remarks If the autoConvert parameter is true and this method cannot find data in the specified format, it attempts to convert the data to the format. If the data cannot be converted to the specified format, or if the data was stored with the autoConvert parameter set to false, this method returns null.
          /// @remarks If the autoConvert parameter is false, this method returns data in the specified format, or null if no data in this format can be found.
          /// @remarks To determine whether data is associated with, or can be converted to, a format, call GetDataPresent before calling GetData. Call GetFormats for a list of valid formats for the data stored in this instance.
          /// @note Data can be converted to another format if it was stored specifying that conversion is allowed, and if the requested format is compatible with the stored format. For example, data stored as Unicode can be converted to text.
          /// @remarks For an implementation of this method, see DataObject.GetData.
          /// @par Examples
          /// This example uses the DataObject class, which implements IDataObject, to demonstrate the use of the GetData method. The example retrieves the data stored in a DataObject, using the autoConvert parameter to specify whether or not to convert the data format. First, myDataObject is created with text data. Then the example tries twice to retrieve the data. In the first trial, it specifies its format as a string and sets the autoConvert parameter to false. This trial fails, and the result is displayed in a message box labeled "Message #1." In the second trial, the example retrieves the same data with the autoConvert parameter set to true. This trial succeeds, and the result is displayed in a message box labeled "Message #2." The example assumes that you have created a Form named Form1.
          /// @code
          /// void GetData3() {
          ///   // Creates a new data object using a text string.
          ///   string myString = "Hello World!";
          ///   DataObject myDataObject(DataFormats.Text, myString);
          ///
          ///   // Displays the string with autoConvert equal to false.
          ///   if (myDataObject.GetData("System.String", false) != null) {
          ///     // Displays the string in a message box.
          ///     MessageBox::Show(myDataObject.GetData("System.String", false)->ToString() + ".", "Message #1");
          ///   } else
          ///     // Displays a not found message in a message box.
          ///     MessageBox::Show("Could not find data of the specified format.", "Message #1");
          ///
          ///   // Displays the string in a text box with autoConvert equal to true.
          ///   string myData = "The data is "_s + myDataObject.GetData("System.String", true)->ToString() + "."_s;
          ///   MessageBox::Show(myData,"Message #2");
          /// }
          /// @endcode
          virtual $<object> GetData(const string& format, bool autoConvert) const = 0;

          ///
          template<typename T>
          $<object> GetData() const {return null;}

          virtual bool GetDataPresent(const string& format) const = 0;

          virtual bool GetDataPresent(const string& format, bool autoConvert) const = 0;

          template<typename T>
          bool GetDataPresent() const {return false;}

          virtual Array<string> GetFormats() const = 0;

          virtual Array<string> GetFormats(bool autoConvert) const = 0;
        };
      }
    }
  }
}
