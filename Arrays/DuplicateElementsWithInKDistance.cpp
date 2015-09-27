#include <iostream>
#include <map>

using namespace std;

void FindDuplicateElementWithInKDistance(int data[], int len){
	map<int, int> hash_map;
	int k;
	cout << "Enter the value of K : ";
	cin >> k;
	bool found = false;
	for(int i = 0; i < len; i++){
		if(i - k > 0){
			hash_map.erase(data[i - k]);
		}
		if(hash_map.find(data[i]) == hash_map.end()){
			hash_map[data[i]] = 1;
		}
		else{
			found = true;
			hash_map[data[i]] += 1;
			printf("%d found at %d\n", data[i], i);
		}
	}
	if(!found){
		printf("No such element\n");
	}
}
int main(){

	int data[] = {1, 2, 3, 1, 4, 5};
	int len = sizeof(data) / sizeof(data[0]);

	FindDuplicateElementWithInKDistance(data, len);

	return(0);
}

