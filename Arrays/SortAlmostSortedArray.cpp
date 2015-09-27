#include <iostream>

using namespace std;

int getOutOfOrderfromLeft(int data[], int len){
	int ind = -1;
	for(int i = 0; i < len - 1; i++){
		if(data[i] > data[i + 1]){
			return(i);
		}
	}
	return(ind);
}

int getOutOfOrderFromRight(int data[], int len){
	int ind = -1;
	for(int i = len -1; i > 0; i--){
		if(data[i] < data[i-1]){
			return(i);
		}
	}
	return(ind);
}
void SortAlmostSortedArray(){
	int data[] = {10, 20, 60, 40, 50, 30} ;
	int len = sizeof(data) / sizeof(data[0]);

	int index1 = getOutOfOrderfromLeft(data, len);
	int index2 = getOutOfOrderFromRight(data, len);

	if(index1 == -1 || index2 == -1){
		printf("No out of order element\n");
		return;
	}
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;

	for(int i = 0; i < len; i++){
		printf("%d->", data[i]);
	}
	printf("\n");

}
int main(){
	SortAlmostSortedArray();
	return(0);
}

