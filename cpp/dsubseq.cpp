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

#define s(x) scanf("%d\n",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

ll mod =1000000007;

char c[260];

char str[100003];

ll res[100013];

int n;

int main(){
  int t;s(t);
  while(t--){
    cin>>str;
    n=strlen(str);
    //cout<<n<<endl;
    res[n+1]=0;
    res[n]=1;

    
    fr(i,200){
      c[i]=n;
    }

    for(int i=n-1;i>=0;i--){
      res[i]=(2*res[i+1]+mod)-res[c[str[i]]+1];
      res[i]%=mod;
      c[str[i]]=i;
    }

    printf("%lld\n",res[0]);
  }


  return 0;
}
