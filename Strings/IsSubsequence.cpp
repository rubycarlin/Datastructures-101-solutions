#include <iostream>
#include <string>

using namespace std;
bool IsSubsequence(string a, string b, int curr_a_len, int curr_b_len){
	bool is_subsequence;
	
	if(curr_a_len >= a.size())
		return(true);
	if(curr_a_len < a.size() && curr_b_len >= b.size())
		return(false);
	if(a[curr_a_len] == b[curr_b_len])
		is_subsequence = IsSubsequence(a,b,curr_a_len + 1, curr_b_len + 1);
	else
		is_subsequence = IsSubsequence(a, b, curr_a_len, curr_b_len + 1);
	return(is_subsequence);
}
int main(){
	string a = "AXY", b = "YADXCP";
	bool is_subsequence = IsSubsequence(a, b, 0, 0);
	if(is_subsequence)
		printf("True\n");
	else
		printf("False\n");
	return(0);
}


