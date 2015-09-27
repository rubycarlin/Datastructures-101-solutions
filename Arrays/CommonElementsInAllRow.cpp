#include <iostream>

using namespace std;

struct node{
	int data;
	int next_row;
	struct node *next;
};
struct node *NewNode(int data, int next_row){
	struct node *temp = new struct node;
	temp->data = data;
	temp->next_row = next_row;
	temp->next = NULL;
}

void InsertNode(struct node **head, int data, int next_row){
	struct node *temp = NewNode(data, next_row);
	if(*head == NULL){
		*head = temp;
	}
	else{
		struct node *tail = *head;
		while(tail->next != NULL)
			tail = tail->next;
		tail->next = temp;
	}
}

void PrintArray(int data[], int len){
	for(int i = 0; i < len; i++){
		cout << data[i] << "->";
	}
	cout << endl;
}
bool BinarySearch(int data[], int search_item, int low, int high){
//	cout << "Inside BS\n";
	
//	PrintArray(data, high);
//	cout << search_item;
	bool found = false;
	int low_ind = low;
	int high_ind = high;
	
	while(low_ind < high_ind){

		int mid = (low_ind + high_ind) / 2 + 1;
	//	cout << high_ind << "\t" << low_ind << "\t" << mid << endl;
		if(search_item == data[mid]){
			found = true;
			break;
		}
		else if(data[mid] > search_item){
			high_ind = mid - 1;
		}
		else{
			low_ind = mid + 1;
		}
	}
//	cout << "\t" << found << endl;
	return(found);
}
void FindCommonElement(int matrix[4][5], int row, int col){
	struct node *qHead = NULL;
	for(int j = 0; j < col; j++){
		InsertNode(&qHead, matrix[0][j], 1);
	}
	
	while(qHead != NULL){
		cout << qHead->data << "\t" << qHead->next_row <<  endl;
		if(qHead->next_row < row && BinarySearch(matrix[qHead->next_row], qHead->data, 0, col)){
			InsertNode(&qHead, qHead->data, qHead->next_row + 1);
		}
		if(qHead->next_row < row)
			qHead = qHead->next;
		else{
			break;
		}
	}
	cout << "Common Elements are : ";
	while(qHead != NULL){
		cout << qHead->data << "->";
		qHead = qHead->next;
	}
	cout << endl;

}
int main(){
	int matrix[4][5] =  { {1, 2, 3, 4, 5}, {2, 4, 5, 8, 10}, {3, 4, 5,  9, 11}, {1, 3, 4, 5, 7} };
	FindCommonElement(matrix, 4, 5);
	return(0);
}

