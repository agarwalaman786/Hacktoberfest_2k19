#include<bits/stdc++.h>
using namespace std;

void solve(int *cost, int *pua, int n){
	int t_cost =0;
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<n;i++)
		pq.push(cost[i]);
	while(pq.size()!=1){
		if(pq.empty()!=1){
			int n1 = pq.top();
			pq.pop();
			if(pq.empty()!=1){
				int n2 = pq.top();
				pq.pop();
				t_cost+=(n1+n2);
				pq.push(n1+n2);
			}
		}
	}
	int s_cost =0;
	for(int i=0;i<n;i++){
		s_cost+=pua[i]*cost[i];
	}
	cout<<t_cost<<endl;
	if(t_cost<s_cost){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int *cost = new int[n];
	int *pua = new int[n];
	for(int i=0;i<n;i++)
		cin>>cost[i];
	for(int i=0;i<n;i++)
		cin>>pua[i];
	solve(cost,pua,n);
	
}