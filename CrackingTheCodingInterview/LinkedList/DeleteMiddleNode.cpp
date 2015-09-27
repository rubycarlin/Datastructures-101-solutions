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
struct node *getMiddleNode(struct node *head){
	struct node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return(slow);
}
void DeleteMiddleNode(struct node *middleNode){
	cout << "Middle node : " << middleNode->data << endl;
	//This code will not work if the node to be deleted is last
	if(middleNode == NULL || middleNode->next == NULL){
		printf("Cannot be deleted\n");
		return;
	}
	struct node *temp = middleNode->next;
	middleNode->data = middleNode->next->data;
	middleNode->next = middleNode->next->next;
	free(temp);
	
}
int main(){
	struct node *head = NULL;
	CreateList(&head);
	struct node *middleNode = getMiddleNode(head);
	DeleteMiddleNode(middleNode);
	PrintList(head);
	return(0);
}

