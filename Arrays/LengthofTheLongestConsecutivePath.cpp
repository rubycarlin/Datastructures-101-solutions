#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct movement{
	int i;
	int j;
};

struct queue{
	char c;
	int len;
	struct movement move;
	struct queue *next;
};


struct movement NewMove(int i , int j){
	struct movement *move= new struct movement;
	move->i = i;
	move->j = j;
	return(*move);
};

struct queue *NewNode(char c, int len, struct movement move){
	struct queue *node = new struct queue;
	node->c = c;
	node->len = len;
	node->move = move;
	node->next = NULL;
	return(node);
}
bool isValidMove(struct movement m1, struct movement m2, struct movement maxmove){
	if(m1.i + m2.i >= 0 && m1.i + m2.i <= maxmove.i && m1.j + m2.j >=0 && m1.j + m2. j <= maxmove.j){
		return(true);
	}
	return(false);
}
bool isAdjacent(char a, char b){
	string alp = "abcdefghijklmnopqrstuvwxyz";
	int diff = alp.find(a) - alp.find(b);
	if(abs(diff) == 1){
		return(true);
	}
	return(false);
}
void InsertNode(struct queue **Q, char c, int len, struct movement move){
	struct queue *node = NewNode(c, len, move);
	if(*Q == NULL){
		*Q= node;
	}
	else{
		struct queue *curr = *Q;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = node;
	}
}
void LengthOfLongestConsecutivePath(){
	char matrix[3][3] = { {'a', 'c', 'd'},{'h', 'b', 'e'}, {'i', 'g', 'f'}};
    int starti = 1, startj = 2, maxi = 2, maxj = 2, maxLen = 1;
   	int visited[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

    //Covers all the eight positions.
    vector<struct movement> moves;
    moves.push_back(NewMove(-1, -1));
    moves.push_back(NewMove(-1, 0));
    moves.push_back(NewMove(-1, 1));
    moves.push_back(NewMove(0, -1));
    moves.push_back(NewMove(0, 1));
    moves.push_back(NewMove(1, -1));
    moves.push_back(NewMove(1, 0));
    moves.push_back(NewMove(1, 1));

    struct movement maxMove = NewMove(maxi, maxj);
    struct queue *currQ = NULL, *nextQ = NULL;
    struct movement move = NewMove(starti, startj);
    currQ = NewNode(matrix[starti][startj], 1, move);
    while(currQ != NULL){
    	printf("Current : %c\n", currQ->c );
    	for(int i = 0; i < moves.size(); i++){
    		if(isValidMove(currQ->move, moves[i], maxMove)){
    			char adj = matrix[currQ->move.i + moves[i].i][currQ->move.j + moves[i].j];
    			bool isvisited = visited[currQ->move.i + moves[i].i][currQ->move.j + moves[i].j];
    			if(!isvisited && isAdjacent(currQ->c, adj)){
    				printf("Adjacent : %c\t", adj);
    				struct movement m = NewMove(currQ->move.i + moves[i].i, currQ->move.j + moves[i].j);
    				visited[currQ->move.i + moves[i].i][currQ->move.j + moves[i].j] = 1;
    				InsertNode(&nextQ, adj, currQ->len + 1, m);
    				if(maxLen < currQ->len + 1){
    					maxLen = currQ->len + 1;
    				}
    			}
    		}

    	}
    	printf("\n");
    	struct queue *temp = currQ;
    	currQ = currQ->next;
    	if(temp != NULL)
    		free(temp);

    	if(currQ == NULL){
    		currQ = nextQ;
    		nextQ = NULL;
    	}

    }
    
    printf("MaxLength is %d\n", maxLen );
}
int main(){
	LengthOfLongestConsecutivePath();
	return(0);
}

