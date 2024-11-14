#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("%d inserted at front\n", data);
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at end\n", data);
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; 
    }
    free(temp);
    printf("Last node deleted\n");
}

void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position or list is empty\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->prev == NULL) {
        printf("No node exists before the specified position\n");
        return;
    }
    struct Node* nodeToDelete = temp->prev;
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = temp; 
    } else {
        *head = temp; 
    }
    temp->prev = nodeToDelete->prev;
    free(nodeToDelete);
    printf("Node before position %d deleted\n", position);
}


void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL; 
    int choice, data, position;

    do {
        printf("\n---- Doubly Linked List Menu ----");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at End");
        printf("\n3. Delete Last Node");
        printf("\n4. Delete Node Before Specified Position");
        printf("\n5. Traverse List");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteLastNode(&head);
                break;
            case 4:
                printf("Enter position to delete node before: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 5:
                traverseList(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

   
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
