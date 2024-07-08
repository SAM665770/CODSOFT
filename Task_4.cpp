#include <iostream>
#include <string>
using namespace std;

const int total_tasks = 100;

void displayMenu() 
{
    cout << "\nTO-DO LIST MANAGER\n"
         << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n"
         << "4. Remove Task\n5. Exit\nChoose an option: ";
}

void addTask(string descriptions[], bool completed[], int& taskCount) 
{
    if (taskCount >= total_tasks) 
    {
        cout << "Task list is full!\n";
        return;
    }
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, descriptions[taskCount]);
    completed[taskCount] = false;
    taskCount++;
    cout << "Task added!\n";
}

void viewTasks(const string descriptions[], const bool completed[], int taskCount) 
{
    if (taskCount == 0) 
    {
        cout << "No tasks to show.\n";
        return;
    }
    for (int i = 0; i < taskCount; i++) 
    {
        cout << i + 1 << ". " << descriptions[i]
             << " [" << (completed[i] ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(bool completed[], int taskCount) 
{
    if (taskCount == 0) 
    {
        cout << "No tasks to mark.\n";
        return;
    }
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > taskCount) 
    cout << "Invalid task number!\n";
    else 
    {
        completed[taskNumber - 1] = true;
        cout << "Task marked as completed!\n";
    }
}

void removeTask(string descriptions[], bool completed[], int& taskCount) {
    if (taskCount == 0) 
    {
        cout << "No tasks to remove.\n";
        return;
    }
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > taskCount)
    cout << "Invalid task number!\n";
    else
    {
        for (int i = taskNumber - 1; i < taskCount - 1; i++) 
        {
            descriptions[i] = descriptions[i + 1];
            completed[i] = completed[i + 1];
        }
        taskCount--;
        cout << "Task removed!\n";
    }
}

int main() 
{
    string descriptions[total_tasks];
    bool completed[total_tasks];
    int taskCount = 0;
    int choice;
    while (true) 
    {
        displayMenu();
        cin >> choice;
        switch (choice) 
        {
            case 1: addTask(descriptions, completed, taskCount); break;
            case 2: viewTasks(descriptions, completed, taskCount); break;
            case 3: markTaskCompleted(completed, taskCount); break;
            case 4: removeTask(descriptions, completed, taskCount); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
}