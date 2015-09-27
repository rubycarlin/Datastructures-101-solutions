#include <iostream>

using namespace std;

void ReplaceOWithX(char matrix[6][6], int row, int col){
	for(int i = 1; i < row - 1; i++){
		for(int j = 1; j < col - 1; j++){
			if(matrix[i][j] == 'O'){
				matrix[i][j] = '-';
			}
		}
	}

	for(int i = 1; i < row - 1; i++){
		for(int j = 1; j < col - 1; j++){
			if(matrix[i][j] == '-'){
				if((matrix[i + 1][j] == 'X' || matrix[i + 1][j] == '-') && (matrix[i][j - 1] == 'X' || matrix[i][j - 1] == '-') && (matrix[i][j + 1] == 'X' || matrix[i][j + 1] == '-') && (matrix[i - 1][j] == 'X' || matrix[i - 1][j] == '-')){
					matrix[i][j] = 'X';
				}
				else{
					matrix[i][j] = 'O';
				}
			}
		}
	}

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
int main(){

	char matrix[6][6] = {{'X', 'O', 'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X', 'O', 'X'}, {'X', 'X', 'X', 'O', 'O', 'X'}, {'O', 'X', 'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'O', 'X', 'O'}, {'O', 'O', 'X', 'O', 'O', 'O'}};
	ReplaceOWithX(matrix, 6, 6);
	return(0);
}

