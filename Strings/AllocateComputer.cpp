#include <iostream>
#include <string>
#include <map>

using namespace std;

void ComputerSimulate(string str, int number_of_computers){
	int c = 0;
	bool can_allocate = true;
	map<char, bool> status;
	string cannot_allocate = "";
	for(int i = 0; i < str.size(); i++){
		if(status.find(str[i]) == status.end()){
			if(cannot_allocate.find(str[i]) == string::npos && c < number_of_computers){
				status[str[i]] = true;
				c += 1;
			}
			else if(cannot_allocate.find(str[i]) == string::npos){
				can_allocate = false;
				cannot_allocate.push_back(str[i]);
				cout << "Cannot allocate the computer for " << str[i] << endl;
			}
				
		}
		else{
			status[str[i]] = false;
			c -= 1;
		}
	}
	if(can_allocate){
		cout << "Can allocate to all the customers :)\n";
	}
}
int main(){
	string str = "GACCBDDBAGEE";
	int number_of_computers = 3;
	ComputerSimulate(str, number_of_computers);
	return(0);
}

