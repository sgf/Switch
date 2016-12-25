#include "TestUtils.h"
#include <Pcf/System/Net/Sockets/TcpListener.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/System/IO/StreamWriter.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::Threading;
using namespace System::IO;
using namespace TUnit;

namespace {

class TcpListener : public testing::Test {
public :
  void SetUp() {
    mLastException = Sp<Exception>::Null();
  }

  void TearDown() {
    if (!mLastException.IsNull())
      mLastException.Reset();
  }

protected:

  static void ServerThreadReceive(Object& _data) {
    // Buffer for reading data 
    byte tableau[128] = {0};
    EventWaitHandle EventWaitServeurStart = EventWaitHandle::OpenExisting("ServerEvent");
    try {
      Sockets::TcpListener& server = as<Sockets::TcpListener>(_data);
      // Start listening for client requests.
      server.Start(1);
      // Thread started
      EventWaitServeurStart.Set();
      bool run= true;
      // Enter the listening loop.
      while ( run ) {
        // Waiting for a connection... 
        // Perform a blocking call to accept requests. 
        // You could also user server.AcceptSocket() here.
        Sp<Sockets::TcpClient> tcpclient = server.AcceptTcpClient();

        // Connected
        // Get a stream Object* for reading and writing
        Sp<Sockets::NetworkStream> pstream = tcpclient->GetStream();

        // Loop to receive all the data sent by the client. 
        int32 i=0;
        bool runRead = true;
        while (runRead) {
          i = pstream->Read( tableau,128, 0, 128 );
          mDataLength += i;
          if (i==0)
            runRead=false;
        }
        // Shutdown and end connection
        tcpclient->Close();
        run = false;
      }

      server.Stop();
      for (int32 index = 0; index < mDataLength; index++)
        mResponse += Char(Convert::ToChar(Byte(tableau[index]))).ToString();
    } catch (Sockets::SocketException& e) {
      mLastException = Sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(e);
    }
    catch (ObjectClosedException& e) {
      mLastException = Sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(e);
    } catch (Exception& e)  {
      Console::WriteLine(e.Message());
    }
  }

  static void ServerThreadReceiveWithStream(Object& _data) {
    try {
      Sockets::TcpListener& server = as<Sockets::TcpListener>(_data);
      EventWaitHandle EventWaitServeurStart = EventWaitHandle::OpenExisting("ServerEvent");
      // Start listening for client requests.
      server.Start(1);
      // Thread started
      EventWaitServeurStart.Set();
      bool run= true;
      // Enter the listening loop.
      while ( run ) {
        // Waiting for a connection... 
        // Perform a blocking call to accept requests. 
        // You could also user server.AcceptSocket() here.
        Sp<Sockets::TcpClient> tcpclient = server.AcceptTcpClient();
        Sp<Stream> pstream = tcpclient->GetStream().ChangeType<Stream>(); // class Networkstream
        StreamReader serverStreamReader(pstream);
        mResponse = serverStreamReader.ReadLine(); 
        tcpclient->Close();
        run = false;
      }
      server.Stop();
    } catch (Sockets::SocketException& e) {
      mLastException = Sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(e);
      Console::WriteLine(e.Message());
    } catch (ObjectClosedException& e) {
      mLastException = Sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(e);
      Console::WriteLine(e.Message());
    } catch (Exception& e) {
      Console::WriteLine(e.Message());
    }
  }

  static void ServerThreadWithNoAction(Object& _data) {
    try {
      Sockets::TcpListener& server = as<Sockets::TcpListener>(_data);
      EventWaitHandle EventWaitServeurStart = EventWaitHandle::OpenExisting("ServerEvent");
      // Start listening for client requests.
      server.Start(1);
      // Thread started
      EventWaitServeurStart.Set();
      bool run= true;
      // Enter the listening loop.
      while ( run ) {
        // Waiting for a connection... 
        // Perform a blocking call to accept requests. 
        // You could also user server.AcceptSocket() here.
        Sp<Sockets::TcpClient> tcpclient = server.AcceptTcpClient();
        tcpclient->Close();
        run = false;
      }
      server.Stop();
    } catch (Sockets::SocketException& e) {
      mLastException = Sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(e);
      Console::WriteLine(e.Message());
    } catch (ObjectClosedException& e) {
      mLastException = Sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(e);
      Console::WriteLine(e.Message());
    } catch (Exception& e) {
      Console::WriteLine(e.Message());
    }
  }

