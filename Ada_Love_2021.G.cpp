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
#define ll long long
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
ll dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
ll dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
//#define multi_ordered_set       tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
#define ld long double
ll x, y;
vi b;
bool valid(ll mid)
{
   ll ans = 0;
   ll bad = mid * x;
   for(auto p : b)
   {
     if(p > bad)
     {
       ll ext = p - bad;
       ll vag = y - x;
        ans += uceil(ext, vag);
     }
   }
   if(ans <= mid)
   return 1;
   else return 0;
}
void solve() {
     ll n;
     cin >> n;
     vi a(n);
     for(int i = 0; i < n; i++) cin >> a[i];
     cin >> x >> y;
    b = a;
    ll l = 1, h = 1e9, mid, ans;
    if(x >= y)
    {
       ll res = 0;
       res = *max_element(all(a));
       res = uceil(res, x);
       cout << res << endl;
       return;
    }
    while(l <= h)
    {
      mid = (l + h) / 2;
      if(valid(mid))
      {
        ans = mid;
        h = mid - 1;
      }
      else l = mid + 1;
    }
    cout << ans << endl;
}
int32_t main()
{
  #ifndef DEBUG
   //ios
   #else
   freopen("in", "r", stdin);
    //freopen("output.txt", "w", stdout);
   #endif
   int t=1;
   //cin>>t;
   int ct=0;

   while(t--)
   {
     ct++;
     //cout << "Case " << ct << ":" << endl;
    solve();  
   }
  return 0 ;
}
