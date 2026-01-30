#ifndef COMMONS_H
#define COMMONS_H

//Libraries
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

//Defines
#define TRUE 1
#define FALSE 0
#define HEADER_SIZE 8
#define MAX_SIZE (64 - HEADER_SIZE)

//Enums
typedef enum{
    M_SMALL,
    M_BIG
} Modes;

//Unions
typedef union{
    void* ptr;
    char data[MAX_SIZE];
} MemoryBlob;

//Structs
typedef struct{
    Modes mode;
    MemoryBlob data;
} MemoryCell;

typedef struct{
    size_t capacity;
    size_t count;
    size_t typeControl;
    MemoryCell* array;
} ArrayList;

#endif