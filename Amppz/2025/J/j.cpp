#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<pair<int, int>> tasks, vector<pair<int, int>> geo_tasks) {
    vector<int> grades;
    for (int i = n-1; i >= 0; i--) {
        grades.push_back(i);
    }

    // first sum then idx
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    };

    sort(tasks.begin(), tasks.end(), comp);
    sort(geo_tasks.begin(), geo_tasks.end(), comp);


    int min_geo = 0;
    int max_geo = min((int)geo_tasks.size(), k);
    int result = 0;

    while (min_geo <= max_geo) {
        int target_geo_count = min_geo + (max_geo - min_geo / 2);

        if (target_geo_count == 0) {
            result = max(result, target_geo_count);
            min_geo = target_geo_count + 1;
            continue;
        }


        int threshold_idx = target_geo_count - 1;
        long long threshold_score = (long long)geo_tasks[threshold_idx].second + grades[threshold_idx];
        int threshold_original_id = geo_tasks[threshold_idx].first;

        int allowed_non_geo = k - target_geo_count;
        bool possible = true;
        int current_add = 0;

        for (int i = allowed_non_geo; i < tasks.size(); i++) {

            long long current_score = (long long)tasks[i].second + current_add;
            int current_id = tasks[i].first;

            bool is_better = false;
            if (current_score > threshold_score) is_better = true;
            else if (current_score == threshold_score && current_id < threshold_original_id) is_better = true;

            if (is_better) {
                possible = false;
                break;
            }

            current_add++;
        }

        if (possible) {
            result = target_geo_count;
            min_geo = target_geo_count + 1;
        } else {
            max_geo = target_geo_count - 1;
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int n,k;
        cin >> n >> k;
        vector<pair<int, int>> geo_tasks;
        vector<pair<int, int>> tasks;

        int sum;
        int czy_geo;
        for (int i = 0; i < n; i++) {
            sum=0;
            czy_geo=0;
            for (int j = 0; j < 5; j++) {
                int a;
                if (j==0) cin>>czy_geo;
                else {
                    cin>>a;
                    sum+=a;
                }
            }
            if (czy_geo) {
                geo_tasks.push_back({i, sum});
            }else {
                tasks.push_back({i, sum});
            }
        }
        solve(n, k, tasks, geo_tasks);
    return 0;
}