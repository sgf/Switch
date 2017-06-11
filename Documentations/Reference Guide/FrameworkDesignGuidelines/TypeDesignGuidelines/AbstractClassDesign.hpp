/// @page AbstractClassDesignPage Abstract Class Design
/// <b>X DO NOT</b> define public or protected internal constructors in abstract types.
///
/// Constructors should be public only if users will need to create instances of the type. Because you cannot create instances of an abstract type, an abstract type with a public constructor is incorrectly designed and misleading to the users.
///
/// <b>√ DO</b> define a protected or an internal constructor in abstract classes.
///
/// A protected constructor is more common and simply allows the base class to do its own initialization when subtypes are created.
///
/// An internal constructor can be used to limit concrete implementations of the abstract class to the assembly defining the class.
///
/// <b>√ DO</b> provide at least one concrete type that inherits from each abstract class that you ship.
///
/// Doing this helps to validate the design of the abstract class. For example, Pcf::System::IO::FileStream is an implementation of the Pcf::System::IO::Stream abstract class.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref TypeDesignGuidelinesPage