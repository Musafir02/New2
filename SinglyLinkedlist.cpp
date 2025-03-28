#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
} *start = NULL;

void create();
void Delete();
void display();

int main() {
    int ch;

    while (1) {
        printf("\n\n1. Create\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: Delete(); break;
            case 3: display(); break;
            case 4: return 0;  // Exit the program properly
            default: printf("\nWrong choice! Try again.");
        }
    }
}

// Function to create a new node and add it to the linked list
void create() {
    struct Node *p, *q;
    p = (struct Node*)malloc(sizeof(struct Node));

    if (!p) {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter data: ");
    scanf("%d", &p->info);
    p->next = NULL;

    if (start == NULL) {
        start = p;
    } else {
        q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }

    printf("\nNode added successfully!");
}

// Function to delete a node by value from the linked list
void Delete() {
    struct Node *q, *r;
    int n, found = 0;

    if (start == NULL) {
        printf("\nLinked list is empty!");
        return;
    }

    printf("\nEnter number to be deleted: ");
    scanf("%d", &n);

    q = start;
    
    // If the node to delete is the first node
    if (q->info == n) {
        start = q->next;
        free(q);
        printf("\nElement deleted successfully!");
        return;
    }

    // Searching for the node to delete
    while (q != NULL && q->info != n) {
        r = q;  // Keep track of the previous node
        q = q->next;
    }

    // If the node was not found
    if (q == NULL) {
        printf("\nNo such element in the linked list!");
        return;
    }

    // Deleting the found node
    r->next = q->next;
    free(q);
    printf("\nElement deleted successfully!");
}

// Function to display the linked list
void display() {
    struct Node *q;
    
    if (start == NULL) {
        printf("\nLinked list is empty!");
        return;
    }

    q = start;
    printf("\nLinked list elements: ");
    while (q != NULL) {
        printf("%d -> ", q->info);
        q = q->next;
    }
    printf("NULL\n");
}

