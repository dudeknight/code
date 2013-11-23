#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

char op[]={'+','-','*','/','^'};


string func(string s){
  int n=s.size();
  
  if(s[0]=='('){
    int count=0;
    char op='x';
    for(int i=1;i<s.size()-1;i++){
      //cout<<count<<" "<<s[i]<<endl;
      if(s[i]=='(') count++;
      else if(s[i]==')') count--;
      else if(s[i]>='a' && s[i]<='z'){;}
      else{
	if(count==0){
	  //cout<<"op1 "<<s[i]<<endl;
	  string res=func(s.substr(1,i-1))+func(s.substr(i+1,n-i-2))+s[i];
	  return res;
	}
      }
    }

    return func(s.substr(1,n-2));

  }
  else{
    int count=0;
    char op='x';
    for(int i=0;i<s.size();i++){
      if(s[i]=='(') count++;
      else if(s[i]==')') count--;
      else if(s[i]>='a' && s[i]>='z'){;}
      else{
	if(count==0){
	  string res=func(s.substr(0,i))+func(s.substr(i+1,n-i-1))+s[i];
	  return res;
	}
      }
    }
    
    return s;

  }


}

int main(){
  int t;scanf("%d",&t);
  string s;
  while(t--){
    cin>>s;
    cout<<func(s)<<endl;
  }
  
  return 0;
}


