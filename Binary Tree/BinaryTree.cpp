#include<bits/stdc++.h>
#include"BinaryTree.h"
#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

//printing the tree in vertical order

void printVertical(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
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
		for(int i=0;i<temp.size();i++){
			cout<<temp[i]<<" ";
		}
	}
	
	//iterating through map of vector
		
//	for(auto& it:m){
//		cout<<it.first<<":";
//		for(auto& z: it.second){
//			cout<<z<<",";
//		}
//		cout<<endl;
//	}
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
	printVertical(root);
}
