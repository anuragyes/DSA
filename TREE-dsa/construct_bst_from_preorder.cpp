

//  given arr and check given array , is make bst  ?

//  class Solution {
//   public:
//     int canRepresentBST(int arr[], int n) {
//     stack<int>st;
//        int root = -1;

//        for(int i=0;i<n;i++) {
//           if(arr[i]<root) return 0; // base case false case

//            while(!st.empty() && arr[i]>st.top()) {
//                root = st.top();
//                st.pop();
//            }
//            st.push(arr[i]);
//        }
//        return 1;
//     }
// };
