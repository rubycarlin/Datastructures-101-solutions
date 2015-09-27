#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(string &str,int i,int j){
	char c = str[i];
	str[i] = str[j];
	str[j] = c;
}
void Permute(string str, int curr){
	if( curr < 0 )
		return;
	for(int i = curr - 1; i >= 0; i--){
		cout << str << endl;
		swap(str, curr, i);
		cout << str << endl;
		Permute(str, curr - 1);
		swap(str, curr, i);
	}
}
int main(){
	string str = "ABC";
	sort(str.begin(), str.end());
	Permute(str, str.size() - 1);
	return(0);
}


