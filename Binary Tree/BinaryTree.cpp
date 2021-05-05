#include"BinaryTree.h"
#include<iostream>
#include<queue>
using namespace std;






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
	printTreeLevelwise(root);
}
