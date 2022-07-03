//https://toph.co/p/fortis-fortuna-adiuvat

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
vector<pair<ll,ll>>arr[100005], brr[100005];
ll dist1[100005], dist2[100005];
ll n, m, x, q;        

void dijkstra(ll nn) {
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
dist1[nn] = 0;
pq.push({0, nn});
 
while(!pq.empty()) {
   auto zz = pq.top();
    pq.pop();
   ll w = zz.ff;
   ll x = zz.ss;
   if(w > dist1[x]) continue;
     for(auto z : arr[x]) {
        ll y = z.ss;
        ll w2 = z.ff;
     if(dist1[y] > dist1[x] + w2)  {
    dist1[y] = dist1[x] + w2;
    pq.push({dist1[y], y});
         }
      }
   }
}
void dijkstra2(ll nn) {
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
dist2[nn] = 0;
pq.push({0, nn});
 
while(!pq.empty()) {
   auto zz = pq.top();
    pq.pop();
   ll w = zz.ff;
   ll x = zz.ss;
   if(w > dist2[x]) continue;
     for(auto z : brr[x]) {
        ll y = z.ss;
        ll w2 = z.ff;
     if(dist2[y] > dist2[x] + w2)  {
    dist2[y] = dist2[x] + w2;
    pq.push({dist2[y], y});
         }
      }
   }
}
void solve(ll ct) {
     cin >> n >> m >> x >> q;
      for(int i = 0; i <= n; i++)
     {
      dist1[i] = 1e18;
      dist2[i] = 1e18;
      brr[i].clear();
      arr[i].clear();
     }
     for(int i = 0; i < m; i++)
     {
        ll u, v, w;
        cin >> u >> v >> w;
        arr[u].pb({w, v});
        brr[v].pb({w, u});
     }
     dijkstra(x);
     dijkstra2(x);
     cout << "Case " << ct + 1 << ":" << endl;
     while(q--)
     {
      ll s, t;
      cin >> s >> t;
       if(dist2[s] == 1e18)
       cout << "Be seeing ya, John" << endl;
       else
       {
         if(dist1[t] == 1e18)
          cout << "Be seeing ya, John" << endl;
          else{
            cout << dist2[s] + dist1[t] << endl;
          }
       }
     }
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
   cin>>t;
   int ct=0;
   while(t--)
   {
    solve(ct++);  
   }
  rr ;
}
