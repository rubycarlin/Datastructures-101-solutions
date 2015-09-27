#include <iostream>
#include <vector>

#define MAX_VAL 999999999
using namespace std;

struct coinData{
	int amt;
	int count;
};
struct coinData NewCoinData(int amt, int count){
	struct coinData *data = new struct coinData;
	data->amt = amt;
	data->count = count;
	return(*data);
}
int getMinimumNumberOfCoins(int *coinValues, int len, int amount){
	int min_count = MAX_VAL;
	vector<struct coinData> dp;
	vector<int> alreadyPresent;
	for(int i = 0; i < len; i++){
		dp.push_back(NewCoinData(coinValues[i], 1));
		alreadyPresent.push_back(coinValues[i]);
		if(amount == coinValues[i]){
			return(1);
		}
	}

	int start = 0, end = len;
	while(start < end){
		
		for(int i = 0; i < len; i++){
			int curr_amt = dp[start].amt + coinValues[i];
			vector<int>::iterator it;
			it =find(alreadyPresent.begin(), alreadyPresent.end(), curr_amt);
			if(it == alreadyPresent.end() && curr_amt <= amount){
				alreadyPresent.push_back(curr_amt);
				dp.push_back(NewCoinData(curr_amt, (dp[start].count + 1)));
				end++;
			}
			
			if(curr_amt == amount && min_count > (dp[start].count + 1)){
				min_count = (dp[start].count + 1);
			}
		}
		printf("\n");
		start++;
	}
	return(min_count);
}
void MinimumNumberOfCoins(){
	int coinValues[] = {25, 10, 5};
	int amount = 30;
	int len = sizeof(coinValues) / sizeof(coinValues[0]);

	int count = getMinimumNumberOfCoins(coinValues, len, amount);

	if(count != MAX_VAL)
		printf("Minimum number of coins required to form %d amount is %d\n", amount, count);
	else
		printf("This amount cannot be formed\n");
}
int main(){
	MinimumNumberOfCoins();
	return(0);
}

