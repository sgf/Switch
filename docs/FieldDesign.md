[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

The principle of encapsulation is one of the most important notions in object-oriented design. This principle states that data stored inside an object should be accessible only to that object.

A useful way to interpret the principle is to say that a type should be designed so that changes to fields of that type (name or type changes) can be made without breaking code other than for members of the type. This interpretation immediately implies that all fields must be private.

**X DO NOT** provide instance fields that are public or protected.

You should provide properties for accessing fields instead of making them public or protected.

**X DO NOT** use public static fields for predefined object instances.

If there are predefined instances of the type, declare them with public static Method of the type itself.
​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Member Design Guidelines](MemberDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
