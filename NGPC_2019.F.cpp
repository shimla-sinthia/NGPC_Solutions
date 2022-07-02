//https://toph.co/arena?practice=62bf0bcfb7d0f135900ae815#!/p/5dd84f510521a6000112fa02
#define ld double
void solve() {
    ld ab, ad, dab;
    cin >> ab >> ad >> dab;
    ld s1 = ab * ab;
    //deb(s1);
    //deb(ad);
    ld s2 = 0.00;
    ld bd = (ab * ab) + (ad * ad) - ((2.00 * ab * ad) * cos((pi * dab) / 180.00));
    bd = sqrt(bd);
    ld bc = 2.00 * bd;
    ld abd = ((ab * ab) + (bd * bd) - (ad * ad)) / (2.00 * ab * bd);
    abd = acos(abd);
    ld ac = (ab * ab) + (bc * bc) - (2.00 * ab * bc * cos(abd));
    s2 = ac;
    ld ans = s1 + s2;
    cout << fixed << setprecision(6) << ans << endl;
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
