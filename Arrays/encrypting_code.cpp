#include<bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2){
	if((s1+s2)<(s2+s1))
		return 0;
	return 1;
}

void solve(vector<string>& s1, int n){
	int arr[26]={0};
	for(int i=0;i<26;i++){
		arr[i] = (i+1);
	}
	vector<string>sol;
	for(int i=0;i<n;i++){
		string s = s1[i];
		int n1 = s.length();
		int num = 0;
		for(int j = n1-1;j>=0;j--){
			num = num+pow(26,n1-(j+1))*arr[s[j]-'A'];
		}
		sol.push_back(to_string(num));
	}
	sort(sol.begin(),sol.end(),comp);
	for(int i=0;i<n;i++)
		cout<<sol[i];
}

int main(){
	int n;
	cin>>n;
	vector<string>s;
	for(int i=0;i<n;i++){
		string s1;
		cin>>s1;
		s.push_back(s1);
	}
	solve(s,n);
}