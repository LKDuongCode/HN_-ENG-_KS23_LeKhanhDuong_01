#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void printMenu(); 
void printList(struct Node* head);

void addToHead(struct Node** head, int newData);
void addToTail(struct Node** head, int newTail);

void addAtPos(struct Node** head, int value, int pos);
void deleteFromHead(struct Node** head);
void deleteFromTail(struct Node** head);
void deleteByValue(struct Node** head, int deleteValue);
void searchByValue(struct Node* head, int searchValue);


int main() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));  
    head->data = 10;  
    head->next = (struct Node*)malloc(sizeof(struct Node)); 
    head->next->data = 20; 
    head->next->next = NULL; 
    
    
    int choice;
    int value;
    int position;

    do {
 		printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\t \t \t \t Nhap gia tri phan tu moi: ");
                int newData;
                scanf("%d", &newData);
                addToHead(&head, newData);
                printList(head);
                break;
            case 2:
                printf("\t \t \t \t nhap gia tri phan tu moi: ");
                int newTail;
                scanf("%d", &newTail);
                addToTail(&head, newTail);
                printList(head);
                break;
            case 3:
                printf("\t \t \t \t Nhap vi tri muon chen: ");
                int newDataInsert;
            	int insertPos;
            	scanf("%d", &insertPos);
            	printf("\t \t \t \t Nhap gia tri chen:");
            	scanf("%d",&newDataInsert);
                
                addAtPos(&head, newDataInsert, insertPos);
                printList(head);
                break;
            case 4:
                deleteFromHead(&head);
                printList(head);
                break;
            case 5:
                deleteFromTail(&head);
                printList(head);
                break;
            case 6:
                printf("\t \t \t \t Nhap gia tri phan tu can xoa: ");
                int deleteValue;
                scanf("%d", &deleteValue);
                deleteByValue(&head, deleteValue);
                printList(head);
                break;
            case 7:
                printf("\t \t \t \t Nhap gia tri can tim: ");
                int searchValue;
                scanf("%d", &searchValue);
                searchByValue(head, searchValue);
                printList(head);
                break;
            case 8:
                printList(head);
                break;
            case 9:
                printf("\t \t \t \t thoat chuong trinh!\n");
                break;
            default:
                printf("\t \t \t \t lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

void printMenu() {
    printf("\t \t \t \t ================== [MENU] =================\n");
    printf("\n");
    printf("\t \t \t \t [1]. Chen phan tu vao dau linked list\n");
    printf("\t \t \t \t [2]. Chen phan tu vao cuoi linked list\n");
    printf("\t \t \t \t [3]. Chen phan tu vao vi tri cu the\n");
    printf("\t \t \t \t [4]. Xoa phan tu dau linked list\n");
    printf("\t \t \t \t [5]. Xoa phan tu cuoi linked list\n");
    printf("\t \t \t \t [6]. Xoa phan tu theo gia tri\n");
    printf("\t \t \t \t [7]. Tim kiem phan tu theo gia tri\n");
    printf("\t \t \t \t [8]. In cac gia tri ra man hinh\n");
    printf("\t \t \t \t [9]. Thoat\n");
    printf("\n");
    printf("\t \t \t \t -----------------------------------------\n");
    printf("\t \t \t \t Nhap lua chon: ");
}

void printList(struct Node* head) {
	//b1 kiem tra rong
    if (head == NULL) {
        printf("\t \t \t \t danh sach trong!\n");
        return;
    }
	
	//b2 duyet ds
    struct Node* temp = head; // tao con tro duyet
    printf("\t \t \t \t ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void addToHead(struct Node** head, int newData) {
	//b1 tao node moi
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //b2 gan gia tri va con tro
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void addToTail(struct Node** head, int newTail) {
	//b1 tao node moi
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newTail;
    newNode->next = NULL;
    
	//kiem tra rong
    if (*head == NULL) {
        *head = newNode;
        return;
    }
	
	//b2 duyet den cuoi va thay con tro
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addAtPos(struct Node** head, int value, int pos) {
	//b1 kiem tra vi tri
    if (pos < 1) {
        printf("\t \t \t \t Vi tri them khong hop le!\n");
        return;
    }
	
	//b2 tao node moi
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

	// b3 thay doi con tro ow vi tri can them
	// neu vi tri dau
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

	// neu vi tri lon hon 1
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\t \t \t \t vi tri vuot qua danh sach!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromHead(struct Node** head) {
	//b1 kiem tra rong
    if (*head == NULL) {
        printf("\t \t \t \t danh sach trong!\n");
        return;
    }
	
	//b2 thay doi con tro va giai phong node xoa
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromTail(struct Node** head) {
	//b1 kiem tra rong va kiem tra co 1 phan tu
    if (*head == NULL) {
        printf("\t \t \t \t danh sach trong!\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
	
	// b2 duyet den cuoi va thay doi con tro
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteByValue(struct Node** head, int deleteValue) {
	//b1 kiem tra rong
    if (*head == NULL) {
        printf("\t \t \t \t danh sach trong!\n");
        return;
    }

    struct Node* temp = *head;
	
	//b2 tim kiem gia tri trong ds
    if ((*head)->data == deleteValue) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->next->data != deleteValue) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("\t \t \t \t khong tim thay phan tu co gia tri %d\n", deleteValue);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void searchByValue(struct Node* head, int searchValue) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            printf("\t \t \t \t tim thay phan tu co gia tri %d\n", searchValue);
            return;
        }
        temp = temp->next;
    }
    printf("\t \t \t \t khong tim thay phan tu co gia tri %d\n", searchValue);
}


