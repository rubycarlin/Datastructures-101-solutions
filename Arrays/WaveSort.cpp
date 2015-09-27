#include <iostream>

using namespace std;

void WaveSort(int data[], int len){
	for(int i = 0; i < len; i++){
		if( i % 2 == 0 && data[i] > data[ i + 1]){
			int temp = data[i];
			data[i] = data[i+1];
			data[i+1] = temp;
		}
		else if( i % 2 == 1 && data[i] < data[i+1]){
			int temp = data[i];
			data[i] = data[i+1];
			data[i+1] = temp;
		}
	}
	for(int i = 0; i < len; i++){
		cout << data[i] << "->";
	}
	cout << endl;
}
int main(){
	int data[] = {10, 5, 6, 3, 2, 20, 100, 80};
	int len = sizeof(data) / sizeof(data[0]);

	WaveSort(data, len);

	return(0);
}

