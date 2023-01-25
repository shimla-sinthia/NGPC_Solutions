https://toph.co/s/872506

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
ll seg[400050];

void update(ll sii, ll sss, ll see, ll qi, ll val)
{
   if(sss == see)
   {
      seg[sii] = val;
      return ;
   }
   ll mid = (sss + see) / 2;
   if(qi <= mid)
   {
     update(2 * sii, sss, mid, qi, val);
   }
   else
   {
      update(2 * sii + 1, mid + 1, see, qi, val);
   }
   seg[sii] = max(seg[sii * 2] , seg[sii * 2 + 1]);
}  
ll query(ll sii, ll sss, ll see, ll qs, ll qe)
{
   if(qs > see || qe < sss)
   return 0;

   if(sss >= qs && see <= qe)
   return seg[sii];

   ll mid = (sss + see) / 2;

   ll l = query(2 * sii , sss , mid , qs , qe);
   ll r = query(2 * sii + 1 , mid + 1 , see , qs , qe);
   return max(l , r);
}
void solve(ll ct) {
     ll n, k;
     cin >> n;
     vi a(n);
     f(i, 0, n) cin >> a[i];
     si st;
     st.in(all(a));
     unordered_map<ll, ll> nn, mm;
     ll id = 1;
     for(auto x : st)
     {
       mm[x] = id++;
       nn[id - 1] = x;
     }
     for(int i = 0; i < n; i++) a[i] = mm[a[i]];
     for(int i = 0; i < n; i++)
     {
        ll x = a[i];
        ll now = query(1, 1, n, x, x);
        now = max(now, nn[x]);
        now = max(now, nn[x] + query(1, 1, n, 1, x - 1));
        update(1, 1, n, x, now);
     }
     cout << query(1, 1, n, 1, n + 5) << endl;
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
    solve(++ct);  
   }
  rr ;
}
