#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
}; 
class BST
{
private:
    Node *root;

    //helper function for search element
    bool searchHelper(Node* head, int x){
        if(head==NULL)
            return false;
        if(head->data==x)
            return true;
        else if(head->data>x)
            return searchHelper(head->left,x);
        else
            return searchHelper(head->right,x);
    }

    /* METHODS WRITTEN 
        1. insert single element           .insert() 
        2. insert multiple element at once .insert(vector<int> v)
        3. printtree                       .printTree()
        4.search an element                .search(int x)
    */

public:
    //constructor
    BST()
    {
        root=NULL;
    }
    
    //Insert only single element;
    void insert(int x){                       
        Node *head=root, *prev=NULL;
        Node* temp=new Node(x);
        
        if(head==NULL){
            root=temp;
            return;
        }
        while(head!=NULL){
            if(head->data==x)
                return;
            if(head->data<x){
                prev=head;
                head=head->right;
            }
            else if(head->data>x){
                prev=head;
                head=head->left;
            }
        }

        if(prev->data>x)
            prev->left=temp;
        if(prev->data<x)
            prev->right=temp;
        
    }

    //Insert multiple elements at once
    void insert(vector<int> TE){          
        
        for(int i=0;i<TE.size();i++){
            this->insert(TE[i]);
        }
    }
    
    //Print tree in level order traversal line by line
    void printTree(){
        if(root==NULL)
            return;
        Node* head=root;
        queue<Node*> q;
        q.push(head);
        while(!q.empty()){
            int count=q.size();
            for(int i=0;i<count;i++){
                Node* temp= q.front();
                q.pop();
                if(temp==NULL){
                    cout<<"N ";
                    continue;
                }
                else
                    cout<<temp->data<<" ";
                q.push(temp->left);
                q.push(temp->right);
            }
            cout<<endl;
        }
    }

    //start: search element
    bool search(int x){
        Node* head=root;
        return searchHelper(head,x);
    }
    // end: Search element


};

int main(){
    BST bstree;
    vector<int> Tree_ele={7,10,4,6,1,10,11};
    return 0;   
}