  static void ServerThreadWithWrite(Object& _data) {
    try {
      Sockets::TcpListener& server = as<Sockets::TcpListener>(_data);
      EventWaitHandle EventWaitServeurStart = EventWaitHandle::OpenExisting("ServerEvent");
      // Start listening for client requests.
      server.Start(1);
      // Thread started
      EventWaitServeurStart.Set();
      bool run= true;
      // Enter the listening loop.
      while ( run ) {
        // Waiting for a connection... 
        // Perform a blocking call to accept requests. 
        // You could also user server.AcceptSocket() here.
        Sp<Sockets::TcpClient> tcpclient = server.AcceptTcpClient();
        Sp<Stream> pstream = tcpclient->GetStream().ChangeType<Stream>(); // class Networkstream
        StreamWriter serverStreamWriter(pstream);
        serverStreamWriter.WriteLine(string("Hein? Papuche?! Makemana papuche? - Na, na, na, na, na, na... Papuuuuuche! - Ahhhhh Papuche!")); 
        tcpclient->Close();
        run = false;
      }
      server.Stop();
    } catch (Sockets::SocketException& e) {
      mLastException = Sp<Exception>::Create<Sockets::SocketException, Sockets::SocketException>(e);
      Console::WriteLine(e.Message());
    } catch (ObjectClosedException& e) {
      mLastException = Sp<Exception>::Create<ObjectClosedException, ObjectClosedException>(e);
      Console::WriteLine(e.Message());
    } catch (Exception& e) {
      Console::WriteLine(e.Message());
    }
  }

  static int32 mDataLength;
  static string mResponse;
  static Sp<Exception> mLastException;
  static int32 mPort;
};

int32 TcpListener::mDataLength = 0;
string TcpListener::mResponse = "";
Sp<Exception> TcpListener::mLastException = Sp<Exception>::Null();
int32 TcpListener::mPort = 51000;

#if 0
TEST_F(TcpListener,  ClientServer) {
  mResponse = string::Empty;
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any(),mPort); 
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread(ServerThreadReceive);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> client = new Sockets::TcpClient();
  byte data[128] = "Hein? Papuche?! Makemana papuche? - Na, na, na, na, na, na... Papuuuuuche! - Ahhhhh Papuche!\r\n";
  client->Connect(string("localhost"),mPort);
  Sp<Sockets::NetworkStream>  netStream = client->GetStream(); 
  netStream->Write(data,128, 0, 128); 
  client->Close();
  // Blocks the calling thread until end of thread
  receivingThread.Join();
  string sendtxt;
  for (int32 index = 0; index < 128; index++)
    sendtxt += Char(Convert::ToChar(Byte(data[index]))).ToString();

  EXPECT_EQ(mResponse.Length(),sendtxt.Length());
  EXPECT_EQ(sendtxt,mResponse);
  EXPECT_TRUE(mLastException.IsNull());
}

TEST_F(TcpListener,  ClientServerWithStream) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any(),++mPort); 
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread(ServerThreadReceiveWithStream);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> client = new Sockets::TcpClient();
  string data("Hein? Papuche?! Makemana papuche? - Na, na, na, na, na, na... Papuuuuuche! - Ahhhhh Papuche!");
  client->Connect(string("localhost"),mPort);
  Sp<Stream>  netStream = client->GetStream().ChangeType<Stream>(); // class Networkstream
  StreamWriter clientStreamWriter(netStream);
  clientStreamWriter.WriteLine(data);
  clientStreamWriter.Flush();
  client->Close();
  // Blocks the calling thread until end of thread
  receivingThread.Join();
  EXPECT_EQ(mResponse.Length(),data.Length());
  EXPECT_EQ(data,mResponse);
  EXPECT_TRUE(mLastException.IsNull());
}
#endif

TEST_F(TcpListener, ConnectWithHostnameAndPortAfterCreation) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> tcpClient = new Sockets::TcpClient();
  tcpClient->Connect(string("localhost"),mPort);
  receivingThread.Join();
}

TEST_F(TcpListener, GetStreamWithSP) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> tcpClient = new Sockets::TcpClient();
  tcpClient->Connect(string("localhost"),mPort);
  tcpClient->GetStream();
  receivingThread.Join();
}

TEST_F(TcpListener, GetStream) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort); 
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sockets::TcpClient tcpclient;
  tcpclient.Connect(string("localhost"),mPort);
  tcpclient.GetStream();
  receivingThread.Join();
}

TEST_F(TcpListener, Close) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sockets::TcpClient tcpclient;
  tcpclient.Connect(string("localhost"),mPort);
  Sp<Sockets::NetworkStream> clientstream = tcpclient.GetStream();
  clientstream->Close();
  tcpclient.Close();
  receivingThread.Join();
}

TEST_F(TcpListener, CloseStream) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sockets::TcpClient tcpclient;
  tcpclient.Connect(string("localhost"),mPort);
  Sp<Sockets::NetworkStream> clientstream = tcpclient.GetStream();
  tcpclient.Close();
  clientstream->Close();
  receivingThread.Join();
}

