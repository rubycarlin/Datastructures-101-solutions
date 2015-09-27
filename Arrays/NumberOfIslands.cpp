#include <iostream>

using namespace std;

void CountIsland(int matrix[6][3], int row, int col){
	int nof_island = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(matrix[i][j] == 'X' && (i == 0 || matrix[i-1][j] != 'X') && (j == 0 || matrix[i][j-1] != 'X'))
				nof_island += 1;
		}
	}
	printf("Number of islands are %d\n", nof_island);
}
int main(){
	int matrix[6][3]={{'O', 'O', 'O'}, {'X', 'X', 'O'}, {'X', 'X', 'O'}, {'O', 'O', 'X'}, {'O', 'O', 'X'}, {'X', 'X', 'O'}};
	CountIsland(matrix, 6, 3);
	return(0);
}


