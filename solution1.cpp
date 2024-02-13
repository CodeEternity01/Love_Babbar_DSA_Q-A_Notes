#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int k = 0; k < t; ++k) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        int count = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            // Check for beautiful pair condition
            if (a[i] % x == 0 && mp.find(a[i] / x) != mp.end()) {
                count++;
            }
            
            mp[a[i] * y]++;  
        }

        cout << count << endl;
    }

    return 0;
}
