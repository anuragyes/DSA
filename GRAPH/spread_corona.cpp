#include <vector>
#include <queue>
using namespace std;

/*
first = find the size of row and column
second = search how many number of cornon patient and those patient push into the queue and set a variable of timer
 third = check there normal pateint means  1  neghbour up down left right  thoese normal pateint make covid patent
   fourth - check  every row and column  if 1 is present return -1 otherwise return timer-1;
class Solution {
public:
    int rows;
    int columns;

    bool valid(int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < columns;
    }

    int helpaterp(vector<vector<int>>& hospital) {
        rows = hospital.size();
        columns = hospital[0].size();

        queue<pair<int, int>> q;
        int timer = -1; // Initially -1 since we start counting after the first push

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (hospital[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            timer++;
            int current_patient = q.size();

            while (current_patient--) {
                int firstnode = q.front().first;
                int secondnode = q.front().second;
                q.pop();

                // Check all 4 possible directions directly
                //  up direction 
                if (valid(firstnode - 1, secondnode) && hospital[firstnode - 1][secondnode] == 1) {
                    hospital[firstnode - 1][secondnode] = 2;
                    q.push({firstnode - 1, secondnode});
                }
                //  down direction 
                if (valid(firstnode + 1, secondnode) && hospital[firstnode + 1][secondnode] == 1) {
                    hospital[firstnode + 1][secondnode] = 2;
                    q.push({firstnode + 1, secondnode});
                }
                //  left direction 
                if (valid(firstnode, secondnode - 1) && hospital[firstnode][secondnode - 1] == 1) {
                    hospital[firstnode][secondnode - 1] = 2;
                    q.push({firstnode, secondnode - 1});
                }
                //  right direction 
                
                if (valid(firstnode, secondnode + 1) && hospital[firstnode][secondnode + 1] == 1) {
                    hospital[firstnode][secondnode + 1] = 2;
                    q.push({firstnode, secondnode + 1});
                }
            }
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (hospital[i][j] == 1) return -1;

        return timer == -1 ? 0 : timer;
    }
};



*/
class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int column[4] = {0, 0, -1, 1};
    int rows;
    int columns;

    bool valid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < columns;
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        rows = hospital.size();
        columns = hospital[0].size();

        queue<pair<int, int>> q;
        int timer = -1; // Initially -1 since we start counting after the first push
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (hospital[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        while (!q.empty())
        {
            timer++;
            int current_patient = q.size();

            while (current_patient--)
            {
                int firstnode = q.front().first;   // first = column
                int secondnode = q.front().second; // second = row
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    if (valid(firstnode + row[k], secondnode + column[k]) && hospital[firstnode + row[k]][secondnode + column[k]] == 1)
                    {
                        //  up direction   firstnode - 1
                        hospital[firstnode + row[k]][secondnode + column[k]] = 2;
                        q.push(make_pair(firstnode + row[k], secondnode + column[k]));
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (hospital[i][j] == 1)
                    return -1;

        // return timer == -1 ? 0 : timer;
        return timer - 1;
    }
};

/*


 queue<make_pair<int>>q;
 int row = hospital.size();
 int column - hospital[0].size();

   for(int i =0;i<row;i++){
   for(int j = 0 ; j< column;j++){
     if(hospital[i][j]==2){
     q.push(make_pair(i,j));
     }

      int timer  = 0;

      while(!q.empty()){
       timer++;
       int n = q.size();
        while(n--){
       int firstnode = q.front().first;
        int secondnode = q.front().second;
        q.pop();

        

        for(int k = 0 ; k <4;k++){
           if (valid(firstnode + row[k], secondnode + column[k]) && hospital[firstnode + row[k]][secondnode + column[k]] == 1)
                    {
                        //  up direction   firstnode - 1
                        hospital[firstnode + row[k]][secondnode + column[k]] = 2;
                        q.push(make_pair(firstnode + row[k], secondnode + column[k]));
                    }
        }

      }
   }
   for(int i =0;i<row;i++){
   for(int j = 0 ; j< column;j++){
     if(hospital[i][j]==1){
     return -1;
     }else{
       return  timer-1;
     }


    
   }















*/