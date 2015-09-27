#include <iostream>

using namespace std;

int GetOddElement(int data[], int low, int high){

	if(high == low){
		return(data[high]);
	}
	printf("Low : %d \t HIGH : %d\n", low, high);
	int mid = (high + low) / 2;
	printf("Mid index : %d\n", mid );
	if(mid % 2 == 0 && data[mid] == data[mid + 1]){
		printf("IF Mid : %d \t MID + 1 : %d\n", data[mid], data[mid + 1] );
		GetOddElement(data, mid + 1, high);
	}
	else if(mid % 2 == 0 && data[mid] != data[mid + 1]){
		printf("ELSE Mid : %d \t MID + 1 : %d\n", data[mid], data[mid + 1] );
		GetOddElement(data, low, mid + 1);
	}
	else if(mid %2 != 0 && data[mid] == data[mid -1]){
		printf("IF Mid : %d \t MID - 1 : %d\n", data[mid], data[mid - 1] );
		GetOddElement(data, mid + 1, high);
	}
	else if(mid %2 != 0 && data[mid] != data[mid -1]){
		printf("ELSE Mid : %d \t MID - 1 : %d\n", data[mid], data[mid - 1] );
		GetOddElement(data, low, mid -1);
	}
}
void FindOddAppearingElement(){
	int data[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40, 13, 13};
	int n = sizeof(data) / sizeof(data[0]);
	int xor_val = data[0];

	//O(n) solution
	for(int i = 1; i < n; i++){
		xor_val = xor_val ^ data[i];
	}
	printf("Odd occuring element is %d \n", xor_val);

	//O(logn) solution using binary search
	int ele = GetOddElement(data, 0, n);
	printf("Odd occuring element is %d \n", ele);
}
int main(){
	FindOddAppearingElement();
	return(0);
}

