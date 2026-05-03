#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    
    if (!(cin >> s)) return 0;

    int n = s.length();
   
    string doubled = s + s;
    int maxGlobalSum = 0;

  
    for (int i = 0; i < n; i++) {
        vector<bool> visited(26, false);
        int currentSum = 0;

        
        for (int j = 0; j < min(n, 26); j++) {
            char c = doubled[i + j];
            int val = c - 'a' + 1;

            
            if (visited[c - 'a']) {
                break;
            }

            
            visited[c - 'a'] = true;
            currentSum += val;
            maxGlobalSum = max(maxGlobalSum, currentSum);
        }
    }

    
    cout << maxGlobalSum << endl;
    
    return 0;
}
