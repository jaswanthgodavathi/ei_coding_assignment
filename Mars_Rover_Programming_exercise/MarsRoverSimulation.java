import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// Rover Command Interface
interface Command {
    void execute();
}

// Directions for the Rover
enum Direction {
    NORTH, EAST, SOUTH, WEST;

    // Rotate left (counterclockwise)
    public Direction turnLeft() {
        return values()[(this.ordinal() + 3) % 4];
    }

    // Rotate right (clockwise)
    public Direction turnRight() {
        return values()[(this.ordinal() + 1) % 4];
    }

    // Get the arrow representation of the direction
    public String getArrow() {
        return switch (this) {
            case NORTH -> "⬆️";
            case EAST -> "➡️";
            case SOUTH -> "⬇️";
            case WEST -> "⬅️";
        };
    }
}

// Position class representing the Rover's position on the grid
class Position {
    int x, y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Move position based on direction
    public void move(Direction direction) {
        switch (direction) {
            case NORTH -> y++;
            case EAST -> x++;
            case SOUTH -> y--;
            case WEST -> x--;
        }
    }

    // Check if two positions are equal
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Position position = (Position) obj;
        return x == position.x && y == position.y;
    }

    @Override
    public int hashCode() {
        return x * 31 + y;
    }
}

// Mars Rover class
class MarsRover {
    private Position position;
    private Direction direction;
    private Set<Position> obstacles;
    private int gridSize;

    public MarsRover(int gridSize, Position startPosition, Direction startDirection, Set<Position> obstacles) {
        this.gridSize = gridSize;
        this.position = startPosition;
        this.direction = startDirection;
        this.obstacles = obstacles;
    }

    // Execute a command on the rover
    public void executeCommand(Command command) {
        command.execute();
        displayGrid(); // Display grid after executing each command
    }

    // Command to move the rover forward
    class MoveForwardCommand implements Command {
        @Override
        public void execute() {
            Position nextPosition = new Position(position.x, position.y);
            nextPosition.move(direction);
            if (isWithinGrid(nextPosition) && !obstacles.contains(nextPosition)) {
                position = nextPosition;
            } else {
                System.out.println("Cannot move forward, obstacle or boundary detected!");
            }
        }
    }

    // Command to turn the rover left
    class TurnLeftCommand implements Command {
        @Override
        public void execute() {
            direction = direction.turnLeft();
        }
    }

    // Command to turn the rover right
    class TurnRightCommand implements Command {
        @Override
        public void execute() {
            direction = direction.turnRight();
        }
    }

    // Check if a position is within the grid
    private boolean isWithinGrid(Position position) {
        return position.x >= 0 && position.x < gridSize && position.y >= 0 && position.y < gridSize;
    }

    // Display the current state of the grid with arrows for direction
    private void displayGrid() {
        System.out.println("Current Grid State:");

        for (int y = gridSize - 1; y >= 0; y--) { // Y-axis from top to bottom
            for (int x = 0; x < gridSize; x++) { // X-axis from left to right
                Position pos = new Position(x, y);
                if (position.equals(pos)) {
                    System.out.print(direction.getArrow() + " "); // Direction arrow based on current facing
                } else if (obstacles.contains(pos)) {
                    System.out.print("🪨 "); // Obstacle emoji
                } else {
                    System.out.print("🟩 "); // Empty space emoji
                }
            }
            System.out.println(); // New line after each row
        }

        System.out.println(); // Extra space for better readability
    }

}

// Main class for the Mars Rover simulation
public class MarsRoverSimulation {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int gridSize = 5;
        Position startPosition = new Position(2, 2);
        Direction startDirection = Direction.NORTH;

        // Define obstacles
        Set<Position> obstacles = new HashSet<>();
        obstacles.add(new Position(1, 2));
        obstacles.add(new Position(3, 3));

        // Initialize Mars Rover
        MarsRover rover = new MarsRover(gridSize, startPosition, startDirection, obstacles);

        System.out.println("Welcome to the Mars Rover Simulation!");
        System.out.println("Commands: move | turn left | turn right | exit");

        while (true) {
            System.out.print("Enter command: ");
            String input = scanner.nextLine().trim().toLowerCase();

            switch (input) {
                case "move":
                    rover.executeCommand(rover.new MoveForwardCommand());
                    break;
                case "turn left":
                    rover.executeCommand(rover.new TurnLeftCommand());
                    break;
                case "turn right":
                    rover.executeCommand(rover.new TurnRightCommand());
                    break;
                case "exit":
                    System.out.println("Exiting simulation.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid command. Please try again.");
            }
        }
    }
}