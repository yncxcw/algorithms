
#include<iostream>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pl1=l1;
        ListNode *pl2=l2;
        ListNode *tn=NULL;
        ListNode *tp=NULL;
        int carry=0;
        int sum  =0;
        while(pl1||pl2){
            cout<<"pl1 "<<pl1<<endl;
            cout<<"pl2 "<<pl2<<endl;
            sum+=carry;
            if(pl1){
                sum+=pl1->val;
                pl1=pl1->next;
            }
            
            if(pl2){
                sum+=pl2->val;
                pl2=pl2->next;
            }
            if(sum/10 > 0){
                carry=1;
            }else{
                carry=0;
            }
            sum = sum%10;
            cout<<"sum: "<<sum<<endl;
            if(tn==NULL){
              cout<<"here"<<endl;
              ListNode *ps= new ListNode(sum);
              tp = ps;
              tn = ps;
           }else{
              ListNode *ps= new ListNode(sum);
              tp->next=ps;
              tp=ps;
            }

            sum=0;
            cout<<"pl1 e"<<pl1<<endl;
            cout<<"pl2 e"<<pl2<<endl;
        }
        
        if(carry>0){
            ListNode *ps= new ListNode(1);
            tp->next=ps;
            tp=ps;
            
        }
       
        
        return tn;
        
    }
};


ListNode* arrayToPointer(int* array,int size){
    ListNode *ps=new ListNode(array[0]);
    ListNode *pt=ps;
    for(int i=1;i<size;i++){
      ListNode *p=new ListNode(array[i]);
      pt->next   =p;
      pt         =p;
    }
 return ps;
}

int main(){
Solution *psol=new Solution();
int array1[1]={0};
int array2[2]={7,3};
ListNode *re=psol->addTwoNumbers(arrayToPointer(array1,1),arrayToPointer(array2,2));
cout<<re->val;
while(re){

cout<<re->val<<" ";
re=re->next;

}


return 0;
}
