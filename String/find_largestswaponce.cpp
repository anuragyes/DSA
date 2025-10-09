#include <bits/stdc++.h> 
int maximumSwap(int num) {
	 string s = to_string(num);
	 int n = s.size();


	 vector<int>last(10,-1);

	 for(int i=0;i<n;i++){
   last[s[i]-'0'] = i ;
	 }


	  for(int i=0;i<n;i++){
		  int curr = s[i]-'0';

		    for(int d = 9 ; d>curr ; d--){
				if(last[d]>i){
					swap(s[i],s[last[d]]);
					return stoi(s);
				}
			}
	  }
	   return num;
}

2
4589
99538
Sample Output 1:
9584
99835
Explanation Of Sample Input 1:
For the first test case, swap the first digit with the last digit, So, return 9584.
For the second test case, swap the third digit with the last digit. So, return 99835.
Sample Input 2:
2
4321   
18
Sample Output 2:
4321
81
