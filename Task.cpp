#include <iostream>
#include "Task.h"


// Surcharge de l'opérateur >> pour le statut
istream& operator>>(istream& flux, taskStatus_t& status) {
    string input;
    flux >> input; // Lire une chaîne depuis le flux

    if (input == "TODO") {
        status = TODO;
    } else if (input == "ONGOING") {
        status = ONGOING;
    } else if (input == "DONE") {
        status = DONE;
    } else {
        flux.setstate(ios::failbit); // Marquer une erreur si l'entrée est invalide
    }

    return flux;
}


istream& operator>>(istream& flux, Date& d) {
    char sep; // Pour gérer les séparateurs comme '/' ou '-'
    flux >> d.day >> sep >> d.month >> sep >> d.year;
    return flux;
}

ostream& operator<<(ostream& flux, const Task t) {
    cout << "| ";
    switch (t.status)
    {
    case TODO:
        flux << "TODO | ";
        break;

    case ONGOING:
        flux << "ONGOING | ";
        break;

    case DONE:
        flux << "DONE | ";
        break;
    
    default:
        flux << "? | ";
        break;
    }

    flux << t.title << " | " << t.dueDate << " | " << t.description << " |" << endl;

    return(flux);
}





ostream& operator<<(ostream& flux, const Date d) {
    flux << d.day << "/" << d.month << "/" << d.year;

    return(flux);
}






taskStatus_t Task::getStatus(void) const {
    return(status);
}

string Task::getTitle(void) const {
    return(title);
}

string Task::getDescription(void) const {
    return(description);
}

Date Task::getDueDate(void) const {
    return(dueDate);
}



errorCode Task::setStatus(taskStatus_t t) {
    status = t;
    return(SUCCESS);
}

errorCode Task::setTitle(string t) {
    title = t;
    return(SUCCESS);
}

errorCode Task::setDescription(string d) {
    description = d;
    return(SUCCESS);
}

errorCode Task::setDueDate(Date dD) {
    dueDate = dD;
    return(SUCCESS);
}




errorCode Task::addChild(Task &childTask) {
    
    if(nb_child_tasks < NB_MAX_CHILDS) {
        childTasks[nb_child_tasks] = &childTask;
        nb_child_tasks++;

        return(SUCCESS);
    }
    else return(FAIL);    
}

unsigned int Task::getNbChilds(void) const {
    return(nb_child_tasks);
}

errorCode Task::printWithChilds(unsigned int indentLevel) const {
    cout << *this;
    
    for(int i = 0; i < indentLevel; i++) {
        cout << "\t";
    }
    
    for(int i=0; i < nb_child_tasks; i++) {
        childTasks[i]->printWithChilds(indentLevel + 1);
    }

    return(SUCCESS);
}


Task** Task::getChilds(void) {
    return(childTasks);
}