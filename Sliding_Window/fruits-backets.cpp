class Solution {
  public:
    int totalFruits(vector<int> &fruits) {
        map<int, int> fruitCount;  // To keep track of fruit types and their frequencies
    int maxFruits = 0;
    int left = 0;  // Left pointer of the window

    // Iterate through each tree (right pointer)
    for (int right = 0; right < fruits.size(); ++right) {
        fruitCount[fruits[right]]++;  // Add the current fruit to the map

        // If we have more than 2 types of fruits, shrink the window from the left
        while (fruitCount.size() > 2) {
            fruitCount[fruits[left]]--;  // Decrease the count of the leftmost fruit
            if (fruitCount[fruits[left]] == 0) {
                fruitCount.erase(fruits[left]);  // Remove the fruit type if count is zero
            }
            left++;  // Move the left pointer to the right
        }

        // Update the maximum number of fruits we can collect
        maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
        //  brute force approch 
        // set<int>st;
        //  int  length =0;
        // for(int i =0;i<arr.size();i++){
        //      for(int j  = i;j<arr.size();j++){
        //          st.insert(arr[j]);
        //           if(st.size()<=2){
        //               length = max(length,j-i+1);
        //           }else{
        //               break;
        //           }
        //      }
        // }
        //   return  length;
        
        
        // optimal approch 
        
         
          
    }
};


/*You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.*/