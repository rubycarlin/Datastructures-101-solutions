#include <iostream>

using namespace std;

void MakeColumnAndRowZero(int matrix[5][3], int rowSize, int colSize){
	bool *row = new bool[rowSize];
	bool *col = new bool[colSize];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));

	for(int i = 0; i < rowSize; i++){
		for(int j = 0; j < colSize; j++){
			if(!matrix[i][j]){
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for(int i = 0; i < rowSize; i++){
		for(int j = 0; j < colSize && row[i]; j++){
			matrix[i][j] = 0;
		}
	}

	for(int j = 0; j < colSize; j++){
		for(int i = 0; i < rowSize && col[j] ; i++){
			matrix[i][j] = 0;
		}
	}
}
int main(){
	int matrix[5][3]={{1,2,3},{0,3,4},{2,4,6},{1,2,0},{2,5,7}};
	MakeColumnAndRowZero(matrix, 5, 3);
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 3; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	return(0);
}

