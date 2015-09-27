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
void RemoveDuplicates(struct node *head){
	map<int, bool> hash_map;
	struct node *curr = head;
	hash_map[curr->data] = true;
	while(curr->next != NULL){
		if(hash_map.end() == hash_map.find(curr->next->data)){
			hash_map[curr->next->data] = true;
			curr = curr->next;
		}
		else{
			curr->next = curr->next->next;
		}
	}

}
void PrintList(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	struct node *head = NULL;
	CreateList(&head);
	RemoveDuplicates(head);
	PrintList(head);
	return(0);
}

