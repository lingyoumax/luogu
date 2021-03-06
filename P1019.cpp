#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
string word[30];
int jc[30][30];
int use[30];
stack<int> sw;
int n;
char c;
int lianjie(int i, int j) {
	string a = word[i];
	string b = word[j];
	int size = min(a.size(), b.size());
	for (int i = 1;i < size;i++) {
		bool flag = true;
		for (int j = 0;j < i;j++) {
			if (a[a.size() - i + j] != b[j]) {
				flag = false;
			}
		}
		if (flag) {
			return i;
		}
	}
	return 0;
}
void yuchuli(int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			jc[i][j] = lianjie(i, j);
		}
	}
}
int dfs(int i) {
	int len = 0;
	int l = 0;
	stack<int> mystack;
	use[i]++;
	mystack.push(i);
	len += word[i].size();
	l = len;
	int begin = -1;
	while (true) {
		int j = begin + 1;
		while (j < n) {
			if ((use[j]<2) && (jc[mystack.top()][j])) {
				break;
			}
			j++;
		}
		if (j >= n) {
			len = max(len, l);
			begin = mystack.top();
			use[begin]--;
			l -= word[begin].size();
			mystack.pop();
			if (mystack.empty()) {
				break;
			}
			l += jc[mystack.top()][begin];
			if ((mystack.top() == i)&&(mystack.size()==1)) {
				break;
			}
		}
		else {
			begin = -1;
			use[j]++;
			l -= jc[mystack.top()][j];
			mystack.push(j);
			l += word[j].size();
		}
	}
	use[i] = 0;
	return len;
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> word[i];
	}
	cin >> c;
	yuchuli(n);
	for (int i = 0;i < n;i++) {
		if (word[i][0] == c) {
			sw.push(i);
		}
	}
	int len = 0;
	while (!sw.empty()) {
		len = max(len, dfs(sw.top()));
		sw.pop();
	}
	cout << len << endl;
	return 0;
}
