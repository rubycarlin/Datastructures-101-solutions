#include <iostream>

using namespace std;

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *NewTreeNode(int data){
	struct tree *temp = new struct tree;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return(temp);
}
struct node{
	struct tree *treeNode;
	struct node *next;
};

struct node *NewNode(struct tree *treeNode){
	struct node *temp = new struct node;
	temp->treeNode = treeNode;
	temp->next = NULL;

	return(temp);
}

void PrintList(struct node *head){
	while(head != NULL){
		cout << head->treeNode->data << "->";
		head = head->next;
	}
	cout << endl;
}
void InsertQNode(struct node **head, struct tree *treeNode){
	struct node *temp = NewNode(treeNode);

	if(*head == NULL)
		*head = temp;
	else{
		struct node *curr = *head;
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
//	PrintList(*head);
}

void InsertNode(struct tree **root, int data){
	struct tree *temp = NewTreeNode(data);
	if(*root == NULL){
		*root = temp;
	}
	else{
		struct node *currList = NULL;
		InsertQNode(&currList, *root);
		while(currList != NULL){
			if(currList->treeNode->left == NULL){
				currList->treeNode->left = temp;
				break;
			}
			else
				InsertQNode(&currList, currList->treeNode->left);
			if(currList->treeNode->right == NULL){
				currList->treeNode->right = temp;
				break;
			}
			else
				InsertQNode(&currList, currList->treeNode->right);	
			struct node *temp = currList;
			currList = currList->next;
			free(temp);		
		}
	}
}
void ConstructCompleteTree(struct tree **root){
	int n ;
	cout << "Enter the number of nodes : " ;
	cin >> n;
	for(int i = 0; i < n; i++){
		int data;
		cout << "Enter the data : " ;
		cin >> data;
		InsertNode(root, data);
	}
}

void InorderPrint(struct tree *root){
	if(root == NULL)
		return;
	InorderPrint(root->left);
	cout << root->data << "->";
	InorderPrint(root->right);

}
bool IsBST(struct tree *root){
	bool is_bst = true;
	if(root == NULL || (root->left == NULL && root->right == NULL))
		is_bst = is_bst && true;
	else{
		IsBST(root->left);
		IsBST(root->right);

		int left_data = root->data - 1, right_data = root->data + 1;

		if(root->left != NULL)
			left_data = root->left->data;
		if(root->right != NULL)
			right_data = root->right->data;

		cout << "Root : " << root->data << "\t Left : " << left_data << "\tRight : " << right_data ;
		if(left_data <= root->data && right_data > root->data)
			is_bst = is_bst && true;
		else
			is_bst = is_bst && false;
		cout << "\tIS BST : " << is_bst << endl;
	}
	return(is_bst);
}
int main(){
	struct tree *root = NULL;

	ConstructCompleteTree(&root);
	InorderPrint(root);
	cout << endl;

	bool is_bst = IsBST(root);

	if(is_bst)
		cout << "Given tree is a binary search tree \n";
	else
		cout << "Given tree is not a binary search tree \n";

}

