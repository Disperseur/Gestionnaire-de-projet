#include <iostream>
#include "TaskList.h"


string TaskList::getName(void) const {
    return(name);
}

unsigned int  TaskList::getNbTasks(void) const {
    return(nbTasks);
}

errorCode TaskList::setName(string n) {
    name = n;
    return(SUCCESS);
}

errorCode TaskList::addTask(const Task &t) {
    if(nbTasks < NB_MAX_TASKS) {
        tasks[nbTasks] = t;
        nbTasks++;
        return(SUCCESS);
    }
    else return(FAIL);
}

errorCode TaskList::print(void) const {
    cout << name << endl;
    for(int i=0; i<nbTasks; i++) {
        tasks[i].printWithChilds();
        cout << endl;
    }

    return(SUCCESS);
}

Task* TaskList::getTasks(void) {
    return(tasks);
}