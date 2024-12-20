#pragma once
#include <cstring>

#define NB_MAX_CHILDS 20
#define MAX_RECURSIVE_CHILDS 2

using namespace std;

enum taskStatus_t {TODO=0, ONGOING, DONE};
enum errorCode {SUCCESS, FAIL};

istream& operator>>(istream& flux, taskStatus_t& status);


class Date
{
public:
    Date() {
        day = 1;
        month = 1;
        year = 2024;
    }

    Date(unsigned int d, unsigned int m) {
        day = d;
        month = m;
    }

    Date(unsigned int d, unsigned int m, unsigned int y) {
        day = d;
        month = m;
        year = y;
    }

    friend ostream& operator<<(ostream& flux, const Date d);
    friend istream& operator>>(istream& flux, Date& d);

private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
};









class Task
{
public:

    // constructeurs
    Task() {
        status = TODO;
        title  = "Task 1";
        description = "No description";

        // childTasks = new Task[NB_MAX_CHILDS];
        nb_child_tasks = 0;
    }

    Task(string t) {
        status = TODO;
        title  = t;
        description = "No description";

        // childTasks = new Task[NB_MAX_CHILDS];
        nb_child_tasks = 0;
    }

    Task(taskStatus_t s, string t, string d, Date dD) {
        status = s;
        title  = t;
        description = d;
        dueDate = dD;

        // childTasks = new Task[NB_MAX_CHILDS];
        nb_child_tasks = 0;
    }

    // fonctions amies et surcharges
    friend ostream& operator<<(ostream& flux, const Task t);
    errorCode printWithChilds(unsigned int indentLevel = 1) const;

    // accesseurs
    taskStatus_t getStatus(void) const;
    string getTitle(void) const;
    string getDescription(void) const;
    Date getDueDate(void) const;
    unsigned int getNbChilds(void) const;
    Task** getChilds(void);
    

    // mutateurs
    errorCode setStatus(taskStatus_t t);
    errorCode setTitle(string t);
    errorCode setDescription(string d); 
    errorCode setDueDate(Date dD);

    // autres methodes
    errorCode addChild(Task &childTask);

private:
    taskStatus_t status;
    string title;
    string description;
    Date dueDate;

    // Task* childTasks;
    Task* childTasks[NB_MAX_CHILDS];
    unsigned int nb_child_tasks;
};