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
  int height;
  bool is_leaf; // only the leaf node contains the symbols
  int key;
  bool is_deleted; // for lazy deleting
  tree(){
    left = NULL;
    right = NULL;
    height = 0;
    is_leaf = true;
    is_deleted = false;
  }
};


class avl_tree{
  int pend_del;
  int del_c;
public:
  tree* root;
  avl_tree(){
    root = NULL;
    del_c = 2;
    pend_del = del_c;
  }

  void insert(int key){
    if (root == NULL){
      root = new tree();
      root->key = key;
      return;
    }
    tree* x = root;
    tree* y = NULL;
    
    while(x != NULL){
      y = x;
      if (x->key > key){
	x = x->left;
      } else if (x->key == key){
	return;
      } else {
	x= x->right;
      }
    }
    tree* node = new tree();
    node->key = key;
    if (key > y->key){
      y->right = node;
    }
    else {
      y->left = node;
    }
    update_height(root);
    // cout << "--- no balance --- \n";
    // print_tree();
    // cout << "--- balance --- \n";
    balance(root);
    print_tree();
    // cout << "---------\n";
  }
  
  // which is the part of signature and just sets the flag
  void del(int key){    

    if (root == NULL){
      cout << "nothing to delete \n";
    }
    
    tree* x = root;
    tree* y = NULL;
    
    while(x != NULL){
      y = x;
      if (x->key > key){
	x = x->left;
      } else if (x->key == key){
	break;
      } else {
	x= x->right;
      }
    }
    
    if (x == NULL){
      cout << "the given key is not there to delete\n";
    } else {
      x->is_deleted = true;
      pend_del--;
      if (pend_del == 0){
	pend_del = del_c;
	true_delete();
      }
    }
    
  }
  // the main function which when called actually deletes
  void true_delete(){
    while (root->is_deleted){
      root = del_replace(root);
      if (root == NULL){
	return;
      }
    }
    
    true_delete_helper(root->left, root, false);
    true_delete_helper(root->right, root, true);
   
    balance(root);
    //has to call the balance function do not forget
  }



  void print_tree(){
    cout << "--tree--\n";
    print_node("", root);
    cout << "--------\n";
  }

private:

  // helper to true_delete just to carry out recursion
  void true_delete_helper(tree* &x, tree* &par, bool flg){
    if (x == NULL){
      return;
    } else {
      while (x->is_deleted){
	x = del_replace(x);
	if (x == NULL){
	  return;
	}
      }
      if (flg){
	par->right = x;
      } else {
	par->left = x;
      }
      if (x == NULL){
	return;
      }
      true_delete_helper(x->left, x, false);
      true_delete_helper(x->right, x, true);
    }
  }  

  // helper function to print_tree
  void print_node(string s, tree* x){
    if (x == NULL){
      cout << s << "NULL" << endl;
    } else {
      cout << s << x->key << " " << x->height << " " << x->is_deleted << endl;
      print_node(s + " ", x->left);
      print_node(s + " ", x->right);
    }
  }

  // the height parameter updater 
  // called in the balance function
  int update_height(tree* x){
    if (x == NULL){
      return -1;
    } else {
      x->height = max(update_height(x->left), update_height(x->right)) + 1;
      return x->height;
    }    
  }

  // provides the replacer node during delete
  // the replacer node is either -
  // the rightmost node of left subtree or viceversa
  tree* del_replace(tree* x){
    if (x->left == NULL && x->right == NULL){
      return NULL;
    } else if(x->right == NULL){
      tree* par = x;
      tree* y = x->left;
      bool flg = false;
      while (y->right != NULL){
	par = y;
	y = y->right;
	flg = true;
      }
      y->right = x->right;
      if (flg){
	par->right = y->left;
	y->left = x->left;
      }
      return y;
    } else{
      tree* par = x;
      tree* y = x->right;
      bool flg = false;
      while (y->left != NULL){
	par = y;
	y = y->left;
	flg = true;
      }
      y->left = x->left;
      if (flg){
	par->left = y->right;
	y->right = x->right;
      }
      return y;	
    }
  }

  // the balance function
  // even though there is redundancy covers all the cases possible
  // this has been done mainly to facilitate abstraction
  // overhead is unecessary to carry out recursion
  void balance(tree* &x){
    if (x == NULL){
      return;
    } else {
      update_height(x);
      //cout << x << endl;
      balance(x->left);
      balance(x->right);
      if (x->left == NULL && x->right == NULL){
	return;
      } else if (x->left == NULL){
	//print_tree();
	tree* temp;
	temp = x;
	x = x->right;
	temp->right = x->left;
	x->left = temp;
	//cout << "-- in bal --\n";
	//print_tree();
	balance(x->left);
	balance(x);	  
      } else if (x->right == NULL){
	if (x->left->height == 0) return;
	tree* temp;
	temp = x;
	x = x->left;
	temp->left = x->right;
	x->right = temp;
	balance(x->right);
	balance(x);	
      } else if (abs(x->left->height - x->right->height) <= 1){
	x->height = max(x->left->height, x->right->height) + 1;
	return;
      } else if (x->left->height > x->right->height){
	tree* temp;
	temp = x;
	x = x->left;
	temp->left = x->right;
	x->right = temp;
	balance(x->right);
	balance(x);
      } else {
	tree* temp;
	temp = x;
	x = x->right;
	temp->right = x->left;
	x->left = temp;
	balance(x->left);
	balance(x);	  
      }
    }
  }

};


int main(){
  cout << "avl tree \n";
  avl_tree avl;
  cout << "give no the inputs to insert\n";
  int n; cin >> n;
  cout << "give the inputs oneby one \n";
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    avl.insert(x);
  }
  cout << " input the no of  transactions \n";
  cin >> n;
  for (int i = 0; i < n; i++){
    char c; cin >> c;
    int x;
    if (c == 'i'){
      cin >> x;
      avl.insert(x);
    } else if (c == 'd'){
      cin >> x;
      avl.del(x);
    } else if (c == 'p'){
      avl.print_tree();
    }	
  }

  avl.true_delete();
  avl.print_tree();
  return 0;
}
