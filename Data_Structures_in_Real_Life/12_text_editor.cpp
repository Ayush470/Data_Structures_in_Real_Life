#include <bits/stdc++.h>
using namespace std;

string s="";

class textEditor{
	int buffer;
	stack<pair<int,string>> Stack;
public:
	textEditor(){
		buffer=4;
	}
	void clear(){
		while(!Stack.empty()){
			Stack.pop();
		}
		s="";
	}
	bool isempty(){
		return Stack.empty();
	}
	pair<int,string> top(){
		return Stack.top();
	}
	void undo(){
		if(!Stack.empty()){
			pair<int,string> pr;
			pr=Stack.top();
			Stack.pop();
			if(pr.first==0){     // if last few operation are of 0 type(addition of character) then undo means that you have to delete those added characters from the string and that's exactly is being done
				int len=pr.second.length();
				s.erase(s.length()-len);   // deleting the last len number of characters from the string
			}
			if(pr.first==1){	// if last few operation are of 1 type(deletion of charcters) then undo means you have to add those deleted characters to the string and that's exactly what is done
				s=s+pr.second;	
			}
		}
		else{
			cout<<"Undo Operation is not possible"<<endl;
		}
	}
	void push(int type,char ch){
		if(Stack.empty()){
			if(type==0){
				string cur(1,ch);
				Stack.push(make_pair(type,cur));
				s=s+ch;
			}
		}
		else{
			pair<int,string> p;
			p=Stack.top();
			if(p.first==type && p.second.length()<buffer){    // stack is not empty and you are performing the same operation wrt last operation i.e.(0 and 0, 1 and 1,(prev,curr)) and one thing very important that your size of string in top element of stack is less than buffer size
				if(type==0){        // (type == 0) mean we are adding character
					Stack.pop();    	
					p.second=ch+p.second;		
					Stack.push(make_pair(type,p.second));
					s=s+ch;
				}
				if(type==1){       // (type==1) means we are deleting character 
					Stack.pop();
					p.second=s[s.length()-1]+p.second;      // notice that this order of addition is important as while doing undo operation you can directly add the string otherwise you have to reverse it and then only you can add
					Stack.push(make_pair(type,p.second));
					if(!s.empty()){
						s.erase(s.length()-1); 			// deleting the last element of the string
					}
				}
			}
			else{
				if(type==0){     // this else loop is executed in two cases one when last operation and current operation are different i.e((prev,cur),(0 and 1),(1 and 0)) and top pair of stack is not removed in this case but a new element (pair<int,string>) is inserted in the stack
					string curr(1,ch);    // and second when last operation and current operation are same but length of string in top element of stack is equal to buffer size(i.e. 4)
					Stack.push(make_pair(type,curr));
					s=s+ch;
				}
				if(type==1){
					if(!s.empty()){
						char character=s[s.length()-1];
						string current(1,character);
						Stack.push(make_pair(type,current));
						s.erase(s.length()-1);
					}
				}
			}
		}
	}
};

int main(){
	textEditor t;

	cout<<"Writing some initial letters:"<<endl;
	t.push(1,'w'); 
	t.push(0,'a');
	t.push(0,'b');
	t.push(0,'c');
	t.push(0,'d');
	t.push(0,'e');
	t.push(0,'f');

	cout<<s<<endl<<endl;

	cout<<"After performing the first undo operation the set of characters left are: "<<endl;
	t.undo();

	cout<<s<<endl<<endl;

	t.push(1,'\0');
	t.push(1,'\0');
	t.push(1,'\0');

	cout<<"After deleting few characters, the letters left are: "<<endl;
	cout<<s<<endl<<endl;

	t.undo();
	cout<<"After performing the second undo operation the set of characters left are: "<<endl;
	cout<<s<<endl<<endl;

	cout<<"After writing few more characters, the final set of letters are: "<<endl;
	t.push(0,'a');
	t.push(0,'b');
	t.push(0,'c');
	t.push(0,'d');
	t.push(0,'e');
	t.push(0,'f');

	cout<<s<<endl;
}