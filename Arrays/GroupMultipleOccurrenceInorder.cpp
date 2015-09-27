#include <iostream>
#include <map>
#include <utility> 

using namespace std;

void GroupMultipleOccurrence(int data[], int len){
	;
	map<int, pair<int, bool> > hash_map;
	int group_data[len];
	for(int i = 0; i < len; i++){
		if(hash_map.find(data[i]) == hash_map.end()){
			hash_map[data[i]].first = 1;
			hash_map[data[i]].second = false;
		}
		else{
			hash_map[data[i]].first += 1;
		}
	}

	int index = 0;
	for(int i = 0; i < len; i++){
		if(!hash_map[data[i]].second){
			for(int j = 0; j < hash_map[data[i]].first; j++){
				group_data[index++] = data[i];
			}
			hash_map[data[i]].second = true;
		}
	}
	for(int i = 0; i < len; i++){
		cout << group_data[i] << "->";
	}
	cout << endl;
}
int main(){
	int data[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
	int len = sizeof(data) / sizeof(data[0]);

	GroupMultipleOccurrence(data, len);
	return(0);
}

