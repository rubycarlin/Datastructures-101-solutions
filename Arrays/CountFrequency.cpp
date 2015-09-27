#include <iostream>

using namespace std;

void CountFrequency(){
	int data[] = {2, 3, 3, 2, 5};
	int len = sizeof(data) / sizeof(data[0]);
	int curr = 0;
	while(curr < len){
		if(data[curr] < 0){
			curr++;
			continue;
		}

		int index = data[curr] - 1;
		if(data[index] >= 0){
			data[curr] = data[index];
			data[index] = -1;
		}
		else{
			data[index]--;
			data[curr] = 0;
			curr++;
		}
	//	printf("Curr : %d \t data[curr] : %d\n",curr, data[curr] );
	}
	for(int i = 0; i < len; i++)
		printf("Frequency of %d is %d \n", i+1, abs(data[i]));
}
int main(){
	CountFrequency();
	return(0);
}

