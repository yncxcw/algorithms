class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];

        if(nums.size()==4)
            return _3_max(nums[0]+nums[1],nums[1]+nums[3],nums[0]+nums[3]);

        int sum1=0;
        int sum2=0;
        for(int i=0;i<nums.size();i++)
         if(i%2)
            sum1+=nums[i];
         else
            sum2+=nums[i];
        
        return sum1>sum2?sum1:sum2;
        
    }
    
    void _3_max(int a, int b, int c){
        return max(a,max(b,c));
    }
};
