#include <iostream>
#include <map>

using namespace std;

void FindUnion(int data1[], int len1, int data2[], int len2){
	int union_arr[len1 + len2];
	map<int, int> hash_map;
	for(int i = 0; i < len1; i++){
		if(hash_map.find(data1[i]) == hash_map.end()){
			hash_map[data1[i]] = 1;
		}
		else{
			hash_map[data1[i]] += 1;
		}
	}
	for(int i = 0; i < len2; i++){
		if(hash_map.find(data2[i]) == hash_map.end()){
			hash_map[data2[i]] = 1;
		}
		else{
			hash_map[data2[i]] += 1;
		}
	}
	int i = 0;
	for(map<int,int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
		union_arr[i] = it->first;
		cout << it->first << "\t";
		i++;
	}
	cout << endl;
}
void FindIntersection(int data1[], int len1, int data2[], int len2){
	int intersection[len1 + len2];
	map<int, int> hash_map;
	for(int i = 0; i < len1; i++){
		if(hash_map.find(data1[i]) == hash_map.end()){
			hash_map[data1[i]] = 1;
		}
		else{
			hash_map[data1[i]] += 1;
		}
	}
	for(int i = 0; i < len2; i++){
		if(hash_map.find(data2[i]) == hash_map.end()){
			hash_map[data2[i]] = 1;
		}
		else{
			hash_map[data2[i]] += 1;
		}
	}
	int i = 0;
	for(map<int,int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
		if(it->second > 1){
			intersection[i] = it->first;
			cout << it->first << "\t";
			i++;
		}
	}
	cout << endl;

}
int main(){
	int data1[] = {1,3,67,2,8,3}, data2[] = {3,6,2,8,1,19};
	FindUnion(data1, 6, data2, 6);
	FindIntersection(data1, 6, data2, 6);
	return(0);
}

