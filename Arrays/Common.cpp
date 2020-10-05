#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	ll int t;
	cin>>t;
	while(t--){
		ll int n;
		cin>>n;
		ll int  *arr = new ll int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<string>arr1;
		int cnt = 1;
		for(int i=0;i<n;i++){
			ll int num = arr[i];
			if(i==0){
				string s1;
				string s2;
				while(num--){
					s1.push_back('a');
					s2.push_back('a');
				}
				arr1.push_back(s1);
				arr1.push_back(s2);
			}
			else{
				string s3;
				ll int tmp = num;
				ll int x = arr1[arr1.size()-1].length();
				if(x==0){
					while(tmp--){
						arr1[arr1.size()-1].push_back('a'+cnt);
					}

					while(num--){
						s3.push_back('a'+cnt);
					}
					cnt++;
					if(cnt==25)
						cnt = 0;
				}
				else{
					while(num--){
						s3.push_back(arr1[arr1.size()-1][0]);
					}
					if(tmp>x){
						ll int diff = tmp - x;
						while(diff--)
							arr1[arr1.size()-1].push_back(arr1[arr1.size()-1][0]);
					}
				}

				arr1.push_back(s3);
			}
		}
		//int cnt = 1;
		for(ll int i=0;i<arr1.size();i++){
			if(arr1[i].length()==0){
				arr1[i].push_back((char)(97+cnt));
				cnt++;
				if(cnt==25){
					cnt = 1;
				}
			}
			cout<<arr1[i]<<endl;
		}
	}
	return 0;
}