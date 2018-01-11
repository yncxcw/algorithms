#include<iostream>

using namespace std;

struct Student{

  int num=0;
  string name="none";

};


int main(){

Student student;

cout<<"default "<<student.name<<"  "<<student.num<<endl;

return 0;

}
