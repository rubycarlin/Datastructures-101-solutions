#include <iostream>
#include <string>

using namespace std;

void RecursePrint(string str, int curr, string buffer, int len){
	if(curr >= len){
		cout << buffer << "\n";
		return;
	}
	RecursePrint(str, curr + 1, buffer + str[curr] , len);
	RecursePrint(str, curr + 1, buffer + " " + str[curr], len);
}
int main(){
	string str = "ABCD";
	string buffer = "A";
	RecursePrint(str, 1, buffer, str.size());
	return(0);
}

