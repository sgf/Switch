/// @file
/// @brief Contains include files of System library.
#pragma once

#include <Switch/Switch.Core>
#include "System/Collections/Concurrent/ConcurrentBag.hpp"
#include "System/Collections/Specialized/StringCollection.hpp"
#include "System/Collections/Specialized/StringDictionary.hpp"
#include "System/Collections/Specialized/StringEnumerator.hpp"
#include "System/Diagnostics/ConsoleTraceListener.hpp"
#include "System/Diagnostics/Debug.hpp"
#include "System/Diagnostics/DefaultTraceListener.hpp"
#include "System/Diagnostics/NullTraceListener.hpp"
#include "System/Diagnostics/Process.hpp"
#include "System/Diagnostics/ProcessStartInfo.hpp"
#include "System/Diagnostics/ProcessWindowStyle.hpp"
#include "System/Diagnostics/Stopwatch.hpp"
#include "System/Diagnostics/TextWriterTraceListener.hpp"
#include "System/Diagnostics/Trace.hpp"
#include "System/Diagnostics/TraceEventCache.hpp"
#include "System/Diagnostics/TraceEventType.hpp"
#include "System/Diagnostics/TraceFilter.hpp"
#include "System/Diagnostics/TraceListener.hpp"
#include "System/Diagnostics/TraceListenerCollection.hpp"
#include "System/Diagnostics/TraceOptions.hpp"
#include "System/Diagnostics/TraceSource.hpp"
#include "System/IO/Ports/Handshake.hpp"
#include "System/IO/Ports/Parity.hpp"
#include "System/IO/Ports/SerialData.hpp"
#include "System/IO/Ports/SerialDataReceivedEventArgs.hpp"
#include "System/IO/Ports/SerialDataReceivedEventHandler.hpp"
#include "System/IO/Ports/SerialError.hpp"
#include "System/IO/Ports/SerialErrorReceivedEventArgs.hpp"
#include "System/IO/Ports/SerialErrorReceivedEventHandler.hpp"
#include "System/IO/Ports/SerialPinChange.hpp"
#include "System/IO/Ports/SerialPinChangedEventArgs.hpp"
#include "System/IO/Ports/SerialPinChangedEventHandler.hpp"
#include "System/IO/Ports/SerialPort.hpp"
#include "System/IO/Ports/StopBits.hpp"
#include "System/IO/ErrorEventArgs.hpp"
#include "System/IO/FileSystemEventArgs.hpp"
#include "System/Media/SystemSound.hpp"
#include "System/Media/SystemSounds.hpp"
#include "System/Net/Sockets/AddressFamily.hpp"
#include "System/Net/Sockets/IOControlCode.hpp"
#include "System/Net/Sockets/IPv6MulticastOption.hpp"
#include "System/Net/Sockets/LingerOption.hpp"
#include "System/Net/Sockets/MulticastOption.hpp"
#include "System/Net/Sockets/NetworkStream.hpp"
#include "System/Net/Sockets/ProtocolFamily.hpp"
#include "System/Net/Sockets/ProtocolType.hpp"
#include "System/Net/Sockets/SelectMode.hpp"
#include "System/Net/Sockets/Socket.hpp"
#include "System/Net/Sockets/SocketError.hpp"
#include "System/Net/Sockets/SocketException.hpp"
#include "System/Net/Sockets/SocketFlags.hpp"
#include "System/Net/Sockets/SocketInformation.hpp"
#include "System/Net/Sockets/SocketInformationOptions.hpp"
#include "System/Net/Sockets/SocketOptionLevel.hpp"
#include "System/Net/Sockets/SocketOptionName.hpp"
#include "System/Net/Sockets/SocketShutdown.hpp"
#include "System/Net/Sockets/SocketType.hpp"
#include "System/Net/Sockets/TcpClient.hpp"
#include "System/Net/Sockets/TcpListener.hpp"
#include "System/Net/Sockets/UdpClient.hpp"
#include "System/Net/WebSockets/ClientWebSocket.hpp"
#include "System/Net/WebSockets/WebSocket.hpp"
#include "System/Net/WebSockets/WebSocketCloseStatus.hpp"
#include "System/Net/WebSockets/WebSocketMessageType.hpp"
#include "System/Net/WebSockets/WebSocketState.hpp"
#include "System/Net/CookieException.hpp"
#include "System/Net/Dns.hpp"
#include "System/Net/DnsEndPoint.hpp"
#include "System/Net/EndPoint.hpp"
#include "System/Net/FtpStatusCode.hpp"
#include "System/Net/FtpWebRequest.hpp"
#include "System/Net/FtpWebResponse.hpp"
#include "System/Net/HttpListenerException.hpp"
#include "System/Net/HttpStatusCode.hpp"
#include "System/Net/HttpWebRequest.hpp"
#include "System/Net/HttpWebResponse.hpp"
#include "System/Net/IPAddress.hpp"
#include "System/Net/IPEndPoint.hpp"
#include "System/Net/IPHostEntry.hpp"
#include "System/Net/NetworkCredential.hpp"
#include "System/Net/ProtocolViolationException.hpp"
#include "System/Net/SocketAddress.hpp"
#include "System/Net/WebException.hpp"
#include "System/Net/WebRequest.hpp"
#include "System/Net/WebRequestMethods.hpp"
#include "System/Net/WebResponse.hpp"
#include "System/Threading/Barrier.hpp"
#include "System/Threading/BarrierPostPhaseException.hpp"
#include "System/Threading/Semaphore.hpp"
#include "System/Threading/SemaphoreFullException.hpp"
#include "System/Uri.hpp"
#include "System/UriComponents.hpp"
#include "System/UriFormat.hpp"
#include "System/UriFormatException.hpp"
#include "System/UriKind.hpp"
#include "System/UriHostNameType.hpp"
#include "System/UriPartial.hpp"
#include "System/UriTemplateMatchException.hpp"
