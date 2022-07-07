#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,b) for(int i=a;i<(int)b;i++)
#define FORr(i,a,b) for(int i =a;i>=(int)b;i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define print(arr)  for(auto a: arr) cout << a<< " "; cout << endl;
#define in(a) int a; cin >> a;
#define inp(arr,n) vector<int>arr(n); for(auto &a: arr) cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vi vector<int>
#define s second
#define mxheap priority_queue<int>
#define mnheap priority_queue<int, vector<int>, greater<int>>
#define mxheap2 priority_queue<pair<int,int>>
#define mnheap2 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
int mod = 1e9 + 7;
#define case cout << "Case "<< tt << ": ";
inline int uceil(int a,int b) {return (a % b ? a / b + 1 : a / b);}
#define pll pair<int, int>
#define set_bit(x, idx) x = x|(1LL<<idx)
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define endl "\n"
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define db long double



#ifdef DEBUG
#include "tpc.hpp"
#define pause(x) thamm
#define ios
#define dbg(...) cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#define ok tikkk
#else
#define pause(x) 
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(...) 
#define ok
#endif


void solvetc(int tt){
    in(n) in(k)
    pll point[n];
    rep(i,n){
        cin >> point[i].f >> point[i].s;
    }
    int trg = -1;
    rep(i, n){
        map<int, int> cnt;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            pll a = point[i];
            pll b = point[j];
            int up = a.f - b.f;
            int down = a.s - b.s;
            int gcd = __gcd(up, down);
            if(gcd != 0) {
                up /= gcd;
                down /= gcd;
            }
            if(up < 0) up = 1000+abs(up);
            if(down < 0) down = 1000 + abs(down);
            up *= 2001; up += down;
            cnt[up]++;
        }
        for(auto a: cnt){
            if(a.s == k-1){
                trg = a.f;
                break;
            }
        }
        dbg(trg);
        if(trg != -1){
            k--;
            cout << point[i].f << " "<< point[i].s << endl;
            FOR(j,0,n){
                if(i == j) continue;
                pll a = point[i];
                pll b = point[j];
                int up = a.f - b.f;
                int down = a.s - b.s;
                int gcd = __gcd(up, down);
                if(gcd != 0) {
                    up /= gcd;
                    down /= gcd;
                }
                if(up < 0) up = 1000+abs(up);
                if(down < 0) down = 1000 + abs(down);
                up *= 2001; up += down;
                if(up == trg){
                    cout << point[j].f << " "<< point[j].s << endl;
                    k--;
                    if(k == 0){
                        break;
                    }
                }
            }
            return;
        }
    }
}

int32_t main()
{
    ios ;
    #ifdef DEBUG
    //freopen("in", "r", stdin);
    #endif
    int nn = 1;
    //cin >> nn;
    rep(i, nn) solvetc(i+1);
}
