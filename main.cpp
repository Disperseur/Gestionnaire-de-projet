#include <iostream>
#include "Task.h"
#include "TaskList.h"
#include "TaskListsManager.h"

using namespace std;


int main()
{
    // // creation des taches elementaires
    // Task maTache1(ONGOING, "Une tache au pif", "", Date(2, 3, 2025));
    // Task maSousTache("Une sous tache au pif");
    // Task maSousSousTache("Une sous sous tache");

    // Task maTache2(ONGOING, "La deuxieme tache importante", "Pas de description pour le moment", Date(2, 5, 2025));

    // // hierarchisation des taches
    // maSousTache.addChild(maSousSousTache);
    // maTache1.addChild(maSousTache);

    // // rangement des taches dans la liste
    
    // TaskList maListe("Ma liste de taches pour ISMIN");
    // maListe.addTask(maTache1);
    // maListe.addTask(maTache2);
    // maListe.print();
    // cout << maListe.getNbTasks();
    TaskListsManager manager;

    manager.runTaskManager();
    
    return(0);
}