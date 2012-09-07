// written by lonerdude(dvdreddy)
// all rights reserved
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

struct tree{
  tree* left;
  tree* right;
  char symbol;
  bool is_leaf; // only the leaf node contains the symbols
  int prob;
};

bool comp(tree* left, tree* right){
  if (left->prob < right->prob){
    return true;
  } else {
    return false;
  }
}


class huffman_encoding{
public:
  // the structures for taking the input
  char c[100];
  int prob[100];
  int cnt;

  // structures for holding the tree, mapping.
  tree* root;
  // will write to write functions and remove the map
  map<char, string> encode; // the map
  map<string, char> decode; // the reverse map 
  // this is the function that creates the huffman tree  
  void create_tree(){
    vector<tree*> v;
    v.resize(cnt);
    for (int i = 0; i < cnt; i++){
      v[i] = new tree();
      v[i]->left = NULL;
      v[i]->right = NULL;
      v[i]->symbol = c[i];
      v[i]->is_leaf = true;
      v[i]->prob = prob[i];
    }

    while (v.size() > 1){
      sort(v.begin(), v.end(), comp);
      vector<tree*>::iterator it;
      it = v.begin();
      tree* x1 = new tree();
      tree* x2 = new tree();
      
      copy(x1, (*it)); it++;
      copy(x2, (*it));
      it = v.begin(); v.erase(it);
      it = v.begin(); v.erase(it);
      
      tree* new_node = new tree();
      new_node->left = x2;
      new_node->right = x1;
      new_node->is_leaf = false;
      new_node->prob = x1->prob + x2->prob;

      v.push_back(new_node);
    }
    root = v[0];
    create_encoding();
    create_decoding();
  }

  void print_tree(){
    //TODO::has to implement using one of the traversals
    cout << "----------------------------------------\n";
    tree_traverse_print("", root);
    cout << "----------------------------------------\n";
  }


  void print_encoding(){
    map<char, string>::iterator it;
    for (it = encode.begin(); it != encode.end(); it++){
      cout<< it->first << " "<< it->second << endl;
    }
  } 

  void print_decoding(){
    map<string, char>::iterator it;
    for (it = decode.begin(); it != decode.end(); it++){
      cout<< it->first << " "<< it->second << endl;
    }
  }

  string decode_message(string encoded_msg){
    // for each new bit we check whether it is complete or not
    map<string, char>::iterator it;
    string s = "";
    string res = "";
    for (int i = 0; i < encoded_msg.size(); i++){
      s = s + encoded_msg[i];
      it = decode.find(s);
      if (it != decode.end()){
	res = res + it->second;
	s = "";
      } 	
    }
    return res;
  }

private:
  void copy(tree* x, tree* y){
    x->left = y->left;
    x->right = y->right;
    x->symbol = y->symbol;
    x->is_leaf = y->is_leaf;
    x->prob = y->prob;
  }

  void create_encoding(){
    tree_traverse_map("", root);
  }

  void tree_traverse_map(string s, tree *x){
    if (x->is_leaf){
      encode[x->symbol] = s;
    } else {
      tree_traverse_map(s + "0", x->left);
      tree_traverse_map(s + "1", x->right);
    }
  }

  void create_decoding(){
    map<char, string>::iterator it;
    for (it = encode.begin(); it != encode.end(); it++){
      decode[it->second] = it->first;
    }
  }

  void tree_traverse_print(string s, tree *x){
    if (x->is_leaf){
      cout << s << "leaf " << x->symbol << " " << x->prob << endl;
    } else {
      cout << s << "node" << endl;
      tree_traverse_print(s + " ", x->left);
      tree_traverse_print(s + " ", x->right);
    }
  }

};



int main(){
  cout << "huffman encoding \n";
  huffman_encoding x;
  cout << "give the number of characters \n";
  cin >> x.cnt;
  cout << "give the character seperated by space probability \n";
  char tempc;
  getc(stdin);
  for (int i = 0; i < x.cnt; i++){
    x.c[i] = getc(stdin);
    cin >> x.prob[i];
    cout << "c" << x.c[i] << endl;
    getc(stdin);
  }

  x.create_tree();
  x.print_tree();
  x.print_encoding();
  cout << "give the message you want to decode \n";
  string msg; cin >> msg;
  string real_msg = x.decode_message(msg);
  cout << "decoded message is:" << real_msg << endl;
  return 0;
}
