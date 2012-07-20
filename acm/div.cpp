#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <assert.h>
using namespace std;




int a[1000101];
bool flg[1000101];
bool flg2[1000101];
vector<int> result;
int main(){
  //  div.resize(1000001);
  for(int i=0;i<1000001;i++){
    //div[i]=new int[300];
    a[i]=0;
    flg[i]=false;
    flg2[i]=true;
  }
  
  for(int i=0;i<101;i++)
    flg2[i*i*i]=false;

  for(int i=1;i<1000001;i++){
    for(int j=i;j<1000001;j+=i){
      a[j]++;
    }
  }
  //cout<<a[a[50]]<<endl;
  //cout<<"there \n";
  for(int i=1;i<1000001;i++){
    if(a[a[i]]==4 && flg2[a[i]] ) {flg[i]=true; }

  }
  
  for(int i=1;i<1000001;i++){
    if(flg[i]) result.push_back(i);
  }

  for(int i=8;i<result.size();i+=9){
    printf("%d\n",result[i]);
  }

  return 0;

}
