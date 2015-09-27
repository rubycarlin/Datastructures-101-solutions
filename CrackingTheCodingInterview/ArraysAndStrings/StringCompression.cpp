#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char *getCompressedString(char *str, int len){
	char *compressedString = new char[sizeof(str)];
	int c = 1;
	
	for(int i = 1; i < len; i++){
		if(str[i] == str[i - 1]){
			c += 1;
		}
		else{			
			char buffer[100];
			sprintf(buffer, "%c%d\0",str[i-1], c);
			strcat(compressedString, buffer);
			c = 1;			
		}
	}
	if(sizeof(compressedString) <= len){
		return(compressedString);
	}
	else{
		return(str);
	}
}
int main(){
	char str[] = "aabcDDwEghhqq\0";
	char *compressedString = getCompressedString(str, sizeof(str));
	printf("Compressed string is %s\n", compressedString);
	return(0);
}

