#include <iostream>
#include <vector>
using namespace std;

void MaximumAverageSubArray(){
	int data[] = {1, 12, -5, -6, 50, 90}, k = 4;
	vector<int> sumArray;
	int maxArrayIndex = -1;
	int n = sizeof(data) / sizeof(data[0]);
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += data[i];
	}
	sumArray.push_back(sum);
	for(int i = 1; i < n; i++){
		sum = sum - data[i-1];
		sumArray.push_back(sum);
	}
	sum = 0;
	for(int i = 0; (i + 4) <= n; i++){
		if((i + 4) < n){
			if (sum < (sumArray[i] - sumArray[i + 4])){
				sum = (sumArray[i] - sumArray[i + 4]);
				maxArrayIndex = i;
			}
		}
		else{
			if(sum < sumArray[i]){
				sum = sumArray[i];
				maxArrayIndex = i;
			}
		}
	}
	printf("Sum is %d and index starts at %d\n", sum, maxArrayIndex);
	printf("Average is %d\n", sum / k);
}
int main(){
	MaximumAverageSubArray();
	return(0);
}


