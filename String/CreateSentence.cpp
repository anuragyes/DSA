#include <bits/stdc++.h> 


 void backtracking(vector < vector < string > > & arr, int row , vector<string>&current, vector < vector < string > > & ans){

     if(arr.size()==row){
         ans.push_back(current);
         return ;
     }


      for(auto words : arr[row]){
          current.push_back(words);
          backtracking(arr,row+1,current,ans);
          current.pop_back();
      }
 }




void createSentences(vector < vector < string > > & arr, vector < vector < string > > & ans) {
    // Write your code here.

     vector<string>current;
     backtracking(arr,0,current,ans);
}



/*Ninja is trying to create a robot, which would talk to humans. Ninja is stuck at a particular phase where he wants the robot to create all possible sentences from a 2D array of words. Help Ninja in solving this problem. For a given 2D array of words, your task is to create all possible sentences that can be made using them.

Note :
In a particular sentence, the robot can use a single word from the row that the word is part of.   example 
Sample Input 1:
1
2 2 
you we
sleep drink
Sample Output 1:
you sleep
you drink
we sleep
we drink
Explanation of Sample Input 1:
Taking a word from each row and adding it to each word of rest all the columns.
Sample Input 2:
2
3 1
i
love
coding
3 2
you we
have are
eat read
Sample Output 2:
i love coding
you have eat
you have read
you are eat
you are read
we have eat
we have read
we are eat
we are read
*/