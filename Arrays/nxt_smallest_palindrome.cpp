#include<bits/stdc++.h>
using namespace std;
void solve(int *arr, int n){
    if(n==0)
        return;
    int l=0,h = 0;
    int mid = n/2;
    l = mid-1;
    
    //if odd for eg:  1 2 3 4 5 (then in this eg we can see that pointers will be situated to the 2 and 4)
    if(n%2!=0){
        h = mid+1;
    }
    else{
        h = mid;
    }
    while(l>=0 && arr[l]==arr[h]){
        l--;
        h++;
    }
    
    //Means given number is already palindrome add 1 to middle number;
    int carry = 0;
    
    //this is the case when left digit is smaller or given number is already a palindrome number
    int flag = 0;
    if(l<0 || arr[l]<arr[h]){
        flag = 1;
    }
    if(flag==0){
        while(l>=0){
            arr[h] = arr[l];
            h++;
            l--;
        }
    }
    else{
        if(n%2==0){
            l = mid-1;
            h = mid;
            int num = (arr[l]+1);
            arr[l]= num%10;
            carry = num/10;
            arr[h] = arr[l];
            l--;
            h++;
            while(l>=0){
                num = (arr[l]+carry);
                arr[l]= num%10;
                carry = num/10;
                arr[h] = arr[l];
                h++;
                l--;
            }
        }
        else{
            l = mid;
            h = mid+1;
            int num = arr[l]+1;
            carry = num/10;
            arr[l] = num%10;
            l--;
            while(l>=0){
                num = (arr[l]+carry);
                arr[l] = num%10;
                carry = num/10;
                arr[h] = arr[l];
                h++;
                l--;
            }
        }
    }
}



int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(arr,n);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}


