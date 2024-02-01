#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "prototype.h"
#define MAX_DESCRIPTION_LENGTH 1000
#define MAX_TASKS 100

// les variables globales

Todo_tasks ToDoList[MAX_TASKS],TMP;
int taskCount = 0;
//fonction exite qui recherche si un élément avec l'ID spécifié existe dans un tableau de structures.
int exist(int ID) {
    int i;
    for (i = 0; i < taskCount; i++) {
        if (ToDoList[i].ID== ID) {
            return 1;
        }
    }
    return 0;
}


//fonction pour ajouter un tache

void addTask(){
    printf("donner le nombre de tache \n");
      	scanf("%d",&TMP.ID);
    if(exist(TMP.ID)==1)
 	{
 	    printf("le id de cette tache est deja exist \n");

	 } else{
	 printf("Entrez la description de la tache : ");
    scanf(" %[^\n]", TMP.description);
    printf("Entrez la priorite de la tache (1-5) : ");
    scanf("%d", &TMP.priority);
    printf("Entrez la date d'echance de la tache (JJ/ MM /AAAA) : ");
    scanf("%d /%d/ %d", &TMP.duedate.day, &TMP.duedate.month, &TMP.duedate.year);


    printf("Entrez le statut de la tache (0: Incomplète, 1: Complète) : ");
    scanf("%d", &TMP.status);

	 ToDoList[taskCount]=TMP;
	   taskCount++;

	 printf("valider");
	 }
 }

 //fonction pour afficher les taches


 void displayTasks() {
    int i;
    for(i=0;i<taskCount;i++)
	{
   	printf(" \n *****les données de la tache %d sont:\n le ID : %d \n la description :  %s \n priorite : %d \n datedechance :%d/%d/%d\n la status :%d   \n ",
	   i+1,ToDoList[i].ID, ToDoList[i].description, ToDoList[i].priority, ToDoList[i].duedate.day, ToDoList[i].duedate.month, ToDoList[i].duedate.year, ToDoList[i].status);
	}

}


//fonction pour modifier la tache


void modifyTask() {
    int choix, i;
    Todo_tasks TMP;

    printf("Donner l'ID de la tâche à modifier : \n");
    scanf("%d", &TMP.ID);

    if (exist(TMP.ID) == 1) {
        for (i = 0; i < taskCount; i++) {
            choix = 0; // Initialiser choix à 0 à chaque itération
            while (choix != 6) {
                printf("1. Modifier l'ID\n");
                printf("2. Modifier la description\n");
                printf("3. Modifier la priorité\n");
                printf("4. Modifier la date\n");
                printf("5. Modifier le statut\n");
                printf("6. Quitter\n");
                printf("Choisissez une option : ");
                scanf("%d", &choix);

                switch (choix) {
                    case 1:
                        printf("Donner le nouvel ID : ");
                        scanf("%d", &ToDoList[i].ID);
                        break;
                    case 2:
                        printf("Donner la nouvelle description : ");
                        scanf(" %[^\n]", ToDoList[i].description);
                        break;
                    case 3:
                        printf("Donner la nouvelle priorité : ");
                        scanf("%d", &ToDoList[i].priority);
                        break;
                    case 4:
                        printf("Donner la nouvelle date (JJ /MM /AAAA) : ");
                        scanf("%d /%d /%d", &ToDoList[i].duedate.day, &ToDoList[i].duedate.month, &ToDoList[i].duedate.year);
                        break;
                    case 5:
                        printf("Donner le nouveau statut : ");
                        scanf("%d", &ToDoList[i].status);
                        break;
                    case 6:
                        printf("valider\n");
                        break;
                    default:
                        printf("Option invalide\n");
                        break;
                }
            }
        }
    } else {
        printf("La tâche avec l'ID %d n'existe pas\n", TMP.ID);
    }
}


//fonction pour supprimer la tache


