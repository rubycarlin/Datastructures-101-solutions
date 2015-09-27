#include <iostream>

using namespace std;

void getFirstTwoLargest(int data[], int len, int &firstLargest, int &secondLargest){
	firstLargest = secondLargest = data[0];
	for(int i = 1; i < len; i++){
		if(data[i] >= firstLargest){
			secondLargest = firstLargest;
			firstLargest = data[i];
		}
	}
}
void LargestPairSum(){
	int data[] = {9, 34, -4, 89, 2};
	int len = sizeof(data) / sizeof(data[0]);

	int firstLargest, secondLargest;
	getFirstTwoLargest(data, len, firstLargest, secondLargest);

	printf("Sum of (%d, %d) is %d which is largest in the array\n", firstLargest, secondLargest, firstLargest + secondLargest);
}
int main(){
	LargestPairSum();
	return(0);
}


