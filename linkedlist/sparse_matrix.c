#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, value;
    struct node *next;
};

struct node *createNode(int r, int c, int v) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->row = r;
    temp->col = c;
    temp->value = v;
    temp->next = NULL;
    return temp;
}

void insert(struct node **head, int r, int c, int v) {
    struct node *newnode = createNode(r, c, v);

    if (*head == NULL)
        *head = newnode;
    else {
        struct node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void display(struct node *head) {
    printf("\nRow\tCol\tValue\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    int m, n, i, j, x;
    struct node *head = NULL;

    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &x);

            if (x != 0) {
                insert(&head, i, j, x);
            }
        }
    }

    printf("\nSparse Matrix (Linked List Representation):");
    display(head);

    return 0;
}
