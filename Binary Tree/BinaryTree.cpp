#include<bits/stdc++.h>
#include"BinaryTree.h"
#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

//zig zag traversal of tree
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int> v;
	if(root==NULL){
	    return v;
	}
	stack<Node*> ms;
	ms.push(root);
	stack<Node*>cs;
	int k=0;
	while(!ms.empty()){
	    int size=ms.size();
	    while(size>0){
	        Node* top=ms.top();
	        v.push_back(top->data);
    	    ms.pop();
    	    if(k%2==0){
        	    if(top->left){
        	       cs.push(top->left);
        	    }
        	    if(top->right){
        	        cs.push(top->right);
        	    }      
    	    }
    	    else{
    	        if(top->right){
        	        cs.push(top->right);
        	    }      
    	        if(top->left){
        	       cs.push(top->left);
        	    }
    	    }
    	    size--;
	    }
	    if(ms.empty()){
	        swap(ms,cs);
	        k++;
	    }
	}	
}

//Diameter of binary tree
 pair<int,int> Heightdiameter(Node* root){
        if(root==NULL){
            pair<int,int>p;
            p.first=0;
            p.second=0;
            return p;
        }
        
        pair<int,int>LeftHeightdiameter=Heightdiameter(root->left);
        pair<int,int>RightHeightdiameter=Heightdiameter(root->right);
        int height=1+max(LeftHeightdiameter.first,RightHeightdiameter.first);
        int diameter=max(LeftHeightdiameter.first+RightHeightdiameter.first,max(LeftHeightdiameter.second,RightHeightdiameter.second));
        pair<int,int>p;
        p.first=height;
        p.second=diameter;
        return p;
    }
    int diameter(Node* root)
    {
    // Your code here
    pair<int,int>p=Heightdiameter(root);
    return p.second+1;
    }

//cousins of binary tree
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   
   if(root==NULL){
       return false;
   }
   queue<Node*>q;
   q.push(root);
   int l1=0;
   int l2=0;
   int k=0;
   while(!q.empty()){
       int size=q.size();
       while(size>0){
       Node* top=q.front();
       if(top->data==a){
           l1=k;
       }
       if(top->data==b){
           l2=k;
       }
       q.pop();
       if(top->left){
           q.push(top->left);
       }
       if(top->right){
           q.push(top->right);
       }
       if(top->left && top->right){
           if((top->left->data==a && top->right->data==b) || (top->left->data==b && top->right->data==a)){
               return false;
           }
       }
       size--;
       }
       k++;
   }
   if(l1!=l2){
       return false;
   }
    return true;
   
}

//bottom view of binary tree (Key is to print the last element in the vertical traversal of map of vector )

vector <int> bottomView(Node *root)
{
   // Your Code Her
        //Your code here
        vector<int>v;
        if(root==NULL){
		    return v;
        }
	queue<pair<Node*,int>>q;
	unordered_map<int,vector<int>>m;
	int hd=0;
	q.push(make_pair(root,hd));
	int mini=INT_MAX;
	int maxi=INT_MIN;
	while(!q.empty()){
			pair<Node*,int> p=q.front();
			hd=p.second;
			mini=min(hd,mini);
			maxi=max(hd,maxi);
			m[p.second].push_back(p.first->data);
			q.pop();
			if(p.first->left){
				q.push(make_pair(p.first->left,hd-1));
			}
			if(p.first->right){
				q.push(make_pair(p.first->right,hd+1));
			}
		}
	for(int k=mini;k<=maxi;k++){
		vector<int> temp=m[k];
		v.push_back(temp[temp.size()-1]);
	}
	return v;
}

