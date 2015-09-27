#include <iostream>

using namespace std;

void FindPair(int data[], int len, int x){
	int start = -1, end = -1;
	for(int i = 0; i < len; i++){
		if(data[i] >data[i + 1]){
			start = i + 1;
			end = i;
			break;
		}
	}
	while(start != end){
		if(end < 0){
			end += len;
		}
		int curr_sum = data[start] + data[end];
		if(curr_sum == x){
			printf("Pair Found (%d, %d) \n",data[start], data[end] );
			return;
		}
		if(curr_sum > x){
			end--;
		}
		else{
			start++;
		}
	}
	printf("No such pair exist\n" );
}
int main(){
	int data[] = {11, 15, 6, 8, 9, 10};
	int len = sizeof(data) / sizeof(data[0]);
	int x = 87;
	FindPair(data, len, x);
	return(0);
}


