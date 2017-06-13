#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "t07defs.h"

#define MAX_STR 64
#define C_OK 0
#define N_OK -1
void printList(const StudentList *);
void printStudent(const StudentType*);
int initStudent(char *f, char *l, int a,
                char *n, float g, StudentType **stuPtr);
/* Implement the following functions */
int insertStudentAlpha(StudentList **, StudentType *);
int deleteStudent(StudentList *, char *, char *);
int cleanupList(StudentList *);

int main(void) {
        int i, rc;

        StudentType *matilda, *joe, *timmy;

        initStudent("Matilda", "Mallister", 22, "123444555",
                    9.0, &matilda);
        initStudent("Joe", "The Plumber", 24, "567888999",
                    8.7, &joe);
        initStudent("Timmy", "Tortoise", 99, "345667788",
                    11.5, &timmy);

        StudentList *comp2401 = malloc(sizeof(StudentList));

        comp2401->head = NULL;

        insertStudentAlpha(comp2401, matilda);
        insertStudentAlpha(comp2401, joe);
        insertStudentAlpha(comp2401, timmy);
        //printList(comp2401);

        rc = deleteStudent(comp2401, "Tommy", "Tortoise");
        printf("%d\n", rc);
        rc = deleteStudent(comp2401, "Joe", "The Plumber");
        printf("%d\n", rc);
        //printList(comp2401);
        deleteStudent(comp2401, "Matilda", "Mallister");
        //printList(comp2401);

        cleanupList(comp2401);

        return 0;
}

int insertStudentAlpha(StudentList **stuList, StudentType *stu) {
        StudentNode *currNode, *prevNode, *newNode;
        currNode = *stuList->head;
        prevNode = NULL;

// Loop to find insertion point

        while (currNode != NULL) {
                if (strcmp(stu->basicInfo.first, currNode.head.data.basicInfo.first)<0) {
                        prevNode = currNode;
                        currNode = currNode->next;
                } else if ((strcmp(stu->basicInfo.first, *stuList.head.data.basicInfo.first)>=0)) {
                        break;
                }
        }
        newNode = malloc(sizeof(StudentNode))
                  newNode->data = stu;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (prevNode == NULL) {
                *stuList = newNode;
        }
        else {
                prevNode->next = newNode;
        }
        newNode->next = currNode;
        newNode->prev = prevNode;

        if (currNode != NULL)
                currNode->prev = newNode;
        return C_OK;
}

int deleteStudent(StudentList *stuList, char *fname, char *lname) {

        return C_OK;
}

int cleanupList(StudentList *stuList) {

        return C_OK;
}
