#include <iostream>
#include <stack>

using namespace std;

//create a class with a datastructure for a binary tree node as a public object
//assign it a value pointer along with a left and right pointer for its left
//and right children

class BinTreeNode{
public:
  BinTreeNode(int value){
    this->value=value;
    this->left=NULL;
    this->right=NULL;
  }
  int value;
  BinTreeNode* left;
  BinTreeNode* right;


};

//essentially a function for creating new nodes for the binary tree and placing them in the relevant
//position in the tree this runs recursivly untill it finds a node that has no children in the correct
//position (left or right)
BinTreeNode* tree_insert(BinTreeNode* tree, int item){
    // if tree equals null create a new node to serve as the root of the tree
  if(tree==NULL)
    tree=new BinTreeNode(item);
  else
    if(item < tree->value)  //if inputted value is lower than the tree nodes value and has no children to the left
      if(tree->left==NULL)  // create a new tree node and point the nodes left pointer to the new node
        tree->left=new BinTreeNode(item);
      else                  //else recursivly run the program sending the left leaf of the node to the next iteration
        tree_insert(tree->left,item);
    else    //else the number is higher and has to be inserted to the right child, if the node has no right child
      if(tree->right==NULL) //create a new noode with the inputted value
        tree->right=new BinTreeNode(item);
      else                  //otherwise run the program again using the nodes right child
        tree_insert(tree->right,item);
  return tree;

}

//recursive function to print the post order of the tree
void postorder(BinTreeNode* tree){
    // if the left node of the tree is not null recursivly move to the left node
  if(tree->left!=NULL)
    postorder(tree->left);
    //if the right node of the tree is not null recursivly move to the right node
  if(tree->right!=NULL)
    postorder(tree->right);
    //this results in each move being the top of the processing stack so nodes get
    //printed in the order that it is traversed
  std::cout << tree->value << std::endl;

}

//this function utilises the stack to move between nodes printing the next lowest value
void in_order(BinTreeNode* tree){

    //initilise a bool for a while loop to break on base case
    bool done = false;

    //create a new stack to push the nodes to for retrieval once the children have been printed
    stack<BinTreeNode*> s;
    //create a new structure used to traverse the tree
    BinTreeNode *current = tree;


    while (!done) {
        // if current is not null (have not gone too far into the left children)
        if (current) {
            //add the current to the stack and go to the left child
            s.push(current);
            current = current->left;
        //if the stack is empty (no more nodes to traverse and print in the stack) break from the loop
        } else if (s.empty()){
            done = true;
        //else there are no left children so current is the last parent node visited and remove it from the stack
        //print the value and move to the right child
        } else {
            current = s.top();
            s.pop();
            cout<<current->value<<" ";
            current = current->right;
        }
        //resulting in the binary tree being printed in a sorted manner before the stack becomes empty
    }

}

int main()
{
  BinTreeNode* t=tree_insert(0,6);
  tree_insert(t,10);
  tree_insert(t,5);
  tree_insert(t,2);
  tree_insert(t,3);
  tree_insert(t,4);
  tree_insert(t,11);
  postorder(t);
  in_order(t);
  return 0;

}

//The big O for inserting a node into a tree is O(log(n)) as each comparison is removing half of the
//remaining elements in the tree

//the worstcase for the in_order and postorder search functions is O(n) as you are requiring the
//algorithm to vist every node within the tree
