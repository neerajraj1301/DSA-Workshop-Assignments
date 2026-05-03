#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    // Read the input string
    if (!(cin >> s)) return 0;

    int n = s.length();
    // Double the string to easily simulate the cyclic property
    string doubled = s + s;
    int maxGlobalSum = 0;

    // Check every possible starting point
    for (int i = 0; i < n; i++) {
        vector<bool> visited(26, false);
        int currentSum = 0;

        // Substring can be at most length 26 (unique characters)
        for (int j = 0; j < min(n, 26); j++) {
            char c = doubled[i + j];
            int val = c - 'a' + 1;

            // If we've seen this character in the current window, stop
            if (visited[c - 'a']) {
                break;
            }

            // Mark as visited and add to current sum
            visited[c - 'a'] = true;
            currentSum += val;
            maxGlobalSum = max(maxGlobalSum, currentSum);
        }
    }

    // Print the maximum possible sum
    cout << maxGlobalSum << endl;
    
    return 0;
}