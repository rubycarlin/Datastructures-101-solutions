#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void SortByFrequency(int data[], int len){
	map<int, int> hash_map;
	for(int i = 0; i < len; i++){
		if(hash_map.find(data[i]) == hash_map.end()){
			hash_map[data[i]] = 1;
		}
		else{
			hash_map[data[i]] += 1;
		}
	}
	sort(hash_map.begin(), hash_map.end());
	for(map<int, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
		for(int i = 0; i < it->second; i++)
			cout << it->first << "->";
	}
	cout << endl;
}
int main(){
	int data[] = {2,5,2,8,5,6,8,8};
	int len = sizeof(data) / sizeof(data[0]);

	SortByFrequency(data, len);
	return(0);
}


