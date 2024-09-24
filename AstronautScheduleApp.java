import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;

// Task class representing a single task
class Task {
    private String description;
    private LocalTime startTime;
    private LocalTime endTime;
    private String priority;
    private boolean isCompleted;

    public Task(String description, LocalTime startTime, LocalTime endTime, String priority) {
        this.description = description;
        this.startTime = startTime;
        this.endTime = endTime;
        this.priority = priority;
        this.isCompleted = false; // Default value
    }

    public String getDescription() {
        return description;
    }

    public LocalTime getStartTime() {
        return startTime;
    }

    public LocalTime getEndTime() {
        return endTime;
    }

    public String getPriority() {
        return priority;
    }

    public boolean isCompleted() {
        return isCompleted;
    }

    public void markAsCompleted() {
        this.isCompleted = true;
    }

    @Override
    public String toString() {
        return String.format("%s - %s: %s [%s]%s", startTime, endTime, description, priority,
                (isCompleted ? " (Completed)" : ""));
    }
}

// Factory Pattern: TaskFactory to create Task objects
class TaskFactory {
    public static Task createTask(String description, String startTime, String endTime, String priority) {
        LocalTime start = LocalTime.parse(startTime);
        LocalTime end = LocalTime.parse(endTime);
        return new Task(description, start, end, priority);
    }
}

// Singleton Pattern: ScheduleManager for managing the tasks
class ScheduleManager {
    private static ScheduleManager instance;
    private List<Task> tasks;

    private ScheduleManager() {
        tasks = new ArrayList<>();
    }

    // Singleton: Ensure only one instance
    public static ScheduleManager getInstance() {
        if (instance == null) {
            instance = new ScheduleManager();
        }
        return instance;
    }

    // Add a new task after checking for conflicts
    public String addTask(Task task) {
        if (isConflict(task)) {
            return "Error: Task conflicts with an existing task.";
        }
        tasks.add(task);
        return "Task added successfully. No conflicts.";
    }

    // Remove an existing task
    public String removeTask(String description) {
        for (Task task : tasks) {
            if (task.getDescription().equals(description)) {
                tasks.remove(task);
                return "Task removed successfully.";
            }
        }
        return "Error: Task not found.";
    }

    // View all tasks sorted by start time
    public String viewTasks() {
        if (tasks.isEmpty()) {
            return "No tasks scheduled for the day.";
        }
        Collections.sort(tasks, Comparator.comparing(Task::getStartTime));
        StringBuilder sb = new StringBuilder();
        for (Task task : tasks) {
            sb.append(task).append("\n");
        }
        return sb.toString();
    }

    // Mark a task as completed
    public String markTaskAsCompleted(String description) {
        for (Task task : tasks) {
            if (task.getDescription().equals(description)) {
                task.markAsCompleted();
                return "Task marked as completed.";
            }
        }
        return "Error: Task not found.";
    }

    // View tasks of a specific priority
    public String viewTasksByPriority(String priority) {
        StringBuilder sb = new StringBuilder();
        for (Task task : tasks) {
            if (task.getPriority().equalsIgnoreCase(priority)) {
                sb.append(task).append("\n");
            }
        }
        return sb.length() > 0 ? sb.toString() : "No tasks with the specified priority.";
    }

    // Check if a new task conflicts with existing tasks
    private boolean isConflict(Task newTask) {
        for (Task task : tasks) {
            if (newTask.getStartTime().isBefore(task.getEndTime())
                    && newTask.getEndTime().isAfter(task.getStartTime())) {
                return true; // Conflict found
            }
        }
        return false;
    }
}

// Observer Pattern: Notification class for task conflict (optional)
class TaskConflictNotifier {
    public static void notifyConflict(String conflictMessage) {
        System.out.println(conflictMessage);
    }
}

// Console-based Application to test the schedule manager
public class AstronautScheduleApp {
    public static void main(String[] args) {
        ScheduleManager scheduleManager = ScheduleManager.getInstance();

        // Adding tasks
        System.out
                .println(scheduleManager.addTask(TaskFactory.createTask("Morning Exercise", "07:00", "08:00", "High")));
        System.out.println(scheduleManager.addTask(TaskFactory.createTask("Team Meeting", "09:00", "10:00", "Medium")));

        // Trying to add a conflicting task
        System.out
                .println(scheduleManager.addTask(TaskFactory.createTask("Training Session", "09:30", "10:30", "High")));

        // Viewing tasks
        System.out.println("\n--- Scheduled Tasks ---");
        System.out.println(scheduleManager.viewTasks());

        // Removing a task
        System.out.println(scheduleManager.removeTask("Morning Exercise"));

        // Adding another task
        System.out.println(scheduleManager.addTask(TaskFactory.createTask("Lunch Break", "12:00", "13:00", "Low")));

        // Marking a task as completed
        System.out.println(scheduleManager.markTaskAsCompleted("Team Meeting"));

        // Viewing tasks by priority
        System.out.println("\n--- High Priority Tasks ---");
        System.out.println(scheduleManager.viewTasksByPriority("High"));

        // Final Task List
        System.out.println("\n--- Final Task List ---");
        System.out.println(scheduleManager.viewTasks());
    }
}
