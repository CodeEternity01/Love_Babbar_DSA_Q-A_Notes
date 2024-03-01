#include <iostream>
#include <vector>

using namespace std;

int minMangoesToRemove(int N, vector<int>& A) {
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

   
    return min(evenCount, oddCount);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << minMangoesToRemove(N, A) << endl;
    }

    return 0;
}
