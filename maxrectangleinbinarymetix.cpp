#include <iostream>
#include <string>
using namespace std;

int solve(const string& str, int start, int end) {
    // Base case: If the start index is greater than or equal to the end index, return 0
    if (start >= end) {
        return 0;
    }

    int count = 0;

    // Find the first non-repeating character after the start index
    int next = start + 1;
    while (next < end && str[next] == str[start]) {
        next++;
    }

    // Case 1: Delete all characters between start and next (exclusive)
    count = 1 + solve(str, next, end);

    // Case 2: Delete a group of three characters starting from the start index
    for (int i = start + 1; i < next; i++) {
        if (str[i] != str[start]) {
            continue;
        }
        for (int j = i + 1; j < next; j++) {
            if (str[j] != str[start]) {
                continue;
            }
            count = min(count, 1 + solve(str, j, end));
        }
    }

    return count;
}

int main() {
    string inputString = "abbdacccmmmcc";
    int steps = minimumStepsToDeleteString(inputString, 0, inputString.length());
    cout << "Minimum steps to delete the string fully: " << steps << endl;

    return 0;
}

