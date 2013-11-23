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

int a[200];
int b[200][200];

vector<string> v;
int main(){
  int t;
  string s;
  s(t);
  while(t--){
    
    cin>>s;
    int n=s.size();
    a[0]=1;
    fr(i,n){
      b[i][0]=0;
    }
    int maxi=1;
    f(i,1,n){
      maxi=1;
      for(int j=i-1;j>=0;j--){
	if(s[j]<=s[i])
	  maxi=max(maxi,a[j]+1);
	
      }
      a[i]=maxi;
      if(maxi!=1){
	fr(j,i){
	  if(a[j]==maxi-1 && s[j]<=s[i]){
	    b[i][0]++;b[i][b[i][0]]=j;
	  }
	}
      }
	
    }

    maxi==1;
    fr(i,n){
      maxi=max(maxi,a[i]);
    }
    vector<vector<string> > y;
    
    y.resize(n);
    fr(i,n){
      if(a[i]==1){
	string st="";
	st+=s[i];
	y[i].push_back(st);
      }
      else{
	fr(j,b[i][0]){
	  fr(k,y[b[i][j+1]].size()){
	    y[i].push_back(y[b[i][j+1]][k]+s[i]);
	  }
	}
      }
    }

    vector<string> res;

    fr(i,n){
      if(a[i]==maxi){
	fr(j,y[i].size()){
	  res.push_back(y[i][j]);
	}
	
      }
    }
    sort(res.begin(),res.end());
    fr(i,res.size()){
      cout<<res[i]<<endl;
    }
    
  }




}
