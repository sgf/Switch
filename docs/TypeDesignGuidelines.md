[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

From the c++ perspective, there are only two categories of types-natives types and class types—but for the purpose of a discussion about framework design, we divide types into more logical groups, each with its own specific design rules.
 
Classes are the general case of reference types. They make up the bulk of types in the majority of frameworks. Classes owe their popularity to the rich set of object-oriented features they support and to their general applicability. Base classes and abstract classes are special logical groups related to extensibility.
 
Interfaces are types that can be implemented by both reference types and value types. They can thus serve as roots of polymorphic hierarchies of reference types and value types.
 
Structs are the general case of value types and should be reserved for small, simple types, similar to language primitives.
 
Enums are a special case of value types used to define short sets of values, such as days of the week, console colors, and so on.
 
Static classes are types intended to be containers for static members. They are commonly used to provide shortcuts to other operations.

Delegates, exceptions, attributes, arrays, and collections are all special cases of reference types intended for specific uses, and guidelines for their design and usage are discussed elsewhere in this book.

√ DO ensure that each type is a well-defined set of related members, not just a random collection of unrelated functionality.

# In This Section

* [Choosing Between Class and Struct](ChoosingBetweenClassAndStruct.md)
* [Abstract Class Design](AbstractClassDesign.md)
* [Static Class Design](StaticClassDesign.md)
* [Interface Design](InterfaceDesign.md)
* [Struct Design](StructDesign.md)
* [Enum Design](EnumDesign.md)
* [Nested Types](NestedTypes.md)

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
