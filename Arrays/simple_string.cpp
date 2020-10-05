#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k, string s){
	int ans = 0;
	string temp;
	int i=1;
	temp.push_back(s[0]);
	int j = 0;
	while(i<n && k>0){
		if(temp[j]==s[i]){
			temp.push_back(s[i]);
			i++;
			j++;
		}
		else{
			temp.pop_back();
			i++;
			temp.push_back('?');
			k--;
		}
	}
	return temp.length()+(n-i);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		cout<<solve(n,k,s)<<endl;
	}
}