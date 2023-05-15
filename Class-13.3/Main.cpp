#include<iostream>
#include <map>
#include<algorithm>

using namespace std;

int N;

typedef multimap<int, float> Mult;
typedef multimap<int, float>::iterator it;

Mult Mmap(int n)
{
	Mult m;
	for (int i = 0; i < n; i++)
	{
		m.insert(i, rand() % 100);
	}
	return m;
}
void Print(Mult m)
{
	it iter;
	for (iter = m.begin();iter != m.end(); iter++)
	{
		cout << iter->first + 1 << ") " << iter->second << endl;
	}
}

struct Mn
{
	bool operator ()(int i)
	{
		return i == N;
	}
};
Mult MapMn(Mult m)
{
	it i = min_element(m.begin(), m.end());
	float mn = i->second;

	cout << "" << endl;
	int n;
	cin >> n;

	N = n;
	replace_if(m.begin(), m.end(), Mn(), mn);
	return m;
}
Mult MapS(Mult m)
{
	it i;
	int n, n1 = 0;
	float s;
	for (i = m.begin(); i != m.end(); i++)
	{
		s += i->second;
		n = i->first + 1;
	}
	s = s / n;
	Mult m1;
	for (i = m.begin(); i != m.end(); i++)
	{
		if (s > i->second)
		{
			m1.insert(make_pair(n1, i->second));
			n1++;
		}
	}
	return m1;
}
Mult MapMax(Mult m)
{
	it i;
	i = max_element(m.begin(), m.end());
	float mx = i->second;

	for (i = m.begin(); i != m.end(); i++)
	{
		i->second = i->second * mx;
	}
	return m;
}

int main()
{
	int n;
	cout << "" << endl;
	cin >> n;

	Mult m;
	m = Mmap(n);
	Print(m);
	m = MapS(m);
	Print(m);
	m = MapMax(m);
	Print(m);
}
