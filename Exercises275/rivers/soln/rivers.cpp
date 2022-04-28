 /*---------------------------------------------------
 Name: Zamam Moeez
 ID: 1665264
 CMPUT 275 , Winter 2022
 CCID: zamam

 Exercise 4 Part 1: Rivers
 ---------------------------------------------------*/
#include <iostream>
using namespace std;

/* int query() takes a pointer a, pointing to the first
river a particular river joins, the n number of rivers,
and the query rivers u and v and returns val1 which is
where they intersect*/

int query(int* a, int n, int u, int v) {
	int val1 = u;  // first river is u
	int val2 = v;  // secod river is v
	for(int i = 0; i < n; i++) {
		if (val1 == val2) {  // if rivers are the same then break
			break;
		} else if (val1 < val2) {  // if first river is smaller
			val2 = *(a + val2 -1);  // move to next river connected by v
		} else if (val2 < val1) {
			val1 = *(a + val1 -1);  // else move to next river connected by u
		}
	}
	return val1;  // return where they connect
}

int main() {
	int n;
	int q;
	int u;
	int v;
	cin >> n;
	cin >> q;
	int* a = new int[n];  // declare dynamic array of rivers
	int* riv = new int[q];  // declare dynamic array of meeting points
	for(int i = 0; i < n; i++) {
		cin >> a[i];  // read in rivers
	}
	for(int i = 0; i < q; i++) {  // iterate through quueries
		cin >> u;
		cin >> v;
		riv[i] = query(a, n, u, v);  // store results in array
	}
	for(int i = 0; i < q; i++) {
		cout << riv[i] << endl;  // print results
	}
}
