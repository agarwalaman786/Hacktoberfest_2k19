#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long calculate(long long p, long long q) 
{ 
    long long mod = pow(10, 9) + 7, expo; 
    expo = mod - 2; 
   while (expo) { 
        if (expo & 1) { 
            p = (p * q) % mod; 
        }
        q = (q * q) % mod; 
        expo >>= 1; 
    } 
    return p; 
}

int main() {
 int t;
 cin>>t;
 while(t--){
      int n;
      cin>>n;
      string s;
      cin>>s;
      int a[n];
      long long int sum=0;
      bool visit[26];
      memset(visit,false,sizeof(visit));
      a[0] = 1;
      visit[s[0]-97] = true;
      sum += a[0];
      for(int i=1;i<n;i++){
           if(visit[s[i]-97])
           	a[i] = a[i-1];
           else{
           	a[i] = a[i-1] + 1;
           	visit[s[i]-97] = true;
           }
           sum+=a[i];
      }
      int ss = sum;
      int tmp = a[0],cnt =0;
      for(int i=1;i<n;i++){
           if(s[i]==s[i-1]){
                ss-=tmp;
                sum = sum + ss;
            }
           else{
                ss = ss - tmp;
                ss -= (n-i);
                sum+=ss;
                cnt++;
           }
           tmp = a[i]-cnt;
      }
      cout<<sum<<endl;
      long long int q = ((n%MOD)*((n+1)%MOD))/2;
      long long int gc = __gcd(sum,q);
      sum = sum/gc;
      q = q/gc;
      cout<<calculate(sum,q)<<endl;
 }
 return 0;
}