 Two Use Cases to Demonstrate Behavioral Design Patterns
Use Case 1: Command Pattern

Scenario: The Mars Rover receives a series of movement commands, like moving forward, turning left, and turning right. These commands are encapsulated as objects and executed in a sequence.
Design Pattern: The Command Pattern allows the system to queue, log, or undo commands by treating each command as an object with an execute() method. This helps separate the invoker (Rover) from the logic that performs the action.
Benefit: The command logic can be easily extended or changed without modifying the core rover logic.
Use Case 2: Observer Pattern

Scenario: Whenever the Mars Rover changes its position, an observer (e.g., a monitoring system) is notified to display or log the rover’s new position.
Design Pattern: The Observer Pattern allows one or more observers (e.g., a logging system) to subscribe to changes in the rover’s state. Whenever the state changes (e.g., movement), the observer receives updates without modifying the rover’s movement logic.
Benefit: It provides flexibility in adding or removing observers without impacting the core system, ensuring modularity.
2. Two Use Cases to Demonstrate Creational Design Patterns
Use Case 1: Singleton Pattern

Scenario: In the Mars Rover simulation, the grid display system should be a single, consistent object to ensure only one instance of the grid is displayed at any time.
Design Pattern: The Singleton Pattern is used to ensure that the GridDisplay class only has one instance throughout the entire simulation.
Benefit: Ensures there’s no accidental creation of multiple grid displays, preventing inconsistent states and excessive memory usage.
Use Case 2: Factory Method Pattern

Scenario: Different types of rovers (e.g., standard rover, advanced rover) may need to be created based on certain conditions (e.g., different sensors or capabilities).
Design Pattern: The Factory Method Pattern is used to create different types of rovers without specifying the exact class that will be instantiated. For example, RoverFactory can produce StandardRover or other rover types based on the mission requirements.
Benefit: It abstracts the instantiation process, making it easier to introduce new types of rovers or modify the creation process without affecting other parts of the code.
3. Two Use Cases to Demonstrate Structural Design Patterns
Use Case 1: Adapter Pattern

Scenario: The Mars Rover system is upgraded, but there are legacy commands from an older system (e.g., “forward”, “left”) that still need to be supported.
Design Pattern: The Adapter Pattern is used to adapt the old command interface to the new command system. For example, the old forward command is adapted to the new MoveForwardCommand.
Benefit: The legacy system can be integrated without refactoring the entire codebase, allowing for backward compatibility with minimal changes.
Use Case 2: Decorator Pattern

Scenario: The Mars Rover simulation needs additional features like logging or telemetry data collection, but you don’t want to modify the core rover behavior.
Design Pattern: The Decorator Pattern is used to dynamically add responsibilities to objects. For example, a RoverCommandLogger wraps around the original command to log each action before executing it.
Benefit: It provides a flexible way to extend functionality (e.g., logging) without altering the core logic, promoting code reusability and separation of concerns.
