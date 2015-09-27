#include<iostream>

struct node{
	int data;
	struct node *next;
};

struct randnode{
	int data;
	struct randnode *next;
	struct randnode *randptr;
};

struct randnode* NewRandNode(int data){
	struct randnode *temp = (struct randnode*) malloc(sizeof(struct randnode));
	temp->data = data;
	temp->next = NULL;
	temp->randptr = NULL;
}

void getData(int *n, int *data){
	printf("Enter the number of elements : ");
	scanf("%d", n);
	for(int i = 0; i < *n; i++){
		printf("Enter the element : ");
		scanf("%d", &data[i]);
	}
}

void PrintData(int n, int *data){
	for(int i = 0; i < n; i++){
		if((data + i) != NULL)
			printf("%d\t", data[i]);
		else
			printf("Element is null");
	}
	printf("\n");
}

void PrintList(struct node *head, struct node * tail){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct node* NewNode(int data){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return(temp);
}

void InsertAtPosition(struct node **head, struct node **tail){
	int data, pos;
	printf("Enter the data to be inserted : ");
	scanf("%d", &data);

	printf("Enter the position : ");
	scanf("%d", &pos);

	struct node* temp = *head;
	while(temp->next != NULL && pos > 1){
		temp = temp->next;
		pos -= 1;
	}

	struct node *node = NewNode(data);
	if(temp == *head){
		node->next = *head;
		*head = node;
	}
	else if(temp == *tail && pos >= 1){
		(*tail)->next = node;
		*tail = node;
	}
	else{
		node->next = temp->next;
		temp->next = node;
	}
	PrintList(*head, *tail);
}

void InsertNode(struct node **head, struct node **tail, int data){
	if((*head) == NULL){
		*head = NewNode(data);
		*tail = *head;
	}
	else if((*tail) != NULL){

		(*tail)->next = NewNode(data);
		(*tail) = (*tail)->next;
	}
	else{
		printf("Something wrong\n");
	}
}

void InsertNodes(int n, int *data, struct node **head, struct node **tail){
	for(int i = 0; i < n; i++){
		InsertNode(head, tail, data[i]);
	}
}

void DeleteHead(struct node **head, struct node **tail){
	if((*head) == (*tail)){
		free(*head);
		(*head) = (*tail) = NULL;
	}
	else{
		struct node *temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}

void DeleteTail(struct node **head, struct node **tail){
	if((*head) == (*tail)){
		free(*head);
		(*head) = (*tail) = NULL;
	}
	else{
		struct node *temp = *head;
		while(temp->next != (*tail)){
			temp = temp->next;
		}
		struct node *nodeToBeRemoved = *tail;
		*tail = temp;
		(*tail)->next = NULL;
		free(nodeToBeRemoved);
		
	}
}

void DeleteElementAtPosition(struct node **head, struct node **tail){
	int position;
	printf("Enter the position : ");
	scanf("%d", &position);
	if(position == 0){
		if((*head) == (*tail)){
			free(*head);
			(*head) = (*tail) = NULL;
		}
		else{
			struct node *temp = *head;
			(*head) = (*head)->next;
			free(temp);
		}
	}
	else{
		struct node *temp = *head;
		while(temp->next->next != NULL && position > 1){
			temp = temp->next;
			position -= 1;
		}

		//If position is greater than 1 then we are deleting the tail node so modify the tail pointer
		if(position > 1){
			struct node *nodeToBeRemoved = temp->next;
			temp->next = nodeToBeRemoved->next;
			*tail = temp;
			free(nodeToBeRemoved);
		}
		else{
			struct node *nodeToBeRemoved = temp->next;
			temp->next = nodeToBeRemoved->next;
			free(nodeToBeRemoved);
		}
	}
}
void DeleteNodes(int n, int *data, struct node **head, struct node **tail){

	int choice = 0;
	while(choice != -1){
		printf("Please enter one of the below option\n 1 Delete head element\n 2 Delete tail element\n3 Delete element at position\n-1 Exit\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				DeleteHead(head, tail);
				PrintList(*head, *tail);
				break;
			case 2:
				DeleteTail(head, tail);
				PrintList(*head, *tail);
				break;
			case 3:
				DeleteElementAtPosition(head, tail);
				PrintList(*head, *tail);
			default:
				break;
		}
	}
}

void JoinTwoList(){
	printf("Join list\n");
	int n1, data1[100], n2, data2[100];
	getData(&n1, data1);
	getData(&n2, data2);

	struct node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
	InsertNodes(n1, data1, &head1, &tail1);
	InsertNodes(n2, data2, &head2, &tail2);

	PrintList(head1, tail1);
	PrintList(head2, tail2);

	struct node *temp;
	if(head1 != NULL){
		temp = head1;
	}
	else{
		printf("First list is empty\n");
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	if(head2 != NULL)
		temp->next = head2;
	else
		printf("Second list is empty\n");
	PrintList(head1, tail2);
}

void DeleteAlternateNodes(struct node **head, struct node **tail){
	struct node *temp = *head;
	while(temp != NULL){
		if(temp->next != NULL){
			struct node *nodeToBeRemoved = temp->next;
			temp->next = nodeToBeRemoved->next;
			free(nodeToBeRemoved);
			temp = temp->next;
		}
		else{
			*tail = temp;
			break;
		}
	}
	PrintList(*head, *tail);
}

void GetNthNode(struct node *head, int pos, int *node_val, int *found){
	int curr = 1;
	while(head != NULL){
		if(curr == pos){
			*node_val = head->data;
			*found = 1;
			break;
		}
		head = head->next;
		curr += 1;
	}
}

struct node* GetNthNodePtr(struct node *head, int pos){
	struct node *nthnode = NULL;
	int curr = 1;
	while(head != NULL){
		if(curr == pos){
			nthnode = head;
			break;
		}
		head = head->next;
		curr += 1;
	}
	return(nthnode);
}
struct node* GetRandomPointer(struct node *head, int n){
	int randPos = (rand()%n) + 1;
	struct node *randPtr = GetNthNodePtr(head, randPos);
	return(randPtr);
}

void DeleteNodePointingToPointer1(struct node **head, struct node *randPtr){
	if(*head == randPtr){
		(*head) = (*head)->next;
		return;
	}
	struct node *temp = *head;
	while(temp->next != randPtr){
		temp = temp->next;
	}
	temp->next = randPtr->next;
}
void DeleteNodePointingToPointer2(struct node **randPtr){

	struct node *temp = *randPtr;
	//This method will not work for deleting the last pointer
	//If you want to use this method for all the scenarios maintain a dummy node at the end of the list
	while((*randPtr) != NULL && (*randPtr)->next != NULL && (*randPtr)->next->next != NULL){
		(*randPtr)->data = (*randPtr)->next->data;
		(*randPtr) = (*randPtr)->next;
	}
	if((*randPtr) != NULL && (*randPtr)->next != NULL ){
		(*randPtr)->data = (*randPtr)->next->data;
		(*randPtr)->next = (*randPtr)->next->next;
	}
	else{
		printf("You are trying to delete the last node of the list\n");
	}

}

void FindMiddleNode(struct node *head){
	struct node *slow = head, *fast = head;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("Middle node is %d \n", slow->data);
}
void FindNthNodeFromLast(struct node *head, int pos){
	struct node *slow = head, *fast = head;
	int nthpos = pos;
	while(fast != NULL && nthpos > 1){
		fast = fast->next;
		nthpos -= 1;
	}
	while(fast != NULL && fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	if(nthpos == 1)
		printf("Element at position %d from end is %d\n",pos, slow->data );
	else
		printf("Not enough elements in the list\n");
}
void DeleteLinkedList(struct node **head){
	struct node * temp = (*head)->next;
	while(*head != NULL){
		free(*head);
		*head = temp;
		if(temp != NULL)
			temp = temp->next;
		printf("Delete node\n");
	}
	
}
int CountValue(struct node *head, int val){
	int count = 0;
	while(head != NULL){
		if(head->data == val){
			count += 1;
		}
		head = head->next;
	}
	return(count);
}

void ReverseList(struct node **head, struct node **tail){
	struct node *p = NULL, *q = NULL, *r = NULL;
	if(*head != NULL){
		*tail = p = *head;
	}
	if(p != NULL && p->next != NULL){
		q = p->next;
	}
	if(q != NULL && q->next != NULL){
		r = q->next;
	}
	p->next = NULL;
	//If there is only one element
	if(p != NULL && q == NULL){
		*head = p;
		return;
	}
	//If there are only 2 elements
	if(q != NULL && r == NULL){
		q->next = p;
		*head = q;
		return;
	}
	while(r!= NULL){
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	*head = q;
}
void CreateLoopInLinkedList(struct node **loophead, struct node **looptail){
	printf("Contents for Loopy linked list\n");
	int n, data[100];
	getData(&n, data);
	PrintData(n, data);
	InsertNodes(n, data, loophead, looptail);

	struct node *randPtr = GetRandomPointer(*loophead, n);
	printf("Random node : %d\n",randPtr->data);

	(*looptail)->next = randPtr;
}

void DetectALoopInTheList(struct node *head){
	struct node *slow = head, *fast = head;
	int found = 0;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if( slow == fast){
			found = 1;
			break;
		}
	}
	if(found){
		printf("Found loop\n");
	}
	else{
		printf("Not found loop\n");
	}
}

int IsLinkedListPalindrome(struct node *head, struct node *tail){
	struct node *reversehead = head, *reversetail = tail;
	//Reversing the linked list
	ReverseList(&reversehead, &reversetail);
	PrintList(reversehead, reversetail);
	while(head != NULL && reversehead != NULL){
		printf("here\n");
		if(head->data != reversehead->data){
			return(0);
		}
		head = head->next;
		reversehead = reversehead->next;
	}
	return(1);
}
void PrintRandList(struct randnode *head, struct randnode * tail){
	struct randnode* temp = head;
	while(temp != NULL){
		if(temp->randptr != NULL)
			printf("%d->%d\n",temp->data,temp->randptr->data);
		else
			printf("%d->NULL\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void InsertRandNode(struct randnode **head, struct randnode **tail, int data, struct randnode *randptr){
	if((*head) == NULL){
		*head = NewRandNode(data);
		*tail = *head;
		if(randptr != NULL){
	//		printf("Rand ptr data : %d\n", randptr->data);
			(*head)->randptr = randptr;
			(*tail)->randptr = randptr;
		}
	}
	else if((*tail) != NULL){

		(*tail)->next = NewRandNode(data);
		(*tail) = (*tail)->next;
		if(randptr != NULL){
	//		printf("Rand ptr data : %d\n", randptr->data);
			(*tail)->randptr = randptr;
		}
		
	}
	else{
		printf("Something wrong\n");
	}
	PrintRandList(*head, *tail);
}
void SetRandomPtrs(struct randnode **head){
	struct randnode *sec = NULL, *fourth = NULL;
	struct randnode *temp = *head;
	int c = 1;
	while(temp != NULL){
		if(c == 2){
			sec = temp;
		}
		if(c == 4){
			fourth = temp;
		}
		temp = temp->next;
		c += 1;
	}
	temp = *head;
	c = 1;
	while(temp!=NULL){
		if(c == 1 && sec != NULL){
			temp->randptr = sec;
		}
		if(c == 3 && fourth != NULL){
			temp->randptr = fourth;
		}
		temp = temp->next;
		c += 1;
	}
}
void CreateLinkedListWithRandomPtr(int n, int *data, struct randnode **head, struct randnode **tail){
	struct randnode *randptr = NULL;
	for(int i = 0; i < n; i++){
		InsertRandNode(head, tail, data[i], randptr);
	}

	SetRandomPtrs(head);
}


void CloneLinkedListWithRandomPtr(struct randnode **head, struct randnode **clonehead, struct randnode **clonetail){
	struct randnode *temp = *head;
	while(temp != NULL){
		InsertRandNode(clonehead, clonetail, temp->data, temp);
		temp = temp->next;
	//	printf("Inserted\n");
	}
	PrintRandList(*clonehead, *clonetail);
	temp = *clonehead;

	while(temp != NULL){
		if(temp->randptr != NULL)
			temp->randptr = temp->randptr->randptr;
		else
			printf("Randptr of %d is NULL\n", temp->data);
		temp = temp->next;
	}

}

void InsertNodeInSortedOrder(struct node **head, struct node **tail, int data){
	if(data <= (*head)->data){
		struct node *temp = NewNode(data);
		temp->next = *head;
		(*head) = temp;
	}
	else{
		struct node *curr = *head;
		while(curr->next != NULL && data > curr->next->data){
			curr = curr->next;
		}
		struct node *temp = NewNode(data);
		temp->next = curr->next;
		curr->next = temp;

		//If the node is added at the end
		if(temp->next == NULL){
			*tail = temp;
		}
	}
}

void PrintReverseList(struct node *head){
	if(head == NULL){
		return;
	}
	PrintReverseList(head->next);
	printf("%d->",head->data);
}

void RemoveDuplicatesFromSortedList(struct node **head, struct node **tail){
	struct node *curr = *head;
	while(curr->next != NULL){
		if(curr->data == curr->next->data){
			struct node *temp = curr->next;
			curr->next = curr->next->next;
			free(temp);
			if(temp->next == NULL){
				*tail = curr;
			}
		}
		else{
			curr = curr->next;
		}
	}
}

void MoveLastElementToFront(struct node **head, struct node **tail){
	struct node *curr = *head;
	while(curr->next != NULL && curr->next->next != NULL){
		curr = curr->next;
	}
	if(curr->next == NULL){
		printf("Only one element in the list \n");
	}
	else{
		curr->next->next = *head;
		*head = curr->next;
		curr->next = NULL;
		*tail = curr;
	}

}

void PairwiseSwap(struct node **head){
	struct node *curr = *head;

	while(curr != NULL && curr->next != NULL){
		int temp = curr->data;
		curr->data = curr->next->data;
		curr->next->data = temp;
		curr = curr->next->next;
	}
}

void IntersectionOfSortedList(struct node *head1, struct node *head2){
	while(head1 != NULL && head2!= NULL){
		if(head1->data < head2->data){
			head1 =head1->next;
		}
		else if(head1->data == head2->data){
			printf("%d->", head1->data);
			head1 = head1->next;
			head2 = head2->next;
		}
		else{
			head2 = head2->next;
		}
	}
}

void MergeTwoSortedList(struct node *head1, struct node *head2, struct node **mergeHead, struct node **mergeTail){
	while(head1 != NULL && head2 != NULL){
		if(head1->data < head2->data){
			InsertNode(mergeHead, mergeTail, head1->data);
			head1 = head1->next;
		}
		else if(head1->data == head2->data){
			InsertNode(mergeHead, mergeTail, head1->data);
			InsertNode(mergeHead, mergeTail, head2->data);
			head1 = head1->next;
			head2 = head2->next;
		}
		else{
			InsertNode(mergeHead, mergeTail, head2->data);
			head2 = head2->next;
		}
	}
	while(head1 != NULL){
		InsertNode(mergeHead, mergeTail, head1->data);
		head1 = head1->next;
	}
	while(head2 != NULL){
		InsertNode(mergeHead, mergeTail, head2->data);
		head2 = head2->next;
	}
}

bool AreIdentical(struct node *head1, struct node *head2){
	bool identical = false;
	while(head1 != NULL && head2 != NULL){
		if(head1->data != head2->data){
			identical = false;
			break;
		}
		else{
			identical = true;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	if((head1 == NULL && head2 != NULL) ||(head1 != NULL && head2 == NULL)){
		identical = false;
	}
	return(identical);
}

void RemoveDuplicatesFromUnsortedList(struct node **head, struct node **tail){
	//Using hashing method
	//This method will work only if the value of data is greater than or equal to 0 and less than or equal to 999

	int hash[1000];
	struct node *curr = *head;

	memset(hash, 0, sizeof(hash));
	hash[curr->data] = 1;
	while(curr->next != NULL){
		if(hash[curr->next->data]){
			struct node *temp = curr->next;
			curr->next = curr->next->next;
			if(temp->next == NULL){
				*tail = curr;
			}
			free(temp);
		}
		else{
			hash[curr->next->data] = 1;
			curr = curr->next;
		}
	}
}

void DeleteNodeHavingGreaterValueOnRight(struct node **head, struct node **tail){
	struct node *curr = *head;
	while(curr->next != NULL){
		struct node *temp;
		if(curr == *head && curr->data < curr->next->data){
			temp = curr;
			*head = curr->next;
			curr = curr->next;
			free(temp);
		}
		else if(curr->next->next != NULL && curr->next->data < curr->next->next->data){
			curr->next = curr->next->next;
		}
		else{
			curr = curr->next;
		}
	}
}

void AddNumbersRepresentedByLinkedList(struct node *head1, struct node *head2, struct node **head3, struct node **tail3){

	int carryover = 0;

	while(head1 != NULL && head2 != NULL){
		int sum = (head1->data + head2->data) + carryover;
		if(sum >= 10)
			carryover = 1;
		else
			carryover = 0;
		sum = sum % 10;
		InsertNode(head3, tail3, sum);
		head1 = head1->next;
		head2 = head2->next;
	}
	while(head1 != NULL){
		if(carryover == 1){
			InsertNode(head3, tail3, (head1->data + 1)%10);
			carryover = (head2->data + 1) / 10;
		}
		else{
			InsertNode(head3, tail3, head1->data);
		}
		head1 = head1->next;
	}

	while(head2 != NULL){
		if(carryover == 1){
			InsertNode(head3, tail3, (head2->data + 1)%10);
			carryover = (head2->data + 1) / 10;
		}
		else{
			InsertNode(head3, tail3, head2->data);
		}
		head2 = head2->next;
	}
	if(carryover){
		InsertNode(head3, tail3, carryover);
	}
}

void DeleteNodeWithConstraint(struct node *head, struct node *toBeDeleted){
	//This will work only if there are atleast two nodes in the list
	if(head == toBeDeleted){
		head->data = head->next->data;
		head->next = head->next->next;
	}
	else{
		while(head->next != toBeDeleted){
			head = head->next;
		}
		head->next = head->next->next;
	}
}

void RotateLinkedList(struct node **head, struct node **tail, int k){
	while(k > 0){
		k--;
		struct node *curr = *head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = *head;
		*tail = *head;
		*head = (*head)->next;
		(*tail)->next = NULL;
	}
}
void RepublicanSort(struct node *head){
	struct node *zero_pos = NULL,*one_pos = NULL, *two_pos = NULL;
	int zero_count = 0, one_count = 0, two_count = 0;
	struct node *temp = head;
	while(temp != NULL){
		if(temp->data == 0){
			zero_count++;
		}
		else if(temp->data == 1){
			one_count++;
		}
		else{
			two_count++;
		}
		temp = temp->next;
	}
	struct node *curr = head;
	while(curr != NULL){
		if(zero_count > 0){
			curr->data = 0;
			zero_count--;
		}
		else if(one_count > 0){
			curr->data = 1;
			one_count--;
		}
		else{
			curr->data = 2;
			two_count--;
		}
		curr = curr->next;
	}
}

void KthNodeFromEnd(struct node *head, struct node **kthnode, int k){
	struct node *slow = head, *fast = head;
	while(k > 0 && fast != NULL){
		fast = fast->next;
		k--;
	}
	while(fast != NULL){
		slow = slow->next;
		fast = fast->next;
	}
	*kthnode = slow;
}
void Kthnodefrombeginning(struct node *head, struct node **kthnode, int k){
	while(k > 1 && head != NULL){
		k--;
		head = head->next;
	}
	*kthnode = head;
}

void DeleteMNodesAfterKNodes(struct node *head, struct node **tail, int k, int m){
	struct node *curr = head;
	while(curr != NULL && curr->next != NULL){
		int k_copy = k;
		while(k_copy > 1 && curr != NULL){
			curr = curr->next;
			k_copy -= 1;
		}
		int m_copy = m;
		while(m_copy > 0 && curr != NULL){
			if(curr->next == NULL){
				*tail = curr;
				break;
			}
			curr->next = curr->next->next;
			m_copy -= 1;
		}
		curr = curr->next;

	}
}

void SplitLinkedList(struct node *head, struct node **head1, struct node **tail1, struct node **head2, struct node **tail2){
	while(head!= NULL){
		InsertNode(head1, tail1, head->data);
		if(head->next != NULL){
			InsertNode(head2, tail2, head->next->data);
			head = head->next->next;
		}
		else{
			break;
		}
	}
}
void SortListWithAlternateAscendingAndDescending(struct node **head, struct node **tail){
	struct node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
	SplitLinkedList(*head, &head1, &tail1, &head2, &tail2);
	ReverseList(&head2, &tail2);
	*head = *tail = NULL;
	MergeTwoSortedList(head1, head2, head, tail);
}

void SwapNodes(struct node **head, struct node **tail, int x, int y){
	struct node *node1prev = NULL, *node2prev = NULL;
	struct node *curr = *head;
	if(curr->data == x || curr->data == y){
		node1prev = *head;
	}
	while(curr != NULL && curr->next != NULL && (node1prev == NULL || node2prev == NULL)){
		if(curr->next->data == x || curr->next->data == y){
			if(node1prev == NULL){
				node1prev = curr;
			}
			else{
				node2prev = curr;
			}
		}
		curr = curr->next;
	}
	//If there are no such elements print error message and return
	if(node1prev == NULL || node2prev == NULL){
		printf("Invalid elements \n");
		return;
	}

	//Special case handling 
	//If the node to be swapped is head
	struct node *temp = NULL;
	if(node1prev == *head && (node1prev->data == x || node1prev->data == y)){
		struct node *node2 = node2prev->next;
		struct node *node2next = node2->next;
		node2->next = (*head)->next;
		(*head)->next = node2next;
		node2prev->next = *head;
		*head = node2;
	}
	else{
		struct node *node1next = node1prev->next->next;
		struct node *node2next = node2prev->next->next;

		struct node *node1 = node1prev->next;
		struct node *node2 = node2prev->next;

		node1prev->next = node2;
		node2->next = node1next;

		node2prev->next = node1;
		node1->next = node2next;

		//Special case handling
		//If the tail node has been swapped
		if(node2next == NULL){
			*tail = node1;
		}
	}
}
void LinkedList(){
	struct node *head = NULL, *tail = NULL;
	int n, data[100];

	getData(&n, data);
	PrintData(n, data);
	InsertNodes(n, data, &head, &tail);
	
	//Swap nodes instead of swapping data
	int x, y;
	printf("Enter the values to be swapped separated by space \n");
	scanf ("%d %d",&x, &y);
	SwapNodes(&head, &tail, x, y);
	PrintList(head, tail);
}

void Operations(){
	struct node *head = NULL, *tail = NULL;
	int n, data[100];

	//Get the linked list data
	getData(&n, data);

	//Print the array data
	PrintData(n, data);

	//Insert node at the end of the list
	InsertNodes(n, data, &head, &tail);

	//Insert a node at a given position
	InsertAtPosition(&head, &tail);

	//Delete node from the linked list
	DeleteNodes(n, data, &head, &tail);

	//Join two linked list
	JoinTwoList();
	//Delete alternate nodes
	DeleteAlternateNodes(&head, &tail);

	//Printing the linked list
	PrintList(head, tail);

	//Nth node
	int node_num, node_val,found = 0;
	printf("Enter the node number : ");
	scanf("%d",&node_num);
	GetNthNode(head, node_num, &node_val,&found);
	if(found){
		printf("Node at pos %d is %d\n", node_num, node_val);
	}
	else{
		printf("No node at position %d\n",node_num );
	}

	//Delete the node pointed by the random pointer
	struct node *randPtr = GetRandomPointer(head, n);
	printf("Random node : %d\n",randPtr->data);

	DeleteNodePointingToPointer1(&head, randPtr);
	PrintList(head, tail);

	randPtr = GetRandomPointer(head, n-1);
	printf("Random node : %d\n",randPtr->data);
	DeleteNodePointingToPointer2(&randPtr);
	PrintList(head, tail);

	//To find the middle node of the linked list
	FindMiddleNode(head);	

	//Nth element from the end
	int nthpos;
	printf("Enter the nth position from end : ");
	scanf("%d", &nthpos);
	FindNthNodeFromLast(head, nthpos);

	DeleteLinkedList(&head);
	if(head == NULL){
		printf("Linkedlist got deleted\n");
	}

	//Count the number of times the value appears in the linked list
	int val, count;
	printf("Enter the value to be counted : ");
	scanf("%d", &val);
	count = CountValue(head, val);
	printf("Count of %d is %d\n",val, count );

	//Reversing the linked list
	ReverseList(&head, &tail);
	PrintList(head, tail);

	struct node *LoopHead = NULL, *LoopTail = NULL;
	CreateLoopInLinkedList(&LoopHead, &LoopTail);
	DetectALoopInTheList(head);
	DetectALoopInTheList(LoopHead);


	//To check if the given list is a palindrome
	int isPalindrome = 0;
	isPalindrome = IsLinkedListPalindrome(head, tail);
	if (isPalindrome)
	{
		printf("Given linked list is a palindrome\n");
	}
	else{
		printf("Given linked list is not a palindrome\n");
	}


	//Cloning a linked list with a random pointer
	struct randnode *randhead = NULL, *randtail = NULL, *clonehead = NULL, *clonetail = NULL;
//	int n, data[100];
	getData(&n, data);
	PrintData(n, data);
	CreateLinkedListWithRandomPtr(n, data, &randhead, &randtail);

	PrintRandList(randhead, randtail);
	
	CloneLinkedListWithRandomPtr(&randhead,&clonehead, &clonetail);

	PrintRandList(clonehead, clonetail);

	//Inserting node in a sorted order in an already sorted list
//	int val;
	printf("Enter the value ot be inserted : ");
	scanf("%d", &val);
	InsertNodeInSortedOrder(&head, &tail, val);

	PrintList(head, tail);

	//Recursive function to print the reverse of a list
	PrintReverseList(head);


	//Remove duplicates from a sorted list
	RemoveDuplicatesFromSortedList(&head, &tail);

	printf("Head : %d \n", head->data);
	printf("Tail : %d\n", tail->data);

	PrintList(head, tail);

	//Move last element to the front

	MoveLastElementToFront(&head, &tail);
	PrintList(head, tail);

	//Pairwise swap
	PairwiseSwap(&head);
	PrintList(head, tail);

	//Intersection of two sorted linked list
	struct node *head1 = NULL, *tail1 = NULL;
	int n1, data1[100];

	getData(&n1, data1);
	InsertNodes(n1, data1, &head1, &tail1);

	struct node *head2 = NULL, *tail2 = NULL;
	int n2, data2[100];

	getData(&n2, data2);
	InsertNodes(n2, data2, &head2, &tail2);

	IntersectionOfSortedList(head1, head2);

	//Merge two sorted linked list
	struct node *mergeHead = NULL, *mergeTail = NULL;
	/*struct node *head1 = NULL, *tail1 = NULL;
	int n1, data1[100];*/

	getData(&n1, data1);
	InsertNodes(n1, data1, &head1, &tail1);

	/*struct node *head2 = NULL, *tail2 = NULL;
	int n2, data2[100];*/

	getData(&n2, data2);
	InsertNodes(n2, data2, &head2, &tail2);

	MergeTwoSortedList(head1, head2, &mergeHead, &mergeTail);
	PrintList(mergeHead, mergeTail);


	//Are identical linked list
	/*struct node *mergeHead = NULL, *mergeTail = NULL;
	struct node *head1 = NULL, *tail1 = NULL;
	int n1, data1[100];

	getData(&n1, data1);
	InsertNodes(n1, data1, &head1, &tail1);

	struct node *head2 = NULL, *tail2 = NULL;
	int n2, data2[100];

	getData(&n2, data2);
	InsertNodes(n2, data2, &head2, &tail2);*/

	bool identical = false;
	identical = AreIdentical(head1, head2);
	std::cout <<"Are linked lists identical : " << identical << "\n";

	//Removeduplicates from unsorted list
	RemoveDuplicatesFromUnsortedList(&head, &tail);
	PrintList(head, tail);

	//Delete a node having greater value on the right side
	DeleteNodeHavingGreaterValueOnRight(&head, &tail);
	PrintList(head, tail);
	
	//Adding two numbers represented by the linked list
	/*struct node *head1 = NULL, *tail1 = NULL;
	int n1, data1[100];*/

	getData(&n1, data1);
	InsertNodes(n1, data1, &head1, &tail1);

	/*struct node *head2 = NULL, *tail2 = NULL;
	int n2, data2[100];*/

	getData(&n2, data2);
	InsertNodes(n2, data2, &head2, &tail2);

	struct node *head3 = NULL, *tail3 = NULL;

	AddNumbersRepresentedByLinkedList(head1, head2, &head3, &tail3);
	PrintList(head3, tail3);
	
	//Delete a node under given constraints
	DeleteNodeWithConstraint(head, head);

	PrintList(head, tail);

	DeleteNodeWithConstraint(head, head->next);

	PrintList(head, tail);

	//Rotate a linked list anti clock wise by k nodes
	int k;
	printf("Enter the number of rotation : \n");
	scanf("%d", &k);

	RotateLinkedList(&head, &tail, k);

	PrintList(head, tail);
	
	//Sort list of o's 1's and 2's
	RepublicanSort(head);
	PrintList(head, tail);

	//Kth node from the end
//	int k;
	struct node *kthnodefromend = NULL;
	printf("Enter the kth position from end : ");
	scanf("%d",&k);

	KthNodeFromEnd(head, &kthnodefromend, k);

	printf("Kth node from the end : %d \n",kthnodefromend->data );
	//Kth node from the beginning
	struct node *kthnodefrombeginning;
	printf("enter the kth position from beginning : ");
	scanf("%d", &k);

	Kthnodefrombeginning(head, &kthnodefrombeginning, k);
	printf("Kth node from the beginning : %d\n", kthnodefrombeginning->data );

	//Delete k node after m nodes
//	int k , m;
	int m;
	printf("Enter the value of k  : ");
	scanf("%d", &k);

	printf("Enter the value of m : ");
	scanf("%d" , &m);

	DeleteMNodesAfterKNodes(head, &tail, k, m);

	PrintList(head, tail);

	//Sort the linkedlist woth alternate ascending and descending elements
	SortListWithAlternateAscendingAndDescending(&head, &tail);
	PrintList(head, tail);
	
}

int main(){
	LinkedList();
	return(0);
}


