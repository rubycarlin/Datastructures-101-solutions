#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void PrintList(vector<string> list, string word){
	map<char, bool> hm;
	for(int i = 0; i < word.size(); i++){
		if(hm.find(word[i]) == hm.end())
			hm[word[i]] = true;
	}
	for(int i = 0; i < list.size(); i++){
		int count = 0;
		for(int j = 0; j < list[i].size(); j++){
			map<char, bool>::iterator map_itr = hm.find(list[i][j]);
			if(map_itr != hm.end() && map_itr->second){
				count += 1;
				map_itr->second = false;
			}
		}
		//cout << list[i] << "\t " << count << endl;
		if(count == word.size())
			cout << list[i] << endl;
		for(map<char, bool>::iterator it = hm.begin() ; it != hm.end(); it++){
		//	cout << it->first << "\t" << it->second << endl;
			it->second = true;
		}
	}
}
int main(){
	string word = "sun";
	string list[] = {"sunday", "geeksforgeeks", "utensils", "just", "sss"};
	std::vector<string> v(list, list + 5);
	PrintList(v, word);
	return(0);
}

