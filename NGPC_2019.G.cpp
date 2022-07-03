//https://toph.co/p/is-bita-happy

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
void solve() {
     ll a, k, l, r;
     cin >> a >> k >> l >> r;
     if(check_bit(a, k) == 0 || power(2, k) > r)
     cout << "Even" << endl;
     else{
         r++;
         ll mot = 0, ago = 0, pgo = 0;
         ll phrase = power(2, k + 1);
         mot = r / phrase;
         mot = mot * (phrase / 2);
         //ago += (mot / 2);
         //deb(ago);
         ll age = phrase;
         phrase = r % phrase;
         phrase -= age / 2;
         ll mx = max(0ll, phrase);
         mot += mx;
         //ago += mx / 2;
         ago = mot / 2;


         ll bad = 0; 
         //l--;
         phrase = power(2, k + 1);
         bad = l / phrase;
         bad = bad * (phrase / 2);
         pgo += (bad / 2);
         age = phrase;
         phrase = l % phrase;
         phrase -= age / 2;
         mx = max(0ll, phrase);
         bad += mx;
         pgo = bad / 2;
        //  deb(ago); deb(pgo);
        //  deb(mot);
        //  deb(bad);
        if(k == 0)
        {
          ago = mot; pgo = bad;
        }
         if((ago - pgo) % 2)
         cout << "Odd" << endl;
         else cout << "Even" << endl;
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
    solve();  
   }
  rr ;
}
