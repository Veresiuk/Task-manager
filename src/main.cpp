#include "TaskManager.h"
#include <iostream>
#include <string>

int main() {
    TaskManager manager;

    std::string command;

    while (true) {

    std::cin >> command;

    bool commandFound = false;

    if (command == "exit") {

        break;
    }

    if (command == "add"){

        commandFound = true;

        std::string description;
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
        std::cin >> id;
        manager.deleteTask(id);
    }

    if (command == "update") {

        commandFound = true;

        int id;
        std::cin >> id;
        std::string description;
        std::getline(std::cin >> std::ws, description);
        manager.updateTask(id, description);
        
    }

    if (command == "mark-in-progress") {

        commandFound = true;

        int id;
        std::cin >> id;
        manager.statusTask(id, "in-progress");
    }

    if (command == "mark-done") {

        commandFound = true;

        int id;
        std::cin >> id;
        manager.statusTask(id, "done");
    }

    if (!commandFound) {

    std::cout << "Unknown command!" << std::endl;
    
    }

    }

}
