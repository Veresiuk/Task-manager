#pragma once

#include <vector>
#include <string>
#include "Task.h"

class TaskManager {

    private:
    std::vector<Task> tasks;

    public:
    TaskManager();

    void addTask(const std::string& description);
    void updateTask(int id, const std::string& description);
    void deleteTask(int id);

    void statusTask(int id, const std::string& status);
    //список всіх завдань//
    void listTask();
    //виконані завдання//
    void doneTask();
    //не виконані завдання//
    void todoTask();
    //завдання в процесі//
    void progressTask();

    void saveTasks() const;

    void loadTasks();

};