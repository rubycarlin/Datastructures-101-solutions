#include<iostream>

#define MAX_SIZE 10

struct node{
	int data;
	struct node* next;
};

void GetData(int *n, int *data){
	printf("Enter the number of elements in the queue : ");
	scanf("%d", n);

	for(int i = 0; i < *n; i++){
		printf("Enter the element : ");
		scanf("%d", (data + i));
	}
}
struct node* NewNode(int data){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return(temp);
}
void PrintQueue(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("\n");
}
void Enqueue(struct node **head, int data){
	static int count;
	if(*head == NULL && count <= MAX_SIZE){
		*head = NewNode(data);
		count++;
	}
	else if(count <= MAX_SIZE){
		struct node *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = NewNode(data);
		count++;
	}
	else{
		printf("Stack overflow\n");
	}
}
void CreateQueue(int n, int *data, struct node **head){
	for(int i = 0; i < n; i++){
		Enqueue(head, data[i]);
	}
	PrintQueue(*head);
}
void Dequeue(struct node **head){
	if(*head == NULL){
		printf("Queue underflow\n");
	}
	else{
		(*head) = (*head)->next;
	}
}
void DequeueElements(struct node **head){
	int n;
	printf("Enter the number of elements to be dequeued : ");
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		Dequeue(head);
	}
}
void Queue(){
	int n, data[100];
	struct node *head = NULL;
	GetData(&n, data);
	CreateQueue(n, data, &head);
	DequeueElements(&head);
	PrintQueue(head);

}
int main(){
	Queue();
}

