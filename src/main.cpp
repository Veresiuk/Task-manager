#include "../include/TaskManager.h"
#include <iostream>
#include <string>

int main() {
    TaskManager manager;

    std::cout << "\n=============================================\n";
    std::cout << "\n           Task Tracker\n";
    std::cout << "\n=============================================\n";
    std::cout << "\nAvailable commands:\n\n";

    std::cout << " add              - Add a new task\n";
    std::cout << " list             - Show all tasks\n";
    std::cout << " list-todo        - Show todo tasks\n";
    std::cout << " list-progress    - Show in-progress tasks\n";
    std::cout << " list-done        - Show done tasks\n";
    std::cout << " update           - Update a task\n";
    std::cout << " delete           - Delete a task\n";
    std::cout << " mark-in-progress - Mark task as in-progress\n";
    std::cout << " mark-done        - Mark task as done\n";
    std::cout << " exit             - Exit program\n";

    std::cout << "\n=============================================\n";

    std::string command;

    while (true) {
    
    std::cout << "\nEnter command: ";
    std::cin >> command;

    bool commandFound = false;

    if (command == "exit") {

        break;
    }

    if (command == "add"){

        commandFound = true;

        std::string description;

        std::cout << "Enter task description: ";
        std::getline(std::cin >> std::ws, description);
        manager.addTask(description);
        
    }

     if (command == "list") {

        commandFound = true;
    
        manager.listTask();

    }

    if (command == "list-done") {

        commandFound = true;

        manager.doneTask();
    }

    if (command == "list-todo") {

        commandFound = true;

        manager.todoTask();

    }

    if (command == "list-progress") {

        commandFound = true;

        manager.progressTask();

    }

    if (command == "delete") {

        commandFound = true;

        int id;

        std::cout << "Enter task ID: ";

        if (std::cin >> id) {
            manager.deleteTask(id);
        }
        else {
            std::cout << "Invalid ID!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    if (command == "update") {

        commandFound = true;

        int id;

        std::cout << "Enter task ID: ";

        if (std::cin >> id) {

            std::string description;

            std::cout << "Enter new description: ";
            std::getline(std::cin >> std::ws, description);

            manager.updateTask(id, description);
        }
        else {
            std::cout << "Invalid ID!" << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        
    }

    if (command == "mark-in-progress") {

         commandFound = true;

        int id;

        std::cout << "Enter task ID: ";

        if (std::cin >> id) {

            manager.statusTask(id, "in-progress");
        }
        else {
            std::cout << "Invalid ID!" << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    if (command == "mark-done") {

        commandFound = true;

        int id;

        std::cout << "Enter task ID: ";

        if (std::cin >> id) {

            manager.statusTask(id, "done");
        }
        else {
            std::cout << "Invalid ID!" << std::endl;

            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    if (!commandFound) {

    std::cout << "Unknown command!" << std::endl;
    
    }

    }

    return 0;

}
