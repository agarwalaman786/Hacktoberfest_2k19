// Backtracking based CPP program to print all
// permutations of a string that follow given
// constraint
#include <bits/stdc++.h>
#define MAX 1000000007
using namespace std;


bool isSafe(string str, int l, int i, int r, string str1)
{
	// If previous character was 'A' and character
	// is 'B', then do not proceed and cut down
	// the recursion tree.
	if (l != 0 && str[l - 1] == str1[0] && str[i] == str1[1])
		return false;

	// This condition is explicitly required for
	// cases when last two characters are "BA". We
	// do not want them to swapped and become "AB"
	if (r == l + 1 && str[i] == str1[0] && str[l] == str1[1]
		|| r == l + 1 && l == i && str[r] == str1[1]
			&& str[l] == str1[0])
		return false;

	return true;
}

void permute(string str, int l, int r, string str1,string temp, int *cnt)
{
	// We reach here only when permutation
	// is valid
	if (l == r) {
		*cnt=(*cnt+1)%MAX;
		return;
	}

	// Fix all characters one by one
	for (int i = l; i <= r; i++) {

		// Fix str[i] only if it is a
		// valid move.
		if (isSafe(str, l, i, r,str1) && isSafe(str, l, i, r,temp)) {
			swap(str[l], str[i]);
			permute(str, l + 1, r,str1,temp,cnt);
			swap(str[l], str[i]);
		}
	}
}

// Driver Code
int main()
{
	string str;
	cin>>str;
	string str1;
	cin>>str1;
	string temp = str1;
	int cnt=  0;
	reverse(temp.begin(),temp.end());
	permute(str, 0, str.length() - 1,str1,temp,&cnt);
	cout<<cnt<<endl;
	return 0;
}
