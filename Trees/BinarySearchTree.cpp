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

void PreorderPrint(struct tree *root){
	if(root == NULL)
		return;
	cout << root->data << "->";
	InorderPrint(root->left);
	InorderPrint(root->right);
}

void PostorderPrint(struct tree *root){
	if(root == NULL)
		return;
	InorderPrint(root->left);
	InorderPrint(root->right);
	cout << root->data << "->";
}

int GetTreeSize(struct tree *root){
	int size = 0;
	if(root == NULL)
		return(0);

	size += 1 + GetTreeSize(root->left) + GetTreeSize(root->right);

	return(size);
}

bool HasRootToLeafPathSum(struct tree *root, int curr_sum, int target_sum){
	bool has_root_to_leaf_path_sum = false;
	if(root == NULL){
		if(curr_sum == target_sum){
			return(true);
		}
		else
			return(has_root_to_leaf_path_sum);
	}
	has_root_to_leaf_path_sum = has_root_to_leaf_path_sum || HasRootToLeafPathSum(root->left, curr_sum + root->data, target_sum);
	has_root_to_leaf_path_sum = has_root_to_leaf_path_sum || HasRootToLeafPathSum(root->right, curr_sum + root->data, target_sum);
	return(has_root_to_leaf_path_sum);
}
int main(){
	struct tree *root = NULL;
	ConstructTree(&root);
	InorderPrint(root);
	cout << endl;
	PreorderPrint(root);
	cout << endl;
	PostorderPrint(root);
	cout << endl;

	int size = GetTreeSize(root);
	cout << "Size of the tree is " << size << endl;

	int target_sum = 5;
	bool has_root_to_leaf_path_sum = HasRootToLeafPathSum(root, 0, target_sum);

	if(has_root_to_leaf_path_sum){
		cout << "Has a root to leaf path with the sum " << target_sum << endl;
	}
	else{
		cout << "Does not have a root to leaf path with the sum " << target_sum << endl;
	}
	
	return(0);
}


