#include <iostream>

using namespace std;

void PrintRangeOfMissingElements(int data[], int len){
	bool *flag = new bool[100];
	for(int i = 0 ; i < len; i++){
		flag[data[i]] = true;
	}
	int start = -1, end = -1;
	for(int i = 0; i < 100; i++){
		if(!flag[i] && start == -1){
			start = i;
		}
		else if(!flag[i] && start != -1){
			end = i;
		}
		else if(flag[i] && start != -1 && end != -1){
			cout << start << '-' << end << endl;
			start = -1;
			end = -1;
		}
		else if(flag[i] && start != -1 && end == -1){
			cout << start << endl;
			start = -1;
		}
	}
	if(start != -1 ){
		cout << start ;
	}
	if(end != -1){
		cout << "-" << end;
	}
	cout <<endl;
}
int main(){
	int data[] = {88,2,6,1,7,3,58};
	int len = sizeof(data) / sizeof(data[0]);
	PrintRangeOfMissingElements(data, len);
	return(0);
}

