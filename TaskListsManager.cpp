#include <iostream>
#include <cstring>
#include <sstream>
#include "Task.h"
#include "TaskList.h"
#include "TaskListsManager.h"

using namespace std;

int* flexInput(int &nbArgs) {
    const int MAX_SIZE = MAX_RECURSIVE_CHILDS; // Taille fixe du tableau
    int* tableau;
    tableau = new int[MAX_SIZE];
    int count = 0; // Compteur pour le nombre d'entiers saisis


    string line;
    cin.ignore();
    getline(cin, line); // Lire une ligne entière de l'entrée utilisateur
    istringstream stream(line); // Convertir la ligne en flux

    for(int i=0; i<MAX_SIZE; i++) {tableau[i] = -1;}

    while (stream >> tableau[count] && count < MAX_SIZE) {
        count++;
    }

    nbArgs = count;
    // cout << "Vous avez saisi : ";
    // for (int i = 0; i < count; i++) {
    //     cout << tableau[i] << " ";
    // }
    // cout << endl;

    return(tableau);
}


errorCode TaskListsManager::runTaskManager(void) {
    // gestionnaire d'interface
    while(1) showMenu();

    return(SUCCESS);
}


void TaskListsManager::printLists(bool showIndex) {
    for(int i=0; i<nbLists; i++) {
        if(showIndex) cout << i << ") ";
        lists[i].print();
    }
}

errorCode TaskListsManager::showMenu(void) {
    unsigned int choice = 0;

    while (choice < 1 || choice > 3)
    {
        // effacement du terminal
        system("clear");

        // affichage des listes presentes
        cout << "Available lists:" << endl;

        printLists();

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
        newTaskHandler();
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


errorCode TaskListsManager::newTaskHandler(void) {
    taskStatus_t status;
    string title;
    string description;
    Date dueDate;


    int choice = -1;


    system("clear");
    cout << "New task editor" << endl << endl;
    cout << "Enter a status for the new task [0: TOTO, 1: ONGOING, 2: DONE]: ";
    cin >> status;
    cout << "Enter a title for the new task:";
    cin >> title;
    cout << "Enter a description for the new task:";
    cin.ignore();
    getline(cin, description);
    
    // cin >> description;
    cout << "Enter a due date for the new task:";
    cin >> dueDate;

    Task* newTask;
    newTask = new Task;
    newTask->setTitle(title);
    newTask->setDescription(description);
    newTask->setDueDate(dueDate);
    newTask->setStatus(status);
    cout << *newTask;

    // gestion de l'affectation de la nouvelle tache
    // choix de la liste ou ajouter la nouvelle tache
    cout << endl << endl;
    cout << "Choose the list to which you want to add the task:\n";
    printLists(true);
    cout << "?: ";
    cin >> choice;

    //affichage de la liste choisie
    lists[choice].print();

    //choix de l'affectation de la nouvelle tache de maniere recursive
    
    if(lists[choice].getNbTasks() == 0) {
        // si la liste ne contient aucunne tache, on en ajoute une
        lists[choice].addTask(*newTask);
    }
    else {
        // recuperation de la position a laquelle inserer la nouvelle tache
        cout << "To choose where to put the new task:";
        int nbValues;
        int* values = flexInput(nbValues);
        
        // temporisation debug
        int k;
        cin >> k;

        // insertion de la nouvelle tache a la position values

        if(nbValues == 1 && values[0] > lists[choice].getNbTasks()-1) {
            // si il n'y a q'une seule valeur alors on ajoute une tache a la liste
            lists[choice].addTask(*newTask);
        }
        else {
            // si il y a au moins deux taches on bosse plus
            Task* currentTask = &lists[choice].getTasks()[values[0]]; //la tache courante 

            int i = 1;
            while(values[i] != -1) {
                currentTask = currentTask->getChilds()[values[i]];
                i++;
            }

            currentTask->addChild(*newTask);
        }
    }


    return(SUCCESS);
}