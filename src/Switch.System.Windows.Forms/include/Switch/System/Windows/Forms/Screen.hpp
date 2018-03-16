/// @file
/// @brief Contains Switch::System::Windows::Forms::Screen class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/Property.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Drawing/Rectangle.hpp>

/// @cond
namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        class Screen;
      }
    }
  }
}

struct __screens__ static_ {
  static Switch::System::Array<Switch::System::Windows::Forms::Screen> __get_screens__();
};
/// @endcond

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @par Library
        /// Switch.System.Windows.Forms
        class Screen : public object {
        public:
          /// @cond
          Screen() {}
          Screen(const Screen& screen) : bitsPerPixel(screen.bitsPerPixel), bounds(screen.bounds), deviceName(screen.deviceName), primary(screen.primary), workingArea(screen.workingArea) {}
          Screen& operator=(const Screen& screen) = default;
          /// @endcond

          static property_<System::Array<Screen>, readonly_> AllScreens;

          property_<int32, readonly_> BitsPerPixel {
            get_ {return this->bitsPerPixel;}
          };

          property_<const System::Drawing::Rectangle&, readonly_> Bounds {
            get_->const System::Drawing::Rectangle& {return this->bounds;}
          };

          property_<const string&, readonly_> DeviceName {
            get_->const string& {return this->deviceName;}
          };

          property_<bool, readonly_> Primary {
            get_ {return this->primary;}
          };

          property_<const System::Drawing::Rectangle&, readonly_> WorkingArea {
            get_->const System::Drawing::Rectangle& {return this->workingArea;}
          };

        private:
          friend struct ::__screens__;
          int32 bitsPerPixel = 0;
          System::Drawing::Rectangle bounds;
          string deviceName;
          bool primary = false;
          System::Drawing::Rectangle workingArea;
        };
      }
    }
  }
}

using namespace Switch;

