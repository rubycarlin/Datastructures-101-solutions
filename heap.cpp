#include<iostream>

struct node{
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct queue{
	struct node* node;
	struct queue* next;
};
void getData(int n, int* data){
	for(int i = 0; i < n; i++){
		printf("Enter the key : ");
		scanf("%d", &data[i]);
	}
}

void printData(int n, int* data){
	for(int i = 0; i < n; i++){
		printf("%d\t", data[i]);
	}
	printf("\n");
}

struct node* newNode(int key){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return(temp);
}

struct queue* newQueueNode(struct node* n){
	struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
	temp->node = n;
	temp->next = NULL;
	return(temp);
}

void bubbleUp(struct node* n){
	struct node* temp = n;
	while(temp != NULL && temp->parent != NULL && temp->key < temp->parent->key){
		int x;
		x = temp->parent->key;
		temp->parent->key = temp->key;
		temp->key = x;
		temp = temp->parent;
	}
}

void printHeap(struct node* root){
	struct node* temp = root;
	struct queue* q1 = newQueueNode(temp);
	struct queue* q2 = NULL, *q2Tail = NULL;
	while(q1 != NULL || q2 != NULL){
		if(q1 == NULL){
			q1 = q2;
			q2 = NULL;
			q2Tail = NULL;
			printf("\n");
		}
		printf("%d\t",q1->node->key);
		if(q1->node->left != NULL){

			if(q2 == NULL){
				q2 = q2Tail = newQueueNode(q1->node->left);

			}
			else
			{
				q2Tail->next = newQueueNode(q1->node->left);
				q2Tail = q2Tail->next;
			}
		}
		if(q1->node->right != NULL){
			if(q2 == NULL){
				q2 = q2Tail = newQueueNode(q1->node->left);
			}
			else{
				q2Tail->next = newQueueNode(q1->node->right);
				q2Tail = q2Tail->next;
			}
		}
		q1 = q1->next;
	}
}
void constructHeap(int n, int* data){
	struct node *root = NULL;
	struct queue *head = NULL, *tail=NULL;

	for(int i = 0; i < n; i++){
		int key = data[i];
		if(root == NULL){
			root = newNode(key);
			head = tail = newQueueNode(root);
		}
		else{
			struct node* temp = newNode(key);
			if(head != NULL && head->node->left == NULL)
			{
				head->node->left = temp;
				temp->parent = head->node;
				if(tail != NULL){
					tail->next = newQueueNode(temp);
					tail = tail->next;
				}
				else{
					printf("Tail is Null\n");
				}
				bubbleUp(temp);
			}
			else if(head != NULL && head->node->right == NULL){
				head->node->right = temp;
				temp->parent = head->node;
				head = head->next;
				if(tail != NULL){
					tail->next = newQueueNode(temp);
					tail = tail->next;
				}
				else{
					printf("Tail is Null\n");
				}
				bubbleUp(temp);
			}
			else{
				printf("No element in the queue\n");
			}
		}
	}
	printHeap(root);
}
void Heap(){
	int data[100], n;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	getData(n, data);
	printData(n, data);
	constructHeap(n, data);
}
int main()
{
	Heap();
	return 0;
}
