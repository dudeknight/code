#include <iostream>
#include <string>
#include <math.h>
#include <cstdio>
using namespace std;

#define get_int(x) scanf("%d",&x)
#define get_ll(x)  scanf("%lld",&x)


long long gcd(long long a,long long b){
  if(b==0) return a;
  else
    return gcd(b,a%b);
}

string s;
long long A;

int main(){
  int t;get_int(t);
  while(t--){
    get_ll(A);cin>>s;
    if(A==0){
      cout<<s<<endl;
      continue;
    }
    long long temp=0;
    for(int i=0;i<s.size();i++){
      temp=temp*10+s[i]-'0';
      temp%=A;
    }
    printf("%lld\n",gcd(A,temp));
  }

  return 0;
}
