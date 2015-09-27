#include <iostream>
#include <map>
using namespace std;

struct node{
	int data;
	struct node *next;
};
struct node *NewNode(int data){
	struct node *temp = new struct node;
	temp->data = data;
	temp->next = NULL;
	return(temp);
}
void InsertNode(struct node **head, int data){
	struct node *temp = NewNode(data);

	if(NULL == *head){
		*head = temp;
	}
	else{
		struct node *curr = *head;
		while(NULL != curr->next){
			curr = curr->next;
		}
		curr->next = temp;
	}
}
void CreateList(struct node **head){
	int n;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	int data;
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		InsertNode(head, data);
	}
}

void PrintList(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("\n");
}

void PartitionLinkedList(struct node *head, int x){
	
	struct node *curr = head;
	struct node *greater_than_x = head;
	while(curr != NULL){
		if(curr->data < x)
			greater_than_x = greater_than_x->next;
		curr = curr->next;
	}
	

	curr = head;
	while(greater_than_x != NULL){
		cout << curr->data << "\t" << greater_than_x->data << endl;
		if(curr->data >= x && greater_than_x->data >= x){
			int temp = curr->data;
			curr->data = greater_than_x->data;
			greater_than_x->data = temp;
			greater_than_x = greater_than_x->next;
			continue;
		}
		if(curr->data >= x && greater_than_x->data < x){
			int temp = curr->data;
			curr->data = greater_than_x->data;
			greater_than_x->data = temp;
			curr = curr->next;
			greater_than_x = greater_than_x->next;
			continue;
		}
		if(curr->data < x)
			curr = curr->next;
		if(greater_than_x->data >= x)
			greater_than_x = greater_than_x->next;
	}

}
void CreateLoop(struct node *head){
	struct node *randPtr = head, *tail = head;
	int c = 3;
	while(tail->next != NULL){
		if(c > 1){
			randPtr = randPtr->next;
			c--;
		}
		tail = tail->next;
	}

	tail->next = randPtr;
}

void DetectLoop(struct node *head){
	struct node *slowPtr = head, *fastPtr = head;
	do{
		if(slowPtr == NULL || fastPtr == NULL || fastPtr->next == NULL){
			printf("No loop in the linked list\n");
			return;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}while(slowPtr != fastPtr);
	slowPtr = head;
	while(slowPtr != fastPtr){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	printf("Loop begins at %d \n", slowPtr->data);
}
int main(){
	struct node *head = NULL;
	CreateList(&head);
	CreateLoop(head);
	DetectLoop(head);
//	PrintList(head);
	return(0);
}

