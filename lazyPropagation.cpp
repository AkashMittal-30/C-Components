#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second

const ll mod = 1e9 + 7;

class SegmentTree {

	int*tree, *lazy;
	int N, s, e;

public:

	SegmentTree(int N) {
		this -> N = N;
		tree = new int[4*N + 1];
		lazy = new int[4*N + 1];
	}

	void build(int*arr, int s, int e, int ind) {

		if(s == e) {
			tree[ind] = arr[s];
			return;
		}

		int mid = (s + e) >> 1;
		build(arr, s, mid, 2*ind);
		build(arr, mid + 1, e, 2*ind + 1);

		tree[ind] = min(tree[2*ind], tree[2*ind + 1]);
		return;
	}

	int query(int s, int e, int qs, int qe, int ind) {

		//resolve the lazy value
		if(lazy[ind] != 0) {
			tree[ind] += lazy[ind];

			if(s != e) {
				lazy[2*ind] += lazy[ind];
				lazy[2*ind + 1] += lazy[ind];
			}

			lazy[ind] = 0;
		}

		if(qe < s || qs > e) {
			return INT_MAX;
		}

		if(s >= qs && e <= qe) {
			return tree[ind];
		}

		int mid = (s + e) >> 1;
		int left = query(s, mid, qs, qe, 2*ind);
		int right = query(mid + 1, e, qs, qe, 2*ind + 1);

		return min(left, right);
	}

	void rangeUpdate(int s, int e, int qs, int qe, int val, int ind) {

		//before going down resolve lazy values
		if(lazy[ind] != 0) {
			tree[ind] += lazy[ind];

			if(s != e) { //non-leaf node so pass lazy val of parent to its children
				lazy[2*ind] += lazy[ind];
				lazy[2*ind + 1] += lazy[ind];
			}

			lazy[ind] = 0; // clear the lazy val
		}

		if(qe < s || qs > e) { //no overlap
			return;
		}

		if(s <= qs && e >= qe) { //complete overlap
			tree[ind] += val;
			if(s != e) {
				lazy[2*ind] += val;
				lazy[2*ind + 1] += val;
			}
			return;
		}

		int mid = (s + e) >> 1;
		rangeUpdate(s, mid, qs, qe, val, 2*ind);
		rangeUpdate(mid + 1, e, qs, qe, val, 2*ind + 1);

		tree[ind] = min(tree[2*ind], tree[2*ind + 1]);
		return;
	}

	void pointUpdate(int s, int e, int ind, int pos, int val) {
		rangeUpdate(s, e, pos, pos, val, ind);
		return;
	}

	void output() {

		for(int i = 0; i < 4*N + 1; ++i) {
			printf("%d ", tree[i]);
		}
		printf("\n");
		return;
	}

};

int main() {

	int N = 6;
	int arr[] = {1, 3, 2, -5, 6, 4};

	SegmentTree tree(6);

	tree.build(arr, 0, N - 1, 1);

	int Q;
	scanf("%d", &Q);

	while(Q--) {

		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if(t == 1) {
			int ans = tree.query(0, N - 1, l, r, 1);
			printf("%d\n", ans);
		} else {
			tree.rangeUpdate(0, N - 1, l, r, 5, 1);
			puts("updated");
		}

	}

	return 0;
}