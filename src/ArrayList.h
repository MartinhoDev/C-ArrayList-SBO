#ifndef ARRAYLIST_H
#define ARRAYLIST_H

//Libraries
#include "Commons.h"

//Defines
#define INITIAL_CAPACITY 10

//Functions
/*Create base structure of ArrayList*/
unsigned short ArrayList_new(ArrayList* arrayList, size_t typeSize);

/**/
void ArrayList_delete(ArrayList* arrayList);

/**/
unsigned short ArrayList_expand(ArrayList* arrayList);

/**/
unsigned short ArrayList_add(ArrayList* arrayList, void* dataPtr, size_t dataSize);

/**/
unsigned short ArrayList_remove(ArrayList* arrayList, size_t index);

/**/
void* ArrayList_get(const ArrayList* arrayList, size_t index);

#endif