// Алгоритм кодирования Шеннона-Фано
// Автор: Петров К.А. (10.12.2020)
// Компилятор g++.exe (gcc-2.95.2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

// Функция для сортировки вектора по второму аргументу пары

bool comp(const pair<char,double> &a, const pair<char,double> &b) {
	return a.second > b.second;
}

// Первые l цифр двоичной записи вещественного числа

string toBIN(double x, int l) {
	string BIN = "";
	for (int i = 0; i != l; i++) {
		x = x * 2;
		if (x < 1) BIN += '0'; 
		else {
			BIN += '1';
			x -= 1;
		}
	}
	return BIN;
} 

//  Функция для вычисления кода Шеннона-Фано

vector<pair<char,string> > ShFano(const vector< pair<char,double> > &v) {
	vector<pair<char,string> > a;
	vector<double> q;
	q.push_back(0); 
	for (int i = 1; i != v.size(); i++) {
		q.push_back(q[i-1] + v[i-1].second);
	}
	int l;
	for (int i = 0; i != v.size(); i++) {
		l = (int)ceil(-(log10(v[i].second)/log10(2)));
		string BIN = toBIN(q[i],l);
		pair<char,string> t(v[i].first,BIN);
		a.push_back(t);
	}
	return a;
}

// Функция вывода кода на экран

void print(const vector< pair<char,string> > &r) {
	cout << "[ ";
	for (int i = 0; i != r.size(); i++)
		cout << "('" << r[i].first << "'," << r[i].second << ") ";
	cout << "]" << endl;
}

// Функция вывода на экран списка частот

void print0(vector< pair<char,double> > &r) {
	cout << "[ ";
	for (int i = 0; i != r.size(); i++)
		cout << "('" << r[i].first << "'," << r[i].second << ") ";
	cout << "]" << endl;
}

// Основная функция

int main() {
	int n; char a, k; double b, s;
	do {
		cout << "Введите кол-во букв: ";
		cin >> n;
		if (n < 1) return 1;
		vector< pair<char,double> > v(n);
		vector< pair<char,string> > r;
		cout << "Ввод пар осуществляется через пробел" << endl;
		for (int i = 0; i != n; i++) {
			cout << "Пара " << i+1 << ": ";
			cin >> a >> b;
			v[i].first = a;
			v[i].second = b;
		}
		sort(v.begin(),v.end(),comp);
		r = ShFano(v);
		cout << "Результат:" << endl;
		print0(v);
		print(r);
		cout << "Продолжить ввод?(y/n) > ";
		cin >> k;
		} while (k == 'y');
	return 0;
}