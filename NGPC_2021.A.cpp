// Bismillah Hir Rehmanir Rahim
// Allah knows best
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define gap ' '
#define mini -10000000000000000
#define endl '\n'
#define f(i, a, n) for (int i = a; i < n; i++)
#define int long long
#define ll long long
#define pi 3.141592653589793
#define vi vector<int>
#define si set<int>
#define pb push_back
#define mp make_pair
#define mod 288230376151711717
#define rr return 0
#define ff first
#define in insert
#define ss second
int hash58 = 288230376151711717;
int hash32 = 1610612741;
#define erase_unique(st) st.erase(unique(st.begin(), st.end()), st.end())
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
#define setbits(x) __builtin_popcountll(x)
#define zrbits(x) __builtin_ctzll(x)
#define unset_bit(x, inx) x = (x & ~(1ll << (inx)))
#define set_bit(x, idx) x = x | 1LL << idx
#define check_bit(x, idx) min(x & (1LL << idx), 1LL)
#define toggle_bit(x, idx) x = x ^ (1LL << idx)
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
#define maxheap2 priority_queue<pair<int, int>>
#define minheap2                                           \
    priority_queue<pair<int, int>, vector<pair<int, int>>, \
                   greater<pair<int, int>>>
inline int uceil(int a, int b) { return (a % b ? a / b + 1 : a / b); }
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>
#ifdef DEBUG
#include "tpc.hpp"
#define ios
#define dbg(...)                                                   \
    {                                                              \
        cerr << __LINE__ << " : ";                                 \
        cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__); \
    }
#define ok tikkk
#else
#define ios                               \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define dbg(...)
#define ok
#endif
#define ld long double
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

ll dp[5000006];
// ll solvet(ll num){
//     if(num <= 2){
//         if(num == 2)
//         return 0;
//     }
//     if(dp[num] != -1)
//     return dp[num];

//     return dp[num] = 1 + solvet(num - 1);
// }

void solve(int ct) {
    ll n;
    cin >> n;
    vi a(n);
    f(i, 0, n) cin >> a[i];

    vi v;
    for(int i = 0; i < n; i++){
        ll x = 0;
        if(a[i] % 2) x = dp[a[i]/2] + 1;
        else x = dp[a[i]/2 - 1] + 1;
        v.pb(x);
    }
    ll xc = 0;
    //dbg(v);
    for(int i = 0; i < n; i++) xc ^= v[i];
    if(xc)
    cout << "Mrinalini" << endl;
    else cout << "Kadambari" << endl;

}
int32_t main() {
    ios int t = 1;
    cin >> t;
    //memset(dp, -1, sizeof(dp));
    //ok
    // solvet(5000000);
    //ok
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= 5000000; i++){
        if(i % 2) dp[i] = dp[i/2] + 1;
        else dp[i] = dp[(i - 1)/2] + 1;
    }
    //for(int i = 0; i <= 12; i++) dbg(dp[i], i);
    for (int ct = 1; ct <= t; ct++) {
        solve(ct);
    }
    rr;
}
