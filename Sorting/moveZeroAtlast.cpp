
// Given an unsorted array of integers, you have to move the array elements in a way such that all the zeroes are transferred to the end, and all the non-zero elements are moved to the front. The non-zero elements must be ordered in their order of appearance.

// For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output array must be:

// [1, -2, 3, 4, 5, -27, 9, 0, 0, 0].

// Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, ‘n’ is the size of the array.

void pushZerosAtEnd(vector<int> &arr) 
{



	int n = arr.size();
	int pos =0;

	 for(int i=0;i<arr.size();i++){
		  if(arr[i]!=0){
			  arr[pos]=arr[i];
			  pos++;
		  }
	 }

	  while(pos<n){
		   arr[pos] =0;
		   pos++;
	  }
	// Write your code here.

	// //  brute force approch   we have use extra space 
	//  vector<int>ans;
	// int count =0;
	//   for(int i=0;i<arr.size();i++){
	// 	  if(arr[i]==0){
	// 		   count++;
	// 	  }else{
    //   ans.push_back(arr[i]);
	// 	  }

		 
	//   }

	//    while(count>0){
	// 	   ans.push_back(0);
	// 	   count--;
	//    }

	//     arr = ans;
		
}