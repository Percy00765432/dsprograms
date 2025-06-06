#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;
    struct Node *curr = *head, *prev = NULL;
    while (curr->data != key) {
        if (curr->next == *head) return;
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == *head && prev == NULL) {
        free(curr);
        *head = NULL;
        return;
    }
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = curr->next;
        prev->next = *head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    printf("List: ");
    printList(head);
    deleteNode(&head, 2);
    printf("After deletion: ");
    printList(head);
    return 0;
}