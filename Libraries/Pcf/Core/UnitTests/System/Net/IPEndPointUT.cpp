#include <Pcf/System/Net/IPEndPoint.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace TUnit;

namespace {
  
  TEST(IPEndPoint, Constructor) {
    EXPECT_EQ(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).ToString(), "172.16.10.30:11000");
    EXPECT_THROW(IPEndPoint(IPAddress(172, 16, 10, 30), IPEndPoint::MinPort()-1), ArgumentOutOfRangeException);
    EXPECT_THROW(IPEndPoint(IPAddress(172, 16, 10, 30), IPEndPoint::MaxPort()+1), ArgumentOutOfRangeException);
  }
  
  TEST(IPEndPoint, MaxMinPort) {
    EXPECT_EQ(IPEndPoint::MinPort(), 0x0000);
    EXPECT_EQ(IPEndPoint::MaxPort(), 0xFFFF);
  }
  
  TEST(IPEndPoint, GetAddress) {
    EXPECT_EQ(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).Address().ToString(), "172.16.10.30");
    EXPECT_EQ(IPEndPoint(IPAddress::IPv6Loopback, 8080).Address().ToString(), "[0:0:0:0:0:0:0:1]");
  }
  
  TEST(IPEndPoint, GetAddressFamily) {
    EXPECT_EQ(Enum<Sockets::AddressFamily>::ToString(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).AddressFamily), "InterNetwork");
    EXPECT_EQ(Enum<Sockets::AddressFamily>::ToString(IPEndPoint(IPAddress::IPv6Loopback, 8080).AddressFamily), "InterNetworkV6");
  }
  
  TEST(IPEndPoint, GetPort) {
    EXPECT_EQ(IPEndPoint(IPAddress(172, 16, 10, 30), 11000).Port(), 11000);
    EXPECT_EQ(IPEndPoint(IPAddress::IPv6Loopback, 8080).Port(), 8080);
  }
  
  TEST(IPEndPoint, Serialize) {
    SocketAddress socketAddress1 = IPEndPoint(IPAddress(172, 16, 10, 30), 11000).Serialize();
    Byte data0 = socketAddress1[0];
    Byte data1 = socketAddress1[1];
    EXPECT_EQ("InterNetwork:16:{42, 248, 172, 16, 10, 30, 0, 0, 0, 0, 0, 0, 0, 0}", socketAddress1.ToString());
    SocketAddress socketAddress2 = IPEndPoint(IPAddress::IPv6Loopback, 8080).Serialize();
    EXPECT_EQ("InterNetworkV6:28:{31, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}", socketAddress2.ToString());
  }
  
  TEST(IPEndPoint, Create) {
    byte buffer[16] = {2, 0, 42, 248, 172, 16, 10, 30, 0, 0, 0, 0, 0, 0, 0, 0};
    SocketAddress address(buffer, 16);
    
    IPEndPoint dummyEndPoint(0, 0);
    SharedPointer<IPEndPoint> endPoint = static_cast<IPEndPoint*>(dummyEndPoint.Create(address).Release());
    ASSERT_EQ(IPAddress(172, 16, 10, 30), endPoint->Address());
    ASSERT_EQ(11000, endPoint->Port());
  }
  
  TEST(IPEndPoint, SetAddress) {
    IPEndPoint IPEndPoint(IPAddress(172, 16, 10, 30), 11000);
    EXPECT_EQ(IPEndPoint.Address().ToString(), "172.16.10.30");
    IPEndPoint.Address = IPAddress(192, 168, 0, 1);
    EXPECT_EQ(IPEndPoint.Address().ToString(), "192.168.0.1");
  }
  
  TEST(IPEndPoint, SetPort) {
    IPEndPoint IPEndPoint(IPAddress(172, 16, 10, 30), 11000);
    EXPECT_EQ(IPEndPoint.Port(), 11000);
    IPEndPoint.Port(8080);
    EXPECT_EQ(IPEndPoint.Port(), 8080);
    EXPECT_THROW(IPEndPoint.Port(IPEndPoint::MinPort()-1), ArgumentOutOfRangeException);
    EXPECT_THROW(IPEndPoint.Port(IPEndPoint::MaxPort()+1), ArgumentOutOfRangeException);
  }
  
  TEST(IPEndPoint, OperatorEqual) {
    IPEndPoint endPoint(IPAddress(127, 0, 0, 1), 12365);
    IPEndPoint copy = endPoint;
    ASSERT_EQ(endPoint.ToString(), copy.ToString());
  }
  
  TEST(IPEndPoint, OperatorEqualTest_Create) {
    IPEndPoint endPoint(IPAddress(127, 0, 0, 1), 12365);
    SocketAddress sockaddr = endPoint.Serialize();
    UniquePointer<EndPoint> created = endPoint.Create(sockaddr);
    ASSERT_EQ(endPoint.ToString(), created->ToString());
  }
}
