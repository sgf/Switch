[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

One of the basic design decisions every framework designer faces is whether to design a type as a class or as a struct. Good understanding of the differences in the behavior of reference types and value types is crucial in making this choice.

The only difference between a class and a struct in C++ is that structs have default public members and bases and classes have default private members and bases. Both classes and structs can have a mixture of public and private members, can use inheritance, and can have member functions.

**√ CONSIDER** defining a struct instead of a class if instances of the type are small and commonly short-lived or are commonly embedded in other objects.

**X AVOID** defining a struct unless the type has all of the following characteristics:

* It logically represents a single value, similar to primitive types (int, double, etc.).
* It is immutable.

In all other cases, you should define your types as classes.
​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Type Design Guidelines](TypeDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
