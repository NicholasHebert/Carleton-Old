#include <stdio.h>
#include <stdlib.h>
#include "a7Defs.h"

int main(){
        printf("start");
        CatListType *catBag;
        getCats(catBag);
        printCats(catBag);
        cleanup(catBag);
        return 0;
}

void printCats(CatListType *catBag){
        NodeType *currNode, *prevNode;

        currNode = catBag;
        prevNode = NULL;

        while(currNode != NULL) {


                prevNode = currNode;
                currNode = currNode->next;


        }
}

void getCats(CatListType *catBag){
        //prep variables that will be used to init the cat object
        int catID;
        char gen;
        char catName[MAX_STR];
        GenderType gender;
        CatType *thisCat;

        //gather user information about cat while also verifying data
        printf("Name the cat -1 to stop...\n");
        while(1) {
                printf("\nEnter the cats name(or -1 to quit): ");
                readString(catName);
                verifyName(catName);
                if (strcmp(catName, "-1") == 0) {
                        break;
                }

                printf("Enter the cats gender(0 for male, 1 for female): ");

                readInt(&gen);

                verifyGender(gen);
                gender = gen;

                printf("Enter the cats ID: ");
                readInt(&catID);
                verifyID(catID);


                //init the cat then add the cat to the list of cats
                initCat(catID, catName, gender, &thisCat);
                printf("%d, %s\n", thisCat->id, thisCat->name);
                addCat(thisCat, catBag);
                printf("cat added");
        }

}

void initCat(int i, char *n, GenderType g, CatType **cat){
        *cat = (CatType *) malloc(sizeof(CatType));

        strcpy((*cat)->name, n);
        (*cat)->id = i;
        (*cat)->gender = g;
}

void verifyGender(int *g){
        if (g != 0 && g != 1) {
                printf("The number you have entered does not correspond to a gender, please try again... (0 or 1): ");
                readInt(&g);
                verifyGender(g);
        }
}

void addCat(CatType *cat, CatListType *catBag){
        NodeType *currNode, *prevNode, *newNode;

        currNode = &catBag->head;
        prevNode = NULL;

        printf("start loop");
        while (currNode != NULL) {
                printf("step in");
                if (strcmp(cat->name, currNode->data->name) == 1) {//problem is here
                        break;
                }
                prevNode = currNode;
                currNode = currNode->next;

        }
        printf("end loop");

        newNode = malloc(sizeof(NodeType));
        newNode->data = cat;

        if (currNode->prev == NULL && currNode->next == NULL) {
                catBag->head = newNode;
                catBag->tail = newNode;
        } else if (currNode->prev == NULL) {
                currNode->prev = newNode;
                newNode->next = currNode;
                catBag->head = newNode;
        } else if (currNode->next == NULL) {
                currNode->next = newNode;
                newNode->prev =currNode;
                catBag->tail = newNode;
        } else {
                prevNode->next = newNode;
                currNode->prev = newNode;
                newNode->next = currNode;
                newNode->prev = prevNode;
        }

}

void cleanup(){


}

void verifyName(char *n){
        while(!n[0]) {
                printf("The cats name cannot be empty, please re-enter: ");
                readString(n);
        }
}

void verifyID(int *i){
        if (i < 0 || i > 1999999999) {
                printf("The ID %d, is not valid. Pick a different ID (0 - 1999999999): ");
                readInt(&i);
                verifyGender(i);
        }
}

/*
    Function:  readString
    Purpose:   reads a string from standard input
        out:   string read in from the user
               (must be allocated in calling function)
 */
void readString(char *str)
{
        char tmpStr[MAX_STR];

        fgets(tmpStr, sizeof(tmpStr), stdin);
        tmpStr[strlen(tmpStr)-1] = '\0';
        strcpy(str, tmpStr);
}

/*
    Function:  readInt
    Purpose:   reads an integer from standard input
        out:   integer read in from the user
               (must be allocated in calling function)
 */

void readInt(int *x)
{
        char str[MAX_STR];

        readString(str);
        sscanf(str, "%d", x);
}
