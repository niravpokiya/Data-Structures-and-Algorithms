#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
     int data;
     Node * left;
     Node* right;

     Node(int d)
     {
        data = d;
        left = NULL;
        right= NULL;
     }
};
Node * minval(Node * root)
{
     Node * tmp = root;
     while(tmp -> left)
      tmp = tmp -> left;
     
     return tmp;
}
Node* DeleteFromBst(Node * root , int val)
{
     if(root -> data == val)
     {
          // 0 child
          if(!root -> left && !root -> right)
          {
               delete root;
               return NULL;
          }

          // 1 child
          if(!root -> left && root -> right)
          {
                Node * tmp  = root -> right;
                delete root;
                return tmp;
          }
          if(root -> left && !root -> right)
          {
                Node * tmp  = root -> left;
                delete root;
                return tmp;
          }
 
          //2 child

          if(root -> left && root -> right)
          {
               int mini = minval(root -> right) -> data;
               root -> data= mini;
               root -> right = DeleteFromBst(root -> right, mini);
               return root;
          }
          return root ;
     }
     if(root -> data < val)
     {
          root -> right= DeleteFromBst(root -> right, val);
     }
     if(root -> data > val)
     {
          root -> left  = DeleteFromBst(root -> left, val);
     }
     return root;
}

Node * insertIntoTree(Node * root , int d)
{
    if(!root)
    {
         root = new Node(d);
         return root;
    }
    if(d > root -> data) 
    {
         root -> right = insertIntoTree(root -> right, d);
    }
    else {
         root -> left = insertIntoTree(root -> left, d);
    }
    return root;
}

Node * BST(Node * & root)
{
     int d;
     cin >> d;
     while(d != -1)
     {
         root = insertIntoTree(root, d);
         cin >> d;
     }
     return root;
}
void inorder(Node * root)
{
    if(!root) return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root-> right);
}
int main()
{
    Node * root = NULL;
    root = BST( root );

    inorder(root);
    root = DeleteFromBst(root, 5);
    cout << endl << "After Deletion" << endl ;
    inorder(root);
}