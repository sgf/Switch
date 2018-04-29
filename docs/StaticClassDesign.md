[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

A static class is defined as a class that contains only static members (of course besides the instance members inherited from System.Object and possibly a private constructor). C++ languages do not provide built-in support for static classes.

Static classes are a compromise between pure object-oriented design and simplicity. They are commonly used to provide shortcuts to other operations (such as System::IO::File), holders of extension methods, or functionality for which a full object-oriented wrapper is unwarranted (such as System::Environment).

**√ DO** use static classes sparingly.

Static classes should be used only as supporting classes for the object-oriented core of the framework.

**X DO NOT** treat static classes as a miscellaneous bucket.

**X DO NOT** declare or override instance members in static classes.

**√ DO** declare static classes as abstract, and add a private instance constructor or add Switch keyword static_ because C++ language does not have built-in support for static classes.

```c++
namespace System {
  class Environment static_ {
  public:
    static void Exit(int exitCode) {
      ...
    }
    ...
  }; 
}
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Type Design Guidelines](TypeDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
