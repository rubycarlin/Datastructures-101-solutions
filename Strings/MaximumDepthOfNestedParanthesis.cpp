#include <iostream>
#include <string>

using namespace std;

void FindMaxDepth(string str){
	int curr = 0, max_dep = 0;
	for(int i =0; i < str.size(); i++){
		if(str[i] == '('){
			curr += 1;
		}
		else if(str[i] == ')'){
			curr -= 1;
		}
		if(curr > max_dep){
			max_dep = curr;
		}
	}
	printf("Max depth is %d\n", max_dep );
}
int main(){
	string str = "( p((q)) ((s)t) )";
	FindMaxDepth(str);
	return(0);
}

