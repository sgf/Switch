/// @file
/// @brief Contains Switch::System::Windows::Forms::PaintEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "PaintEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @par Library
        /// Switch.System.Windows.Forms
        using PaintEventHandler = GenericEventHandler<PaintEventArgs&>;
      }
    }
  }
}
