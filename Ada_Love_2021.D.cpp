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


using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 modd) {
        u64 result = 1;
        base %= modd;
        while (e) {
            if (e & 1)
                result = (u128)result * base % modd;
            base = (u128)base * base % modd;
            e >>= 1;
        }
        return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
        u64 x = binpower(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
        if (n < 4)
            return n == 2 || n == 3;

        int s = 0;
        u64 d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }

        for (int i = 0; i < iter; i++) {
            int a = 2 + rand() % (n - 3);
            if (check_composite(n, a, d, s))
                return false;
        }
        return true;
}

void solve(ll ct) {
    string s;
    cin >> s;
    ll cnt = 0;
    ll n = s.size();
    ll id = 0;
    f(i, 0, n)
    {
        if(s[i] == 'x')
        {
            cnt++;
            id = i;
        }
    }

    if(cnt >= 2)
    cout << "Not Prime" << endl;
    else
    {
        ll c1 = 0, c2 = 0;
       for(int i = 0; i < 10; i++)
       {
         if(s[0] == 'x' && i == 0) continue;
         if(s[id] == 'x')
         {
            string a = s;
            a[id] = '0' + i;
            ll aa = stoll(a);
            //deb(aa);
            if(MillerRabin(aa))
            c1++;
            else c2++;
         }
       }
       if(cnt == 0)
       {
            ll aa = stoll(s);
            if(MillerRabin(aa))
            c1++;
            else c2++;
       }
       if(c2 > c1)
       cout << "Not Prime" << endl;
       else cout << "Prime" << endl;
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
    solve(++ct);  
   }
  rr ;
}
