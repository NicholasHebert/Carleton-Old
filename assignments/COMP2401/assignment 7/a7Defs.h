#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR  64
#define MAX_STR  32

typedef enum { MALE, FEMALE } GenderType;

typedef struct {
        int id;
        char name[MAX_STR];
        GenderType gender;
} CatType;

typedef struct Node {
        CatType     *data;
        struct Node *prev;
        struct Node *next;
} NodeType;

typedef struct {
        NodeType *head;
        NodeType *tail;
} CatListType;

void initCat(int, char*, GenderType, CatType**);
void initAllCats(CatListType**);
void addCat(CatType*, CatListType*);
void getCats(CatListType*);
void verifyGender(int*);
void verifyName(char*);
void cleanup();
void readInt(int*);
void reasString(char*);
