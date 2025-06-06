#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1; // -1 indicates an empty slot
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }

    if (i == SIZE) {
        printf("Hash table is full\n");
        return;
    }

    hashTable[(index + i) % SIZE] = key;
}

int search(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i) % SIZE] == key)
            return (index + i) % SIZE;
        i++;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: ~\n", i);
    }
}

int main() {
    init();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(20);

    printf("Hash Table:\n");
    display();

    int key = 15;
    int pos = search(key);
    if (pos != -1)
        printf("\nKey %d found at index %d\n", key, pos);
    else
        printf("\nKey %d not found\n", key);

    return 0;
}
