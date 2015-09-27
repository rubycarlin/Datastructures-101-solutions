#include <iostream>

#define MAX_SIZE 100

static int StackCount;
struct node{
	int data;
	struct node *next;
};

void GetData(int *n, int *data){
	printf("Enter the number of elements in the stack : ");
	scanf("%d", n);

	for(int i = 0; i < *n; i++){
		printf("Enter the element : ");
		scanf("%d", &data[i]);
	}
}

void PrintStack(struct node *top){
	struct node *temp = top;
	while(temp != NULL){
		printf("%d->", temp->data );
		temp = temp->next;
	}
	printf("\n");
}

struct node* NewNode(int data){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
}

void Push(struct node **top, int data){
	if(*top == NULL){
		(*top) = NewNode(data);
		StackCount++;
	}
	else if(StackCount >= MAX_SIZE){
		printf("Stack overflow\n");
	}
	else{
		struct node *temp = NewNode(data);
		temp->next = *top;
		*top = temp;
	}

}
int IsEmpty(struct node **top){
	if(*top == NULL){
		return(1);
	}
	else{
		return(0);
	}
}
void Pop(struct node **top){
	if(IsEmpty(top)){
		printf("Stack Underflow\n");
	}
	else{
		printf("Poped element : %d\n", (*top)->data);
		(*top) = (*top)->next;
	}
}


void InsertElements(int n, int *data, struct node **top){
	for(int i = 0; i < n; i++){
		Push(top, data[i]);
	}
}

void DeleteElements(struct node **top){
	char ch = 'y';
	while(ch == 'y'){
		printf("Do you want to delete (y/n) : ");
		ch = getchar();
		switch(ch){
			case 'y':
				Pop(top);
				break;
			case 'n':
				return;
			default:
				ch = 'y';
		}
	}
}
void Stack(){
	int n, data[100];
	struct node *top = NULL;
	GetData(&n, data);
	InsertElements(n, data, &top);
	PrintStack(top);
	DeleteElements(&top);
	PrintStack(top);

}
void Operations(){
	int data;
	struct node *top = NULL;
	Push(&top,data);
	Pop(&top);
	IsEmpty(&top);
}
int main(){
	Stack();
	return(0);
}



