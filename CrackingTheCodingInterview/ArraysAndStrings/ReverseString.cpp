#include <iostream>

using namespace std;

void ReverseString(char *str){
	int n = 0;
	for(int i = 0; str[i] != '\0'; i++){
		n += 1;
	}
	cout << n << endl;
	for(int i = 0, j = n - 1; i < j; i++, j--){
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}
int main(){
	//If you use *str you have to use the pointers to swap the content because the content of char *str = "hello" will be placed in ROM
	char str[] = "How are you\0";
	ReverseString(str);
	printf("Reversed string is %s\n", str);
	return(0);
}

