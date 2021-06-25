source:
https://sourcemaking.com/design_patterns/strategy
https://refactoring.guru/design-patterns/strategy

---
## Summary
"Program to an interface, not an implementation"

Use the Strategy pattern when you want to/when:
- use different variants of an algorithm within an object and be able to switch from one algorithm to another during runtime.
- you have a lot of similar classes that only differ in the way they execute some behavior.
- isolate the business logic of a class from the implementation details of algorithms that may not be as important in the context of that logic.
- your class has a massive conditional operator that switches between different variants of the same algorithm.

The Strategy pattern lets you:
- indirectly alter the object’s behavior at runtime by associating it with different sub-objects which can perform specific sub-tasks in different ways.
- extract the varying behavior into a separate class hierarchy and combine the original classes into one, thereby reducing duplicate code.
- isolate the code, internal data, and dependencies of various algorithms from the rest of the code. Various clients get a simple interface to execute the algorithms and switch them at runtime.
- do away with such a conditional by extracting all algorithms into separate classes, all of which implement the same interface. The original object delegates execution to one of these objects, instead of implementing all variants of the algorithm.


---
## Intent

-Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from the clients that use it.
-Capture the abstraction in an interface, bury implementation details in derived classes.

---
## Discussion
### Pros
- You can swap algorithms used inside an object at runtime.
- You can isolate the implementation details of an algorithm from the code that uses it.
- You can replace inheritance with composition.
- Open/Closed Principle. You can introduce new strategies without having to change the context.
### Cons
- If you only have a couple of algorithms and they rarely change, there’s no real reason to overcomplicate the program with new classes and interfaces that come along with the pattern.
- Clients must be aware of the differences between strategies to be able to select a proper one.
- A lot of modern programming languages have functional type support that lets you implement different versions of an algorithm inside a set of anonymous functions. Then you could use these functions exactly as you’d have used the strategy objects, but without bloating your code with extra classes and interfaces.

## Example Applications
Imagine that you have to get to the airport. You can catch a bus, order a cab, or get on your bicycle. These are your transportation strategies. You can pick one of the strategies depending on factors such as budget or time constraints.

## How to Implement

- In the context class, identify an algorithm that’s prone to frequent changes. It may also be a massive conditional that selects and executes a variant of the same algorithm at runtime.
- Declare the strategy interface common to all variants of the algorithm.
- One by one, extract all algorithms into their own classes. They should all implement the strategy interface.
- In the context class, add a field for storing a reference to a strategy object. Provide a setter for replacing values of that field. The context should work with the strategy object only via the strategy interface. The context may define an interface which lets the strategy access its data.
- Clients of the context must associate it with a suitable strategy that matches the way they expect the context to perform its primary job.


## Notes

- Strategy is like Template Method except in its granularity.
- State is like Strategy except in its intent.
- Strategy lets you change the guts of an object. Decorator lets you change the skin.
- State, Strategy, Bridge (and to some degree Adapter) have similar solution structures. They all share elements of the 'handle/body' idiom. They differ in intent - that is, they solve different problems.
- Strategy has 2 different implementations, the first is similar to State. The difference is in binding times (Strategy is a bind-once pattern, whereas State is more dynamic).
- Strategy objects often make good Flyweights.

