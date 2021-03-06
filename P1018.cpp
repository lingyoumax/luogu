#include<iostream>
#include<string>
using namespace std;
string n;
int k;
string ans[41][7];
string mult(string a, string b) {//两个高精度的乘法
	string c = "";
	int as = a.size();
	int bs = b.size();
	if ((!as) || (!bs)) {
		return c;
	}
	int size = as + bs;
	for (int i = 0;i < size;i++) {
		c += "0";
	}
	for (int i = (as-1);i >= 0;i--) {
		for (int j = (bs-1);j >=0;j--) {
			int k = i + j + 1;
			char aa = a[i];
			char bb = b[j];
			int ai = aa - '0';
			int bi = bb - '0';
			int ab = ai * bi;
			while (ab != 0) {
				char cc = c[k];
				int ci = cc - '0';
				ci += ab;
				ab = ci / 10;
				ci = ci % 10;
				char sc = '0' + ci;
				c[k] = sc;
				k--;
			}
		}
	}
	while ((c.size() > 1) && (c[0] == '0')) {
		c.erase(0, 1);
	}
	return c;
}
string max(string a, string b) {//求最大的值
	if (a.size() > b.size()) {
		return a;
	}
	if (b.size() > a.size()) {
		return b;
	}
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {
	int n;
	int k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 1;i <= n;i++) {
		ans[i][0] = s.substr(0, i);
	}
	for (int i = 1;i <= k;i++) {
		for (int j = 1;j <= n;j++) {
			for (int m = 1;m < j;m++) {
				ans[j][i] = max(ans[j][i], mult(ans[m][i - 1], s.substr(m , j - m)));
			}
		}
	}
	cout << ans[n][k];
	return 0;
}
