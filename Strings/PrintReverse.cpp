#include <iostream>
#include <string>

using namespace std;

void ReversePrint(string str, int curr){
	if(curr >= str.size())
		return;
	ReversePrint(str, curr + 1);
	cout << str[curr];
}
int main(){
	string str = "hello";
	ReversePrint(str, 0);
	return(0);
}


