#include <iostream>
#include <string>

using namespace std;

string Filter(string str){
	string output;
	int prev_a = -1;
	for(int i = 0; i < str.size();){
		if(str[i] == 'b' ){
			i++;
			continue;
		}
		else if(str[i] == 'a'){
			if(prev_a >= 0){
				output.push_back(str[prev_a]);
				prev_a = -1;
			}
			if((i + 1) < str.size() && str[i + 1] == 'c'){
				i += 2;
				continue;
			}
			else{
				prev_a = i;
				i  += 1;
			}
		}
		else{
			if(prev_a >= 0 && str[i] == 'c'){
				prev_a = -1;
				i += 1;
			}
			else if(prev_a >= 0){
				output.push_back(str[prev_a]);
				prev_a = -1;
				output.push_back(str[i]);
				i++;
			}
			else{
				output.push_back(str[i]);
				i++;
			}
			
		}
	}
	if(prev_a >= 0){
		
		output.push_back(str[prev_a]);
		prev_a = -1;
	}
	return(output);
}
int main(){
	string str = "aa";
	string output = Filter(str);
	cout << "output : " << output << endl;
	return(0);
}

