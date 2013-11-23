#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <assert.h>
using namespace std;




int a[1000101];
bool flg[1000101];
vector<int> result;
int main(){
  //  div.resize(1000001);
  for(int i=0;i<1000001;i++){
    //div[i]=new int[300];
    a[i]=0;
    flg[i]=true;
  }

  for(int i=1;i<1000001;i++){
    for(int j=i;j<1000001;j+=i){
      a[j]++;
    }
  }
  //cout<<"there \n";
  for(int i=1;i<1000001;i++){
    if(a[i]<=3) { flg[i]=false;}
    for(int j=i;j<1000001;j+=i){
      if(a[j]%a[i]!=0) flg[j]=false;
    }
  }
  
  for(int i=1;i<1000001;i++){
    if(flg[i]) result.push_back(i);
  }

  for(int i=107;i<result.size();i+=108){
    printf("%d\n",result[i]);
  }

  return 0;

}
