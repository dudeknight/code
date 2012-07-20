//the template by dvdreddy

#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

bool cap(char x){
  if(x>='A' && x<='Z')
    return true;
  else
    return false;
}
bool sml(char x){
  if(x>='a' && x<='z')
    return true;
  else
    return false;
}



int main(){
  string s;
  while(cin>>s){
    int res=0;
    for(int i=0;i<s.size();i++){
      if(i&1 && cap(s[i])) res++;
      else if( (!(i&1)) && sml(s[i])) res++; 
    }
    int res2=0;
    for(int i=0;i<s.size();i++){
      if((!(i&1)) && cap(s[i])) res2++;
      else if( (i&1) && sml(s[i])) res2++; 
    }

    printf("%d\n",min(res,res2));

  }



}
