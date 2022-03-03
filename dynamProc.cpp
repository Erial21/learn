#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    vector<int> s;
    vector<int> f;
    int ans=0;
    s = { 1,2,3,4,5,6,7,2,3,4,5,6,7,1,2,3,4 };

    cout << s.size();
    for (int i = 0;i < s.size();i++) {
        f.push_back(1);
        cout << f.back();
    }
    int a = 5, b = 6;
    cout << endl << max(a, b) << endl;

    for (int i = 0;i < s.size();i++) {
        for (int j = 0;j < i;j++) {
            if (s[j] < s[i]) {
                f[i] = max<int>(f[i], (f[j] + 1));
            }
        }
        cout << "f(" << i + 1 << ") = " << f[i] << endl;
    }

    for (int i = 0;i < s.size();i++) {
        if(ans<f[i]){
            ans=f[i];
        }
        ans = max(ans,f[i]);
    }

    cout << ans << endl;
    return 0;
}