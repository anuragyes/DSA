#include <iostream>
#include <vector>
using namespace std;
void  solve(int arr[], int size)
{
    int count = 0;
    vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }else{
                continue;
            }
        }
        ans.push_back(count);
        // count = 0;
    }

    for(int i =0;i<ans.size();i++){
         cout<<ans[i]<<endl;
    }
    
}

int main()
{
    int arr[7] = {12, 1, 2, 3, 0, 11, 4};
    solve(arr, 7);

    return 0;
}
//  030110074762
//  6038527098