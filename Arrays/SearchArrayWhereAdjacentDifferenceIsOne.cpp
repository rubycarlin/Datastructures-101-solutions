#include <iostream>

#define NOT_FOUND -1
using namespace std;

int getIndex(int data[], int len, int key){
	for(int i = 0; i < len; ){
		if(data[i] == key){
			return(i);
		}
		i = i + abs(key - data[i]);
	}
	return(NOT_FOUND);
}
void SearchArrayWithAdjacentDifferenceOne(){
	int data[] = {8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3};
	int key = 3, index = NOT_FOUND;
	int n = sizeof(data) / sizeof(data[0]);

	index = getIndex(data, n, key);

	if(index == NOT_FOUND){
		printf("Element not found\n");
	}
	else{
		printf("%d found at %d\n",key, index );
	}
}
int main(){
	SearchArrayWithAdjacentDifferenceOne();
	return(0);
}

