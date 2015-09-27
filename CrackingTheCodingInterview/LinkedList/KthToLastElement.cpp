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
void KthToLastElement(struct node *head, int k){
	struct node *slow = head, *fast = head;
	int k_copy = k;
	while(k_copy && fast != NULL){
		fast = fast->next;
		k_copy--;
	}
	if(k_copy){
		printf("No such node exist\n");
		return;
	}
	while(NULL != fast){
		slow = slow->next;
		fast = fast->next;
	}
	printf("%dth node from end is %d\n",k, slow->data );
}
int main(){
	struct node *head = NULL;
	CreateList(&head);
	int k;
	printf("Enter the position of K from the end : ");
	scanf("%d", &k);
	KthToLastElement(head, k);
	PrintList(head);
	return(0);
}

