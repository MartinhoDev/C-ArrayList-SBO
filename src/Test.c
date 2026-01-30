#include "Test.h"

void printList(ArrayList* arrayList){
    printf("[");
    for(size_t i = 0; i < arrayList->count; i++){
        printf("%hd", (*(short*)ArrayList_get(arrayList, i)));
        if(i != arrayList->count - 1){
            printf(", ");
        }
    }
    printf("]");
    return;
}

void menuSmall(){
    ArrayList numberList;
    char cursor;
    short shortBuffer, exe = TRUE;
    size_t indexBuffer;
    void *ptr = NULL;

    switch(ArrayList_new(&numberList, sizeof(short))){
        case FALSE:
            fprintf(stderr, "Error when creating Array List, closing program...\n");
            exit(1);
    }

    while(exe){
        printf("\nMenu:\n");
        printf("Actual list: ");
        printList(&numberList);
        printf("\n");
        printf("1 - Add number to list\n");
        printf("2 - Remove number by index\n");
        printf("3 - Get number by index\n");
        printf("4 - Check capacity and count\n");
        printf("0 - Exit\n");
        printf("Select an option: ");
        scanf(" %c", &cursor);

        switch(cursor){
            case '1':
                printf("Type a number: ");
                scanf("%hd", &shortBuffer);
                switch(ArrayList_add(&numberList, &shortBuffer, sizeof(short))){
                    case TRUE:
                        printf("Added to the list successfully!\n");
                        break;
                    case FALSE:
                        fprintf(stderr, "Error when adding to list!\n");
                        break;
                }
                break;
            case '2':
                printf("Type an index: ");
                scanf("%zu", &indexBuffer);
                switch(ArrayList_remove(&numberList, indexBuffer)){
                case TRUE:
                    printf("Removed sucessufully!\n");
                    break;
                case FALSE:
                    fprintf(stderr, "Error when removing from list!\n");
                    break;
                }
                break;
            case '3':
                printf("Type an index: ");
                scanf("%zu", &indexBuffer);
                ptr = ArrayList_get(&numberList, indexBuffer);
                if(!ptr){
                    printf("Error when getting from the list!\n");
                } else{
                    printf("The number is: %hd\n", *((short*)ptr));
                }
                break;
            case '4':
                printf("Capacity: %zu || Count: %zu\n", numberList.capacity, numberList.count);
                break;
            case '0':
                ArrayList_delete(&numberList);
                exe = FALSE;
                printf("Array List deleted sucefully, closing program!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }
}

void menuBig(){
    ArrayList namesList;
    char cursor;
    short exe = TRUE;
    size_t indexBuffer;
    char nameBuffer[1024];
    void *ptr = NULL;

    switch(ArrayList_new(&namesList, 1024)){
        case FALSE:
            fprintf(stderr, "Error when creating Array List, closing program...\n");
            exit(1);
    }

    while(exe){
        printf("\nMenu:\n");
        printf("1 - Add name to list\n");
        printf("2 - Remove name by index\n");
        printf("3 - Get name by index\n");
        printf("4 - Check capacity and count\n");
        printf("0 - Exit\n");
        printf("Select an option: ");
        scanf(" %c", &cursor);

        switch(cursor){
            case '1':
                printf("write a name: ");
                scanf(" %1023[^\n]", nameBuffer); getchar();
                switch(ArrayList_add(&namesList, nameBuffer, 1024)){
                    case TRUE:
                        printf("Added to the list successfully!\n");
                        break;
                    case FALSE:
                        fprintf(stderr, "Error when adding to list!\n");
                        break;
                }
                break;
            case '2':
                printf("Type an index: ");
                scanf("%zu", &indexBuffer);
                switch(ArrayList_remove(&namesList, indexBuffer)){
                case TRUE:
                    printf("Removed sucessufully!\n");
                    break;
                case FALSE:
                    fprintf(stderr, "Error when removing from list!\n");
                    break;
                }
                break;
            case '3':
                printf("Type an index: ");
                scanf("%zu", &indexBuffer);
                ptr = ArrayList_get(&namesList, indexBuffer);
                if(!ptr){
                    printf("Error when getting from the list!\n");
                } else{
                    printf("The name is: %s\n", (char*)ptr);
                }
                break;
            case '4':
                printf("Capacity: %zu || Count: %zu\n", namesList.capacity, namesList.count);
                break;
            case '0':
                ArrayList_delete(&namesList);
                exe = FALSE;
                printf("Array List deleted sucefully, closing program!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }
}

void testStart(int argc, char** argv){
    if(argc != 2){
        fprintf(stderr, "Please, insert a valid type of test in the command line...\n");
        fprintf(stderr, "Ex: ./ArrayList.bin <test_type>\n");
        fprintf(stderr, "1-Small data || 2-Big data\n");
        exit(1);
    }
    switch((*argv[1])){
        case '1':
            menuSmall();
            break;
        case '2':
            menuBig();
            break;
        default:
            fprintf(stderr, "Please, insert a valid type of test in the command line...\n");
            fprintf(stderr, "Ex: ./ArrayList.bin <test_type>\n");
            fprintf(stderr, "1-Small data || 2-Big data\n");
            exit(1);
    }
    return;
}