#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int index;
	string name;
	string message;
	node* prev;
	node* next;

	// constructor
	node(int idx,string nm,string msg){
		index=idx;
		name=nm;
		message=msg;
		prev=NULL;
		next=NULL;
	}
};

map<int,node*> mp;

void insertAtHead(node*&head,int idx,string nm,string msg){
	node* n=new node(idx,nm,msg);
	mp[idx]=n;
	n->next=head;
	if(head!=NULL){
		head->prev=n;
	}
	head=n;
	head->prev=n;
}

void print(node* head){
	while(head!=NULL){
		cout<<head->index<<" "<<head->name<<" "<<head->message<<endl;
		head=head->next;
	}
}

void newMessage(node*&head,int idx,string nm,string msg){
	if(mp.find(idx)==mp.end()){
		insertAtHead(head,idx,nm,msg);
	}
	else{
		node* cur=mp[idx];			// Finding the node to be updated
		msg=msg+cur->message;
		node* temppre=cur->prev;	// Finding the previous node
		node* tempnxt=cur->next;   	// Finding the next node
		if(cur->index!=head->index){   // Checking that the node to be updated is not head pointed node
			temppre->next=tempnxt;    
		}							   // Just the node to be updated is pull out
		else{						   // and the previous node and the next node 
			head=tempnxt;			   // are linked with each other.
		}
		if(tempnxt!=NULL){
			tempnxt->prev=temppre;
		}
		mp.erase(idx);
		delete cur;
		insertAtHead(head,idx,nm,msg);
	}
}

void deleteMessage(node*& head,int idx){
	node* cur=mp[idx];
	node* temppre=cur->prev;
	node* tempnxt=cur->next;
	if(cur->index!=head->index){
		temppre->next=tempnxt;
	}
	else{
		head=tempnxt;
	}
	if(tempnxt!=NULL){
		tempnxt->prev=temppre;
	}
	mp.erase(idx);
	delete cur;
}
int main(){
	node* head=NULL;

	insertAtHead(head,1,"Anuj","How are you...");
	insertAtHead(head,2,"Aman","He was going somewhere...");
	insertAtHead(head,3,"Shivam","where are you currently...");
	insertAtHead(head,4,"Akash","She has joined there...");

	cout<<"Initial state of the chatlist is:"<<endl<<endl;
	print(head);
	cout<<endl<<endl<<endl;

	newMessage(head,5,"Piyush","he has completed...");
	newMessage(head,2,"Aman","He will be back soon....");
	newMessage(head,3,"Shivam","i need your help, can you come little fast...");

	cout<<"State of the chatlist after receiving few messages is:"<<endl<<endl;
	print(head);
	cout<<endl<<endl<<endl;

	deleteMessage(head,2);
	deleteMessage(head,1);
	deleteMessage(head,3);

	cout<<"State of the chatlist after user deleted few messages is:"<<endl<<endl;
	print(head);
}