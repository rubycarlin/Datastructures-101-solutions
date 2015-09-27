#include <iostream>

using namespace std;

bool HasUniqueCharacters(string s){
	//This code is applicable only for ascii character set
	if(s.length() >= 128){
		return(false);
	}

	bool *character_check = new bool[256];
	memset(character_check, false, sizeof(character_check));
	for(int i = 0; i < s.length(); i++){
		if(character_check[s[i]]){
			return(false);
		}
		character_check[s[i]] =  true;
	}
	return(true);
}
int main(){
	string s = "hairy";
	if(HasUniqueCharacters(s))
		printf("String '%s' has unique characters\n", s.c_str());
	else
		printf("String '%s' does not have unique characters\n", s.c_str());
	return(0);
}


