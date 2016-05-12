#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


ll period_length = 2;
vector<ll> fib_mods = {0, 1};
vector<int> fibs = {0, 1};

int calc_fib(int n) {
    if (n > 1) {
    	for (int i = 2; i < n + 1; ++i) {
    		fibs.push_back(fibs[i-1] + fibs[i-2]);
    	}
    }
    return fibs[n];
}

ll calc_fib_mods(ll m) {
	ll fib_0 = 0;
	ll fib_1 = 1;
	ll fib_0_old;
	for (ll i = 0; i < (m * m) + 1; ++i) {
		if ((fib_1 == 1 && fib_0 == 0) && period_length > 2) {
    		return period_length;
    	}
		fib_0_old = fib_0;
    	fib_0 = fib_1;
    	fib_1 = (fib_0_old % m) + (fib_0 % m);
    	cout << fib_1 << ' ';
    	period_length++;
	}

   //  if (n > 1) {
   //  	for (ll i = 2; i < (m ^ 2); ++i) {
   //  		fib_0_old = fib_0;
   //  		fib_0 = fib_1;
   //  		fib_1 = (fib_0_old % m) + (fib_1 % m);
   //  		// fib_1 = (((fib_0_old % m) + m) % m) + (((fib_1 % m) + m) % m);
   //  		cout << fib_1 << ' ';
			// // fibs.push_back(fibs[i-1] + fibs[i-2]);
			// fib_mods.push_back(fib_1);
			// // cout << fib_mods[i] << ' ';
			// if ((fib_mods[i] == 1 && fib_mods[i-1] == 0) && fib_mods.size() > 2) {
   //  			vector<ll>::const_iterator first = fib_mods.begin();
   //  			vector<ll>::const_iterator last = fib_mods.begin() + (fib_mods.size() - 2);
   //  			vector<ll> mod_seq(first, last);
   //  			return mod_seq;
   //  		}
   //  	}
   //  }
   //  return fib_mods;
}

ll get_fibonaccihuge(ll n, ll m) {
	// vector<ll> mods(calc_fib_mods(n, m));
	ll period_length = calc_fib_mods(m);
	cout << "period length: " << period_length << endl;
	

	// vector<ll>::iterator v = mods.begin();
	// while (v != mods.end()) {
	// 	cout << *v << ' ';
	// 	v++;
	// }
	// cout << '\n';
	return calc_fib(n % period_length) % m;
	// return mods[n % mods.size()] % m;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << get_fibonaccihuge(n, m) << '\n';
}

// start calculating all mods from 0 to n
// stop when '01' sequence detected and length greater than 2