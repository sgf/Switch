[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

Member overloading means creating two or more members on the same type that differ only in the number or type of parameters but have the same name. For example, in the following, the WriteLine method is overloaded:

```c++
class Console static_ {
public:
  static void WriteLine();
  static void WriteLine(const string& value);
  static void WriteLine(bool value);
  ...
};
```

Because only methods, constructors, and indexed properties can have parameters, only those members can be overloaded.

Overloading is one of the most important techniques for improving usability, productivity, and readability of reusable libraries. Overloading on the number of parameters makes it possible to provide simpler versions of constructors and methods. Overloading on the parameter type makes it possible to use the same member name for members performing identical operations on a selected set of different types.

**√ DO** try to use descriptive parameter names to indicate the default used by shorter overloads.

**X AVOID** arbitrarily varying parameter names in overloads. If a parameter in one overload represents the same input as a parameter in another overload, the parameters should have the same name.

**X AVOID** being inconsistent in the ordering of parameters in overloaded members. Parameters with the same name should appear in the same position in all overloads.

**√ DO** make only the longest overload virtual (if extensibility is required). Shorter overloads should simply call through to a longer overload.

**X DO NOT** use ref or out modifiers to overload members.

Some languages cannot resolve calls to overloads like this. In addition, such overloads usually have completely different semantics and probably should not be overloads but two separate methods instead.

**X DO NOT** have overloads with parameters at the same position and similar types yet with different semantics.

**√ DO** allow #null to be passed for optional arguments.

**√ DO** use member overloading rather than defining members with default arguments.

Default arguments are not authorized.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Member Design Guidelines](MemberDesignGuidelines.md)

______________________________________________________________________________________________

© 2018 Gammasoft.
