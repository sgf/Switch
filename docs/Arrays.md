[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

**✓ DO** prefer using collections over arrays in public APIs. The Guidelines for Collections section provides details about how to choose between collections and arrays.

**X DO NOT** use read-only array fields. The field itself is read-only and can't be changed, but elements in the array can be changed.

**✓ CONSIDER** using jagged arrays instead of multidimensional arrays.

A jagged array is an array with elements that are also arrays. The arrays that make up the elements can be of different sizes, leading to less wasted space for some sets of data (e.g., sparse matrix) compared to multidimensional arrays. Furthermore, the Switch optimizes index operations on jagged arrays, so they might exhibit better runtime performance in some scenarios.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Usage Guidelines](UsageGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
