https://toph.co/arena?practice=62bff170d5ce10c32792715c#!/p/5dda3d3f4aeec7000136d609
void solve() {
     ll n, q;
     cin >> n >> q;
     vi a(n);
     f(i, 0, n) cin >> a[i];
     sort(all(a));
     ll sum = 0;
     while(q--)
     {
        ll ty;
        cin >> ty;
        if(ty == 1)
        {
          ll val; cin >> val;
          sum += val;
        }
        else
        {
          ll l, r, k;
          cin >> l >> r >> k;
          int p = upper_bound(all(a), r + sum) - lower_bound(all(a), l + sum);
          if(p < k)
          cout << -1 << endl;
          else
          {
            cout << a[(lower_bound(all(a), l + sum) - a.begin()) + k - 1] - sum << endl;
          }
        }
     }
}
