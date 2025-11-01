/**
 *      Author : Raj Patel
 *      @Raj_Patel_7807
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include "D:/Code_PlayGround/C++/Header/debug.hpp"
#else
#define debug(...) 7807
#endif
using namespace std;
using namespace __gnu_pbds;

struct custom_hash { //to avoid TLE due to collision in unordered_map and unordered_set;
    static inline const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL; return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const { return splitmix64(x + FIXED_RANDOM); }
    template <typename T1, typename T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        size_t h1 = operator()(static_cast<uint64_t>(p.first)); size_t h2 = operator()(static_cast<uint64_t>(p.second));
        return h1 ^ (h2 << 1);
    }
};

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
#define int ll
#define double ld
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using pll = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;
using ppll = pair<pair<ll, ll>, ll>;
using pllp = pair<ll, pair<ll, ll>>;
using mll = map<ll, ll>;
using umll = unordered_map<ll, ll, custom_hash>;
template <class T1, class T2> using pr = pair<T1, T2>;
template <class T> using vc = vector<T>;
template <class T1, class T2> using umap = unordered_map<T1, T2, custom_hash>;
template <class T> using uset = unordered_set<T, custom_hash>;
template <class T> using pqmax = priority_queue<T>;
template <class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using idset = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using idmap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// For `idset` & `idmap`:
//     .find_by_order(k)  returns iterator to kth element starting from 0;
//     .order_of_key(k) returns count of elements strictly smaller than k;

#define endl '\n'
#define ln cout << '\n';
#define pb push_back
#define popb pop_back
#define ff first
#define ss second
#define len(x) (ll)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define fo1(s) for(ll i=0; i<(s); ++i)
#define fo2(i, s) for(ll i=0; i<(s); ++i)
#define fo3(i, s, e) for(ll i=(s); i<(e); ++i)
#define fo4(i, s, e, inc) for(ll i=(s); i<(e); i+=(inc))
#define rfo1(s) for(ll i=(s)-1; i>=0; --i)
#define rfo2(i, s) for(ll i=(s)-1; i>=0; --i)
#define rfo3(i, s, e) for(ll i=(s)-1; i>=(e); --i)
#define rfo4(i, s, e, dec) for(ll i=(s)-1; i>=e; i-=dec)
#define get_for(a, b, c, d, loop, ...) loop
#define fo(...) get_for(__VA_ARGS__, fo4, fo3, fo2, fo1)(__VA_ARGS__)
#define rfo(...) get_for(__VA_ARGS__, rfo4, rfo3, rfo2, rfo1)(__VA_ARGS__)
#define foe(x, a) for(auto& x : (a))

template <typename... T> inline void read(T&... args) { ((cin >> args), ...); }
template <typename... T> inline void write(bool F, T&&... args) { ((cout << args << (F ? '\n' : ' ')), ...); }
#define in(T, ...) T __VA_ARGS__; read(__VA_ARGS__);
#define out(...) write(true, __VA_ARGS__);
#define outt(...) write(false, __VA_ARGS__);
#define vin(T, name, n) vector<T> name(n); for(auto& x : name) cin >> x;
#define vvin(T, name, n, m) vector<vector<T>> name(n, vector<T>(m)); fo(i, n) fo(j, m) cin >> name[i][j];
#define vpin(T, V, name, n) vector<pair<T, V>> name(n); fo(n) cin >> name[i].ff >> name[i].ss;
#define vout(a) for(auto x : a) { cout << x << ' '; } cout << '\n';
#define vpout(a) for(auto x : a) { cout << x.first << ' ' << x.second << '\n'; }
// rotate(v.begin(), v.end()-r, v.end()); - Rotate vector r times right;
// rotate(v.begin(), v.begin()+r, v.end()); - Rotate vector r times left;
// auto p = equal_range(all(a), x); - gives pair of {lowerbound, upperbound} of x in array;

constexpr ld PI = 3.1415926535897932384626L, E = 2.7182818284590452353602L;
constexpr ll INF = 1e18 + 9, MOD = 1e9 + 7, MOD1 = 998244353, MAX = 1e6 + 5;
ll PRIME[MAX+2], SPF[MAX+2], FACT[MAX+2], invFACT[MAX+2]; bool isPRIME[MAX+2];
vector<ll> Divs[MAX+2], prDivs[MAX+2], prDivsall[MAX+2];

inline void YES(bool F = true, bool S = false) { cout << (F ? (S ? "Yes\n" : "YES\n") : (S ? "No\n" : "NO\n")); }
inline void NO(bool F = true, bool S = false) { cout << (F ? (S ? "No\n" : "NO\n") : (S ? "Yes\n" : "YES\n")); }
template <typename T> inline ll minid(const T& v) { return (min_element(all(v)) - v.begin()); }
template <typename T> inline ll maxid(const T& v) { return (max_element(all(v)) - v.begin()); }
inline ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return ((a / gcd(a, b)) * b); }
bool isPrime(ll n) {
    if(n <= 1) return false; if(n <= 3) return true; if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i=5; i*i<=n; i+=6) { if(n % i == 0 || n % (i+2) == 0) return false; } return true;
}
void prime(ll n) {
    fill(isPRIME, isPRIME + n + 1, true); isPRIME[0] = isPRIME[1] = false; ll id = 0;
    for(ll i=2; i<=n; i++) { if(isPRIME[i]) { for(ll j=i*i; j<=n; j+=i) { isPRIME[j] = false; } } }
    for(ll i=2; i<=n; i++) { if(id < MAX && isPRIME[i]) { PRIME[id] = i; id++; } }
}
void compDivs(ll n) { for(ll i=1; i<=n; i++) { for(ll j=i; j<=n; j+=i) { Divs[j].push_back(i); } } }
void compPrDivs(ll n, bool unq = true) {
    for(ll i=2; i<=n; i++) if(SPF[i] == 0) {
        for(ll j=i; j<=n; j+=i) { if(SPF[j] == 0) { SPF[j] = i; } prDivs[j].push_back(i); }
    } if(!unq) { for(ll i=2; i<=n; i++) { ll x = i; while(x > 1) { prDivsall[i].push_back(SPF[x]); x /= SPF[x]; } } }
}
vector<ll> getDivs(ll n) {
    vector<ll> divs; for(ll i=1; i*i<=n; i++) if(n % i == 0) { divs.push_back(i); if(i * i != n) { divs.push_back(n/i); } }
    return divs;
}
vector<ll> getPrDivs(ll n, bool unq = true) {
    vector<ll> prdivs;
    for(ll i=2; i*i<=n; i++) if(n % i == 0) {
        if(unq) { prdivs.push_back(i); } while(n % i == 0) { if(!unq) { prdivs.push_back(i); } n /= i; }
    } if(n > 1) { prdivs.push_back(n); } return prdivs;
}
inline ll power(ll a, ll b, ll mod = MOD) {
    ll ans = 1; a %= mod; while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; } return ans;
}
inline bool isPowOfTwo(ll n) { return ((n > 0) && !(n & (n-1))); }
inline bool isPerfectSq(ll n) { if(n < 0) return false; ll sr = static_cast<ll>(sqrt(n)); return (sr*sr == n); }
inline ll modAdd(ll a, ll b, ll mod = MOD) { return ((a % mod + b % mod) % mod); }
inline ll modSub(ll a, ll b, ll mod = MOD) { return (((a % mod - b % mod) + mod) % mod); }
inline ll modMult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modInv(ll a, ll mod = MOD) { return power(a, mod-2, mod); }
inline ll modDiv(ll a, ll b, ll mod = MOD) { return modMult(a, modInv(b, mod), mod); }
inline void factorial(ll n, ll mod = MOD) {
    FACT[0] = invFACT[0] = 1; for(ll i=1; i<=n; i++) { FACT[i] = (FACT[i-1] * i) % mod; }
    invFACT[n] = modInv(FACT[n], mod); for(ll i=n-1; i>0; i--) { invFACT[i] = (invFACT[i+1] * (i+1)) % mod; }
}
inline ll nCr(ll n, ll r, ll mod = MOD) { if(r > n) return 0; return ((FACT[n] * ((invFACT[r] * invFACT[n-r]) % mod)) % mod); }
ll findMEX(const set<ll>& st) { ll mex=0; while(st.find(mex)!=st.end()) { mex++; } return mex; }
inline ll ask(ll x) { cout << "? " << x << endl; cout.flush(); ll result; cin >> result; return result; }
inline ll computeXOR(ll n) { if(n%4==0) return n; if(n%4==1) return 1; if(n%4==2) return (n+1); return 0; }
inline ll cntSetBit(ll n) { return (__builtin_popcountll(n)); }
inline ll msbPos(ll n) { if(n == 0) { return -1; } return (63 - (__builtin_clzll(n))); }
inline ll getBit(ll n, ll pos) { return ((n >> pos) & 1); }
inline ll setBit(ll n, ll pos) { return (n | (1LL << pos)); }
inline ll clearBit(ll n, ll pos) { return (n & (~(1LL << pos))); }
inline ll toggleBit(ll n, ll pos) { return (n ^ (1LL << pos)); }
inline ll updateBit(ll n, ll pos, ll bit) { return (n & (~(1LL << pos)) | (bit << pos)); }
bool comp(const pll& a, const pll& b) { return a.ss < b.ss; }
void init() {}

//==========^==========<<   C O D E   B Y   R A J  P A T E L   >>==========^==========//

void solve(ll tt) {
    in(ll, n, m);
    vin(ll, a, n);
    vvll dp(n+1, vll(m+1));

    // dp[i][j] -> i elements with last element = j;
    fo(m) if(a[0] == i+1 || !a[0]) dp[1][i+1] = 1;
    fo(i, 2, n+1) fo(j, 1, m+1) {
        if(a[i-1] && a[i-1] != j) dp[i][j] = 0;
        else {
            dp[i][j] = modAdd(dp[i][j], dp[i-1][j]);
            if(j-1 >= 1 && j-1 <= m) dp[i][j] = modAdd(dp[i][j], dp[i-1][j-1]);
            if(j+1 >= 1 && j+1 <= m) dp[i][j] = modAdd(dp[i][j], dp[i-1][j+1]);
        }
    }
    ll ans = 0;
    fo(m) ans = modAdd(ans, dp[n][i+1]);
    out(ans);   
}

signed main() {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("D:/Code_PlayGround/C++/Input.txt", "r", stdin);
    //     freopen("D:/Code_PlayGround/C++/Output.txt", "w", stdout);
    //     freopen("D:/Code_PlayGround/C++/Debug.txt", "w", stderr);
    // #endif
    ll tt = 1; // cin >> tt;
    init();
    fo(tt) solve(i);
    return 0;
}