void deleteTask() {

    int index,i;
    printf("Entrez le numéro de la tâche que vous souhaitez supprimer : ");
    scanf("%d", &index);

    if (index > 0 && index <= taskCount) {
        // Déplace les tâches suivantes vers le haut pour remplir l'emplacement supprimé
        for (i = index - 1; i < taskCount - 1; i++) {
            ToDoList[i] = ToDoList[i + 1];
        }

        // Décrémente le nombre total de tâches après la suppression
        taskCount--;

        printf("valider.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
}


//fonction pour filter par priority


void filterTasksByPriority(int priority) {
    int i;
    printf("Tâches avec priorité %d :\n", priority);
    for (i = 0; i < taskCount; i++) {
        if (ToDoList[i].priority == priority) {
            printf("Tache %d :\n",i + 1 );
            printf("ID : %d\n", ToDoList[i].ID);
            printf("Description : %s\n", ToDoList[i].description);
            printf("Date limite : %d/%d/%d\n", ToDoList[i].duedate.day, ToDoList[i].duedate.month, ToDoList[i].duedate.year);
            printf("Priorité : %d\n", ToDoList[i].priority);
            printf("Statut : %s\n", ToDoList[i].status ? "Complete" : "Incomplete");
            printf("\n");
        }
    }
}


//fonction filter par status


void filterTasksByStatus(int status) {
    int i;
    printf("Tâches avec statut %s :\n", status ? "Complete" : "Incomplete");
    for (i = 0; i < taskCount; i++) {
        if (ToDoList[i].status == status) {
            printf("Tache %d :\n", i + 1);
            printf("ID : %d\n", ToDoList[i].ID);
            printf("Description : %s\n",ToDoList[i].description);
            printf("Date limite : %d/%d/%d\n", ToDoList[i].duedate.day,ToDoList[i].duedate.month, ToDoList[i].duedate.year);
            printf("Priorite : %d\n", ToDoList[i].priority);
            printf("Statut : %s\n", ToDoList[i].status ? "Complete" : "Incomplete");
            printf("\n");
        }
    }
}


//fonction  pour filter par date


void filterTasksByDate(Todo_tasks ToDoList[])
{
    int i;
    int year,month,day;
    printf("donner le jour \n");
    scanf("%d", &day);
    printf("donner le mois \n");
    scanf("%d", &month);
    printf("donner l'annee \n");
    scanf("%d", &year);

    for (i = 0; i < taskCount; i++) {
        if (ToDoList[i].duedate.day == day && ToDoList[i].duedate.month == month && ToDoList[i].duedate.year == year) {
            printf("les donnés dans la tache %d :\n", i + 1);
            printf("ID : %d\n", ToDoList[i].ID);
            printf("Description : %s\n", ToDoList[i].description);
            printf("Priorite : %d\n", ToDoList[i].priority);
            printf("Date d 'echance : %d/%d/%d\n", ToDoList[i].duedate.day, ToDoList[i].duedate.month, ToDoList[i].duedate.year);

		}

}

}


//fonction pour ordonner croissante


void sortTasksAscending() {
	int i,j;
    for ( i = 0; i < taskCount - 1; i++) {
        for (j = 0; j < taskCount - i - 1; j++) {
            // Comparaison la date
            if (ToDoList[j].duedate.year > ToDoList[j + 1].duedate.year ||
                (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                 ToDoList[j].duedate.month > ToDoList[j + 1].duedate.month) ||
                (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                 ToDoList[j].duedate.month == ToDoList[j + 1].duedate.month &&
                 ToDoList[j].duedate.day > ToDoList[j + 1].duedate.day)) {
                //  ordonner
                Todo_tasks temp = ToDoList[j];
                ToDoList[j] = ToDoList[j + 1];
                ToDoList[j + 1] = temp;
            }
            // Si les dates sont les memes, comparez par description
            else if (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                     ToDoList[j].duedate.month == ToDoList[j + 1].duedate.month &&
                     ToDoList[j].duedate.day == ToDoList[j + 1].duedate.day &&
                     strcmp(ToDoList[j].description, ToDoList[j + 1].description) > 0) {
                // ordonner
                Todo_tasks temp = ToDoList[j];
                ToDoList[j] = ToDoList[j + 1];
                ToDoList[j + 1] = temp;
            }
            // Si les dates et les descriptions sont les memes, comparez par priorite
            else if (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                     ToDoList[j].duedate.month == ToDoList[j + 1].duedate.month &&
                     ToDoList[j].duedate.day == ToDoList[j + 1].duedate.day &&
                     strcmp(ToDoList[j].description, ToDoList[j + 1].description) == 0 &&
                     ToDoList[j].priority > ToDoList[j + 1].priority) {
                // achange des taches si elles ne sont pas dans l'ordre
                Todo_tasks temp = ToDoList[j];
                ToDoList[j] = ToDoList[j + 1];
                ToDoList[j + 1] = temp;
            }
        }
    }

    printf("Les taches ont tries par date d'achance, puis par description, et enfin par priorite si necessaire est croissante.\n");
}


// fonction pour ordonner decroissante


void sortTasksDescending() {
	int i,j;
    for (i = 0; i < taskCount - 1; i++) {
        for (j = 0; j < taskCount - i - 1; j++) {
            // Comparaison  sur la date
            if (ToDoList[j].duedate.year < ToDoList[j + 1].duedate.year ||
                (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                 ToDoList[j].duedate.month < ToDoList[j + 1].duedate.month) ||
                (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                 ToDoList[j].duedate.month == ToDoList[j + 1].duedate.month &&
                 ToDoList[j].duedate.day < ToDoList[j + 1].duedate.day)) {
                // change des taches si elles ne sont pas dans l'ordre
                Todo_tasks temp = ToDoList[j];
                ToDoList[j] = ToDoList[j + 1];
                ToDoList[j + 1] = temp;
            }
            // Si les dates sont les memes, comparez par description
            else if (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                     ToDoList[j].duedate.month == ToDoList[j + 1].duedate.month &&
                     ToDoList[j].duedate.day == ToDoList[j + 1].duedate.day &&
                     strcmp(ToDoList[j].description, ToDoList[j + 1].description) < 0) {
                //change des taches si elles ne sont pas dans l'ordre
                Todo_tasks temp = ToDoList[j];
                ToDoList[j] = ToDoList[j + 1];
                ToDoList[j + 1] = temp;
            }
            // Si les dates et les descriptions sont les memes, comparez par priorite
            else if (ToDoList[j].duedate.year == ToDoList[j + 1].duedate.year &&
                     ToDoList[j].duedate.month == ToDoList[j + 1].duedate.month &&
                     ToDoList[j].duedate.day == ToDoList[j + 1].duedate.day &&
                     strcmp(ToDoList[j].description, ToDoList[j + 1].description) == 0 &&
                     ToDoList[j].priority < ToDoList[j + 1].priority) {
                // change des taches si elles ne sont pas dans l'ordre
                Todo_tasks temp = ToDoList[j];
                ToDoList[j] = ToDoList[j + 1];
                ToDoList[j + 1] = temp;
            }
        }
    }

    printf("Les taches ont ete triees par date d'achance (ordre decroissant), puis par description, et enfin par priorite si necessaire.\n");
}

// fonction pour save les taches en fichiers


void saveTasksToFile() {
    int i;
     FILE *fichier = fopen("listedestaches.txt", "w");

    if (fichier == NULL) {
        printf("le fichier est vide.\n");
        return;
    }

    for (i = 0; i< taskCount; i++) {
        fprintf(fichier, "%d\n%s\n%d\n%d %d %d\n%d\n", ToDoList[i].ID, ToDoList[i].description, ToDoList[i].priority, ToDoList[i].duedate.day, ToDoList[i].duedate.month, ToDoList[i].duedate.year,ToDoList[i].status);
    }

    fclose(fichier);
    printf("Les donnees ont ete sauvegardees dans le fichier listedestaches.txt.\n");
}


//fonction pour stocker les taches sur fichiers


void loadTasksFromFile() {
	int i;
    FILE *fichier = fopen("listedestaches.txt", "r");

    if (fichier == NULL) {
        printf("le fichier est vide.\n");
        return;
    }

    taskCount = 0; // Reset taskCount before loading tasks

    while (fscanf(fichier, "%d", &TMP.ID) == 1) {
        // Read the rest of the line to capture the description
        fscanf(fichier, " ");
        fgets(TMP.description, sizeof(TMP.description), fichier);

        fscanf(fichier,"%d %d %d %d %d\n",
               &TMP.priority, &TMP.duedate.day, &TMP.duedate.month, &TMP.duedate.year, &TMP.status);

        ToDoList[taskCount] = TMP;
        taskCount++;

        // Check if taskCount exceeds the array size to avoid buffer overflow
        if (taskCount >= MAX_TASKS) {
            printf("Erreur : Le nombre de tâches dépasse la capacité maximale.\n");
            break;
        }
    }

    fclose(fichier);

    // Debug prints
    printf("Les donnees ont ete chargees depuis le fichier listedestaches.txt.\n");
}

// fonction main


int main() {
    loadTasksFromFile();
    int choice;
    int ch;
    int priority;
    int status;

    do {
    	printf("\n********************************");
        printf("\n******Gestion des taches********\n");
        printf("*          Menu           	*\n");
        printf("* 1. Ajouter une tache  	*\n");
        printf("* 2. Afficher la liste  	*\n");
        printf("* 3. Modifier une tache 	*\n");
        printf("* 4. Supprimer une tache	*\n");
        printf("* 5. Ordonner les taches	*\n");
        printf("* 6. Filtrer par priorite	*\n");
        printf("* 7. Filtrer par statut 	*\n");
        printf("* 8. Filtrer par date   	*\n");
        printf("* 9. Enregistrer 	        *\n");
        printf("* 0. Quitter            	*\n");
        printf("********************************\n");
        printf("********************************\n");

        printf("Choisissez une option : ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                modifyTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("1. Trier par ordre croissant\n2. Trier par ordre decroissant\n");
                printf("Choisissez une option : ");
                scanf("%d", &ch);
                if (ch == 1) {
                    sortTasksAscending();
                } else if (ch == 2) {
                    sortTasksDescending();
                }
                break;
            case 6:
                printf("Entrez la priorite pour le filtrage : ");
                scanf("%d", &priority);
                filterTasksByPriority(priority);
                break;
            case 7:
                printf("Entrez le statut pour le filtrage (0: Incomplète, 1: Complète) : ");
                scanf("%d", &status);
                filterTasksByStatus(status);
                break;
            case 8:
				filterTasksByDate(ToDoList);
			    break;
			case 9:
                saveTasksToFile();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);
    return 0;
}
