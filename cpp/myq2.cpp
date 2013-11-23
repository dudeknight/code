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


char c[1000007];

int v[1000007];
bool ex[1000008];
int st[1000008];
int len[1000008];


int main(){
  int t;
  ll n,m,k;
  s(t);
  while(t--){
    //cin.getline(c,1000003);
    gets(c);
    gets(c);
    
    //cout<<"1: "<<c<<endl;
    sll(m);sll(k);
    n=(ll)strlen(c);
    fr(i,n){
      if(c[i]>='a' && c[i]<='z')
	v[i]=c[i]-'a'+1;
      else if(c[i]>='A' && c[i]<='Z')
	v[i]=c[i]-'A'+51;
      else
	v[i]=c[i];
    }
    
    fr(i,m){
      ex[i]=false;
    }

    fr(i,n){
      if(i)
	v[i]+=v[i-1];
      v[i]%=m;
      ex[v[i]]=true;
      st[v[i]]=0;
      len[v[i]]=i+1;
    }
    /*
    fr(i,n)
      cout<<v[i]<<" ";
    cout<<endl;
    */

    fr(i,n){
      ll val=v[i];
      ll tmp=(v[i]+k)%m;
      /*
      fr(j,m)
	cout<<ex[j]<<" ";
      cout<<endl;
      fr(j,m)
	cout<<st[j]<<" ";
      cout<<endl;
      fr(j,m)
	cout<<len[j]<<" ";
      cout<<endl;
      */
      if(ex[tmp]){
	if(ex[k]){
	  if(len[k] < (len[tmp]-(i+1))){
	      st[k]=i+1;
	      len[k]=len[tmp]-(i+1);
	  }
	}
	else{
	  if(len[tmp]>i+1){
	    ex[k]=true;
	    st[k]=i+1;
	    len[k]=len[tmp]-(i+1);
	  }
	}
      }
    }    
    
    if(ex[k]){
      printf("%d %d\n",st[k],len[k]);

    }
    else{
      if(k){
	printf("-1\n");
      }
      else{
	printf("0 0\n");
      }
    }

    /*
    fr(i,n)
      cout<<v[i]<<" ";
    cout<<endl;
    */
  }
  
}

