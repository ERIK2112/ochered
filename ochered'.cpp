#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

struct Fteam{
int goal;
char* name;
friend ostream operator <<(ostream&out,Fteam a){
out<<a.name<<" "<<a.goal;
return out;
}
friend istream operator >>(istream&in,Fteam a){
in>>a.goal;
in>>a.name;
return in;
}
Fteam(int g,char*nm){
goal=g;
name=nm;
}

Fteam(){name=0;goal=0;}

};


class Cless{
public:
bool operator() (Fteam x,Fteam y){
return (x.goal<y.goal);
}
};

void main(){
Fteam a(1,"one");
priority_queue <Fteam,vector<Fteam>,Cless > q;
q.push(a);
a.goal=6;
a.name="two";
q.push(a);
a.goal=4;
a.name="three";
int cnt=1;
do{
a=q.top();
cout<<cnt<<" place is "<<a<<"\n";cnt++;
q.pop();
}while ( !q.empty() );



}