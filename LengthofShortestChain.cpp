#include <iostream>

using namespace std;
struct queue{
	string word;
	int len;
	struct queue *next;
};

struct queue *NewNode(string word, int len){
	struct queue *temp = new struct queue;
	temp->word = word;
	temp->len = len;
	temp->next = NULL;
	return(temp);
}
void InsertNode(struct queue **Q, string word, int len){
	struct queue *temp = NULL, *node = NewNode(word, len);
	if(*Q == NULL){
		*Q = node;
	}
	else{
		temp = *Q;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = node;
	}
}

bool isAdjacent(string a, string b){
	int c = 0;
	if(a.length() != b.length() || a == b){
		return false;
	}
	for(int i =0; i < a.length(); i++){
		if(a[i] != b[i]){
			c++;
		}
	}
	if(c > 1){
		return(false);
	}
	return(true);
}
int BreadthFirstSearch(string start, string target, string *dict, int n){
	struct queue *currQ = NULL, *nextQ = NULL;
	currQ = NewNode(start, 1);
	int count = -1;
	int visited[n];
	memset(visited, 0, sizeof(visited));
	
	while(currQ != NULL && currQ->word != target){
		cout << "Current : " << currQ->word << "\n";
		cout << "Adjacent : " ;
		for(int i = 0; i < n; i++){
			if(!visited[i] && isAdjacent(dict[i], currQ->word)){
				cout << dict[i] << "\t";
				InsertNode(&nextQ, dict[i], currQ->len + 1);
				visited[i] = 1;
				if(dict[i] == target){
					return(currQ->len + 1);
				}
			}
		}
		cout <<"\n";
		
		struct queue *t = currQ;
		currQ = currQ->next;
		free(t);
		
		if(currQ == NULL){
			currQ = nextQ;
			nextQ = NULL;
		}
	}
	return(count);
}
void FindThePath(){

	string dict[] = {"poon", "plee", "same", "poie", "plea", "plie", "poin"};
	string start = "toon", target = "plea";

	int count = 0;
	count = BreadthFirstSearch(start, target, dict, 7);
	printf("Count is %d \n", count);

}
int main(){
	FindThePath();
	return(0);
}