void LeftBoundary(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	if(root->left){
		cout<<root->data<<" ";
		LeftBoundary(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
		LeftBoundary(root->right);
	}
}


void RightBoundary(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	if(root->left){
		cout<<root->data<<" ";
		RightBoundary(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
		RightBoundary(root->right);
	}
}

void printLeaf(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	
	if(root->left==NULL && root->right==NULL){
		cout<<root->data;
	}
	
	printLeaf(root->left);
	printLeaf(root->right);
}

//boundary traversal of tree
void printBoundary(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<";";
	LeftBoundary(root->left);
	RightBoundary(root->right);
	printLeaf(root);
}


//top view of binary tree (Idea is to print first element from the vertical traversal map of vector)

vector<int> topView(BinaryTreeNode<int>*root)
    {
        //Your code here
          vector<int>v;
        if(root==NULL){
		return v;
	}
	
	queue<pair<BinaryTreeNode<int>*,int>>q;
	unordered_map<int,vector<int>>m;
	int hd=0;
	q.push(make_pair(root,hd));
	int mini=INT_MAX;
	int maxi=INT_MIN;
	while(!q.empty()){
			pair<BinaryTreeNode<int>*,int> p=q.front();
			hd=p.second;
			mini=min(hd,mini);
			maxi=max(hd,maxi);
			m[p.second].push_back(p.first->data);
			q.pop();
			if(p.first->left){
				q.push(make_pair(p.first->left,hd-1));
			}
			if(p.first->right){
				q.push(make_pair(p.first->right,hd+1));
			}
		}
	for(int k=mini;k<=maxi;k++){
		vector<int> temp=m[k];
		v.push_back(temp[0]);
	}
	return v;
    }

//printing the tree in vertical order

void printVertical(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	
	queue<pair<BinaryTreeNode<int>*,int>>q;
	map<int,vector<int>>m;
	int hd=0;
	q.push(make_pair(root,hd));
	int mini=INT_MAX;
	int maxi=INT_MIN;
	while(!q.empty()){
			pair<BinaryTreeNode<int>*,int> p=q.front();
			hd=p.second;
			mini=min(hd,mini);
			maxi=max(hd,maxi);
			m[p.second].push_back(p.first->data);
			q.pop();
			if(p.first->left){
				q.push(make_pair(p.first->left,hd-1));
			}
			if(p.first->right){
				q.push(make_pair(p.first->right,hd+1));
			}
		}
	
//	for(int k=mini;k<=maxi;k++){
//		vector<int> temp=m[k];
//		for(int i=0;i<temp.size();i++){
//			cout<<temp[i]<<" ";
//		}
//	}
	
	//iterating through map of vector
		
	for(auto& it:m){
		cout<<it.first<<":";
		for(auto& z: it.second){
			cout<<z<<",";
		}
		cout<<endl;
	}
}

//for printing the right view of tree

void printRIght(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int>* > q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		int k=0;
		while(size>0){
			BinaryTreeNode<int>* front=q.front();
			q.pop();
			if(k==0){
				cout<<front->data;
				k++;
			}
			if(front->right){
				q.push(front->right);
			}
			if(front->left){
				q.push(front->left);
			}
			size--;
		}
	}
}


//for printing the left view of tree

void printLeft(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int>* > q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		int k=0;
		while(size>0){
			BinaryTreeNode<int>* front=q.front();
			q.pop();
			if(k==0){
				cout<<front->data;
				k++;
			}
			if(front->left){
				q.push(front->left);
			}
			if(front->right){
				q.push(front->right);
			}
			size--;
		}
	}
}



//for printing Tree Levelwise
void printTreeLevelwise(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode<int>* front=q.front();
		cout<<front->data<<":";
		q.pop();
		if(front->left!=NULL){
			cout<<"L"<<front->left->data;
			q.push(front->left);
		}
		if(front->right!=NULL){
			cout<<"R"<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	}
}


void printTree(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL){
		cout<<"L"<<root->left->data;
	}
	if(root->right!=NULL){
		cout<<"R"<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}

//for taking input level wise
BinaryTreeNode<int>* takeInputLevelwise(){
	int rootData;
	cout<<"Enter root Data";
	cin>>rootData;
	queue<BinaryTreeNode<int>*> q;
	BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
	q.push(root);
	while(!q.empty()){
		BinaryTreeNode<int>* front=q.front();
		q.pop();
		cout<<"Enter left child of"<<front->data<<endl;
		int leftchildData;
		cin>>leftchildData;
		if(leftchildData!=-1){
			BinaryTreeNode<int>* left= new BinaryTreeNode<int>(leftchildData);
		front->left=left;
		q.push(left);
	}
		cout<<"Enter right child of"<<front->data<<endl;
		int rightchildData;
		cin>>rightchildData;
		if(rightchildData!=-1){
			BinaryTreeNode<int>* right= new BinaryTreeNode<int>(rightchildData);
		front->right=right;
		q.push(right);
	}
}
	return root;
}

BinaryTreeNode<int>* takeInput(){
	int data;
	cout<<"Enter root Data";
	cin>>data;
	if(data==-1){
		return NULL;
	}
	BinaryTreeNode<int>* root= new BinaryTreeNode<int>(data);
	BinaryTreeNode<int>* left=takeInput();
	BinaryTreeNode<int>* right=takeInput();
	root->left=left;
	root->right=right;
	return root; 
}


int main(){
	BinaryTreeNode<int>* root;
	//BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
	//BinaryTreeNode<int>* root1=new BinaryTreeNode<int>(2);
	//BinaryTreeNode<int>* root2=new BinaryTreeNode<int>(3);
	//root->left=root1;
	//root->right=root2;
	root=takeInputLevelwise();
	printBoundary(root);
}
