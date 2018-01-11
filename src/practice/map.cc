#include<iostream>
#include<map>

using namespace std;


int main(){

map<int,int> tmap;

tmap[10]=5;

cout<<tmap[-1]<<endl;
cout<<tmap.at(2016)<<endl;

return 0;
}
