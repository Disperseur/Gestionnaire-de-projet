#pragma once
#include <cstring>
#include "Task.h"

#define NB_MAX_TASKS 100

using namespace std;



class TaskList
{
public:
    TaskList() {
        name = "None";
        nbTasks = 0;
    }

    TaskList(string n) {
        name = n;
    }

 


    string getName(void) const;
    unsigned int getNbTasks(void) const;

    errorCode setName(string n);

    errorCode addTask(const Task &t);

    errorCode print(void) const;

    Task* getTasks(void);

private:
    string name;
    unsigned int nbTasks;
    Task tasks[NB_MAX_TASKS];
};