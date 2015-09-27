#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>



using namespace std;

void MoveDDistanceAway(string str, int d){
	map<char, int> hash_map;
	for(int i = 0; i < str.size(); i++){
		if(hash_map.find(str[i]) == hash_map.end())
			hash_map[str[i]] = 1;
		else
			hash_map[str[i]] += 1;
	}
	vector<
	sort(hash_map.begin(), hash_map.end());
	for(map<char, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
		cout << it->first  << "\t" << it->second << endl;
	}
}
int main(){
	string str = "aacbbc";
	int d = 3;
	MoveDDistanceAway(str, d);
	cout << "Output : " << str << endl;
	return(0);
}

