#include <iostream>

using namespace std;

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

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

void Increment(struct tree *root, int diff){
	if(root->left != NULL){
		root->left->data += diff; 
		Increment(root->left, diff);
	}
	else if(root->right != NULL){
		root->right->data += diff;
		Increment(root->right, diff);
	}
}
void ConstructChildrenSumTree(struct tree *root){
	int left_data = 0, right_data = 0, diff = 0;
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	else{
		ConstructChildrenSumTree(root->left);
		ConstructChildrenSumTree(root->right);

		if(root->left != NULL)
			left_data = root->left->data;

		if(root->right != NULL)
			right_data = root->right->data;

		diff = left_data + right_data - root->data;
		
		if(diff > 0)
			root->data += diff;
		else if(diff < 0)
			Increment(root, -diff);
	}
}

bool HasChildrenSumProperty(struct tree *root){
	bool has_children_sum_property = true;
	int left_data = 0, right_data = 0, diff = 0;

	if(root == NULL || (root->left == NULL && root->right == NULL))
		has_children_sum_property = has_children_sum_property && true;
	else{
		HasChildrenSumProperty(root->left);
		HasChildrenSumProperty(root->right);

		if(root->left != NULL)
			left_data = root->left->data;
		if(root->right != NULL)
			right_data = root->right->data;

		diff = left_data + right_data - root->data;

		if(!diff)
			has_children_sum_property = has_children_sum_property && true;
		else
			has_children_sum_property = has_children_sum_property && false;
	}
	return(has_children_sum_property);
}
int main(){

	struct tree *root = NULL;
	ConstructTree(&root);
	InorderPrint(root);
	cout << endl;

	ConstructChildrenSumTree(root);
	InorderPrint(root);
	cout << endl;
	

	bool has_children_sum_property = HasChildrenSumProperty(root);
	if(has_children_sum_property)
		cout << "Given tree has children sum property\n";
	else
		cout << "Given tree does not have children sum property\n";

	root->data += 5;

	has_children_sum_property = HasChildrenSumProperty(root);
	if(has_children_sum_property)
		cout << "Given tree has children sum property\n";
	else
		cout << "Given tree does not have children sum property\n";



	return(0);

}

