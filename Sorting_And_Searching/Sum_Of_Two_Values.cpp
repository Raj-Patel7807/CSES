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

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
#define int ll
#define double ld
template <typename T, typename V> using pr = pair<T, V>;
template <typename T> using vc = vector<T>;
template <typename T, typename V> using umap = unordered_map<T, V>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using pqmax = priority_queue<T>;
template <typename T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using idset = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// For `idset`:
//     find_by_order(k) - O(log n) - Find the k-th smallest element (0-based index);
//     order_of(value) - O(log n) - Find the index of a value in the sorted set;
//     Can find the k-th smallest element, or get the position of a value in sorted order;

#define endl '\n'
#define ln cout << '\n';
#define PUSH push_back
#define POP pop_back
#define FF first
#define SS second
#define LEN(x) (ll)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FOR1(s) for(ll i=0; i<(s); ++i)
#define FOR2(i, s) for(ll i=0; i<(s); ++i)
#define FOR3(i, s, e) for(ll i=(s); i<(e); ++i)
#define FOR4(i, s, e, inc) for(ll i=(s); i<(e); i+=(inc))
#define FORR1(s) for(ll i=(s)-1; i>=0; --i)
#define FORR2(i, s) for(ll i=(s)-1; i>=0; --i)
#define FORR3(i, s, e) for(ll i=(s)-1; i>=(e); --i)
#define FORR4(i, s, e, dec) for(ll i=(s)-1; i>=e; i-=dec)
#define GET_FOR(a, b, c, d, LOOP, ...) LOOP
#define FOR(...) GET_FOR(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(...) GET_FOR(__VA_ARGS__, FORR4, FORR3, FORR2, FORR1)(__VA_ARGS__)
#define FORE(x, a) for(auto& x : (a))

template <typename... T> inline void INPUT(T&... args) { ((cin >> args), ...); }
template <typename... T> inline void OUTPUT(bool F, T&&... args) { ((cout << args << (F ? '\n' : ' ')), ...); }
#define IN(T, ...) T __VA_ARGS__; INPUT(__VA_ARGS__);
#define OUT(...) OUTPUT(true, __VA_ARGS__);
#define OUTT(...) OUTPUT(false, __VA_ARGS__);
#define VIN(T, name, n) vector<T> name(n); for(auto& x : name) cin >> x;
#define VVIN(T, name, n, m) vector<vector<T>> name(n, vector<T>(m)); FOR(i, n) FOR(j, m) cin >> name[i][j];
#define VOUT(a) for(auto x : a) { cout << x << ' '; } cout << '\n';
// rotate(v.begin(), v.end()-r, v.end()); - Rotate vector r times right;
// rotate(v.begin(), v.begin()+r, v.end()); - Rotate vector r times left;

constexpr ld PI = 3.1415926535897932384626L, E = 2.7182818284590452353602L;
constexpr ll INF = 1e18 + 9, MOD = 1e9 + 7, MOD1 = 998244353, MAX = 1e6+5;
ll PRIME[MAX], FACT[MAX], invFACT[MAX]; bool isPRIME[MAX];
vector<vector<ll>> Divisors(MAX);

