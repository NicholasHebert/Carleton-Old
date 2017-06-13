#ifndef A6DEFS_H_INCLUDED
#define A6DEFS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR  64
#define MAX_STR  32

typedef enum { MALE, FEMALE } GenderType;

typedef struct {
        int month;
        int year;
} DOBType;

typedef struct {
        int id;
        char name[MAX_STR];
        GenderType gender;
        DOBType dob;
} CatType;

typedef struct {
        CatType *elements[MAX_ARR];
        int size;
} CatArrType;

void initCat(int, char*, GenderType, int, int, CatType**);

#endif // A6DEFS_H_INCLUDED
