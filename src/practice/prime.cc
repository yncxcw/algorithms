#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:

   
    int countPrimes(int n) {
        int sum=0; 
        if(n<=2) return 0;
        if(n==3) return 1;
        vector<bool> passed(n+1, true);
        
        for(int p=2;p*p<=n;p++){
            if(passed[p]){
                
                for(int i=p*2;i<=n;i+=p){
                    passed[i]=false;
                }
            }
            
        }
        
    for(int i=2;i<n;i++){
        if(passed[i]){
           cout<<i<<endl;
           sum++;
        }
    }
    return sum;        
    }
    
    
};


int main(){

 Solution *so=new Solution();
 cout<<so->countPrimes(5);


 return 0;

}