inline void YES(bool F = true, bool S = false) { cout << (F ? (S ? "Yes\n" : "YES\n") : (S ? "No\n" : "NO\n")); }
inline void NO(bool F = true, bool S = false) { cout << (F ? (S ? "No\n" : "NO\n") : (S ? "Yes\n" : "YES\n")); }
template <typename T> inline ll minid(const vector<T>& v) { return (min_element(all(v)) - v.begin()); }
template <typename T> inline ll maxid(const vector<T>& v) { return (max_element(all(v)) - v.begin()); }
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
vector<ll> getPrimeDivisors(ll n){
    vector<ll> primeDivisors;
    for(ll i=2; i*i<=n; i++) { while(n % i == 0) { primeDivisors.push_back(i); n /= i; } }
    if(n > 1) { primeDivisors.push_back(n); } return primeDivisors;
}
void precomputeDivisors(ll n) {
    for(ll i=1; i<=n; i++) { for(ll j=i; j<=n; j+=i) { Divisors[j].push_back(i); } }
}
inline ll power(ll a, ll b, ll mod = MOD) {
    ll ans = 1; a %= mod;
    while(b > 0) { if(b & 1) { ans = (ans * a) % mod; } a = (a * a) % mod; b >>= 1; }
    return ans;
}
inline bool isPowOfTwo(ll n) { return ((n > 0) && !(n & (n-1))); }
inline bool isPerfectSq(ll n) {
    if(n < 0) return false; ll sr = static_cast<ll>(sqrt(n)); return (sr*sr == n);
}
inline ll modAdd(ll a, ll b, ll mod = MOD) { return ((a % mod + b % mod) % mod); }
inline ll modSub(ll a, ll b, ll mod = MOD) { return (((a % mod - b % mod) + mod) % mod); }
inline ll modMult(ll a, ll b, ll mod = MOD) { return ((a % mod * b % mod) % mod); }
inline ll modInv(ll a, ll mod = MOD) { return power(a, mod-2, mod); }
inline ll modDiv(ll a, ll b, ll mod = MOD) { return modMult(a, modInv(b, mod), mod); }
inline void factorial(ll n, ll mod = MOD) {
    FACT[0] = invFACT[0] = 1; for(ll i=1; i<=n; i++) { FACT[i] = (FACT[i-1] * i) % mod; }
    invFACT[n] = modInv(FACT[n], mod); for(ll i=n-1; i>0; i--) { invFACT[i] = (invFACT[i+1] * (i+1)) % mod; }
}
inline ll nCr(ll n, ll r, ll mod = MOD) {
    if(r > n) return 0; factorial(n, mod);
    return (FACT[n] * ((invFACT[r] * invFACT[n-r]) % mod)) % mod;
}
class DSU {
private :
    vector<ll> parent, size, edge;
public :
    DSU(ll n) {
        parent.resize(n + 1); size.assign(n + 1, 1);
        edge.assign(n+1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(ll x, ll y) {
        x = find(x), y = find(y);
        if(x != y) {
            if(size[x] < size[y]) { swap(x, y); }
            parent[y] = x; size[x] += size[y];
            edge[x] += edge[y] + 1;
        } else { edge[x]++; }
    }
    ll componentCount(ll n) {
        ll count = 0;
        for(ll i=1; i<=n; ++i) { if(find(i) == i) ++count; }
        return count;
    }
    bool isSame(ll x, ll y) { return find(x) == find(y); }
    ll getSize(ll x) { return size[find(x)]; }
    ll getEdgeCount(ll x) { return edge[find(x)]; }
};
void BFS(ll root, vector<vector<ll>> &graph, vector<ll> &visited) {
    queue<ll> q; q.push(root); visited[root] = 1;
    while(!q.empty()) { ll node = q.front(); q.pop();
        for(ll neighbor : graph[node]) {
            if(!visited[neighbor]) { visited[neighbor] = 1; q.push(neighbor); }
        }
    }
}
void DFS(ll node, vector<vector<ll>> &graph, vector<ll> &visited) {
    visited[node] = 1;
    for(ll neighbor : graph[node]) { if(!visited[neighbor]) { DFS(neighbor, graph, visited); } }
}
ll findMEX(const set<ll>& st) { ll mex=0; while(st.find(mex)!=st.end()) { mex++; } return mex; }
inline ll ask(ll x) {
    cout << "? " << x << endl; cout.flush();
    ll result; cin >> result; return result;
}
inline void answer(ll x) { cout << "! " << x << endl; cout.flush(); }
inline ll computeXOR(ll n) { if(n%4==0) return n; if(n%4==1) return 1; if(n%4==2) return (n+1); return 0; }
inline ll cntSetBit(ll n) { return (__builtin_popcountll(n)); }
inline ll msbPos(ll n) { if(n == 0) { return -1; } return (63 - (__builtin_clzll(n))); }
inline ll getBit(ll n, ll pos) { return ((n >> pos) & 1); }
inline ll setBit(ll n, ll pos) { return (n | (1 << pos)); }
inline ll clearBit(ll n, ll pos) { return (n & (~(1 << pos))); }
inline ll toggleBit(ll n, ll pos) { return (n ^ (1 << pos)); }
inline ll updateBit(ll n, ll pos, ll bit) { return (n & (~(1 << pos)) | (bit << pos)); }
inline ll TT(bool flag = false) { ll tt = 1; if(flag) { cin >> tt; } return tt; }
inline void SETUP_IO(bool FILE_IO = true) {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    if(FILE_IO) {
        #ifndef ONLINE_JUDGE
            freopen("D:/Code_PlayGround/C++/Input.txt", "r", stdin);
            freopen("D:/Code_PlayGround/C++/Output.txt", "w", stdout);
            freopen("D:/Code_PlayGround/C++/Debug.txt", "w", stderr);
        #endif
    }
}

//==========^==========<<   C O D E   B Y   R A J  P A T E L   >>==========^==========//

void Raj_Patel_7807(ll tt) {
    IN(ll, n, k); VIN(ll, a, n);
    map<ll, ll> mp;
    FOR(n) {
        ll x = k - a[i];
        if(mp.count(x)) {
            OUTT(min(mp[x]+1, i+1), max(mp[x]+1, i+1)); ln; return;
        } mp[a[i]] = i;
    } OUT("IMPOSSIBLE");
}

signed main() {
    SETUP_IO(); ll tt = TT();
    FOR(i, tt) Raj_Patel_7807(i);
    return 0;
}
