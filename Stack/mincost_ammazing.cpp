int minCost(string s, vector<int>& cost) {
    stack<pair<char, int>> st;
    int n = s.size();
    int i = 0;
    int minicost = 0;

    while (i < n) {
        if (!st.empty() && st.top().first == s[i]) {
            // Same character sequence → remove cheaper one
            if (st.top().second < cost[i]) {
                minicost += st.top().second; // delete stack top
                st.pop();
                st.push({s[i], cost[i]}); // keep current
            } else {
                minicost += cost[i]; // delete current
            }
        } else {
            st.push({s[i], cost[i]});
        }
        i++;
    }

    return minicost;
}


// Got it 👍 — you pasted a snippet that looks like you’re trying to solve the “Minimum Deletion Cost to Avoid Repeating Letters” problem (LeetCode 1578).

// Your current code has several bugs and missing logic. Let me debug and correct it for you.