#include <iostream>
#include <vector>
using namespace std;

// Function to find the longest common substring
void longestCommonSubstring(string s1, string s2) {
    int n = s1.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // DP table with extra row/column

    int maxLength = 0;
    int endIdx = 0;

    // Fill the DP table using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) { 
                dp[i][j] = dp[i - 1][j - 1] + 1; // Extend the previous match
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIdx = i;
                }
            } else {
                dp[i][j] = 0; // Reset if characters don't match
            }
        }
    }

    // Print the DP table (Lookup Table)
    cout << "Lookup Table (DP Table):\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Extract the longest common substring
    if (maxLength > 0) {
        string lcs = s1.substr(endIdx - maxLength, maxLength);
        cout << "\nLongest Common Substring: " << lcs << endl;
    } else {
        cout << "\nNo common substring found." << endl;
    }
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    longestCommonSubstring(str1, str2);

    return 0;
}
