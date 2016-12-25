/// @file
/// @brief Contains Pcf::System::Net::Dns class.
#pragma once

#include "../../Static.h"
#include "../../Types.h"
#include "../Object.h"
#include "../String.h"
#include "IPAddress.h"
#include "IPHostEntry.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Provides simple domain name resolution functionality.
      class Dns pcf_static {
      public:
        /// @brief Returns the Internet Protocol (IP) addresses for the specified host.
        /// @param hostNameOrAddress The host name or IP address to resolve.
        /// @return Array<IPAddress> An array of type IPAddress that holds the IP addresses for the host that is specified by the hostNameOrAddress parameter..
        static Array<IPAddress> GetHostAddresses(const String& hostNameOrAddress);

        /// @brief Resolves an IP address to an IPHostEntry instance.
        /// @param address An IP address.
        /// @return IPHostEntry An IPHostEntry instance that contains address information about the host specified in address.
        static IPHostEntry GetHostEntry(const IPAddress& address);

        /// @brief Resolves a host name or IP address to an IPHostEntry instance.
        /// @param hostNameOrAddress The host name or IP address to resolve.
        /// @return IPHostEntry An IPHostEntry instance that contains address information about the host specified in hostNameOrAddress.
        static IPHostEntry GetHostEntry(const String& hostNameOrAddress);

        /// @brief Gets the host name of the local computer.
        /// @return string A string that contains the DNS host name of the local computer.
        static String GetHostName();
     };
    }
  }
}

using namespace Pcf;
