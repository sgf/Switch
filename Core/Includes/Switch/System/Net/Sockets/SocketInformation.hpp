/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketInformation class.
#pragma once

#include "../../../Property.hpp"
#include "../../../Types.hpp"
#include "../../Array.hpp"
#include "../../Object.hpp"
#include "SocketInformationOptions.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Encapsulates the information that is necessary to duplicate a Socket.
        /// @remarks Socket::DuplicateAndClose creates a SocketInformation instance for use with the Socket::Socket(SocketInformation) constructor.
        class _public SocketInformation : public Object {
        public:
          /// @brief Create a new instance of SocketInformation class.
          SocketInformation() {}
          
          /// @cond
          SocketInformation(const SocketInformation&) = delete;
          SocketInformation& operator =(const SocketInformation&) = delete;
          /// @endcond

          /// @brief Gets or sets the options for a Socket.
          /// @param options A SocketInformationOptions instance.
          /// @return SocketInformationOptions A SocketInformationOptions instance.
          Property<const SocketInformationOptions&> Options {
            _get->const SocketInformationOptions& {return this->options;},
            _set {this->options = value;}
          };

          /// @brief Gets or sets the protocol information for a Socket.
          /// @param protocolInformation An array of type Byte.
          /// @return Array<Byte> An array of type Byte.
          Property<const Array<byte>&> ProtocolInformation {
            _get->const Array<byte>& {return this->protocolInfrmation;},
            _set {this->protocolInfrmation = value;}
          };

        private:
          /// @cond
          SocketInformationOptions options = SocketInformationOptions::None;
          Array<byte> protocolInfrmation;
          /// @endcond
        };
      }
    }
  }
}

using namespace Switch;
