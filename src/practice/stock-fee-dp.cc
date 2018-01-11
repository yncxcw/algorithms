#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    
     vector<int> buys(prices.size(),0); //max profit at buy status
     vector<int> sell(prices.size(),0); //max profit at sell status

     //buy status, given the last action you took is a buy action at day K, where K<=i, you have the right to sell at day i+1 or do nothing
     //如果在buy status 说明手里有股票，反之在sell status说明手里没有股票。
     //所以要么可以从没有股票的sell status那里买了股票变成有股票的buy status，或者继续继承buys[i-1]，说明这一轮没有操作，继续保有有股票的状态。
     //we assume we buy it on the first day
     buys[0]=-prices[0];
     sell[0]=0;
     //we iterate it from the second day
     int i=1;
     for(;i<prices.size();i++){
         buys[i]=max(buys[i-1],sell[i-1]-prices[i]);
	 sell[i]=max(sell[i-1],buys[i-1]+prices[i]-fee);
	 cout<<buys[i]<<"   "<<sell[i]<<endl;
     
     }
     return max(buys[i-1],sell[i-1]);
    }
};


int main(){


Solution *p=new Solution();
int pros[6]={1,3,2,8,4,9};
vector<int> prosv(pros,pros+6);


cout<<p->maxProfit(prosv,2)<<endl;




}
