#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* ptr;
    size_t size;
    char name[50];
    int isFree;
} Mem;
Mem memList[100];
int memCount = 0;
size_t totalGiven = 0, totalFreed = 0;

void* giveMem(size_t size, const char* name) {
    void* p = malloc(size);
    if (p) {
        totalGiven += size;
        printf("\n[INFO] Allocated %zu bytes for '%s' at address %p\n", size, name, p);
        memList[memCount].ptr = p;
        memList[memCount].size = size;
        strcpy(memList[memCount].name, name);
        memList[memCount].isFree = 0;
        memCount++;
    } else {
        printf("\n[ERROR] Allocation failed for '%s'\n", name);
    }
    return p;
}

void freeMem(const char* name) {
    for (int i = 0; i < memCount; i++) {
        if (!memList[i].isFree && strcmp(memList[i].name, name) == 0) {
            free(memList[i].ptr);
            totalFreed += memList[i].size;
            memList[i].isFree = 1;
            printf("\n[INFO] Freed %zu bytes from '%s'\n", memList[i].size, name);
            return;
        }
    }
    printf("\n[WARNING] Variable '%s' not found or already freed.\n", name);
}
void showReport() {
    printf("\n=========== MEMORY USAGE REPORT ===========\n");
    printf("Total Memory Allocated: %zu bytes\n", totalGiven);
    printf("Total Memory Freed   : %zu bytes\n", totalFreed);
    if (totalGiven > totalFreed) {
        printf("Memory Leak Detected : %zu bytes not freed\n", totalGiven - totalFreed);
        printf("\nLeaked Blocks:\n");
        for (int i = 0; i < memCount; i++) {
            if (!memList[i].isFree) {
                printf("  - '%s' at %p (%zu bytes)\n", memList[i].name, memList[i].ptr, memList[i].size);
            }
        }
    } else {
        printf("All memory successfully freed. No leaks detected.\n");
    }
    printf("===============\n");
}
void showMenu() {
    printf("\n=========================\n");
    printf("         MEMORY TRACKER OPTIONS        \n");
    printf("===========================\n");
    printf("1. Allocate Memory\n");
    printf("2. Free Memory\n");
    printf("3. Show Memory Report\n");
    printf("0. Exit\n");
    printf("===========================\n");
    printf("Enter your choice: ");
}
int main() {
    int choice;
    printf("\n");
    printf("        Welcome to the Memory Tracker       \n");
    printf("  Monitor allocations and detect memory leaks\n");
    printf("============================================\n");
    do {
        showMenu();
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            char name[50];
            int size;
            printf("\nEnter variable name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            printf("Enter size in bytes: ");
            scanf("%d", &size);
            getchar();
            giveMem(size,name);
        } else if(choice == 2) {
            char name[50];
            printf("\nEnter variable name to free: ");
            fgets(name,sizeof(name), stdin);
            name[strcspn(name,"\n")] = 0;
            freeMem(name);
        } else if (choice==3) {
            showReport();
        } else if (choice!= 0) 
            printf("\nERROR Invalid option.\n");
    } while (choice != 0);
    printf("\nExiting program and displaying final report...\n");
    showReport();
    return 0;
}
