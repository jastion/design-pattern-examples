source:
https://sourcemaking.com/design_patterns/factory_method
https://www.gofpatterns.com/design-patterns/module3/singleton-real-world-examples.php

---
## Summary
Use the Singleton pattern when:

- There must be exactly one instance of a class, and it must be accessible to clients from a well-known access point
- When the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code.

The Singleton pattern restricts a class so that only one instance can be created. This can be accomplished by
- making its constructor private or protected and
- providing an instance() member that returns a pointer to a new instance if one does not already exist but returns a pointer to that instance if it does.

---
## Intent
Ensure a class has only one instance, and provide a global point of access to it.
Encapsulated "just-in-time initialization" or "initialization on first use".

---
## Problem

Application needs one, and only one, instance of an object. Additionally, lazy initialization and global access are necessary. The most common reason for this is to control access to some shared resource—for example, a database or a file. 

---
## Discussion
Make the class of the single instance object responsible for creation, initialization, access, and enforcement. Declare the instance as a private static data member. Provide a public static member function that encapsulates all initialization code, and provides access to the instance.

The client calls the accessor function (using the class name and scope resolution operator) whenever a reference to the single instance is required.

Singleton should be considered only if all three of the following criteria are satisfied:

 - Ownership of the single instance cannot be reasonably assigned
 - Lazy initialization is desirable
 - Global access is not otherwise provided for

Alternative reasons can also be:
- Controls concurrent access to a shared resource.
- Access to the resource will be requested from multiple, disparate parts of the system.
- There can be only one object.

If ownership of the single instance, when and how initialization occurs, and global access are not issues, Singleton is not sufficiently interesting.

The Singleton pattern can be extended to support access to an application-specific number of instances.

The "static member function accessor" approach will not support subclassing of the Singleton class. If subclassing is desired, refer to the discussion in the book.

Deleting a Singleton class/instance is a non-trivial design problem.

## Example Applications
- Loggers
- Global configurations
- Hardware Access

## Notes

This behavior is impossible to implement with a regular constructor since a constructor call must always return a new object by design.
