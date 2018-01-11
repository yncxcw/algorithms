#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> ops;
    int count;
    int findTargetSumWays(vector<int>& nums, int S) {
        for(int i=0;i<nums.size();i++){
          ops.push_back(false);
        }
        this->count=0;
        dfs(0,nums,S);
        return count;
    }
   
    int partial_sum(vector<int> &nums, int index){
      int sum=0;
      for(int i=0;i<=index;i++){
              if(ops[i])
                 sum+=nums[i];
              else
                 sum-=nums[i];
            }
     return sum;

    } 
    void dfs(int index, vector<int>& nums,int S){
        if(index==nums.size()){
            int sum=0;
            //check results
            for(int i=0;i<nums.size();i++){
              if(ops[i])
                 sum+=nums[i];
              else
                 sum-=nums[i];
            }
            
            cout<<"sum: "<<sum<<endl;
            if(sum==S){
               cout<<"reached"<<endl;
               count++;
            }
            return;
        }
        
        ops[index]=true;
        dfs(index+1,nums,S);
        ops[index]=false;
        dfs(index+1,nums,S);
        
    }    
    
};


int main(){
int array[4]={1,1,1,1};
vector<int> nums(array,array+4);
Solution *p = new Solution();
cout<<p->findTargetSumWays(nums,3);


return 0;
}
