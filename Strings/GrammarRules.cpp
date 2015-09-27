#include <iostream>
#include <string>

using namespace std;

bool CheckGrammar(string str){
	int spaceCount = 0;
	for(int i = 0; i < str.size(); i++){
		if(i == 0 && !(str[i] >= 'A' && str[i] <='Z')){
			return(false);
		}
		else if(i == str.size() - 1 && str[i] != '.'){
			return(false);
		}
		else if(str[i] == ' ' && str[i-1] == ' '){
			return(false);
		}
		else if(i != 0 && (str[i] >= 'A' && str[i] <='Z') && str[i-1] != ' '){
			return(false);
		}
		if(str[i] == ' '){
			spaceCount++;
		}
	}
	if(spaceCount)
		return(true);
	
	return(false);
}
int main(){
	string str = "I lovE cinema.";
	bool valid = CheckGrammar(str);
	if(valid)
		cout << "Given statement is valid\n";
	else
		cout << "Given statement is not a valid one\n";
	return(0);
}

