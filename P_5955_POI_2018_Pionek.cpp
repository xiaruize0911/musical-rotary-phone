// Author: xiaruize
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "On Line:" << __LINE__ << #x << "=" << x << endl
bool start_of_memory_use;
#else
#define debug(x)
#endif
#include <bits/stdc++.h>
namespace __DEBUG_UTIL__
{
	using namespace std;
	/* Primitive Datatypes Print */
	void print(const char *x) { cerr << x; }
	void print(bool x) { cerr << (x ? "T" : "F"); }
	void print(char x) { cerr << '\'' << x << '\''; }
	void print(signed short int x) { cerr << x; }
	void print(unsigned short int x) { cerr << x; }
	void print(signed int x) { cerr << x; }
	void print(unsigned int x) { cerr << x; }
	void print(signed long int x) { cerr << x; }
	void print(unsigned long int x) { cerr << x; }
	void print(signed long long int x) { cerr << x; }
	void print(unsigned long long int x) { cerr << x; }
	void print(float x) { cerr << x; }
	void print(double x) { cerr << x; }
	void print(long double x) { cerr << x; }
	void print(string x) { cerr << '\"' << x << '\"'; }
	template <size_t N>
	void print(bitset<N> x) { cerr << x; }
	void print(vector<bool> v)
	{ /* Overloaded this because stl optimizes vector<bool> by using
		  _Bit_reference instead of bool to conserve space. */
		int f = 0;
		cerr << '{';
		for (auto &&i : v)
			cerr << (f++ ? "," : "") << (i ? "T" : "F");
		cerr << "}";
	}
	/* Templates Declarations to support nested datatypes */
	template <typename T>
	void print(T &&x);
	template <typename T>
	void print(vector<vector<T>> mat);
	template <typename T, size_t N, size_t M>
	void print(T (&mat)[N][M]);
	template <typename F, typename S>
	void print(pair<F, S> x);
	template <typename T, size_t N>
	struct Tuple;
	template <typename T>
	struct Tuple<T, 1>;
	template <typename... Args>
	void print(tuple<Args...> t);
	template <typename... T>
	void print(priority_queue<T...> pq);
	template <typename T>
	void print(stack<T> st);
	template <typename T>
	void print(queue<T> q);
	/* Template Datatypes Definitions */
	template <typename T>
	void print(T &&x)
	{
		/*  This works for every container that supports range-based loop
			i.e. vector, set, map, oset, omap, dequeue */
		int f = 0;
		cerr << '{';
		for (auto &&i : x)
			cerr << (f++ ? "," : ""), print(i);
		cerr << "}";
	}
	template <typename T>
	void print(vector<vector<T>> mat)
	{
		int f = 0;
		cerr << "\n~~~~~\n";
		for (auto &&i : mat)
		{
			cerr << setw(2) << left << f++, print(i), cerr << "\n";
		}
		cerr << "~~~~~\n";
	}
	template <typename T, size_t N, size_t M>
	void print(T (&mat)[N][M])
	{
		int f = 0;
		cerr << "\n~~~~~\n";
		for (auto &&i : mat)
		{
			cerr << setw(2) << left << f++, print(i), cerr << "\n";
		}
		cerr << "~~~~~\n";
	}
	template <typename F, typename S>
	void print(pair<F, S> x)
	{
		cerr << '(';
		print(x.first);
		cerr << ',';
		print(x.second);
		cerr << ')';
	}
	template <typename T, size_t N>
	struct Tuple
	{
		static void printTuple(T t)
		{
			Tuple<T, N - 1>::printTuple(t);
			cerr << ",", print(get<N - 1>(t));
		}
	};
	template <typename T>
	struct Tuple<T, 1>
	{
		static void printTuple(T t) { print(get<0>(t)); }
	};
	template <typename... Args>
	void print(tuple<Args...> t)
	{
		cerr << "(";
		Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
		cerr << ")";
	}
	template <typename... T>
	void print(priority_queue<T...> pq)
	{
		int f = 0;
		cerr << '{';
		while (!pq.empty())
			cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
		cerr << "}";
	}
	template <typename T>
	void print(stack<T> st)
	{
		int f = 0;
		cerr << '{';
		while (!st.empty())
			cerr << (f++ ? "," : ""), print(st.top()), st.pop();
		cerr << "}";
	}
	template <typename T>
	void print(queue<T> q)
	{
		int f = 0;
		cerr << '{';
		while (!q.empty())
			cerr << (f++ ? "," : ""), print(q.front()), q.pop();
		cerr << "}";
	}
	/* Printer functions */
	void printer(const char *) {} /* Base Recursive */
	template <typename T, typename... V>
	void printer(const char *names, T &&head, V &&...tail)
	{
		/* Using && to capture both lvalues and rvalues */
		int i = 0;
		for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
			if (names[i] == '(' or names[i] == '<' or names[i] == '{')
				bracket++;
			else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
				bracket--;
		cerr.write(names, i) << " = ";
		print(head);
		if (sizeof...(tail))
			cerr << " ||", printer(names + i + 1, tail...);
		else
			cerr << "]\n";
	}
	/* PrinterArr */
	void printerArr(const char *) {} /* Base Recursive */
	template <typename T, typename... V>
	void printerArr(const char *names, T arr[], size_t N, V... tail)
	{
		size_t ind = 0;
		for (; names[ind] and names[ind] != ','; ind++)
			cerr << names[ind];
		for (ind++; names[ind] and names[ind] != ','; ind++)
			;
		cerr << " = {";
		for (size_t i = 0; i < N; i++)
			cerr << (i ? "," : ""), print(arr[i]);
		cerr << "}";
		if (sizeof...(tail))
			cerr << " ||", printerArr(names + ind + 1, tail...);
		else
			cerr << "]\n";
	}
}
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
clock_t start_clock = clock();
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define ull unsigned long long
#define ALL(a) (a).begin(), (a).end()
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pis pair<int, string>
#define sec second
#define fir first
#define sz(a) int((a).size())
#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl
#define mms(arr, n) memset(arr, n, sizeof(arr))
#define rep(i, a, n) for (int i = (a); i <= (n); ++i)
#define per(i, n, a) for (int i = (n); i >= (a); --i)
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;
const int N = 4e5 + 10;
const double PI = acos(-1);

struct node
{
	int x, y;
	double ang;
} s[N];
int n;

bool cmp(node a, node b)
{
	return a.ang < b.ang;
}

void solve()
{
	cin >> n;
	rep(i, 1, n)
	{
		cin >> s[i].x >> s[i].y;
		s[i].ang = atan2(s[i].y, s[i].x);
	}
	sort(s + 1, s + n + 1, cmp);
	rep(i, 1, n) s[i + n] = {s[i].x, s[i].y, s[i].ang + PI * 2};
	int x = 0, y = 0;
	int res = 0;
	for (int l = 1, r = 1; l <= n; l++)
	{
		while (r < n + l && s[r].ang - s[l].ang < PI)
		{
			x += s[r].x;
			y += s[r].y;
			res = max(res, (x * x + y * y));
			r++;
		}
		x -= s[l].x;
		y -= s[l].y;
		res = max(res, (x * x + y * y));
	}
	cout << res << endl;
}

#ifndef ONLINE_JUDGE
bool end_of_memory_use;
#endif

signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase = 1;
	// cin >> testcase;
	while (testcase--)
		solve();
#ifndef ONLINE_JUDGE
	cerr << "Memory use:" << (&end_of_memory_use - &start_of_memory_use) / 1024.0 / 1024.0 << "MiB" << endl;
	cerr << "Time use:" << (double)clock() / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
#endif
	return 0;
}
