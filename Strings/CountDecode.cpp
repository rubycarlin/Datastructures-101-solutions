#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int CountDecode(string str, int curr){
	int count = 0;
	if(curr >= str.size())
		return(1);
	count += CountDecode(str, curr + 1);

	if(curr < str.size() - 1)
	{
		char double_digit[3];
		double_digit[0] = str[curr];
		double_digit[1] = str[curr + 1];
		double_digit[2] = '\0';
		if(atoi(double_digit) <= 26){
	//		cout << atoi(double_digit) << endl;
			count += CountDecode(str, curr + 2);
		}
	}
	
		
	return(count);
}
int main(){
	string str = "121";
	int count = CountDecode(str, 0);
	cout << "Number of decode is " << count << endl;
	return(0);
}

