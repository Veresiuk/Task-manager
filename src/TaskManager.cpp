#include "../include/TaskManager.h"
#include "../include/DateTime.h"

#include <iostream>
#include <fstream>


TaskManager::TaskManager(){

    loadTasks();

}

void TaskManager::addTask(const std::string& description) {

    Task newTask;

    newTask.id = tasks.empty() ? 1 : tasks.back().id + 1;
    newTask.description = description;
    newTask.status = "todo";

    std::string currentTime = getCurrentDateTime();
    newTask.createdAt = currentTime;
    newTask.updatedAt = currentTime;

    tasks.push_back(newTask);
    saveTasks();
    std::cout << "\nTask added successfully!\n";
}

void TaskManager::updateTask(int id, const std::string& description) {
    for (Task& task : tasks){

        if(task.id == id){

            task.description = description;
            task.updatedAt = getCurrentDateTime();
            saveTasks();

            std::cout << "\nTask updated successfully!\n";
            std::cout << "ID:          " << task.id << std::endl;
            std::cout << "Description: " << task.description << std::endl;
            std::cout << "Status:      " << task.status << std::endl;
            std::cout << "Created:     " << task.createdAt << std::endl;
            std::cout << "Updated:     " << task.updatedAt << std::endl;

            return;
        }
    }

    std::cout << "Task with ID " << id << " not found!" << std::endl;

}

void TaskManager::deleteTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); it++){

            if (it->id == id){

                tasks.erase(it);
                saveTasks();

                std::cout << "\nTask deleted successfully!\n";

                return;
            }
        }

        std::cout << "Task with ID " << id << " not found!" << std::endl;

    }


void TaskManager::statusTask(int id, const std::string& status) {

     for (Task& task : tasks){

        if(task.id == id){

            task.status = status;
            task.updatedAt = getCurrentDateTime();
            saveTasks();

            std::cout << "\nTask status updated successfully!\n";
            std::cout << "ID:          " << task.id << std::endl;
            std::cout << "Description: " << task.description << std::endl;
            std::cout << "Status:      " << task.status << std::endl;
            std::cout << "Created:     " << task.createdAt << std::endl;
            std::cout << "Updated:     " << task.updatedAt << std::endl;

            return;
        }
    }

    std::cout << "Task with ID " << id << " not found!" << std::endl;

}

void TaskManager::listTask() {

    if (tasks.empty()) {

        std::cout << "The task list is empty!"<< std::endl;

        return;
    }

    for (const Task& task : tasks) {

        std::cout << "\n----------------------------------------\n";
        std::cout << "ID:          " << task.id << std::endl;
        std::cout << "Description: " << task.description << std::endl;
        std::cout << "Status:      " << task.status << std::endl;
        std::cout << "Created:     " << task.createdAt << std::endl;
        std::cout << "Updated:     " << task.updatedAt << std::endl;
        std::cout << "----------------------------------------\n";
    }

}

void TaskManager::doneTask() {

    bool found = false;

    for (const Task& task : tasks) {

        if (task.status == "done") {

             found = true;

            std::cout << "\n----------------------------------------\n";
            std::cout << "ID:          " << task.id << std::endl;
            std::cout << "Description: " << task.description << std::endl;
            std::cout << "Status:      " << task.status << std::endl;
            std::cout << "Created:     " << task.createdAt << std::endl;
            std::cout << "Updated:     " << task.updatedAt << std::endl;
            std::cout << "----------------------------------------\n";

        }

    }

        if (!found) {
            std::cout << "\nNo completed tasks found!\n";

        }

    
}

void TaskManager::todoTask() {

    bool found = false;


    for (const Task& task : tasks) {

        if (task.status == "todo") {
            
            found = true;

            std::cout << "\n----------------------------------------\n";
            std::cout << "ID:          " << task.id << std::endl;
            std::cout << "Description: " << task.description << std::endl;
            std::cout << "Status:      " << task.status << std::endl;
            std::cout << "Created:     " << task.createdAt << std::endl;
            std::cout << "Updated:     " << task.updatedAt << std::endl;
            std::cout << "----------------------------------------\n";

        }
    }

    if (!found) {
        std::cout << "\nNo todo tasks found!\n";
    }

}

void TaskManager::progressTask() {

    bool found = false;

    for (const Task& task : tasks) {

        if (task.status == "in-progress"){
            
            found = true;

            std::cout << "\n----------------------------------------\n";
            std::cout << "ID:          " << task.id << std::endl;
            std::cout << "Description: " << task.description << std::endl;
            std::cout << "Status:      " << task.status << std::endl;
            std::cout << "Created:     " << task.createdAt << std::endl;
            std::cout << "Updated:     " << task.updatedAt << std::endl;
            std::cout << "----------------------------------------\n";
        }
    }

    if (!found) {
        std::cout << "\nNo tasks in progress found!\n";

}

}

void TaskManager::saveTasks() const{
    
    std::ofstream file("data/tasks.json");

    file << "[\n";

    for (const Task& task : tasks) {

        file << "  {\n";
        file << "    \"id\": " << task.id << ",\n";
        file << "    \"description\": \"" << task.description << "\",\n";
        file << "    \"status\": \"" << task.status << "\",\n";
        file << "    \"createdAt\": \"" << task.createdAt << "\",\n";
        file << "    \"updatedAt\": \"" << task.updatedAt << "\"\n";
        file << "  }";

        if (task.id != tasks.back().id) {

            file << ",";
        }
        file << "\n";
    }
    file << "]\n";
}

void TaskManager::loadTasks() {

    std::ifstream file("data/tasks.json");

    if (!file.is_open()) {

    return;
    }

    std::string line;

    Task task;

    while (std::getline(file, line)) {

        if (line.find("\"id\"") != std::string::npos) {

            size_t pos = line.find(":");
            task.id = std::stoi(line.substr(pos + 1));

        }

        if (line.find("\"description\"") != std::string::npos) {

            size_t start = line.find("\"", line.find(":") + 1);
            size_t end = line.find("\"", start + 1);
            task.description = line.substr(start + 1, end - start -1);

        }

        if (line.find("\"status\"") != std::string::npos) {
            size_t start = line.find("\"", line.find(":") + 1);
            size_t end = line.find("\"", start + 1);
            task.status = line.substr(start + 1, end - start - 1);

        }

        if (line.find("\"createdAt\"") != std::string::npos) {

            size_t start = line.find("\"", line.find(":") + 1);
            size_t end = line.find("\"", start + 1);
            task.createdAt = line.substr(start + 1, end - start - 1);

        }

        if (line.find("\"updatedAt\"") != std::string::npos) {

            size_t start = line.find("\"", line.find(":") + 1);
            size_t end = line.find("\"", start + 1);
            task.updatedAt = line.substr(start + 1, end - start - 1);

            tasks.push_back(task);

        }
    
    }
}