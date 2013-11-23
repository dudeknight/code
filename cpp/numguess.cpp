#include <iostream>
#include <math.h>


using namespace std;


string s;
int a,b;

int main(){
  cin>>a>>b;
  string s;
  s="temp";
  while(s!="WIN"){
    int mid=(a+b)/2;
    cout<<mid<<endl;
    cin>>s;
    if(s=="LOW"){
      a=mid+1;
    }
    else if(s=="HIGH){
      b=mid-1;
    }
  }

  return 0;
}
