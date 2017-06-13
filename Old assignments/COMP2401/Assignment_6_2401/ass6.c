/*Author: Nicholas Hebert (100954895)
Purpose: This program will ask a user to identify cats to then be put into a list of cats
Sources: Christine's slides and source code.
Headers: <stdio.h>, <string.h>, <stdlib.h>, "A6Defs.h"
DataFiles: N/A*/

#include <stdio.h>
#include <stdlib.h>
#include "A6Defs.h"

//functions that will be used in this program
void addTheKitty (CatArrType*, CatType*);
void verifyGender(int*);
void verifyDOB(DOBType*);
void verifyID(int*);
void verifyName(char*);
void cleanup(CatArrType*);
void printTheCat(CatType*);
void readString(char*);
void readInt(int*);

int main()
{
    //Our empty "cat bag"
    CatArrType catList;
    catList.size = 0;

    //prep variables that will be used to init the cat object
    int catID, i;
    char gen;
    char catName[MAX_STR];
    GenderType gender;
    DOBType birthday;
    CatType *thisCat;

    //gather user information about cat while also verifying data
    printf("Name the cat -1 to stop...\n");
    while(catList.size<MAX_ARR){
        printf("\nEnter the cats name(or -1 to quit): ");
        readString(catName);
        verifyName(catName);
        if (strcmp(catName, "-1") == 0){
            break;
        }

        printf("Enter the cats gender(0 for male, 1 for female): ");

        readInt(&gen);
        verifyGender(gen);
        gender = gen;
        printf("Enter the cats date of birth...\n");

        printf("The cat was born in which MONTH? (1-12): ");
        readInt(&birthday.month);
        printf("The cat was born in which YEAR? (0-4000): ");
        readInt(&birthday.year);
        verifyDOB(&birthday);

        printf("Enter the cats ID: ");
        readInt(&catID);
        verifyID(catID);
    
        //init the cat then add the cat to the list of cats
        initCat(catID, catName, gender, birthday.month, birthday.year, &thisCat);
        addTheKitty(&catList, thisCat);
    }
    
    //print all cats
    for(i = 0; i < catList.size; i++){
        printTheCat(catList.elements[i]);
    }

    //send all cats to a nice place
    cleanup(catList);
    return 0;
}

//this function sends the cats to a nice place by itterating through and using the function "free"
void cleanup(CatArrType *arr)
{
  int i;

  for (i=0; i<((arr)->size); i++) {
    free(arr->elements[i]);
  }
  free(arr->elements);
}

//this function prints one cat object
void printTheCat(CatType *theCat){
    printf("\n");
    printf("Cat ID: %d\nName:   %s\nDate of birth(m/y): %d/%d\nGender: ", theCat->id, theCat->name, theCat->dob.month, theCat->dob.year);
    if (theCat->gender == 0){
        printf("female\n");
    } else {
        printf("male\n");
    }
}

//this function appends the cat to the array of cats
void addTheKitty (CatArrType *catBag, CatType *theKitty){
    (catBag)->elements[(catBag)->size] = theKitty;
    (catBag)->size++;
}

//this function inits the cat with the information gathered in main()
void initCat(int i, char *n, GenderType g, int m, int y, CatType **cat){
    *cat = (CatType *) malloc(sizeof(CatType));

    strcpy((*cat)->name, n);
    (*cat)->id = i;
    (*cat)->gender = g;
    (*cat)->dob.month = m;
    (*cat)->dob.year = y;
}

//function checks if the "string" is empty and corrects if it is 
void verifyName(char *n){
    while(!n[0]){
        printf("The cats name cannot be empty, please re-enter: ");
        readString(n);
    }
}

//function makes sure ID is reasonable. Max int value is 2.14bil, limit set to 2bil
void verifyID(int *i){
if (i < 0 || i > 1999999999){
        printf("The ID %d, is not valid. Pick a different ID (0 - 1999999999): ");
        readInt(&i);
        verifyGender(i);
    }
}

//function verifies date of birth is reasonable and prints sarcasm if its not
void verifyDOB(DOBType *b){
    while(b->month > 12 || b->month < 1){
        printf("%d is not a valid month, please re-enter (1-12): ",b->month);
        readInt(&b->month);
    }

    while(b->year > 4000 || b->year < 0){
        if(b->year > 4000){printf("The year %d is pretty far from now...\n", b->year);}
        if(b->year < 0){printf("Your cat is too old...\n");}
        printf("Please re-enter the cats year of birth (0-4000): ");
        readInt(&b->year);
    }
}

//function verifies the user has inputted a binary int
void verifyGender(int *g){
    if (g != 0 && g != 1){
        printf("The number you have entered does not correspond to a gender, please try again... (0 or 1): ");
        readInt(&g);
        verifyGender(g);
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


