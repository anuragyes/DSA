// class Solution
// {
//     public:
    
//     // Function to reverse first k elements of a queue.
//     queue<int> modifyQueue(queue<int> q, int k) {
//         /*
//            queue<int> ans;
//         stack<int> rev;
//         int n = q.size();
//         for(int i=1;i<=k;i++){
//             int ele = q.front();
//             q.pop();
//             rev.push(ele);
//         }
//         for(int i=0;i<n;i++){
//             if(i<k){
//                 int ele = rev.top();
//                 rev.pop();
//                 ans.push(ele);
//             }else{
//                 int ele = q.front();
//                 q.pop();
//                 ans.push(ele);
//             }
//         }
//         return ans;
//         */
        
//          queue<int> ans;
//         deque<int> temp;
        
//         // Push first k elements into deque in reverse order
//         for (int i = 0; i < k; ++i) {
//             temp.push_front(q.front());
//             q.pop();
//         }
        
//         // Push remaining elements from queue into result queue
//         while (!q.empty()) {
//             temp.push_back(q.front());
//             q.pop();
//         }
        
//         // Copy elements from deque to result queue
//         while (!temp.empty()) {
//             ans.push(temp.front());
//             temp.pop_front();
//         }
        
//         return ans;
//     }
// };