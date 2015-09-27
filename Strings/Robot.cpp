#include <iostream>
#include <string>
#include <utility>

using namespace std;

void IsCircular(string instruction, char curr_direction, pair<int, int> curr_pos){
	for(int i = 0; i < instruction.size(); i++){
		if(instruction[i] == 'G'){
			if(curr_direction == 'N'){
				curr_pos.second += 1;
			}
			else if(curr_direction == 'S'){
				curr_pos.second -= 1;
			}
			else if(curr_direction == 'E'){
				curr_pos.first += 1;
			}
			else{
				curr_pos.first -= 1;
			}
		}
		else if(instruction[i] == 'L'){
			if(curr_direction == 'N'){
				curr_direction = 'W';
			}
			else if(curr_direction == 'S'){
				curr_direction = 'E';
			}
			else if(curr_direction == 'E'){
				curr_direction = 'N';
			}
			else if(curr_direction == 'W'){
				curr_direction = 'S';
			}

		}
		else{
			if(curr_direction == 'N'){
				curr_direction = 'E';
			}
			else if(curr_direction == 'S'){
				curr_direction = 'W';
			}
			else if(curr_direction == 'E'){
				curr_direction = 'S';
			}
			else if(curr_direction == 'W'){
				curr_direction = 'N';
			}

		}
	}
	if(curr_pos.first == 0 && curr_pos.second == 0){
		cout << "Given instructions are circular" << endl;
	}
	else{
		cout << "Given instructions are not circular . Current position is (" << curr_pos.first << " , " << curr_pos.second << ")\n";
	}
}
int main(){
	string instruction = "GLGG";
	char curr_direction = 'N';
	pair<int, int> curr_pos(0,0);
	IsCircular(instruction, curr_direction, curr_pos);
	return(0);
}

