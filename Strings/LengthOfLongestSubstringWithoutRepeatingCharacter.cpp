#include <iostream>
#include <string>
#include <map>

using namespace std;

int LongestSubstringLength(string str){
	int cur_len = 0, max_len = 0;
	map<char, int> visited;
	for(int i = 0; i < str.size(); i++){
		if(cur_len > max_len)
			max_len = cur_len;
		if(visited.find(str[i]) == visited.end()){
			visited[str[i]] = i;
			cur_len += 1;
		}
		else{
			cur_len = i - visited[str[i]];
			visited[str[i]] = i;
		}
	}
	return(max_len);
}
int main(){

	string str = "GEEKSFORGEEKS";
	int len = LongestSubstringLength(str);
	cout << "Length of the longest substring is " << len << endl;
	return(0);
}

