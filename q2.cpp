#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main () {
	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		ll a[n];

		for (ll i=0 ; i<n ; i++) cin >> a[i];





		// Condition when the given sequence is in AP

		int flag=0;

		ll diff = (a[1]-a[0]);

		for (ll i=1; i<n ; i++) {
			if ((a[i]-a[i-1])!=diff) {
				flag=1;
				break;
			}
		}

		if (flag==0) {
			for (ll i=0 ; i<n ; i++) cout << a[i] << " ";
			cout << endl;
			// cout << "s1" << endl;
			continue;
		}

		// End of Part 1









		// Condition when last element is the wrong one (Part 2)

		flag=0;

		diff = (a[1]-a[0]);

		for (ll i=1 ; i<(n-1) ; i++) {
			if ((a[i]-a[i-1]) != diff) {
				flag=1;
				break;
			}
		}




		if (flag==0) {

			a[n-1] = a[0] + ((n-1)*diff);

			for (ll i=0 ; i<n ; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			// cout << "s2" << endl;
			continue;

		}



		// End of Part 2











		ll diff1=-1, freq1=0, diff2=-1, freq2=0;

		ll temp_diff=-1;

		flag=0;

		double temp_diff_1 = 0;

		ll idx=-1;


		for (ll i=0 ; i<(n-1) ; i++) {

			temp_diff = (a[n-1]-a[i])/(n-1-i);


			temp_diff_1 = (double)(a[n-1]-a[i])/(n-1-i);

			if (floor(temp_diff_1) != ceil(temp_diff_1)) {
				flag=1;
				idx = i;
				break;
			}

			if (diff1==-1) {
				diff1 = temp_diff;
				freq1++;
				continue;
			}



			else if (diff1 == temp_diff) {
				freq1++;
				continue;
			}



			else {
				diff2 = temp_diff;
				freq2++;
				continue;
			}


		}


		// Corner Case Code

		if (flag==1) {


			ll diff3=0;

			for (ll i=0 ; i<(n-1) ; i++) {
				if (i!=idx) {
					diff3 = (a[n-1]-a[i])/(n-1-i);
					break;
				}
			}


			a[idx] = a[n-1] - (diff3*(n-1-idx));

			for (ll i=0 ; i<n ; i++) {
				cout << a[i] << " ";
			}

			cout << endl;

			continue;


		}


		// End of Corner Case Code











		ll max_diff=0;

		if (freq1 >= freq2) max_diff = diff1;
		else max_diff = diff2;



		for (ll i=0 ; i<(n-1) ; i++) {
			if (((a[n-1]-a[i])/(n-1-i))  != max_diff ) {
				a[i] = a[n-1] - (max_diff*(n-1-i));
			}
		}


		for (ll i=0 ; i<n ; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		// cout << "s3" << endl;



	}
}




// Corner case : When does it have 2 possible answers ?

