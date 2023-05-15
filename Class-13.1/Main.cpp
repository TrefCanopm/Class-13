#include <iostream>
#include <vector>
#include "Money.h"
#include <algorithm>

using namespace std;

typedef vector <Money> Vec;
Money M;

Vec MVector(int n)
{
	Vec v;
	Money m;
	int k;
	long r;
	for (int i = 0; i < n; i++)
	{
		k = rand() % 100;
		r = rand() % 100;
		m.SetMoney(r, k);
		v.push_back(m);
	}
	return v;
}

void Print(vector<Money> m)
{
	for (int i = 0; i < m.size(); i++)
		cout << m[i] << endl;
	cout << "------------------------------------" << endl;
}

struct Greater_s
{
	bool operator() (Money m)
	{
		if (M < m)
			return false;
		else
			return true;
	}
};

struct Comp_less
{
	bool operator()(Money m, Money m1)
	{
		if (m1 < m)
			return true;
		else
			return false;
	}
};

struct Equal_s
{
	bool operator() (Money m)
	{
		return m == M;
	}
};

void del(Money& m)
{
	m = m * M;
}

int main()
{
	Vec v1, v;
	int n;
	cout << "Enter the size of the container" << endl;
	cin >> n;

	v1 = MVector(n);

	Vec::iterator i;

	i = min_element(v1.begin(), v1.end());
	Money mn = *(i);

	

	cout << "Sort in ascending order: " << endl;
	sort(v1.begin(), v1.end());
	Print(v1);

	i = max_element(v1.begin(), v1.end());
	Money mx = *i;
	M = mn;
	replace_if(v1.begin(), v1.end(), Greater_s(), mx);
	Print(v1);

	cout << "Search" << endl;
	cin >> M;
	i = find_if(v1.begin(), v1.end(), Equal_s()); // оставить
	if (i != v1.end())
		cout << *(i) << endl;
	else
		cout << "Not such element" << endl;

	cout << "Dell" << endl;
    M.srednee(v1);
	i = remove_if(v1.begin(), v1.end(), Equal_s());// не работает
	Print(v1);
	for (int k = 0; k < v1.size();k++)
	{
		if (!(M < v1[k]))
		{
			v.push_back(v1[k]);
		}
	}
	v1 = v;
	Print(v1);

	cout << "Domnozhenie" << endl;
	i = max_element(v1.begin(), v1.end());
	M = *(i);
	for_each(v1.begin(), v1.end(), del); // изменить название на умножение
	Print(v1);
}