class Solution {
    long long count = 0;
    int N;
    long long MOD = 1e9 + 7;

public:
    void solve(vector<bool>& isSick, int sickCount) {
        if (sickCount == N) {
            count = (count + 1) % MOD;
            return;
        }

  
        set<int> candidates;
        
        for (int i = 0; i < N; ++i) {
            if (isSick[i]) {
                if (i - 1 >= 0 && !isSick[i - 1]) {
                    candidates.insert(i - 1);
                }
                if (i + 1 < N && !isSick[i + 1]) {
                    candidates.insert(i + 1);
                }
            }
        }

        for (int candidate : candidates) {
            isSick[candidate] = true;
            solve(isSick, sickCount + 1);
            isSick[candidate] = false;
        }
    }

    int numberOfSequence(int n, vector<int>& sick) {
        N = n;
        count = 0;
        
        vector<bool> isSick(n, false);
        for (int s : sick) {
            isSick[s] = true;
        }
        solve(isSick, sick.size());

        return count;
    }
};