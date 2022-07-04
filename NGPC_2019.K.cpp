//https://toph.co/p/happy-sub-sequence

//Bismillah Hir Rehmanir Rahim
//Allah knows best
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using    namespace __gnu_pbds;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#define gap ' '
#include <bitset>
#define mini -10000000000000000
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define f(i, a, n) for(int i=a; i<n;i++)
#define ll unsigned long long
#define int long long
#define pi 3.141592653589793
#define vi              vector<ll>
#define si              set<ll>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
ll hash58 = 288230376151711717;
ll hash32 = 1610612741;
#define erase_unique(st)        st.erase(unique(st.begin(), st.end()),st.end())
#define all(a) a.begin(), a.end()
typedef pair<ll, ll> pii;
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define unset_bit(x,inx) x = (x & ~(1ll<<(inx)))
#define deb(x)          cout << #x << " = " << x << endl
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define maxheap                  priority_queue<ll>
#define minheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define maxheap2                 priority_queue<pair<ll,ll>>
#define minheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
#define ld long double
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
ll power(ll a, ll b)
{
ll ans = 1;
while(b>0)
{
if(b&1) {ans*=a;}
a*= a;
b>>=1;
}
return ans;
}
ll dp[200005];
void solve() {
     ll n;
     cin >> n;
     vi a(n);
     f(i, 0 , n) cin >> a[i];
     ll frq[200005] = {0};
     ll ans = 0;
     dp[0] = 1;
     frq[0] = 1;
     for(int i = 0; i < n; i++)
     {
       if(i == 0)
       {
        dp[1] = dp[0];
        frq[1]++;
        continue;
       }
       si st;
       for(int j = 1; j * j <= a[i]; j++)
       {
         if(a[i] % j == 0)
         {
             st.in(j);
             st.in(a[i]/j);
             if((a[i] / j) <= n && (a[i] / j) != j)
             {
                frq[a[i] / j] = dp[a[i] / j - 1];
                frq[a[i] / j] %= mod;
             }
             frq[j] = dp[j - 1];
             frq[j] %= mod;
         }
       }
       for(auto x : st)
         {
          //deb(x);
          //deb(dp[x]);
           dp[x] += frq[x];
           //deb(dp[x]);
         }
     }
     for(int i = 1; i <= n; i++)
     {
      ans += dp[i];
      ans %= mod;
      //deb(dp[i]);
      if(dp[i] == 0)
      break;
     }
     cout << ans % mod << endl;
}
int32_t main()
{
  #ifndef DEBUG
   ios
   #else
   freopen("in", "r", stdin);
    //freopen("output.txt", "w", stdout);
   #endif
   int t=1;
   //cin>>t;
   int ct=0;
   while(t--)
   {
    solve();  
   }
  rr ;
}
