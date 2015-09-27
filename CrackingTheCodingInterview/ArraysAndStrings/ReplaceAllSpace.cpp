#include <iostream>

#define NO_OF_REPLACEMENT_CHARACTER 3
using namespace std;

void ReplaceAllSpace(char *str, int len){
	int nof_space = 0;
	for(int i = 0; i < len; i++){
		if(' ' == str[i])
			nof_space += 1;
	}
	int curr = len, end = len - nof_space + (nof_space * NO_OF_REPLACEMENT_CHARACTER);
	str[end--] = str[curr--];
	while(curr <= end){
		if(str[curr] != ' '){
			str[end--] = str[curr--];
		}
		else{
			str[end--] = '0';
			str[end--] = '2';
			str[end--] = '%';
			curr--;
		}
	}
}
int main(){

	char str[] = "Mr John Smith\0    ";
	int len = 13;
	ReplaceAllSpace(str, len);
	printf("After replacement : %s\n", str);
	return(0);
}


