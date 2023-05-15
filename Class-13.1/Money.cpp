#include "Money.h"
#include <iostream>
#include <vector>
using namespace std;
Money::Money()
{
	rubles = 0;
	kopecks = 0;
}
Money::Money(long r, int k)
{
	rubles = r;
	if (k < 100)
	{
		kopecks = k;
	}
	else
	{
		rubles = rubles + k / 100;
		kopecks = k % 100;
	}
}
Money::Money(const Money& m)
{
	rubles = m.rubles;
	kopecks = m.kopecks;
}

long Money::GetMoneyR()
{
	return rubles;
}
int Money::GetMoneyK()
{
	return kopecks;
}

void Money::SetMoney(long r, int k)
{
	rubles = r;
	kopecks = k;
}

Money& Money::operator*(const Money& m)
{
	int s = (kopecks + rubles * 100) * (m.kopecks + m.rubles * 100);
	rubles = s / 100;
	kopecks = s % 100;
	return *this;
}
Money& Money::operator/(const int n)
{
	int S = rubles * 100 + kopecks;
	S = S / n;
	rubles = S / 100;
	kopecks = S % 100;
	return *this;

}
Money& Money::operator+(const Money& m)
{
	if (kopecks + m.kopecks > 100)
	{
		rubles = rubles + m.rubles + (kopecks + m.kopecks) / 100;
		kopecks = (kopecks + m.kopecks) % 100;
	}
	else
	{
		rubles += m.rubles;
		kopecks += m.kopecks;
	}
	return *this;
}
Money& Money::operator = (const Money& m)
{
	rubles = m.rubles;
	kopecks = m.kopecks;
	return *this;
}
Money& Money::operator -- ()
{
	kopecks = kopecks - 1;
	return *this;
}
Money& Money::operator--(int)
{
	kopecks = kopecks - 1;
	return *this;
}


ostream& operator << (ostream& out, const Money& p)
{
	return(out << p.rubles << ", " << p.kopecks);
}
istream& operator >> (istream& in, Money& p)
{
	in >> p.rubles;
	in >> p.kopecks;
	return in;
}

bool Money::operator!=(const Money& m)
{
	if (this->rubles != m.rubles)
	{
		return 1;
	}
	else
	{
		if (this->kopecks != m.kopecks)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
bool Money::operator==(const Money& m)
{
	if (this->rubles == m.rubles)
	{
		if (this->kopecks == m.kopecks)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

bool Money:: operator <(const Money& m)
{
	if (this->rubles < m.rubles)
	{
		return 1;
	}
	else
	{
		if (this->rubles == m.rubles)
		{
			if (this->kopecks < m.kopecks)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
}

Money Money::srednee(vector<Money> M)
{
	Money m;

	for (int i = 0; i < M.size();i++)
		m = m + M[i];
	int n = M.size();
	return m / n;
}