#include <iostream>

using namespace std;

struct node{
	int x;
	int y;
	struct node *next;
};

struct node *NewNode(int x, int y){
	struct node *temp = new struct node;
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	return(temp);
}
void InsertNode(struct node **head, int x, int y){
	struct node *temp = NewNode(x, y);
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
}
void FloodFill(int matrix[8][8], int row, int col){
	int x, y, replcement_color;
	cout << "Enter the x position : ";
	cin >> x;
	cout << "Enter the y position : ";
	cin >> y;
	cout << "Enter the replacement color : ";
	cin >> replcement_color;

	int target_color = matrix[x][y];
	struct node * qHead = NULL;
	InsertNode(&qHead, x, y);
	while(qHead != NULL){
		matrix[qHead->x][qHead->y] = replcement_color;
		if(qHead->x + 1 < 8 && matrix[qHead->x + 1][qHead->y] == target_color)
			InsertNode(&qHead, qHead->x + 1,  qHead->y);
		if(qHead->y + 1 < 8 && matrix[qHead->x][qHead->y + 1] == target_color)
			InsertNode(&qHead, qHead->x,  qHead->y + 1);
		if(qHead->x - 1 >= 0 && matrix[qHead->x - 1][qHead->y] == target_color)
			InsertNode(&qHead, qHead->x - 1,  qHead->y);
		if(qHead->y - 1 >= 0 && matrix[qHead->x][qHead->y - 1] == target_color)
			InsertNode(&qHead, qHead->x,  qHead->y - 1);

		struct node *temp = qHead;
		qHead = qHead->next;
		free(temp);
	}

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << matrix[i][j] << "\t";
		}
		cout <<endl;
	}

}
int main(){
	int matrix[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0}, {1, 0, 0, 1, 1, 0, 1, 1}, {1, 2, 2, 2, 2, 0, 1, 0},  {1, 1, 1, 2, 2, 0, 1, 0}, {1, 1, 1, 2, 2, 2, 2, 0}, {1, 1, 1, 1, 1, 2, 1, 1}, {1, 1, 1, 1, 1, 2, 2, 1}};

	FloodFill(matrix, 8,8);
	return(0);
}


