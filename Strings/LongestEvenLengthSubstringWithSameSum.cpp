#include <iostream>
#include <string>

using namespace std;

void LongestEvenLengthSubstringWithSameSum(string str){
	int max_len = 0, curr_len = 0;
	int str_len = str.size();
	for(int i = 0; i < str_len - 1; i++){
		int l = i, r = i + 1;
		int lsum = 0, rsum = 0;
		while(l >= 0 && r < str_len){
			curr_len = r - l + 1;
		//	cout << l << "," << r << "," << curr_len << endl;
			lsum += str[l--] - '0';
			rsum += str[r++] - '0';
			
			
		//	cout << lsum << "," << rsum << endl << endl;
			if(lsum == rsum && curr_len > max_len){
				max_len = curr_len;
			} 
		}
	}
	printf("Max length is %d\n", max_len);
}
int main(){
	string str = "1538023";
	LongestEvenLengthSubstringWithSameSum(str);
	return(0);
}

