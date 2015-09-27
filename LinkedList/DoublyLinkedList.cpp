#include<iostream>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node* NewNode(int data){
	struct node *temp = new struct node;
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;
	return(temp);
}

struct node* GetLastNode(struct node *head){
	while(head->next != NULL){
		head = head->next;
	}
	return(head);
}
void PrintDLL(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("\n");
}
void PrintReverseDLL(struct node *head){
	struct node *tail = GetLastNode(head);
	while(tail != NULL){
		printf("%d->", tail->data);
		tail = tail->prev;
	}
	printf("\n");
}
void InsertNode(struct node **head, int data){
	struct node *temp = NewNode(data);
	if(*head == NULL){
		*head = temp;
	}
	else{
		struct node *curr = *head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		temp->prev = curr;
		curr->next = temp;
	}
}
void CreateDLL(struct node **head){
	int n;
	printf("Enter the number of elements in the DLL : ");
	scanf("%d",&n);
	int *data = new int[n];
	
	for(int i = 0; i <n ;i++){
		printf("Enter the value of the element : ");
		scanf("%d", &data[i]);
		InsertNode(head, data[i]);
	}

}
void DoublyLinkedList(){
	struct node *head = NULL;
	CreateDLL(&head);
	PrintDLL(head);
	PrintReverseDLL(head);

}
void Operations(){

}
int main(){
	DoublyLinkedList();
	return(0);
}


