[![Switch](../docs/Pictures/Menu/Switch.png)](Home.md)[![Switch](../docs/Pictures/Menu/Gallery.png)](Gallery.md)[![Switch](../docs/Pictures/Menu/Examples.png)](Examples.md)[![Switch](../docs/Pictures/Menu/Downloads.png)](Downloads.md)[![Switch](../docs/Pictures/Menu/Documentation.png)](Documentation.md)[![Switch](../docs/Pictures/Menu/Project.png)](https://sourceforge.net/projects/switchpro)[![Switch](../docs/Pictures/Menu/Sources.png)](https://github.com/gammasoft71/switch)[![Switch](../docs/Pictures/Menu/Contact.png)](Contact.md)[![Switch](../docs/Pictures/Menu/Gammasoft.png)](https://gammasoft71.wixsite.com/gammasoft)

Events are the most commonly used form of callbacks (constructs that allow the framework to call into user code). Other callback mechanisms include members taking delegates, virtual members, and interface-based plug-ins. Data from usability studies indicate that the majority of developers are more comfortable using events than they are using the other callback mechanisms. Events are nicely integrated with Switch.

It is important to note that there are two groups of events: events raised before a state of the system changes, called pre-events, and events raised after a state changes, called post-events. An example of a pre-event would be Form::Closing, which is raised before a form is closed.

An example of a post-event would be Form::Closed, which is raised after a form is closed.

**√ DO** use the term "raise" for events rather than "fire" or "trigger."

**√ DO** use System::TEventHandler <TEventArgs> instead of manually creating new delegates to be used as event handlers.

**√ CONSIDER** using a subclass of System::EventArgs as the event argument, unless you are absolutely sure the event will never need to carry any data to the event handling method, in which case you can use the System::EventArgs type directly.

If you ship an API using System::EventArgs directly, you will never be able to add any data to be carried with the event without breaking compatibility. If you use a subclass, even if initially completely empty, you will be able to add properties to the subclass when needed.

**√ DO** use a public virtual method to raise each event. This is applicable to nonstatic events on classes, or static events.

The purpose of the method is to provide a way for a derived class to handle the event using an override. Overriding is a more flexible, faster, and more natural way to handle base class events in derived classes. By convention, the name of the method should start with "On" and be followed with the name of the event.

The derived class can choose not to call the base implementation of the method in its override. Be prepared for this by not including any processing in the method that is required for the base class to work correctly.

**√ DO** take one parameter to the method that raises an event.

The parameter should be named e and should be typed as the event argument class.

**X DO NOT** pass null as the sender when raising a nonstatic event.

**√ DO** pass Object as the sender when raising a static event.

**X DO NOT** pass null as the event data parameter when raising an event.

You should pass System::EventArgs::Empty if you don’t want to pass any data to the event handling method. Developers expect this parameter not to be null.

# Custom Event Handler Design

**√ DO** use a return type of void for event handlers.

An event handler can invoke multiple event handling methods, possibly on multiple objects. If event handling methods were allowed to return a value, there would be multiple return values for each event invocation.

**√ DO** use object as the type of the first parameter of the event handler, and call it sender.

**√ DO** use System::EventArgs or its subclass as the type of the second parameter of the event handler, and call it e.

**X DO NOT** have more than two parameters on event handlers.
​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Member Design Guidelines](MemberDesignGuidelines.md)

______________________________________________________________________________________________

© 2018 Gammasoft.
