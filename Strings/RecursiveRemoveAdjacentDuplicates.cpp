#include <iostream>
#include <string>

using namespace std;
void RcursiveRemoveAdjacentDuplicate(string &str, int curr){
	if(curr >= str.size() - 1)
		return;
	if(str[curr] == str[curr + 1]){
		str.erase(curr, 2);
		if(curr > 0)
			RcursiveRemoveAdjacentDuplicate(str, curr - 1);
		else
			RcursiveRemoveAdjacentDuplicate(str, curr);
	}
	else{
		RcursiveRemoveAdjacentDuplicate(str, curr + 1);
	}
}
int main(){
	string str = "geeksforgeeg";
	RcursiveRemoveAdjacentDuplicate(str, 0);
	cout << "After removal : " << str << endl;

	return(0);
}

