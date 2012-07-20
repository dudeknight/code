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


struct b{
  ll c[6];
};

bool comp(b x,b y){
  fr(i,6){
    if(x.c[i]<y.c[i]) return true;
    else if(x.c[i]>y.c[i]) return false;
  }
  return false;
}

char num[20];

void printx(ll x,int y){
  sprintf(num,"%lld",x);
  int n=strlen(num);
  //cout<<n<<endl;
  fr(i,y-n){
    printf("0");
  }
  printf("%s",num);

}


void print(b x){
  printx(x.c[0],2);
  printf(" ");
  printx(x.c[1],8);
  f(i,2,6){
    if(i)printf(" ");
    printx(x.c[i],4);
  }
}

b a[100000];

int main(){
  int t;s(t);
  while(t--){
    int n;
    s(n);
    fr(i,n){
      fr(j,6){
	sll(a[i].c[j]);
      }
    }

    
    sort(a,a+n,comp);
    //    cout<<n<<endl;
    // return 0;
    int x=1;
    /*
    fr(i,n){
      print(a[i]);
      printf("\n");
    }
    */
    fr(i,n){
      
      if(i){
	if(!comp(a[i-1],a[i])){
	  x++;
	}
	else{
	  printf(" %d\n",x);
	  x=1;
	  print(a[i]);
	}
      }
      else{
	print(a[i]);
      }
      

      
    }
      
    printf(" %d\n \n",x);


  }

}



