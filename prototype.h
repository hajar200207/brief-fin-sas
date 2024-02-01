#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_TASKS 100
// Structure pour représenter une date
struct Date {
    int day;
    int month;
    int year;
};

// Structure pour représenter une tâche
struct Todo_tasks {
    int ID;
    char description[MAX_DESCRIPTION_LENGTH];
    struct Date duedate;
    int priority;
    int status; // 0 pour Incomplete, 1 pour Complete
};

// Prototypes des fonctions
int exist(int ID);
void addTask();
void displayTasks();
void modifyTask();
void deleteTask();
void filterTasksByPriority(int priority);
void filterTasksByStatus(int status);
void filterTasksByDate(struct Todo_tasks ToDoList[]);
void sortTasksAscending();
void sortTasksDescending();
void saveTasksToFile();
void loadTasksFromFile();

#endif // PROTOTYPE_H

