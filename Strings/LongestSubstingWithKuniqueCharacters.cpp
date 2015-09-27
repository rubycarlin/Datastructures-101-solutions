#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void FindLongestSubstringWithKUniqueChars(string str, int k){
	vector<int> count(str.size(), 0);
	map<char, bool> hash_map;

	int hm_size = 0;
	for(int i = 0; i < str.size(); i++){
		if(hash_map.find(str[i]) == hash_map.end()){
			hash_map[str[i]] = true;
			hm_size += 1;
		}
		count[i] = hm_size;
	}
	for(int curr = 0 ; curr < count.size(); curr++)
		cout << count[curr] << "->";
	cout << endl;
	int prev = 0;
	int max_len = 0;
	for(int curr = 0 ; curr < count.size(); curr++){
		cout << count[curr] - count[prev] << endl;
		if(count[curr] - count[prev] >= k){
			while(count[curr] - count[prev] >= k){
				prev++;
			}
		}		
		cout << curr << "\t" << prev  << "\t" << (curr - prev + 1) << endl;
		if((curr - prev + 1) > max_len){
			max_len = curr - prev + 1;
		}
	}
	printf("Max length is %d\n", max_len );
}
int main(){
	string str = "aabacbebebe";
	int k = 3;
	FindLongestSubstringWithKUniqueChars(str, k);
	return(0);
}

