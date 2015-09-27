#include <iostream>

#define ROWINDEX 3
#define COLINDEX 3

using namespace std;

void CalculateSum(int sum, int row_sum[3], int col_sum[3], int indexes[3][2], int matrix[3][3]){
	for(int i = 0; i < 3; i++){
		int row = indexes[i][0];
		int col = indexes[i][1];
		printf("Sum of matrix except (%d,%d) is %d\n",row , col, sum - row_sum[row] - col_sum[col] + matrix[row][col]);
	}
	
}
void SumOfElementsInAMatrixWithoutARowAndAColumn(){
	int matrix[3][3] = {{1,1,2}, {3,4,6},{5,3,2}};
	int Indexes[3][2] = {{0,0}, {1,1}, {0,1}};
	int sum = 0;
	int row_sum[3], col_sum[3];
	memset(row_sum, 0, sizeof(row_sum));
	memset(col_sum, 0, sizeof(col_sum));

	for(int i = 0; i < ROWINDEX; i++){
		for(int j = 0; j < COLINDEX; j++){
			sum += matrix[i][j];
			row_sum[i] += matrix[i][j];
			col_sum[j] += matrix[i][j];
		}
	}
	CalculateSum(sum, row_sum, col_sum, Indexes, matrix);
	
}
int main(){
	SumOfElementsInAMatrixWithoutARowAndAColumn();
	return(0);
}

