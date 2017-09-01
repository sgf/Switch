#include "../../../../../Includes/Switch/System/NullReferenceException.hpp"
#include "../../../../../Includes/Switch/System/OutOfMemoryException.hpp"
#include "../../../../../Includes/Switch/System/StackOverflowException.hpp"
#include "../../../../../Includes/Switch/System/Net/Sockets/TcpClient.hpp"
#include "../../../../../Includes/Switch/System/Net/Dns.hpp"
#include "../../../../../Includes/Switch/System/Net/Sockets/SocketException.hpp"
#include "../../../../../Includes/Switch/System/Threading/ThreadInterruptedException.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

TcpClient::TcpClient(AddressFamily addressFamily) {
  if (addressFamily != AddressFamily::InterNetwork && addressFamily != AddressFamily::InterNetworkV6)
    throw ArgumentException(_current_information);
  this->data->clientSocket = Socket(addressFamily, SocketType::Stream, addressFamily == AddressFamily::InterNetworkV6 ? ProtocolType::IPv6 : ProtocolType::Tcp);
}

TcpClient::TcpClient(const IPEndPoint& endPoint) {
  this->data->clientSocket.Bind(endPoint);
}

TcpClient::TcpClient(const string& hostname, int32 port) {
  this->Connect(hostname, port);
}

TcpClient::TcpClient(const Socket& acceptedSocket) {
  this->data->clientSocket = acceptedSocket;
  this->data->active = true;
}

void TcpClient::Connect(const IPEndPoint& endPoint) {
  if (this->data->clientSocket.Connected)
    throw SocketException((int32)SocketError::IsConnected, _current_information);
  
  this->data->clientSocket.Connect(endPoint);
  this->data->active = true;
}

void TcpClient::Connect(const IPAddress& iPAddress, int32 port) {
  if (this->data->clientSocket.Connected)
    throw SocketException((int32)SocketError::IsConnected, _current_information);
  
  this->data->clientSocket.Connect(iPAddress, port);
  this->data->active = true;
}

void TcpClient::Connect(const string& hostname, int32 port) {
  if (this->data->clientSocket.Connected)
    throw SocketException((int32)SocketError::IsConnected, _current_information);
  
  this->data->clientSocket.Connect(Dns::GetHostAddresses(hostname), port);
  this->data->active = true;
}

void TcpClient::Close() {
  this->data->active=false;
  this->data->clientSocket = Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
  this->data->clientSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReuseAddress, true);
}

NetworkStream TcpClient::GetStream() {
  if (!this->data->clientSocket.Connected)
    throw SocketException((int32)SocketError::NotConnected, _current_information);
  
  return NetworkStream(this->data->clientSocket, true);
}
