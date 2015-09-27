#include<iostream>

struct node{
	int data;
	struct node *ptr;
};

struct node* NewNode(int data){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->ptr = NULL;
	return(temp);
}

void PrintReverseMemoryEfficientDLL(struct node *head){
	struct node *next = NULL, *curr = head, *prev = NULL;
	while(curr != NULL){
		next = (struct node *)(void *)((uintptr_t)(curr->ptr) ^ (uintptr_t)(prev));
		prev = curr;
		curr = next;
	}
	while(prev != NULL){
		curr = prev;
		printf("%d->",curr->data);
		prev = (struct node *)(void *)((uintptr_t)(curr->ptr) ^ (uintptr_t)(next));
		next = curr;
	}
	printf("\n");
}
void PrintMemoryEfficientDLL(struct node *head){
	struct node *prev = NULL, *curr = head;
	while(curr != NULL){
		printf("%d->", curr->data);
		struct node *temp = curr;
		curr = (struct node *)(void *)((uintptr_t)(curr->ptr) ^ (uintptr_t)prev);
		prev = temp;
	}
	printf("\n");
}
void InsertNode(struct node **head, int data){
	if(*head == NULL){
		(*head) = NewNode(data);
	}
	else{
		struct node *curr = *head;
		while(curr->ptr != NULL){
			curr = curr->ptr;
		}
		curr->ptr = NewNode(data);
	}
}

void ConvertToDLL(struct node **head){
	struct node *prev = NULL, *next = NULL, *curr = *head;
	while(curr->ptr != NULL){
		next = curr->ptr;
		curr->ptr = (struct node *)(void *)((uintptr_t)prev ^ (uintptr_t)next);
		prev = curr;
		curr = next;
	}
	if(curr->ptr == NULL){
		curr->ptr = (struct node*)(void *)((uintptr_t)prev ^ (uintptr_t)NULL);
	}
}
void CreateMemoryEfficientDLL(int *n, struct node **head){
	printf("Enter the number of nodes : ");
	scanf("%d", n);

	int *data = (int*) malloc(sizeof(int) * (*n));
	for(int i = 0; i < *n; i++){
		printf("Enter the element : ");
		scanf("%d", &data[i]);
	}

	for(int i = 0; i < *n; i++){
		InsertNode(head, data[i]);
	}
	ConvertToDLL(head);
}
void MemoryEfficientDoublyLinkedList(){
	struct node *head = NULL;
	int n;
	CreateMemoryEfficientDLL(&n, &head);
	PrintMemoryEfficientDLL(head);
	PrintReverseMemoryEfficientDLL(head);
}
int main(){
	MemoryEfficientDoublyLinkedList();
	return(0);
}


