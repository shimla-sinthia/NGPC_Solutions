https://toph.co/s/872358

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

void solve(ll ct) {
     ll n;
     cin >> n;
     vi a(n), b(n);
     f(i, 0, n) cin >> a[i] >> b[i];
      ll prf[n + 1] = {0};
      prf[0] = b[0];
      for(int i = 1; i < n; i++)
      prf[i] += prf[i - 1] + b[i];
      map<ll, vector<ll>>mm;
      map<ll, ll>nn, pp;
      //ok
      for(int i = 0; i < n; )
      {
        ll str = i, ed = i;
        ll sum = 0;
        while(i < n && a[i] == a[str])
        {
          sum += b[i];
          ed = i;
          i++;
        }
        for(int j = str; j < i; j++)
        mm[j] = {sum, str, ed};
      }
      for(int i = 0; i < n; )
      {
        ll sum = 0;
        ll ch = a[i];
        ll str = i, ed = i;
        while(i < n && a[i] <= ch)
        {
         sum += b[i];
         ed = i;
         ch = a[i];
         i++;
        }
        for(int j = str; j < i; j++)
        {
          nn[j] = ed;
        }
      }
      for(int i = n - 1; i >= 0; )
      {
        ll sum = 0;
        ll ch = a[i];
        ll str = i, ed = i;
        while(i >= 0 && a[i] <= ch)
        {
         sum += b[i];
         ed = i;
         ch = a[i];
         i--;
        }
        for(int j = str; j > i; j--)
        {
          pp[j] = ed;
        }
      }
     ll q;
     cin >> q;
     while(q--)
     {
        ll id;
        cin >> id;
        id--;
        auto x = mm[id];
        // for(auto xx : x)
        // deb(xx);  
        ll m1 = 0, m2 = 0;
        auto y = pp[id];
        //deb(y);
        // for(auto yy : y)
        // deb(yy);  
        auto z = nn[id];
        //  for(auto zz : z)
        //  deb(zz); 
        // deb(prf[x[1]]);
        // deb(prf[y]);
        m1 = prf[x[1]] - prf[y] - b[x[1]] + b[y];
        //deb(m1);
        m2 = prf[z] - prf[x[2]];
        cout << x[0] + max(m1, m2) << endl;
        //cout << m1 << endl;
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
   //cin>>t;
   int ct=0;
   while(t--)
   {
    solve(ct + 1);  
    ct++;
   }
  rr ;
}
