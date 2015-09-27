#include <iostream>
#include <vector>

using namespace std;

void NearestSmallerNumberOnLeft(){
	int data[] = {1, 6, 4, 10, 2, 5};
	int len = sizeof(data) / sizeof(data[0]);

	vector<int> smallNumberArray, stack;
	smallNumberArray.push_back(-1);
	stack.push_back(-1);
	stack.push_back(data[0]);
	int curr = 1;
	for(int i = 1; i < len; i++){
		if(data[i] > stack[curr]){
			smallNumberArray.push_back(stack[curr]);
			stack.push_back(data[i]);
			curr++;
		}
		else{
			while(data[i] < stack[curr]){
				stack.pop_back();
				curr--;
			}
			smallNumberArray.push_back(stack[curr]);
			stack.push_back(data[i]);
			curr++;
		}
	}
	for(int i = 0; i < len; i++){
		printf("Element : %d Smallest on left : %d\n",data[i], smallNumberArray[i] );
	}

}
int main(){
	NearestSmallerNumberOnLeft();
	return(0);
}

