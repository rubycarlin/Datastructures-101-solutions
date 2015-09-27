#include <iostream>

using namespace std;

bool IsOnePermutationOfOther(char *str1, char *str2){
	if(sizeof(str1) != sizeof(str2))
		return(false);

	//This code works only for ASCII characterset
	int *flags = new int[256];
	memset(flags, 0, sizeof(flags));
	for(int i = 0; i < sizeof(str1); i++){
		flags[str1[i]] += 1;
	}
	for(int i = 0; i < sizeof(str2); i++){
		flags[str2[i]] -= 1;
		if(flags[str2[i]] < 0)
			return(false);
	}
	return(true);
}
int main(){
	char str1[] = "madam", str2[] = "daamm";

	if(IsOnePermutationOfOther(str1, str2))
		printf(" %s is a permutation of %s\n",str2, str1);
	else
		printf("%s is not a permutation of %s\n",str2, str1);
	return(0);
}


