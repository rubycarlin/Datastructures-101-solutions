#include <iostream>
#include <string.h>

using namespace std;

bool IsRotation(char *str1, char *str2, int len){
	char buffer[len*2];
	cout << str1 << "\t" << str2 << endl;
	sprintf(buffer, "%s%s\0", str2, str2);
	if(strstr(buffer, str1) != NULL)
		return(true);
	return(false);
}
int main(){
	char str1[] = "waterbottle\0", str2[] = "erbottlewat\0";
	bool isRotation = IsRotation(str1, str2, sizeof(str2));
	if(isRotation)
		printf("%s is rotation of %s\n",str2, str1);
	else
		printf("%s is not rotation of %s\n",str2, str1);
	return(0);
}


