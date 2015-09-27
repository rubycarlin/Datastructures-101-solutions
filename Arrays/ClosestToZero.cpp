#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FindClosestToZero(vector<int> data, int len){

	int min = data[0] + data[len - 1];
	sort(data.begin(), data.end());
	int ele1 = data[0], ele2 = data[len-1];
	for(int i = 1, j = len-2; i < j; ){
		if(abs(data[i] + data[j]) < min ){
			min = data[i] + data[j];
			ele1 = data[i];
			ele2 = data[j];
		}
		if(data[i] + data[j] == 0){
			ele1 = data[i];
			ele2 = data[j];
			break;
		}
		else if(data[i] + data[j] < 0){
			i++;
		}
		else{
			j--;
		}
	}
	printf("Closest pair is (%d, %d) \n",ele1, ele2 );

}
int main(){
	int data[] = {1, 60, -10, 70, -80, 85};

	int len = sizeof(data) / sizeof(data[0]);

	vector<int> vec_data(data, data + len);

	FindClosestToZero(vec_data, len);
	return(0);
}

