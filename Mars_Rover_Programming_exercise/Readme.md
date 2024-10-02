# 🚀 Mars Rover Simulation Design Patterns

Welcome to the **Mars Rover Simulation Project!** 🌌 This project implements various software design patterns to build a flexible, modular, and easily extendable system for controlling and monitoring a Mars Rover. Below, we’ll walk through six use cases that demonstrate key **behavioral**, **creational**, and **structural** design patterns. These patterns ensure **scalability**, **maintainability**, and **flexibility** in the code. Run ***MarsRoverSimulation.java***💨.

## 1. Behavioral Design Patterns 🧠

### Use Case 1: Command Pattern 🎮
- **Scenario**: The Mars Rover receives a series of commands, like moving forward, turning left, and turning right. These movement instructions need to be executed in a specific order.
- **Design Pattern**: The Command Pattern treats each action as an object with an `execute()` method. By encapsulating commands, we can queue, log, or even undo movements without touching the core rover logic.
- **Benefit**: Command logic is highly flexible and can be extended or modified without changing how the rover operates.
- **Example**: Issue a `MoveForwardCommand` to move the rover, followed by a `TurnLeftCommand`. Each command is executed in sequence, ensuring a clean, modular structure.

### Use Case 2: Observer Pattern 👁️
- **Scenario**: Whenever the Mars Rover changes its position, a monitoring system needs to be notified so it can update the display or log the movement.
- **Design Pattern**: The Observer Pattern enables one or more observers to subscribe to changes in the rover’s state. When the rover moves, all observers (e.g., monitoring dashboards) get updated automatically.
- **Benefit**: This provides flexibility to add or remove observers without impacting the rover’s movement logic.
- **Example**: The rover moves north, and all subscribed observers—like a map display and a logging system—are notified immediately, ensuring the data is always up to date.

## 2. Creational Design Patterns 🛠️

### Use Case 1: Singleton Pattern 🔒
- **Scenario**: We want to ensure that only one instance of the `GridDisplay` exists throughout the simulation to avoid inconsistent states.
- **Design Pattern**: The Singleton Pattern guarantees that only a single instance of the `GridDisplay` class exists during the simulation.
- **Benefit**: This prevents accidental creation of multiple grid instances, ensuring consistent visuals and reducing memory usage.
- **Example**: A single grid display reflects the rover's position at all times, even as the rover moves across different quadrants of Mars.

### Use Case 2: Factory Method Pattern 🏭
- **Scenario**: We need to create different types of rovers (e.g., standard rover, advanced rover) with various sensors and capabilities based on mission requirements.
- **Design Pattern**: The Factory Method Pattern abstracts the process of creating rovers, allowing us to instantiate different rover types without specifying the exact class.
- **Benefit**: This pattern makes it easier to introduce new rover models or modify the creation process without affecting the core logic.
- **Example**: The `RoverFactory` produces either a `StandardRover` or an `AdvancedRover` depending on the mission’s needs, all behind a simple interface.

## 3. Structural Design Patterns 🏗️

### Use Case 1: Adapter Pattern 🔌
- **Scenario**: Our Mars Rover system has been upgraded, but we still need to support legacy commands like `forward` and `left` from the old system.
- **Design Pattern**: The Adapter Pattern translates old commands into the new command system. For example, the `forward` command from the old system is adapted into the new `MoveForwardCommand`.
- **Benefit**: It allows for backward compatibility without refactoring the entire codebase.
- **Example**: A legacy command like `forward` is adapted into `MoveForwardCommand` in the new system, allowing us to continue supporting old mission protocols.

### Use Case 2: Decorator Pattern 🎨
- **Scenario**: We need to add new features like logging or telemetry data collection to the Mars Rover without changing its core behavior.
- **Design Pattern**: The Decorator Pattern wraps around existing objects to dynamically add functionality. For example, a `RoverCommandLogger` wraps around the base command to log each action.
- **Benefit**: It allows us to extend the rover’s functionality (e.g., logging) in a modular way without modifying its core logic.
- **Example**: Add a logging decorator to the `MoveForwardCommand`, enabling real-time logging of every movement without altering the core movement functionality.

## 🚀 Conclusion
By utilizing these design patterns, we have built a modular, scalable, and maintainable Mars Rover simulation system. Each pattern solves specific challenges while keeping the codebase clean and flexible for future expansions. Whether it's creating new rovers, issuing commands, or adding new features, the system is designed to grow and evolve.

## 📝 Sample Input and Output

### Sample Input:
```bash
Enter command: move
Enter command: turn left
Enter command: move
Enter command: turn right
Enter command: exit

## Sample Output:
Current Grid State:
🟩 🟩 🟩 🟩 🟩 
🟩 🟩 🪨 🟩 🟩 
🟩 🟩 ⬆️ 🟩 🟩 
🟩 🟩 🟩 🪨 🟩 
🟩 🟩 🟩 🟩 🟩 

Current Grid State:
🟩 🟩 🟩 🟩 🟩 
🟩 🟩 🪨 🟩 🟩 
🟩 🟩 ⬅️ 🟩 🟩 
🟩 🟩 🟩 🪨 🟩 
🟩 🟩 🟩 🟩 🟩 

Current Grid State:
🟩 🟩 🟩 🟩 🟩 
🟩 🟩 ⬅️ 🪨 🟩 
🟩 🟩 🟩 🟩 🟩 
🟩 🟩 🟩 🪨 🟩 
🟩 🟩 🟩 🟩 🟩 

Current Grid State:
🟩 🟩 🟩 🟩 🟩 
🟩 🟩 🪨 🟩 🟩 
🟩 🟩 ⬆️ 🟩 🟩 
🟩 🟩 🟩 🪨 🟩 
🟩 🟩 🟩 🟩 🟩 

Exiting simulation.

