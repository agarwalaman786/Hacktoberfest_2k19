#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll int MOD=1e9+7;
  
int main() 
{ 
   int n;
   cin>> n;
   ll int k;
   cin>> k;
   vector<ll int>arr(n);
   for(int i=0;i<n;i++){
       cin>> arr[i];
   }  
   sort(arr.begin(),arr.end());
   int i=0, j=n-1;
   int ans=0;
   while(i<j){
       if(arr[i]+arr[j]<=k){
           i++;
       }
       else if(arr[i]+arr[j]>k){
           ans++;
           j--;
       }
   }
   ans++;
   cout<<ans<<endl;
    return 0; 
}

