#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
   
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long k;
    
    cin >> k;

    
    long long remainder = a[0] % k;
    if (remainder < 0) remainder += abs(k); // Handle negative modulo

    for (int i = 1; i < n; i++) {
        long long currentRem = a[i] % k;
        if (currentRem < 0) currentRem += abs(k);
        
       
        if (currentRem != remainder) {
            cout << -1 << endl;
            return 0;
        }
    }

    sort(a.begin(), a.end());
    long long target = a[n / 2]; 
    
   
    long long totalOps = 0;
    for (int i = 0; i < n; i++) {
        totalOps += abs(a[i] - target) / k;
    }

    // Print the result
    cout << totalOps << endl;
    
    return 0;
}
