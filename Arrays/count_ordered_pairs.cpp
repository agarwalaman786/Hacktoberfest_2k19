#include<bits/stdc++.h>
using namespace std;

int solve(int n){
	int ans = 0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(i!=n/i)
				ans+=2;
			else{
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	//x*b = n^2;
	cout<<solve(n*n);
}