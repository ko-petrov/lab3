// ������ ����஢���� ����
// ����: ���஢ �.�. (10.12.2020)
// ��������� g++.exe (gcc-2.95.2)
// new comment in the dark
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �㭪�� ��� ���஢�� ����� �� ��஬� ��㬥��� ����

bool comp(const pair<char,double> &a, const pair<char,double> &b) {
	return a.second > b.second;
}

// �㭪�� ��� ��宦����� �㬬� ����� ��㬥�⮢ ���� � �����

double summa(const vector< pair<char,double> > &v, int s1, int s2) {
	double sum = 0;
	for (int i = s1; i != s2; i++) sum += v[i].second;
	return sum;
}

// �����ᨢ��� �㭪�� ��� ���᫥��� ���� ����

void Fano(const vector< pair<char,double> > &v, int s1, int s2, string BIN,
				vector< pair<char,string> > &r) {
	if (s2 - s1 == 1) {
		pair<char,string> t(v[s1].first, BIN);
		r.push_back(t);
	}
	else {
		double sum = 0, sumpr = 0; int j;
		double sumsr = summa(v, s1, s2)/2;
		for (j = s1; sum < sumsr; j++) {
			sumpr = sum;
			sum += v[j].second;
		}
		if (sum - sumsr > sumsr - sumpr) j--;
		Fano(v, s1, j, BIN + '0', r);
		Fano(v, j, s2, BIN + '1', r);
	}
}

// �㭪�� �뢮�� �� �࠭ ����

void print(vector< pair<char,string> > &r) {
	cout << "[ ";
	for (int i = 0; i != r.size(); i++)
		cout << "('" << r[i].first << "'," << r[i].second << ") ";
	cout << "]" << endl;
}

// �㭪�� �뢮�� �� �࠭ ᯨ᪠ ����

void print0(vector< pair<char,double> > &r) {
	cout << "[ ";
	for (int i = 0; i != r.size(); i++)
		cout << "('" << r[i].first << "'," << r[i].second << ") ";
	cout << "]" << endl;
}

// �᭮���� �㭪��

int main() {
	int n; char a, k; double b, s;
	do {
		cout << "������ ���-�� �㪢: ";
		cin >> n;
		if (n < 1) return 1;
		vector< pair<char,double> > v(n);
		vector< pair<char,string> > r;
		cout << "���� ��� �����⢫���� �१ �஡��" << endl;
		for (int i = 0; i != n; i++) {
			cout << "��� " << i+1 << ": ";
			cin >> a >> b;
			v[i].first = a;
			v[i].second = b;
		}
		sort(v.begin(),v.end(),comp);
		string BIN = "";
		Fano(v, 0, n, BIN, r);
		cout << "�������:" << endl;
		print0(v);
		print(r);
		cout << "�த������ ����?(y/n) > ";
		cin >> k;
		} while (k == 'y');
	return 0;
}