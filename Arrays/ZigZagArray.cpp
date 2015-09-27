#include <iostream>

using namespace std;

void ZigZagArray(){
	int data[] = {4, 3, 7, 8, 6, 2, 1};
	int n = sizeof(data) / sizeof(data[0]);
	for(int i = 0; i < n - 1; i++){
		if( i % 2 == 0){
			if(data[i] > data[ i + 1]){
				int temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
			}
		}
		else{
			if(data[i] < data[i + 1]){
				int temp = data[i];
				data[i] = data[ i + 1];
				data[i+1] = temp;
			}
		}
	}
	printf("After zigzag\n");
	for(int i = 0; i < n; i++){
		printf("%d->",data[i] );
	}
	printf("\n");
}
int main(){
	ZigZagArray();
	return(0);
}

