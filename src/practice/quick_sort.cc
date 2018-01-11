#include<iostream>

using namespace std;

void aprint(int *p,int size){

for(int i=0;i<size;i++){

    cout<<p[i]<<" ";

}

cout<<endl;

}


void swap(int &a, int &b){

int tmp=a;
a=b;
b=tmp;

}

void quick_sort(int* array,int s,int e){

if(s>=e){

return;

}

int middle=array[s];
int i=s;
int j=e;


cout<<"begin "<<s<<" end "<<e<<endl;


while(i<j){

//cout<<"begin "<<i<<" end "<<j<<endl;

    while(array[j]>middle  && i<j) j--;
    while(array[i]<=middle && i<j) i++;

    if(i<j){
        swap(array[i],array[j]);
    }
    aprint(array,10);
}

//cout<<"i: "<<i<<"j: "<<j<<endl;
//cout<<"swap "<<s<<" "<<i<<endl;
//cout<<"middle "<<i<<endl;

//if(array[s]>=array[i])
cout<<array[s]<<" " <<array[i]<<endl;
swap(array[s],array[i]);
aprint(array,10);

quick_sort(array,s,i-1);
quick_sort(array,i+1,e);

}




int main(){

int sort[10]={1,2,-1,2,6,5,4,3,2,1};

aprint(sort,10);
quick_sort(sort,0,9);
aprint(sort,10);


return 0;

}
