#include <iostream>
#include <string>

using namespace std;

bool IsInterleaved(string a, string b, string c){
	if(c.size() < (a.size() + b.size()))
		return(false);
	int a_start = 0, b_start = 0;
	for(int i = 0; i < c.size(); i++){
		if(c[i] == a[a_start])
			a_start++;
		else if(c[i] == b[b_start])
			b_start++;
	}
	if(a_start >= a.size() && b_start >= b.size())
		return(true);
	return(false);
}
int main(){
	string a = "AB", b = "CD", c = "CDAB";
	bool is_interleaved = IsInterleaved(a,b,c);
	if(is_interleaved)
		cout << c << " is interleaved of " << a << " and " << b << endl;
	else
		cout << c << " is not interleaved of " << a << " and " << b << endl;
	return(0);
}

