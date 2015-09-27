#include <iostream>

using namespace std;

struct node{
	struct tree *treeNode;
	struct node *next;
};

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};



struct node *NewQNode(struct tree *treeNode){
	struct node *temp = new struct node;
	temp->treeNode = treeNode;
	temp->next = NULL;

	return(temp);
}

struct tree *NewNode(int data){
	struct tree *temp = new struct tree;
	temp->data = data;
	temp->left = temp->right = NULL;

	return(temp);
}
void InsertNode(struct tree **root, int data){
	struct tree *node = NewNode(data);
	if(*root == NULL){
		*root = node;
	}
	else{
		struct tree *curr = *root;
		while(1){
			if(curr->data >= data && curr->left != NULL){
				curr = curr->left;
			}
			else if(curr->data >= data && curr->left == NULL){
				curr->left = node;
				break;
			}
			else if (curr->data < data && curr->right != NULL){
				curr = curr->right;
			}
			else{
				curr->right = node;
				break;
			}
		}
	}
}

void ConstructTree(struct tree **root){
	int n;
	cout << "Enter the number of nodes in the tree : ";
	cin >> n;
	for(int i = 0; i < n; i++){
		int data;
		cout << "Enter the data : ";
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

void InsertIntoQueue(struct node **head, struct tree *treeNode){
	struct node *temp = NewQNode(treeNode);

	if(*head == NULL)
		*head = temp;
	else{
		struct node *curr = *head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void LevelOrderTraversal(struct tree *root){
	struct node *CurrQHead = NULL, *TempQHead = NULL;

	InsertIntoQueue(&CurrQHead, root);

	while(CurrQHead != NULL){
		cout << CurrQHead->treeNode->data << "\t";
		if(CurrQHead->treeNode->left != NULL)
			InsertIntoQueue(&TempQHead, CurrQHead->treeNode->left);

		if(CurrQHead->treeNode->right != NULL)
			InsertIntoQueue(&TempQHead, CurrQHead->treeNode->right);

		struct node *temp = CurrQHead;
		CurrQHead = CurrQHead->next;
		free(temp);

		if(CurrQHead == NULL){
			cout << endl;
			CurrQHead = TempQHead;
			TempQHead = NULL;
		}
	}
	cout << endl;
}

int GetTreeHeight(struct tree *root){
	if(root == NULL)
		return(0);
	return(1 + max(GetTreeHeight(root->left), GetTreeHeight(root->right)));
}
void PrintLevel(struct tree *root, int level, bool ltr){
	if(root != NULL && level == 1)
		cout << root->data << "\t";
	else if(root != NULL){
		if(ltr){
			PrintLevel(root->left, level - 1, ltr);
			PrintLevel(root->right, level - 1, ltr);
		}
		else{
			PrintLevel(root->right, level - 1, ltr);
			PrintLevel(root->left, level - 1, ltr);
		}
	}

}
void SpiralPrint(struct tree *root){
	int height = GetTreeHeight(root);

	cout << "Height of the tree : " << height << endl;
	bool ltr = false;
	for(int i = 1; i <= height; i++){
		PrintLevel(root, i, ltr);
		cout << endl;
		ltr = !ltr;
	}
}


int main(){

	struct tree *root = NULL;
	ConstructTree(&root);
	InorderPrint(root);
	cout << endl;

	LevelOrderTraversal(root);

	SpiralPrint(root);

	return(0);

}


