#include <iostream>

using namespace std;

void CountInversion(int data[], int len){
	int c = 0;
	for(int i = 1; i < len; i++){
		if(data[i - 1] > data[ i ])
			c += 1;
	}
	printf("Number of inversion is %d\n",c );
}
int main(){
	int data[] = {3,2,1};
	int len = sizeof(data) / sizeof(data[0]);

	CountInversion(data, len);
	return(0);
}

