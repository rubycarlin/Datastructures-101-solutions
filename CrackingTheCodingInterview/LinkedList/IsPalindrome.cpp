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

void CopyLinkedList(struct node *head, struct node **reverseHead){
	struct node *temp, *tail;
	while(head != NULL){
		temp = NewNode(head->data);
		if(*reverseHead == NULL){
			*reverseHead = temp;
			tail = temp;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
		head = head->next;
	}
}

void ReverseLinkedList(struct node **reverseHead){
	struct node *p = NULL, *q = NULL, *r = NULL;

	if(*reverseHead != NULL){
		p = *reverseHead;
	}
	else{
		printf("No element in the list\n");
		return;
	}
	if(p != NULL && p->next != NULL){
		q = p->next;
	}
	else{
		//Only one element in the list
		printf("Only one element in the list\n");
		return;
	}
	if(q != NULL && q->next != NULL){
		r = q->next;
	}
	else{
		//Only two elements in the list
		q->next = p;
		p->next = NULL;
		*reverseHead = q;
	}
	p->next = NULL;
	while(r != NULL){
//		cout << p->data << "\t" << q->data << "\t" << r->data << endl;
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	*reverseHead = q;
	PrintList(*reverseHead);
}
bool IsPalindrome(struct node *head){
	struct node *reverseHead = NULL;
	CopyLinkedList(head, &reverseHead);
	ReverseLinkedList(&reverseHead);
	struct node *curr = reverseHead;
	while(head != NULL && curr != NULL){
		if(head->data != curr->data){
			return(false);
		}
		head = head->next;
		curr = curr->next;
	}
	if((curr == NULL && head != NULL) || (curr != NULL && head == NULL)){
		printf("Linked list has been corrupted\n");
		return(false);
	}
	return(true);
}
int main(){
	struct node *head = NULL;
	CreateList(&head);
	if(IsPalindrome(head))
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");
	PrintList(head);
	return(0);
}

