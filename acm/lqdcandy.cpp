#include <iostream>
#include <cstdio>
using namespace std;



int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;cin>>n;
    long long x=1;bool f=true;
    int count =0;int val=0;
    while(n/x){
      count++;
      if(n&x && f){f=false;val++;}
      if(!f)val++;
      x<<=1;
    }
    if(n%(x>>1)==0)  {x>>=1;val=1;}
    cout<<x<<" "<<val-1<<endl;


    }

    return 0;

  }
