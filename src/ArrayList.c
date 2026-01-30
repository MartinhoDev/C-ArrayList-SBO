#include "ArrayList.h"

unsigned short ArrayList_new(ArrayList* arrayList, size_t typeSize){
    MemoryCell* array = NULL;

    arrayList->capacity = INITIAL_CAPACITY;
    arrayList->count = 0;
    arrayList->typeControl = typeSize;
    array = (MemoryCell*) calloc(INITIAL_CAPACITY, sizeof(MemoryCell));
    if(!array){
        return FALSE;
    }
    arrayList->array = array;
    return TRUE;
}

void ArrayList_delete(ArrayList* arrayList){
    for(size_t i = 0; i < arrayList->count; i++){
        switch(arrayList->array[i].mode){
            case(M_BIG):
                free(arrayList->array[i].data.ptr);
                break;
            case(M_SMALL):
                break;
        }
    }
    free(arrayList->array);
    arrayList->array = NULL;
    arrayList->count = 0;
    arrayList->typeControl = 0;
    arrayList->capacity = 0;
    return;
}

unsigned short ArrayList_expand(ArrayList* arrayList){
    MemoryCell* ptr = NULL;
    size_t newCapacity = arrayList->capacity + (arrayList->capacity / 2);

    ptr = (MemoryCell*) realloc(arrayList->array, (newCapacity * sizeof(MemoryCell)));
    if(!ptr) return FALSE;
    arrayList->array = ptr;
    arrayList->capacity = newCapacity;
    return TRUE;
}

unsigned short ArrayList_add(ArrayList* arrayList, void* dataPtr, size_t dataSize){
    unsigned short control = TRUE;
    void* ptr = NULL;

    if(!arrayList) return FALSE;
    if(!dataPtr) return FALSE;
    if(dataSize == 0) return FALSE;
    if(dataSize != arrayList->typeControl) return FALSE;

    if(arrayList->count == arrayList->capacity){
        control = ArrayList_expand(arrayList);
        if(control == FALSE) return FALSE;
    }

    if(dataSize <= MAX_SIZE){
        memcpy(arrayList->array[arrayList->count].data.data, dataPtr, dataSize);
        arrayList->array[arrayList->count].mode = M_SMALL;
    }else{
        ptr = (void*) calloc(1, dataSize);
        if(!ptr) return FALSE;
        memcpy(ptr, dataPtr, dataSize);
        arrayList->array[arrayList->count].data.ptr = ptr;
        arrayList->array[arrayList->count].mode = M_BIG;
    }
    arrayList->count++;
    return TRUE;
}

unsigned short ArrayList_remove(ArrayList* arrayList, size_t index){
    if(!arrayList) return FALSE;
    if(index >= arrayList->count) return FALSE;

    if(arrayList->array[index].mode == M_BIG){
        free(arrayList->array[index].data.ptr);
    }

    for(size_t i = index; i < arrayList->count - 1; i++){
        arrayList->array[i] = arrayList->array[i+1];
    }
    arrayList->count--;
    return TRUE;
}

void* ArrayList_get(const ArrayList* arrayList, size_t index){
    if(!arrayList) return NULL;
    if(index >= arrayList->count) return NULL;

    switch(arrayList->array[index].mode){
        case(M_BIG):
            return arrayList->array[index].data.ptr;
            break;
        case(M_SMALL):
            return (void*) arrayList->array[index].data.data;
            break;
    }
    return NULL;
}