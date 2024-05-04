#include<iostream>
#include<queue>
#include<dirent.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node* right;
    Node(int data = 0)
    {
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};
Node * Buildtree(Node * root)
{
    int data;
    cin >> data;
    Node * tree = new Node(data);
    if(data == -1)
    return NULL;
    tree -> left = Buildtree(tree -> left);
    tree -> right = Buildtree(tree -> right);
    return tree;
}
void inOrder(Node * root)
{
    if(root == NULL)return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}
void preOrder(Node * root)
{
    if(root == NULL)return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}
void postOrder(Node * root)
{
    if(root == NULL)return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}
void levelOrder(Node * root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node * temp = q.front();
        if(temp){
        int data= temp ->data;
        cout << data << " "; }
        q.pop();
        if(temp == nullptr) {
            cout << endl;
            if(!q.empty())
             q.push(NULL);
        }
        else{
        
        if(temp -> left)
        {
            q.push(temp -> left);
        }
        if(temp -> right)
        q.push(temp -> right);
        }
    }
}
void createLevelOrder(Node * & root)
{
    queue<Node *> q;
    int data; cin >> data;
    root = new Node(data);
    q.push(root);
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        cout << "enter left of " << temp -> data;
        int l;
        cin >> l;
        if(l != -1)
        {
            temp -> left= new Node(l);
            q.push(temp -> left);
        }
        cout << "enter right of :" << temp -> data;
        int r;
        cin >> r;
        if(r != -1)
        {
            temp -> right= new Node(r);
            q.push(temp -> right);
        }
    }
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1

    // Node * root = NULL;
    // root =  Buildtree(root);
    // cout << "level Order : "; 
    // levelOrder(root);
    // cout << "\nin Order : ";
    // inOrder(root);
    // cout << "\npre Order : ";
    // preOrder(root);
    // cout << "\npost Order : ";
    // postOrder(root);
    Node * root = NULL;
    createLevelOrder(root);
    levelOrder(root);
    return 0;
}
