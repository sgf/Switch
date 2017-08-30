/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>

namespace Switch {
  namespace System {
    namespace ComponentModel {
      class sw_public CancelEventArgs : public EventArgs {
      public:
        CancelEventArgs() {}
        CancelEventArgs(const CancelEventArgs& ce) : cancel(ce.cancel) {}
        CancelEventArgs(bool cancel) : cancel(cancel) {}

        Property<bool> Cancel {
          sw_get {return cancel;},
          sw_set {this->cancel = value;}
        };
 
      private:
        bool cancel = false;
      };
    }
  }
}