#if 0
TEST_F(TcpListener, StopWithoutConnect) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread(ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  tcpListener->Stop();
  receivingThread.Join();
}
#endif

TEST_F(TcpListener, ConnectWithIPEndPointAfterCreation) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> tcpClient   = new Sockets::TcpClient();
  Sp<IPEndPoint> ipEndPoint = new IPEndPoint(IPAddress::Loopback, mPort);
  ASSERT_FALSE(ipEndPoint.IsNull());
  tcpClient->Connect(ipEndPoint); 
  receivingThread.Join();
}

TEST_F(TcpListener, ConnectWithIPAddressAndPortAfterCreation) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> tcpClient = new Sockets::TcpClient();
  Sp<IPEndPoint> ipEndPoint = new IPEndPoint(IPAddress::Loopback, mPort);
  ASSERT_FALSE(ipEndPoint.IsNull());
  tcpClient->Connect(ipEndPoint);
  receivingThread.Join();
}

TEST_F(TcpListener, ConnectWithNoWrite) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithWrite);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> tcpClient = new Sockets::TcpClient();
  Sp<IPEndPoint> ipEndPoint = new IPEndPoint(IPAddress::Loopback, mPort);
  ASSERT_FALSE(ipEndPoint.IsNull());
  tcpClient->Connect(ipEndPoint);
  Sp<Stream> netStream = tcpClient->GetStream().ChangeType<Stream>();
  StreamReader clientStreamReader(netStream);
  string txt = clientStreamReader.ReadLine();
  receivingThread.Join();
}

TEST_F(TcpListener, ConnectWithNoWriteAction) {
  Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Any,++mPort);
  EventWaitHandle EventWaitServeurStart(false, EventResetMode::AutoReset, "ServerEvent");
  Thread receivingThread((ParameterizedThreadStart)ServerThreadWithNoAction);
  receivingThread.Start(tcpListener.ToObject());
  EventWaitServeurStart.WaitOne();
  Sp<Sockets::TcpClient> tcpClient = new Sockets::TcpClient();
  Sp<IPEndPoint> ipEndPoint = new IPEndPoint(IPAddress::Loopback, mPort);
  ASSERT_FALSE(ipEndPoint.IsNull());
  tcpClient->Connect(ipEndPoint);
  Sp<Stream> netStream = tcpClient->GetStream().ChangeType<Stream>();
  StreamReader clientStreamReader(netStream);
  string txt = clientStreamReader.ReadLine();
  receivingThread.Join();
}

#if 0
TEST_F(TcpListener, DefaultConstructorIPEndPoint) {
	Sp<IPEndPoint> endPoint = new IPEndPoint(IPAddress::Loopback, 51000);
  ASSERT_FALSE(endPoint.IsNull());
	Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(endPoint); 
  ASSERT_FALSE(tcpListener.IsNull());
	tcpListener->Start();
	tcpListener->Stop();
}

TEST_F(TcpListener, DefaultConstructorIPAddressAndport) {
	Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Loopback,51000);
  ASSERT_FALSE(tcpListener.IsNull());
	tcpListener->Start();
	tcpListener->Stop();
}
#endif

TEST_F(TcpListener, GetServer) {
	Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Loopback,51000); 
  ASSERT_FALSE(tcpListener.IsNull());
	Sp<Sockets::Socket> socket1 = tcpListener->GetServer();
  ASSERT_FALSE(socket1.IsNull());
	const Sp<Sockets::Socket> socket2 = tcpListener->GetServer();
  ASSERT_FALSE(socket2.IsNull());
}

// TODO __APPLE__
TEST_F(TcpListener, DISABLED_GetExclusiveAddressUse) {
	Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Loopback,51000);
  ASSERT_FALSE(tcpListener.IsNull());
	EXPECT_EQ(tcpListener->GetExclusiveAddressUse(),false);
}

// TODO __APPLE__
TEST_F(TcpListener, DISABLED_SetGetExclusiveAddressUse) {
	Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Loopback,51000);
  ASSERT_FALSE(tcpListener.IsNull());
	tcpListener->SetExclusiveAddressUse(true);
	EXPECT_EQ(tcpListener->GetExclusiveAddressUse(),true);
}

TEST_F(TcpListener, GetLocalEndPoint) {
	Sp<Sockets::TcpListener> tcpListener = new Sockets::TcpListener(IPAddress::Loopback,51000); 
  ASSERT_FALSE(tcpListener.IsNull());
	Sp<EndPoint> endPoint1 = tcpListener->GetLocalEndPoint();
  ASSERT_FALSE(endPoint1.IsNull());
	const Sp<EndPoint> endPoint2 = tcpListener->GetLocalEndPoint();
  ASSERT_FALSE(endPoint2.IsNull());
}

}
