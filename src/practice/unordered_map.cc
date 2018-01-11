#include<unordered_map>
#include<iostream>
#include<map>

using namespace std;

int main(){

 string str="abcdef";
 map<char,double> dmap1;
 cout<<dmap1['c']<<endl;
 unordered_map<string,string> dmap2;
 cout<<dmap2["abc"]<<endl;

 string empty;
 cout<<"empty "<<empty<<endl;

}
