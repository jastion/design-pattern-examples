



---
## Summary
Also known as: Virtual Constructor

Use the Factory Method when you don’t know beforehand the exact types and dependencies of the objects your code should work with.

Use the Factory Method when you want to provide users of your library or framework with a way to extend its internal components.

Use the Factory Method when you want to save system resources by reusing existing objects instead of rebuilding them each time.

---
## Intent
Factory Method is a creational design pattern that provides an interface for creating objects in a 
superclass, but allows subclasses to alter the type of objects that will be created.

Define an interface for creating an object, but let subclasses decide which class to instantiate.
Factory Method lets a class defer instantiation to subclasses by defining a "virtual" constructor.
The new operator considered harmful.

---
## Problem
A framework needs to standardize the architectural model for a range of applications, but allow for individual applications to define their own domain objects and provide for their instantiation.

---
## Discussion
Abstract Factory classes are often implemented with Factory Methods, but they can be implemented using Prototype.
 - Factory Methods are usually called within Template Methods.
 - Factory Method: creation through inheritance. Prototype: creation through delegation.
 - Often, designs start out using Factory Method (less complicated, more customizable, subclasses proliferate) and evolve toward Abstract Factory, Prototype, or Builder (more flexible, more complex) as the designer discovers where more flexibility is needed.
 - Prototype doesn't require subclassing, but it does require an Initialize operation. Factory Method requires subclassing, but doesn't require Initialize.
 - The advantage of a Factory Method is that it can return the same instance multiple times, or can return a subclass rather than an object of that exact type.
 - Some Factory Method advocates recommend that as a matter of language design (or failing that, as a matter of style) absolutely all constructors should be private or protected. It's no one else's business whether a class manufactures a new object or recycles an old one.
 - The new operator considered harmful. There is a difference between requesting an object and creating one. - The new operator always creates an object, and fails to encapsulate object creation. A Factory Method enforces that encapsulation, and allows an object to be requested without inextricable coupling to the act of creation.

## Analysis

### Pros
 - You avoid tight coupling between the creator and the concrete products.
 - Single Responsibility Principle. You can move the product creation code into one place in the program, making the code easier to support.
 - Open/Closed Principle. You can introduce new types of products into the program without breaking existing client code.
 
 ### Cons
  - The code may become more complicated since you need to introduce a lot of new subclasses to implement the pattern. The best case scenario is when you’re introducing the pattern into an existing hierarchy of creator classes.

## Example Applications

## source
https://sourcemaking.com/design_patterns/factory_method
https://www.gofpatterns.com/design-patterns/module3/singleton-real-world-examples.php