// minimium swaps to all ones together  example 1,0,1,0,1  ans = 1   0,0,1,1,1  swap arr[0],arr[3]

#include <bits/stdc++.h> 
int groupAllOneTogether(vector<int> &arr, int n) {
	 int countones = count(arr.begin(),arr.end(),1);
	  if(countones==0)  return -1;
	  if(countones==n)  return 0;


	   int zerocount =0;

	    for(int i=0;i<countones;i++){
			if(arr[i]==0)  zerocount++;
		}

		 int minSwaps = zerocount;


		  for(int i=countones;i<n;i++){
			  if(arr[i-countones]==0)  zerocount--;

			   if(arr[i]==0) zerocount++;

			   minSwaps = min(minSwaps,zerocount);
		  }

		   return minSwaps;
	
}