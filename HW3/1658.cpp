#include <bits/stdc++.h>

using namespace std;


int main()
{
    int k1 = 901, k2 = 8101, t, s1, s2;
    cin >> t;
    vector <vector <long long> > dp (k1, vector <long long> (k2, -1));
    dp[0][0] = 0;
    long long tmp;
    for(int i = 1; i < k1; i++) {
        for(int j = 0; j < k2; j++) {
            for(int d = 1; d < 10; d++) {
                if(i >= d && j >= d*d && dp[i - d][j - d*d] != -1) {
                    tmp = dp[i - d][j - d*d] + 1;
                    if(tmp <= 100 && (dp[i][j] == -1 || dp[i][j] >= tmp))
                        dp[i][j] = tmp;
                }
            }
        }
    }
    string ans_i;
    vector <string> ans;
    for(int l = 0; l < t; l++) {
        ans_i = "";
        cin >> s1 >> s2;
        if(s1 > 900 || s2 > 8100 || dp[s1][s2] == -1)
            ans_i =  "No solution";
        else {
            while(s1 != 0 || s2 != 0) {
                for(int d = 1; d < 10; d++) {
                    if(s1 >= d && s2 >= d*d && dp[s1 - d][s2 - d*d] + 1 == dp[s1][s2]) {
                        ans_i += to_string(d);
                        s1 -= d;
                        s2 -= d*d;
                        break;
                    }
                }
            }
        }
        ans.push_back(ans_i);
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}
