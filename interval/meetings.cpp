// Count Days Without Meetings
// Example 1:

// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

// Output: 2

// Explanation:

// There is no meeting scheduled on the 4th and 8th days.

// Example 2:

// Input: days = 5, meetings = [[2,4],[1,3]]

// Output: 1

// Explanation:

// There is no meeting scheduled on the 5th day.


//   step 1 : sort the meetings based on first value 
//   step 2 : take a 2d vector and merge interval 
//   step 3 :  check how many days meeting happens 









#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

         
   // If no meetings, return all days as available
        if (meetings.empty()) {
            return days;
        }
        
        // Sort the meetings by start day, then by end day
        sort(meetings.begin(), meetings.end());

        // Merging overlapping meetings
        vector<pair<int, int>> mergedMeetings;
        mergedMeetings.push_back({meetings[0][0], meetings[0][1]}); // Corrected to push a pair

        for (int i = 1; i < meetings.size(); ++i) {
            // If the current meeting starts after the last merged meeting ends, no overlap
            if (meetings[i][0] > mergedMeetings.back().second) {
                mergedMeetings.push_back({meetings[i][0], meetings[i][1]); // Push pair
            } else {
                // If overlapping, merge the meetings by extending the end of the last one
                mergedMeetings.back().second = max(mergedMeetings.back().second, meetings[i][1]);
            }
        }

        // Now, count the available days by subtracting the days covered by meetings
        int occupiedDays = 0;
        for (auto& meeting : mergedMeetings) {
            occupiedDays += (meeting.second - meeting.first + 1);
        }

        // The result is the total number of days minus the days occupied by meetings
        return days - occupiedDays;
        /*
        //   this solution give me TLT
        //    intuation is correct 
        // Map to store days with meetings

         if (meetings.empty()) {
            return days;
        }
        unordered_map<int, bool> maap;

        // Process each meeting
        for (auto& element : meetings) {
            int first = element[0];  // Access first element (start of meeting)
            int second = element[1]; // Access second element (end of meeting)

            // Mark all days from 'first' to 'second ' as having a meeting
            for (int i = first; i <= second; i++) {
                maap[i] = true;
            }
        }

        int count = 0;

        // Count the number of days that have no meetings
        for (int i = 1; i <= days; i++) {
            if (maap.find(i) == maap.end()) {
                count++; // Day 'i' does not have any meeting
            }
        }

        return count; // Return the number of days without meetings
*/
    }
};
