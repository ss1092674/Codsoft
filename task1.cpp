#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        std::cout << i + 1 << ". [" << (task.completed ? "X" : " ") << "] " << task.description << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Quit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Clear the newline character from the buffer

        switch (choice) {
            case 1: {
                std::cout << "Enter a description for the task: ";
                std::string description;
                std::getline(std::cin, description);

                Task newTask;
                newTask.description = description;
                newTask.completed = false;

                tasks.push_back(newTask);

                std::cout << "Task added!\n";
                break;
            }
            case 2: {
                displayTasks(tasks);
                break;
            }
            case 3: {
                displayTasks(tasks);
                std::cout << "Enter the number of the task you want to delete: ";
                int taskNumber;
                std::cin >> taskNumber;

                if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    std::cout << "Task deleted!\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }

                break;
            }
            case 4: {
                std::cout << "Goodbye!\n";
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
