#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Delete from Beginning
void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    free(temp);
}

// Delete from End
void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete from Given Position
void deleteFromPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    if (position == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;

        free(temp);
        return;
    }

    struct Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);
}

// Display Linked List
void display(struct Node *head) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at End (to create the list)
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    struct Node *head = NULL;

    int choice, value, position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Given Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertAtEnd(&head, value);
                break;

            case 2:
                deleteFromBeginning(&head);
                break;

            case 3:
                deleteFromEnd(&head);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &position);

                deleteFromPosition(&head, position);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}