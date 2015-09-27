#include <iostream>
#include <string>

using namespace std;

void RemoveSpace(string str){
	int slow = 0, fast = 0;
	int str_len = str.size();
	while(slow < str_len && fast < str_len){
		if(str[slow] == ' '){
			fast = slow;
			while(str[fast] == ' ' && fast < str_len){
				fast++;
			}
			while(str[slow] == ' ' && str[fast] != ' ' && fast < str_len){
				str[slow] = str[fast];
				str[fast] = ' ';
			}
		}
		else
			slow++;
	}
	str[slow] = '\0';
	cout << str << endl;
}
int main(){
	string str = "g  eeks     for ge  eeks  ";
	RemoveSpace(str);
	return(0);
}

