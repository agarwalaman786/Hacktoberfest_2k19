#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>nums, int n){
	map<int,int>mp;
	for(int i=0;i<n;i++)
		mp[nums[i]]++;
	cout<<mp.size()<<endl;
}


int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	solve(arr,n);
}