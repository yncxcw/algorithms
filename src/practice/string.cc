#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;


int main(){

 string str1="1283.456"; 
 string str2="123.456";
 if (str1==str2)
   cout<<"equal";
 cout<<typeid(str1[0]).name()<<endl;
 return 0;

}
