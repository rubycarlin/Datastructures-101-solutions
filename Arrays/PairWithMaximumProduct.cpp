#include <iostream>

using namespace std;

int getMaxPositiveProduct(int data[], int len){
	int product = 1;
	int first_max = data[0], second_max = data[0];
	for(int i = 0; i < len; i++){
		if(data[i] >= first_max){
			second_max = first_max;
			first_max = data[i];
		}
	}
	printf("(%d, %d)\n",first_max, second_max );
	return(first_max * second_max);
}
int getMaxNegativeProduct(int data[], int len){
	int product = 1;
	int first_max = data[0], second_max = data[0];
	for(int i = 0; i < len; i++){
		if(data[i] <= first_max){
			second_max = first_max;
			first_max = data[i];
		}
	}
	printf("(%d, %d)\n",first_max, second_max );
	return(first_max * second_max);
}
int getMaxOfPositiveAndNegative(int data[], int len){
	int pos_product = getMaxPositiveProduct(data, len);
	int neg_product = getMaxNegativeProduct(data, len);
	if(pos_product > neg_product)
		return(pos_product);
	return(neg_product);
}
bool isNegativePresent(int data[], int len){
	for(int i = 0; i < len; i++){
		if(data[i] < 0){
			return(true);
		}
	}
	return(false);
}
void FindMaxProduct(){
	int data[] = {-1, -3, -4, 2, 0, -5} ;
	int len = sizeof(data)/ sizeof(data[0]);
	int max_product = 0;
	if(!isNegativePresent(data, len)){
		printf("Max product is %d\n", getMaxPositiveProduct(data, len) );
	}
	else{
		printf("Max product is %d\n", getMaxOfPositiveAndNegative(data, len) );
	}
}
int main(){
	FindMaxProduct();
	return(0);
}


