/// @file
/// @brief Contains include files of Core library.
#pragma once

/// @defgroup Keywords Keywords
/// @brief Keywords are predefined, reserved identifiers that have special meanings to the compiler. They cannot be used as identifiers in your program unless they include @ as a prefix. For example, @@if is a valid identifier, but if is not because if is a keyword.

/// @defgroup Types Types
/// @brief Types definitions

#include "Microsoft/Win32/Registry.hpp"
#include "Microsoft/Win32/RegistryHive.hpp"
#include "Microsoft/Win32/RegistryKey.hpp"
#include "Microsoft/Win32/RegistryKeyPermissionCheck.hpp"
#include "Microsoft/Win32/RegistryOptions.hpp"
#include "Microsoft/Win32/RegistryValueKind.hpp"
#include "Microsoft/Win32/RegistryValueOptions.hpp"
#include "System/Collections/Concurrent/ConcurrentQueue.hpp"
#include "System/Collections/Concurrent/ConcurrentStack.hpp"
#include "System/Collections/Concurrent/IProducerConsumerCollection.hpp"
#include "System/Collections/Generic/Comparer.hpp"
#include "System/Collections/Generic/Dictionary.hpp"
#include "System/Collections/Generic/GenericException.hpp"
#include "System/Collections/Generic/ICollection.hpp"
#include "System/Collections/Generic/IComparer.hpp"
#include "System/Collections/Generic/IDictionary.hpp"
#include "System/Collections/Generic/IEnumerable.hpp"
#include "System/Collections/Generic/IEnumerator.hpp"
#include "System/Collections/Generic/IList.hpp"
#include "System/Collections/Generic/KeyValuePair.hpp"
#include "System/Collections/Generic/List.hpp"
#include "System/Collections/ObjectModel/Collection.hpp"
#include "System/Collections/ObjectModel/ReadOnlyCollection.hpp"
#include "System/Collections/ArrayList.hpp"
#include "System/Collections/BitArray.hpp"
#include "System/Collections/Comparer.hpp"
#include "System/Collections/DictionaryEntry.hpp"
#include "System/Collections/Hashtable.hpp"
#include "System/Collections/ICollection.hpp"
#include "System/Collections/IComparer.hpp"
#include "System/Collections/IDictionary.hpp"
#include "System/Collections/IEnumerable.hpp"
#include "System/Collections/IEnumerator.hpp"
#include "System/Collections/IList.hpp"
#include "System/Collections/Queue.hpp"
#include "System/Collections/Stack.hpp"
#include "System/Diagnostics/StackFrame.hpp"
#include "System/Diagnostics/StackTrace.hpp"
#include "System/Globalization/NumberStyles.hpp"
#include "System/IO/BinaryReader.hpp"
#include "System/IO/BinaryWriter.hpp"
#include "System/IO/Directory.hpp"
#include "System/IO/DirectoryInfo.hpp"
#include "System/IO/DirectoryNotFoundException.hpp"
#include "System/IO/DriveInfo.hpp"
#include "System/IO/DriveNotFoundException.hpp"
#include "System/IO/DriveType.hpp"
#include "System/IO/EndOfStreamException.hpp"
#include "System/IO/File.hpp"
#include "System/IO/FileAccess.hpp"
#include "System/IO/FileAttributes.hpp"
#include "System/IO/FileFormatException.hpp"
#include "System/IO/FileInfo.hpp"
#include "System/IO/FileLoadException.hpp"
#include "System/IO/FileMode.hpp"
#include "System/IO/FileNotFoundException.hpp"
#include "System/IO/FileShare.hpp"
#include "System/IO/FileStream.hpp"
#include "System/IO/FileSystemInfo.hpp"
#include "System/IO/IOException.hpp"
#include "System/IO/MemoryStream.hpp"
#include "System/IO/Path.hpp"
#include "System/IO/PathTooLongException.hpp"
#include "System/IO/SeekOrigin.hpp"
#include "System/IO/Stream.hpp"
#include "System/IO/StreamReader.hpp"
#include "System/IO/StreamWriter.hpp"
#include "System/IO/StringReader.hpp"
#include "System/IO/StringWriter.hpp"
#include "System/IO/TextReader.hpp"
#include "System/IO/TextWriter.hpp"
#include "System/Linq/Enumerable.hpp"
#include "System/Linq/Linq.hpp"
#include "System/Reflection/Assembly.hpp"
#include "System/Reflection/AssemblyCompanyAttribute.hpp"
#include "System/Reflection/AssemblyConfigurationAttribute.hpp"
#include "System/Reflection/AssemblyCopyrightAttribute.hpp"
#include "System/Reflection/AssemblyCultutreAttribute.hpp"
#include "System/Reflection/AssemblyDescriptionAttribute.hpp"
#include "System/Reflection/AssemblyGuidAttribute.hpp"
#include "System/Reflection/AssemblyIdentifierAttribute.hpp"
#include "System/Reflection/AssemblyProductAttribute.hpp"
#include "System/Reflection/AssemblyVersionAttribute.hpp"
#include "System/Reflection/AssemblyTitleAttribute.hpp"
#include "System/Reflection/AssemblyTrademarkAttribute.hpp"
#include "System/Runtime/CompilerServices/Caller.hpp"
#include "System/Runtime/Serialization/Formatter.hpp"
#include "System/Runtime/Serialization/ISerializable.hpp"
#include "System/Runtime/Serialization/IFormatter.hpp"
#include "System/Runtime/Serialization/SerializationException.hpp"
#include "System/Runtime/Serialization/SerializationEntry.hpp"
#include "System/Runtime/Serialization/SerializationInfo.hpp"
#include "System/Security/HostProtectionException.hpp"
#include "System/Security/SecureString.hpp"
#include "System/Security/SecurityException.hpp"
#include "System/Security/VerificationException.hpp"
#include "System/Security/XmlSyntaxException.hpp"
#include "System/Text/ANSIEncoding.hpp"
#include "System/Text/ASCIIEncoding.hpp"
#include "System/Text/Decoder.hpp"
#include "System/Text/Encoder.hpp"
#include "System/Text/Encoding.hpp"
#include "System/Text/StringBuilder.hpp"
#include "System/Text/UTF32Encoding.hpp"
#include "System/Text/UTF8Encoding.hpp"
#include "System/Text/UnicodeEncoding.hpp"
#include "System/Threading/Tasks/ITask.hpp"
#include "System/Threading/Tasks/Parallel.hpp"
#include "System/Threading/Tasks/Task.hpp"
#include "System/Threading/Tasks/TaskStatus.hpp"
#include "System/Threading/Tasks/TaskTResult.hpp"
#include "System/Threading/AbandonedMutexException.hpp"
#include "System/Threading/AutoResetEvent.hpp"
#include "System/Threading/EventResetMode.hpp"
#include "System/Threading/EventWaitHandle.hpp"
#include "System/Threading/Interlocked.hpp"
#include "System/Threading/LockRecursionException.hpp"
#include "System/Threading/ManualResetEvent.hpp"
#include "System/Threading/Monitor.hpp"
#include "System/Threading/Mutex.hpp"
#include "System/Threading/ParameterizedThreadStart.hpp"
#include "System/Threading/RegisteredWaitHandle.hpp"
#include "System/Threading/SpinLock.hpp"
#include "System/Threading/Thread.hpp"
#include "System/Threading/ThreadLocal.hpp"
#include "System/Threading/ThreadAbortException.hpp"
#include "System/Threading/ThreadInterruptedException.hpp"
#include "System/Threading/ThreadPool.hpp"
#include "System/Threading/ThreadPriority.hpp"
#include "System/Threading/ThreadStart.hpp"
#include "System/Threading/ThreadStartException.hpp"
#include "System/Threading/ThreadState.hpp"
#include "System/Threading/ThreadStateException.hpp"
#include "System/Threading/Timeout.hpp"
#include "System/Threading/Timer.hpp"
#include "System/Threading/TimerCallback.hpp"
#include "System/Threading/WaitCallback.hpp"
#include "System/Threading/WaitOrTimerCallback.hpp"
#include "System/Threading/WaitHandle.hpp"
#include "System/Threading/WaitHandleCannotBeOpenedException.hpp"
#include "System/AccessViolationException.hpp"
#include "System/Action.hpp"
#include "System/AggregateException.hpp"
#include "System/AppDomainUnloadedException.hpp"
#include "System/ArgumentException.hpp"
#include "System/ArgumentNullException.hpp"
#include "System/ArgumentOutOfRangeException.hpp"
#include "System/ArithmeticException.hpp"
#include "System/Array.hpp"
#include "System/ArraySegment.hpp"
#include "System/ArrayTypeMismatchException.hpp"
#include "System/AsyncCallback.hpp"
#include "System/Attribute.hpp"
#include "System/BadImageFormatException.hpp"
#include "System/BitConverter.hpp"
#include "System/Boolean.hpp"
#include "System/Buffer.hpp"
#include "System/Byte.hpp"
#include "System/CannotUnloadAppDomainException.hpp"
#include "System/Char.hpp"
#include "System/CharEnumerator.hpp"
#include "System/Comparison.hpp"
#include "System/Console.hpp"
#include "System/ConsoleColor.hpp"
#include "System/ConsoleKey.hpp"
#include "System/ConsoleKeyInfo.hpp"
#include "System/ConsoleModifiers.hpp"
#include "System/ContextMarshalException.hpp"
#include "System/Convert.hpp"
#include "System/Converter.hpp"
#include "System/DataMisalignedException.hpp"
#include "System/DateTime.hpp"
#include "System/DateTimeKind.hpp"
#include "System/DayOfWeek.hpp"
#include "System/Decimal.hpp"
#include "System/Delegate.hpp"
#include "System/DivideByZeroException.hpp"
#include "System/DllNotFoundException.hpp"
#include "System/Double.hpp"
#include "System/DuplicateWaitObjectException.hpp"
#include "System/Enum.hpp"
#include "System/Environment.hpp"
#include "System/EntryPointNotFoundException.hpp"
#include "System/EventArgs.hpp"
#include "System/EventHandler.hpp"
#include "System/ExecutionEngineException.hpp"
#include "System/Exception.hpp"
#include "System/FieldAccessException.hpp"
#include "System/FormatException.hpp"
#include "System/FormatProvider.hpp"
#include "System/Func.hpp"
#include "System/Guid.hpp"
#include "System/IAsyncResult.hpp"
#include "System/ICloneable.hpp"
#include "System/IComparable.hpp"
#include "System/IConvertible.hpp"
#include "System/ICustomFormatter.hpp"
#include "System/IFormatProvider.hpp"
#include "System/IFormattable.hpp"
#include "System/IndexOutOfRangeException.hpp"
#include "System/Int16.hpp"
#include "System/Int32.hpp"
#include "System/Int64.hpp"
#include "System/IntPtr.hpp"
#include "System/InsufficientExecutionStackException.hpp"
#include "System/InsufficientMemoryException.hpp"
#include "System/InvalidCastException.hpp"
#include "System/InvalidOperationException.hpp"
#include "System/InvalidProgramException.hpp"
#include "System/InvalidTimeZoneException.hpp"
#include "System/Math.hpp"
#include "System/MemberAccessException.hpp"
#include "System/MethodAccessException.hpp"
#include "System/MissingFieldException.hpp"
#include "System/MissingMemberException.hpp"
#include "System/MissingMethodException.hpp"
#include "System/MulticastNotSupportedException.hpp"
#include "System/NotFiniteNumberException.hpp"
#include "System/NotImplementedException.hpp"
#include "System/NotSupportedException.hpp"
#include "System/NullPointerException.hpp"
#include "System/NullReferenceException.hpp"
#include "System/Nullable.hpp"
#include "System/Object.hpp"
#include "System/ObjectDisposedException.hpp"
#include "System/OperatingSystem.hpp"
#include "System/OperationCanceledException.hpp"
#include "System/OutOfMemoryException.hpp"
#include "System/OverflowException.hpp"
#include "System/PlatformID.hpp"
#include "System/PlatformNotSupportedException.hpp"
#include "System/Predicate.hpp"
#include "System/Random.hpp"
#include "System/RankException.hpp"
#include "System/SByte.hpp"
#include "System/Single.hpp"
#include "System/StackOverflowException.hpp"
#include "System/String.hpp"
#include "System/StringSplitOptions.hpp"
#include "System/SystemException.hpp"
#include "System/TimeoutException.hpp"
#include "System/TimeSpan.hpp"
#include "System/TimeZoneInfo.hpp"
#include "System/TimeZoneNotFoundException.hpp"
#include "System/Tuple.hpp"
#include "System/Type.hpp"
#include "System/TypeAccessException.hpp"
#include "System/TypeCode.hpp"
#include "System/TypeInitializationException.hpp"
#include "System/TypeUnloadedException.hpp"
#include "System/UInt16.hpp"
#include "System/UInt32.hpp"
#include "System/UInt64.hpp"
#include "System/UIntPtr.hpp"
#include "System/UnauthorizedAccessException.hpp"
#include "System/ValueTuple.hpp"
#include "System/ValueType.hpp"
#include "System/Version.hpp"
#include "Allocator.hpp"
#include "Abstract.hpp"
#include "Any.hpp"
#include "As.hpp"
#include "Async.hpp"
#include "Await.hpp"
#include "Boxing.hpp"
#include "CoreExport.hpp"
#include "Event.hpp"
#include "ExceptionPtr.hpp"
#include "GetHashCode.hpp"
#include "InitializerList.hpp"
#include "Interface.hpp"
#include "Is.hpp"
#include "LiteralOperatorConverter.hpp"
#include "Lock.hpp"
#include "Move.hpp"
#include "Nameof.hpp"
#include "NullPtr.hpp"
#include "Property.hpp"
#include "Ref.hpp"
#include "RefPtr.hpp"
#include "Startup.hpp"
#include "Static.hpp"
#include "Types.hpp"
#include "Unused.hpp"
#include "Using.hpp"
