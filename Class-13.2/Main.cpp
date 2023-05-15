#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef priority_queue<int> Pri;

Pri MQueue(int n)
{
	Pri p;
	for (int i = 0; i < n; i++)
		p.push(rand() % 100);
	return p;
}

void Print(Pri p)
{
	while (!p.empty())
	{
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}

Pri AddMin(Pri p)
{
	Pri p1 = p;
	int mn;
	while (!p1.empty())
	{
		mn = p1.top();
		p1.pop();
	}
	cout << "Enter the number to put the item on" << endl;
	int n;
	cin >> n;
	int k = 0;
	int temp;
	while (k != n)
	{
		temp = p.top();
		p1.push(temp);
		p.pop();
		k++;
	}
	p1.push(mn);
	while (!p.empty())
	{
		temp = p.top();
		p1.push(temp);
		p.pop();
	}
	return p1;
}

Pri Del(Pri p)
{
	int s = 0;
	Pri p1 = p;
	while (!p1.empty())
	{
		s += p1.top();
		p1.pop();
	}
	s = s / p.size();
	while (!p.empty())
	{
		if (p.top() < s)
		{
			p1.push(p.top());
		}
		p.pop();
	}
	return p1;
}

Pri M(Pri p)
{
	int mx = p.top();
	Pri p1;
	while (!p.empty())
	{
		p1.push(p.top() * mx);
		p.pop();
	}
	return p1;
}

int main()
{
	Pri p;
	cout << "Enter the size of the container" << endl;
	int n;
	cin >> n;
	p = MQueue(n);
	Print(p);
	p = AddMin(p);
	Print(p);
	p = Del(p);
	Print(p);
	p = M(p);
	Print(p);
}
