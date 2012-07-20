#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

long long mod= 1000000007;



long long fast_pow(long long t){
  if(t==0) return 1;
  if(t==1) return 2;
  if (t & 1){
    long long x=fast_pow(t>>1);
    return (2*((x*x)%mod)%mod);
  }
  else{
    long long x=fast_pow(t>>1);
    return(x*x)%mod;
  }
}

long long a[100010];
long long n;

int main(){

  //cout<<fast_pow(3)<<endl;
  cout<<fast_pow(2)<<endl;
  int t;cin>>t;
  //cout<<t<<endl;
  while(t--){
    cin>>n;
    for(long long i=0;i<n;i++){
      scanf("%lld",&a[i]);
    }

    long long max_val=0,min_val=100011;
    queue<long long> v_max,v_min;
    for(int i=0;i<n;i++) {
      max_val=max(a[i],max_val);
      min_val=min(a[i],min_val);
    }
    cout<<max_val<<" "<<min_val<<endl;

    long long subseq,substr;
    if(max_val==min_val){
      subseq=fast_pow(n)-1;
      subseq%=mod;
      substr=((n*(n+1))/2)%mod;
    }

    else{

      for(long long i=0;i<n;i++){
	if(a[i]==min_val) v_min.push(i);
	if(a[i]==max_val) v_max.push(i);
      }
      
      cout<<v_min.size()<<" "<<v_max.size()<<endl;
      subseq=fast_pow(n-v_min.size()-v_max.size());cout<<"1 "<<subseq<<endl;
      subseq*=((fast_pow(v_max.size())-1)*(fast_pow(v_min.size())-1))%mod;
      cout<<"2 "<<n<<" "<<subseq<<endl;
      subseq%=mod;
    
      substr=0;
      for(long long i=0;i<n;i++){

	if(i>v_max.front()) v_max.pop();
	if(i>v_min.front()) v_min.pop();
	if(v_max.empty() || v_min.empty()) break;
	substr+=n-max(v_max.front(),v_min.front());
	substr%=mod;
      }
    }
    while(!v_max.empty()) v_max.pop();
    while(!v_min.empty()) v_min.pop();
    //cout<<"adfad"<<endl;
    cout<<substr%mod<<" "<<subseq<<endl;
    //printf("%ld %ld\n",substr,subseq);
    
  }
  
  return 0;
}





