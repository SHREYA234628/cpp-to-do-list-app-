#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

// Save tasks to file
void saveTasks() {
    ofstream file("tasks.txt");
    for (auto &task : tasks) {
        file << task.name << "," << task.completed << "\n";
    }
    file.close();
}

// Load tasks from file
void loadTasks() {
    ifstream file("tasks.txt");
    tasks.clear();
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            Task t;
            t.name = line.substr(0, pos);
            t.completed = (line.substr(pos + 1) == "1");
            tasks.push_back(t);
        }
    }
    file.close();
}

// Add new task
void addTask() {
    cin.ignore(); // clear input buffer
    string taskName;
    cout << "Enter task name: ";
    getline(cin, taskName);
    tasks.push_back({taskName, false});
    saveTasks();
    cout << "Task added successfully!\n";
}

// Mark task as completed
void markCompleted() {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        saveTasks();
        cout << " Task marked as completed!\n";
    } else {
        cout << " Invalid task number!\n";
    }
}

// View all tasks
void viewTasks() {
    cout << "\n Pending Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        if (!tasks[i].completed) {
            cout << i + 1 << ". " << tasks[i].name << "\n";
        }
    }
    cout << "\n Completed Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].completed) {
            cout << i + 1 << ". " << tasks[i].name << "\n";
        }
    }
}

int main() {
    loadTasks();
    int choice;
    do {
        cout << "\n--- TO-DO LIST MENU ---\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: markCompleted(); break;
            case 3: viewTasks(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
