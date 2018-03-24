/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies constants indicating which elements of the Help file to display.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks This enumeration is used by the Help and HelpProvider classes to provide access to specific elements of a Help file. For example, when used with the HelpProvider component that provides F1 Help, the TopicId or Topic value could be specified to open Help to a context-specific topic.
        /// @par Examples
        /// The following code example displays a form with three buttons that can be used to interact with the mspaint.chm Help file. The Show Help Index button displays the Index tab for the Help file. The Show Help button displays content in the Help file based on the value selected in the Help Navigator list. The Show Keyword button displays content in the Help file based on the keyword specified in the Keyword text box.<br><br>
        /// For example, to show the Ovals Help page by the index value, select the HelpNavigator.KeywordIndex value in the Help Navigator drop-down list, type ovals in the Parameter text box, and then click the Show Help button. To show the "To paint with a brush" Help topic by the keyword, type mspaint.chm::/paint_brush.htm in the Keyword text box, and then click the Show Keyword button.<br><br>
        /// The example uses the ShowHelp method to display the different Help tabs and Help topics, and the ShowHelpIndex method to display the Help index.
        /// @include ShowHelp.cpp
        enum class HelpNavigator {
          /// @brief The Help file opens to a topic indicated by a numeric topic identifier.
          TopicId = -2147483641,
          /// @brief The Help file opens to the topic with the specified index entry, if one exists; otherwise, the index entry closest to the specified keyword is displayed.
          KeywordIndex = -2147483642,
          /// @brief The Help file opens to the index entry for the first letter of a specified topic.
          AssociateIndex = -2147483643,
          /// @brief The Help file opens to the search page.
          Find = -2147483644,
          /// @brief The Help file opens to the index.
          Index = -2147483645,
          /// @brief The Help file opens to the table of contents.
          TableOfContents = -2147483646,
          /// @brief The Help file opens to a specified topic, if the topic exists.
          Topic = -2147483647,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::HelpNavigator> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::HelpNavigator, string>& values, bool& flags) {
    values[System::Windows::Forms::HelpNavigator::TopicId] = "TopicId";
    values[System::Windows::Forms::HelpNavigator::KeywordIndex] = "KeywordIndex";
    values[System::Windows::Forms::HelpNavigator::AssociateIndex] = "AssociateIndex";
    values[System::Windows::Forms::HelpNavigator::Find] = "Find";
    values[System::Windows::Forms::HelpNavigator::Index] = "Index";
    values[System::Windows::Forms::HelpNavigator::TableOfContents] = "TableOfContents";
    values[System::Windows::Forms::HelpNavigator::Topic] = "Topic";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
