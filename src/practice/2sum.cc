#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct Nms{
       int value;
       int index;
    };

    static bool num_compare(Nms& n1, Nms& n2){
        return n1.value < n2.value;
    } 
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Nms> bnums;
        for(int i=0;i<nums.size();i++){
            Nms nm;
            nm.value=nums[i];
            nm.index=i;
            bnums.push_back(nm);
        }
        sort(bnums.begin(),bnums.end(),num_compare);
        int sindex = 0;
        int eindex = nums.size()-1;
        
        int sum=0;
        vector<int> result;
        while(sindex<=eindex){
            sum=bnums[sindex].value+bnums[eindex].value;
            cout<<sindex<<"  "<<eindex<<endl;
            cout<<sum<<endl;
            if(sum < target){
                sindex++;
               
            }else if(sum>target){
                eindex--;
                   
            }else{

               result.push_back(bnums[sindex].index);
               result.push_back(bnums[eindex].index);
               break;
            }
        }
        
      return result;    
    }
};


int main(){

 Solution *  pslo= new Solution();
 vector<int> vtest;
 vtest.push_back(3);
 vtest.push_back(2);
 vtest.push_back(4);
 cout<<pslo->twoSum(vtest,6)[0];

 return 0;
}
