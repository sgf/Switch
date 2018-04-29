[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

This section describes the standard exceptions provided by the Framework and the details of their usage. The list is by no means exhaustive. Please refer to the Switch Framework reference documentation for usage of other Framework exception types.

# Exception and SystemException

**X DO NOT** throw System::Exception or :System::SystemException.

**X DO NOT** catch System::Exception or System::SystemException in framework code, unless you intend to rethrow.

**X AVOID** catching System::Exception or System::SystemException, except in top-level exception handlers.

# ApplicationException

**X DO NOT** throw or derive from ApplicationException.

# InvalidOperationException

**√ DO** throw an InvalidOperationException if the object is in an inappropriate state.

# ArgumentException, ArgumentNullException, and ArgumentOutOfRangeException

**√ DO** throw System::ArgumentException or one of its subtypes if bad arguments are passed to a member. Prefer the most derived exception type, if applicable.

**√ DO** set the ParamName property when throwing one of the subclasses of ArgumentException.
This property represents the name of the parameter that caused the exception to be thrown. Note that the property can be set using one of the constructor overloads.

**√ DO** use value for the name of the implicit value parameter of property setters.

# NullReferenceException, NullPointerException, IndexOutOfRangeException, and AccessViolationException

**X DO NOT** allow publicly callable APIs to explicitly or implicitly throw System::NullReferenceException, System::NullPointerException, System::AccessViolationException, or System::IndexOutOfRangeException. These exceptions are reserved and thrown by the execution engine and in most cases indicate a bug.

Do argument checking to avoid throwing these exceptions. Throwing these exceptions exposes implementation details of your method that might change over time.

# StackOverflowException

**X DO NOT** explicitly throw System::StackOverflowException. The exception should be explicitly thrown only by the Operating System.

**X DO NOT** catch System::StackOverflowException.

It is almost impossible to write code that remains consistent in the presence of arbitrary stack overflows.

# OutOfMemoryException

**X DO NOT** explicitly throw System::OutOfMemoryException. This exception is to be thrown only by the Switch infrastructure.

# ComException, SEHException, and ExecutionEngineException

**X DO NOT** explicitly throw System::COMException, System::ExecutionEngineException, and System::SEHException. These exceptions are to be thrown only by the Switch infrastructure.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Design Guidelines for Exception](DesignGuidelinesForException.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
