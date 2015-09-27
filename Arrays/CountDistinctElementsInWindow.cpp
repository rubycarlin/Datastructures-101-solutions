#include <iostream>
#include <map>

using namespace std;

void CountDistinctElement(){
	int data[] = {1, 2, 1, 3, 4, 2, 3}, windowSize = 4;
	int n = sizeof(data) / sizeof(data[0]);

	map<int, int> HM;
	int count = 0;
	int start = 0;
	for(int i = 0; i < n + 1; i++){
		if(i != 0 && i - start == windowSize){
			printf("Count Between %d and %d is %d\n",i-windowSize, i-1, count );
			HM[data[i-windowSize]] -= 1;
			if(HM[data[i-windowSize]] == 0){
				HM.erase(data[i-windowSize]);
				count--;
			}
			start++;
		}
		if(i < n && HM.find(data[i]) != HM.end()){
			HM[data[i]] += 1;
		}
		else if(i < n){
			HM[data[i]] = 1;
			count++;
		}


	}
}
int main(){
	CountDistinctElement();
	return(0);
}

