#include <stdio.h>
#include <conio.h>
#include <stddef.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *address;
};

struct node *start = NULL, *temp, *new1, *prev, *next;

void create();
void display();
void finsert();
void linsert();
void ascinsert();
void deletef();
void deleteb();
void deleteAfterPosition();
void traverseList();

void main() {
    int choice;
    do {
        printf("\n ------Linked List Menu------");
        printf("\n 1. Create");
        printf("\n 2. Display");
        printf("\n 3. Insert First");
        printf("\n 4. Insert Last");
        printf("\n 5. Insert in Ascending Order");
        printf("\n 6. Delete First Node");
        printf("\n 7. Delete Before Specified Node");
        printf("\n 8. Delete After Specified Position");
        printf("\n 9. Traverse Linked List");
        printf("\n ----------------------------");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: finsert(); break;
            case 4: linsert(); break;
            case 5: ascinsert(); break;
            case 6: deletef(); break;
            case 7: deleteb(); break;
            case 8: deleteAfterPosition(); break;  // Removed parentheses
            case 9: traverseList(); break;  // Removed parentheses
            default: printf("\n Invalid choice\n");
        }
    } while (choice != 10);
}

void create() {
    char ch;
    int n;
    printf("Enter element: ");
    scanf("%d", &n);

    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->address = NULL;
    temp = start;

    printf("\n Want to continue (Y/N)? ");
    ch = getch();

    while (ch == 'Y' || ch == 'y') {
        printf("\n Enter next element: ");
        scanf("%d", &n);

        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->address = NULL;

        temp->address = new1;
        temp = temp->address;

        printf("\n Want to continue (Y/N)? ");
        ch = getch();
    }
}

void display() {
    if (start == NULL) {
        printf("\n List is empty\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->address;
        }
        printf("NULL\n");
    }
}

void finsert() {
    int n;
    if (start == NULL) {
        printf("List not found\n");
    } else {
        printf("Enter new element for insert: ");
        scanf("%d", &n);

        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->address = start;
    }
    start = new1;
}

void linsert() {
    int n;
    if (start == NULL) {
        printf("List not found\n");
    } else {
        printf("Enter new element for insert: ");
        scanf("%d", &n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->address = NULL;
        temp = start;
        while (temp->address != NULL) {
            temp = temp->address;
        }
        temp->address = new1;
    }
}

void ascinsert() {
    int n;
    if (start == NULL) {
        printf("List not found\n");
    } else {
        printf("Enter element for insert: ");
        scanf("%d", &n);
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->address = NULL;
        temp = start;

        while (temp->address != NULL && temp->address->data < n) {
            temp = temp->address;
        }
        new1->address = temp->address;
        temp->address = new1;
    }
}

void deletef() {
    if (start == NULL) {
        printf("List not found\n");
    } else {
        temp = start;
        start = start->address;
        printf("Deleted node is %d\n", temp->data);
        free(temp);
    }
}

void deleteb() {
    int n;
    if (start == NULL) {
        printf("List not found\n");
    } else {
        printf("Enter element before which to delete: ");
        scanf("%d", &n);
        temp = start;
        while (temp->address != NULL && temp->address->data != n) {
            prev = temp;
            temp = temp->address;
        }
        if (temp == start) {
            printf("No node before the first node\n");
        } else {
            prev->address = temp->address;
            printf("Deleted node is %d\n", temp->data);
            free(temp);
        }
    }
}

void deleteAfterPosition() {
    int pos, i;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position after which node should be deleted: ");
    scanf("%d", &pos);

    temp = start;
    for (i = 0; temp != NULL && i < pos; i++) {
        temp = temp->address;
    }

    if (temp == NULL || temp->address == NULL) {
        printf("No node exists after the specified position.\n");
        return;
    }

    struct node* nodeToDelete = temp->address;
    temp->address = nodeToDelete->address;

    printf("Deleted node after position %d is %d\n", pos, nodeToDelete->data);
    free(nodeToDelete);
}

void traverseList() {
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = start;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->address;
    }
    printf("NULL\n");
}
