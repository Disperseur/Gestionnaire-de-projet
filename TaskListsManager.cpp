#include <iostream>
#include "Task.h"
#include "TaskList.h"
#include "TaskListsManager.h"

using namespace std;


errorCode TaskListsManager::runTaskManager(void) {
    // gestionnaire d'interface
    while(1) showMenu();

    return(SUCCESS);
}


errorCode TaskListsManager::showMenu(void) {
    unsigned int choice = 0;

    while (choice < 1 || choice > 3)
    {
        // effacement du terminal
        system("clear");

        // affichage des listes presentes
        cout << "Available lists:" << endl;

        for(int i=0; i<nbLists; i++) {
            lists[i].print();
        }

        // affichage des choix
        
        cout << endl;
        cout << "*****************Main Menu*****************\n\n";
        cout << "1) Create New list\n";
        cout << "2) Create New Task\n";
        cout << "3) Exit\n";
        cout << endl;
        cout << ">>>";
        cin >> choice;
    }

    mainMenuChoiceHandler(choice);

    return(SUCCESS);
}


errorCode TaskListsManager::mainMenuChoiceHandler(unsigned int c) {
    switch (c)
    {
    case 1:
        {
            // creation d'une nouvelle liste
            TaskList list = newListHandler();
            addNewList(list);
            break;
        }

    case 2:
        // creation d'une nouvelle tache et assignement a une liste
        break;

    case 3:
        // exit
        break;
    
    default:
        break;
    }

    return(SUCCESS);
}


TaskList TaskListsManager::newListHandler(void) {
    // gestion de la creation d'une nouvelle liste
    TaskList newTaskList;
    string name;

    system("clear");
    cout << "New list editor" << endl << endl;
    cout << "Enter a name for the new list: ";
    cin >> name;

    newTaskList.setName(name);
    
    return(newTaskList);
}

errorCode TaskListsManager::addNewList(const TaskList &list) {
    if(nbLists < NB_LISTS) {
        lists[nbLists] = list;
        nbLists++;

        return(SUCCESS);
    }
    else return(FAIL);
}