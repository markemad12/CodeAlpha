#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({description, false});
        cout << "Task added successfully!\n";
    }

    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number!\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }

        cout << "TO-DO LIST:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
};

void displayMenu() {
    cout << "\nTO-DO LIST APPLICATION\n";
    cout << "1. Add Task\n";
    cout << "2. Mark Task as Completed\n";
    cout << "3. View Tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    TodoList todo;
    int choice;
    string taskDescription;
    int taskNumber;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
            case 2:
                todo.viewTasks();
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todo.markCompleted(taskNumber - 1);
                break;
            case 3:
                todo.viewTasks();
                break;
            case 4:
                cout << "Exiting application. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
} 