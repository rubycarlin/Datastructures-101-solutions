#include <iostream>

using namespace std;

struct node{
	int next_ind;
	struct node *next;
};
struct node *NewNode(int next_ind){
	struct node *temp = new struct node;
	temp->next_ind = next_ind;
	temp->next = NULL;

	return(temp);
}
void InsertNode(struct node **head, int next_ind){
	struct node *temp = NewNode(next_ind);
	if(*head == NULL){
		*head = temp;
	}
	else{
		struct node *curr = *head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	cout << endl;
}

void PrintList(struct node *head){
	while(head != NULL){
		cout << head->next_ind << "->";
		head = head->next;
	}
	cout << endl;
}
void FindSubString(char str[], int len){
	struct node *qHead = NULL;
	int count = 0;
	for(int i = 0; i < len; i++){
		if(str[i] == '1'){
			InsertNode(&qHead, i  + 1);
		}
			
	}
		
	PrintList(qHead);

	int c = 0;
	while(qHead != NULL){
		if(qHead->next_ind < len && str[qHead->next_ind] == '1')
			count += 1;
		if(qHead->next_ind + 1 < len)
			InsertNode(&qHead, qHead->next_ind + 1);
		struct node *temp = qHead;
		qHead = qHead->next;
		free(temp);
	}
	cout << "Number of substrings starting and ending with 1 is " << count << endl;
}
int main(){

	char str[] = "00100101";
	int len = sizeof(str);
	FindSubString(str, len);
	return(0);
}

