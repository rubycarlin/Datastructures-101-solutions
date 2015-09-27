#include<iostream>

struct node{
	int data;
	struct node *next;
};

struct node* NewNode(int data){
	struct node *temp = new struct node;
	temp->data = data;
	temp->next = NULL;
	return(temp);
}
struct node* GetTail(struct node *head){
	struct node *curr = head;
	while(curr->next != head){
		curr = curr->next;
	}
	return(curr);
}
void PrintCLL(struct node *head){
	struct node *curr = head->next;
	printf("%d->",head->data );
	while(curr != head){
		printf("%d->",curr->data );
		curr = curr->next;
	}
	printf("\n");
}
void InsertNode(struct node **head, int data){
	struct node *temp = NewNode(data);
	if(*head == NULL){
		*head = temp;
		(*head)->next = *head;
	}
	else{
		struct node *tail = GetTail(*head);
		tail->next = temp;
		temp->next = *head;
	}
}
void CreateCLL(struct node **head){
	int n;
	printf("Enter the numebr of elements : ");
	scanf("%d",&n);
	for(int i =0; i < n; i++){
		int ele;
		printf("Enter the element : ");
		scanf("%d", &ele);
		InsertNode(head, ele);
	}
}

void CircularLinkedList(){
	struct node *head = NULL;
	CreateCLL(&head);
	PrintCLL(head);
}
void Operations(){

}
int main(){
	
	CircularLinkedList();
	return(0);
}

