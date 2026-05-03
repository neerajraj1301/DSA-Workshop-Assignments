#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    // Read the size of the array
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    // Read array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long k;
    // Read the fixed integer K
    cin >> k;

    // Step 1: Check if it's possible to make all elements equal
    long long remainder = a[0] % k;
    if (remainder < 0) remainder += abs(k); // Handle negative modulo

    for (int i = 1; i < n; i++) {
        long long currentRem = a[i] % k;
        if (currentRem < 0) currentRem += abs(k);
        
        // If remainders differ, it's impossible
        if (currentRem != remainder) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Step 2: Sort the array to find the median
    sort(a.begin(), a.end());
    long long target = a[n / 2]; // The median element
    
    // Step 3: Calculate the minimum total operations
    long long totalOps = 0;
    for (int i = 0; i < n; i++) {
        totalOps += abs(a[i] - target) / k;
    }

    // Print the result
    cout << totalOps << endl;
    
    return 0;
}