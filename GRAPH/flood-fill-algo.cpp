#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int rows;
    int columns;

    bool valid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < columns;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &images, int sr, int sc, int color)
    {
        rows = images.size();
        columns = images[0].size();

        int initialColor = images[sr][sc];

        // If the initial color is the same as the new color, no need to process
        if (initialColor == color)
        {
            return images;
        }

        // Start the BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});
        images[sr][sc] = color; // Change the color of the starting pixel

        while (!q.empty())
        {
            int firstnode = q.front().first;
            int secondnode = q.front().second;
            q.pop();

            // Check all 4 directions (up, down, left, right)
            if (valid(firstnode - 1, secondnode) && images[firstnode - 1][secondnode] == initialColor)
            {
                images[firstnode - 1][secondnode] = color;
                q.push({firstnode - 1, secondnode});
            }
            if (valid(firstnode + 1, secondnode) && images[firstnode + 1][secondnode] == initialColor)
            {
                images[firstnode + 1][secondnode] = color;
                q.push({firstnode + 1, secondnode});
            }
            if (valid(firstnode, secondnode - 1) && images[firstnode][secondnode - 1] == initialColor)
            {
                images[firstnode][secondnode - 1] = color;
                q.push({firstnode, secondnode - 1});
            }
            if (valid(firstnode, secondnode + 1) && images[firstnode][secondnode + 1] == initialColor)
            {
                images[firstnode][secondnode + 1] = color;
                q.push({firstnode, secondnode + 1});
            }
        }

        return images;
    }
};
