#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter the number of transactions: ";
	int numOfTransa;
	cin>>numOfTransa;

	int friends;
	cout<<endl<<"Enter the number of friends: ";
	cin>>friends;
	map<string,int> net;

	string x,y;
	int amount;
	int i=1;
	while(numOfTransa--){
		cout<<endl<<"Enter the name of creditor involved in transaction "<<i<<": ";
		cin>>x;
		cout<<"Enter the name of debitor involved in transaction "<<i<<": ";
		cin>>y;
		cout<<"Enter the amount: ";
		cin>>amount;
		i++;
		net[x]-=amount;
		net[y]+=amount;
	}
	multiset<pair<int,string>> s;
	for(auto it:net){
		string name=it.first;
		int sum=it.second;
		s.insert(make_pair(sum,name));
	}
	cout<<endl<<"The net transaction required to settle all previous transactions is: "<<endl;
	while(!s.empty()){
		auto p1=s.begin();
		auto p2=prev(s.end());

		int debit=p1->first;
		string debitor=p1->second;
		int credit=p2->first;
		string creditor=p2->second;

		// int debit=(*p1).first;
		// string debitor=(*p1).second;
		// int credit=(*p2).first;
		// string creditor=(*p2).second;

		s.erase(p1);
		s.erase(p2);

		if(-debit>credit){
			cout<<debitor<<" gives "<<credit<<" amount to "<<creditor<<endl;
			int cur=debit+credit;
			s.insert(make_pair(cur,debitor));
		}
		else if(-debit<credit){
			cout<<debitor<<" gives "<<(-debit)<<" amount to "<<creditor<<endl;
			int cur=debit+credit;
			s.insert(make_pair(cur,creditor));
		}
		else{
			cout<<debitor<<" gives "<<(-debit)<<" amount to "<<creditor<<endl;
		}
	}
	return 0;
}