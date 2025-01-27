#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ")
                      << tasks[i].description << std::endl;
        }
    }

    void markCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void editTask(size_t index, const std::string& newDescription) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].description = newDescription;
            std::cout << "Task edited successfully." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    std::string input, description;
    size_t index;

    while (true) {
        std::cout << "\nTo-Do List Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Edit Task" << std::endl;
        std::cout << "5. Remove Task" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);

        if (input == "1") {
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            todoList.addTask(description);
        } else if (input == "2") {
            todoList.viewTasks();
        } else if (input == "3") {
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> index;
            std::cin.ignore();
            todoList.markCompleted(index);
        } else if (input == "4") {
            std::cout << "Enter task number to edit: ";
            std::cin >> index;
            std::cin.ignore();
            std::cout << "Enter new task description: ";
            std::getline(std::cin, description);
            todoList.editTask(index, description);
        } else if (input == "5") {
            std::cout << "Enter task number to remove: ";
            std::cin >> index;
            std::cin.ignore();
            todoList.removeTask(index);
        } else if (input == "6") {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

