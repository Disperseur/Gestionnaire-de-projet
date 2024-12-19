#pragma once
#include "TaskList.h"

#define NB_LISTS 10

using namespace std;


class TaskListsManager
{
public:
    TaskListsManager() {
        nbLists = 0;
    }

    errorCode runTaskManager(void);

private:
    errorCode showMenu(void);
    errorCode mainMenuChoiceHandler(unsigned int c);
    TaskList newListHandler(void);
    errorCode addNewList(const TaskList &list);

    unsigned int nbLists;
    TaskList lists[NB_LISTS];
};