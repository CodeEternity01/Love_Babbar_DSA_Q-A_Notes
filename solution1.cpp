#include <iostream>
#include <cmath>

using namespace std;

bool isSafeCombination(int ix, int iy, int jx, int jy, int fx, int fy, int t) {
    // Step 1: Calculate Distance
    int distance = abs(jx - ix) + abs(jy - iy);

    // Step 2: Calculate Time Taken for Fire to Reach
    int timeToReach = abs(fx - jx) + abs(fy - jy);

    // Step 3: Compare Time Taken with Distance
    // Step 4: Decision Making
    return timeToReach > distance && (timeToReach - distance) % 2 == 0 && timeToReach <= t;
}

int main() {
    int n; 
    cin >> n;

    for (int i = 0; i < n; ++i) {
        // Input values for starting point, ending point, fire starting point, and time combinations
        int ix, iy, jx, jy, fx, fy, t;
        cin >> ix >> iy >> jx >> jy >> fx >> fy >> t;

        // Check if the combination is safe
        if (isSafeCombination(ix, iy, jx, jy, fx, fy, t)) {
            cout << "Combination " << i + 1 << ": Safe for Jimmy!" << endl;
        } else {
            cout << "Combination " << i + 1 << ": Unsafe for Jimmy!" << endl;
        }
    }

    return 0;
}