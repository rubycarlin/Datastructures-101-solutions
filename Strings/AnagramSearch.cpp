#include <iostream>
#include <map>
#include <string>

using namespace std;
bool checkAndRemove(map<char,int>& hash_map, char to_be_removed){
	bool found = true;
	for(map<char, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
//		cout << it->first << "\t" <<it->second << endl;
		if(!it->second)
			found = false;
	}
	
	map<char, int>::iterator it = hash_map.find(to_be_removed);
	if(it != hash_map.end()){
		it->second -= 1;
//		cout << "removed : " << it->first << "\t" << it->second << endl;
	}
//	cout <<endl << endl;
	return(found);
}
void CheckAnagram(string txt, string pattern){
	map<char, int> hash_map;
	int pattern_size = pattern.size();
	for(int i = 0; i < pattern.size(); i++){
		if(hash_map.find(pattern[i]) == hash_map.end()){
			hash_map[pattern[i]] = 0; 
		}
	}
	for(int i = 0; i < txt.size() + 1; i++){
		if(i >= pattern_size){
			if(checkAndRemove(hash_map, txt[i-pattern_size]))
				cout << "Pattern starts at " << (i-pattern_size) << endl;
		}
		if(i < txt.size() &&  hash_map.find(txt[i]) != hash_map.end()){
			hash_map[txt[i]] += 1;
		}
	}
}
int main(){
	string txt = "BACDGABCDA", pattern = "ABCD";
	CheckAnagram(txt, pattern);
	return(0);

}

