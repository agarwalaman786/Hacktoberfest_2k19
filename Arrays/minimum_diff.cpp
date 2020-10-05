//Very Important question not solved through the DP

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll int n;
	cin>>n;
	ll int sum=(n*(n+1)/2);
    sum = sum/2;
	vector<ll int>arr1,arr2;
	ll int temp = n;
	while(sum){
		if(sum-n>=0){
			sum = sum - n;
			arr1.push_back(n);
		}
		else
			arr2.push_back(n);
		n--;
	}

	if((arr1.size()+arr2.size())<temp){
		for(ll int i=1;i<=n;i++)
			arr2.push_back(i);
	}

	cout<<abs(accumulate(arr1.begin(),arr1.end(),0) - accumulate(arr2.begin(),arr2.end(),0))<<endl;
	return 0;
}
