#include <stdio.h>
#include <stdlib.h>

// cau truc node
struct Node {
    int data;
    struct Node* next;
};

void addFirst(struct Node** head, int value);
void addLast(struct Node** head, int value);
void insertAtPosition(struct Node** head, int value, int position);
void deleteFirst(struct Node** head);
void deleteLast(struct Node** head);
void deleteByValue(struct Node** head, int value);
void searchByValue(struct Node* head, int value);
void printList(struct Node* head);


int main() {
    int choice, value, position;
    struct Node* head = NULL;  
    addFirst(&head, 20);  
    addFirst(&head, 10); 
    do {
        printf("==================menu=================\n");
        printf("1. them phan tu vao dau danh sach\n");
        printf("2. them phan tu vao cuoi danh sach\n");
        printf("3. chen phan tu vao vi tri cu the\n");
        printf("4. xoa phan tu dau danh sach\n");
        printf("5. xoa phan tu cuoi danh sach\n");
        printf("6. xoa phan tu theo gia tri\n");
        printf("7. tim kiem phan tu theo gia tri\n");
        printf("8. in danh sach cac gia tri ra man hinh\n");
        printf("9. thoat\n");
        printf("========================================\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("nhap gia tri phan tu: ");
                scanf("%d", &value);
                addFirst(&head, value);
                break;
            case 2:
                printf("nhap gia tri phan tu: ");
                scanf("%d", &value);
                addLast(&head, value);
                break;
            case 3:
                printf("nhap gia tri phan tu va vi tri: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("nhap gia tri phan tu can xoa: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 7:
                printf("nhap gia tri can tim: ");
                scanf("%d", &value);
                searchByValue(head, value);
                break;
            case 8:
                printList(head);
                break;
            case 9:
                printf("thoat chuong trinh!\n");
                break;
            default:
                printf("lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

void addFirst(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void addLast(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("vi tri khong hop le!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("vi tri vuot qua danh sach!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("danh sach trong!\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("danh sach trong!\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("danh sach trong!\n");
        return;
    }

    struct Node* temp = *head;

    if ((*head)->data == value) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("khong tim thay phan tu co gia tri %d\n", value);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void searchByValue(struct Node* head, int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("tim thay phan tu co gia tri %d\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("khong tim thay phan tu co gia tri %d\n", value);
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("danh sach trong!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

