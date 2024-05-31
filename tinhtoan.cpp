#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

string test(string a)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] == ' ')
		{
			a.erase(i, 1);
			i--;
		}
	return a;
}

bool error(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*' || s[i] == '/' || s[i] == '^')
			if (s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '^' || i == 0 || i == s.size() -1)
				return true;
		if (s[i] == '+' || s[i] == '-')
			if (s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '^' || i == s.size() - 1)
				return true;
	}
	return false;
}

bool check(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '(' || s[i] == ')')
			return true;
	return false;
}

string rep(float c)
{
	string s;
	int d = 0, dem = 0, ld;

	if (c == 0)
		s.insert(0, "0");
	if (c < 0)
	{
		d = 1;
		c = -c;
	}
	while (float(c) - long(c) != 0)
	{
		c *= 10;
		dem++;
	}

	long kt = long(c);

	for (int i = 0; i < dem; i++)
	{
		ld = kt % 10;
		kt /= 10;
		
		switch (ld)
		{
		case 0: s.insert(0, "0"); break;
		case 1: s.insert(0, "1"); break;
		case 2: s.insert(0, "2"); break;
		case 3: s.insert(0, "3"); break;
		case 4: s.insert(0, "4"); break;
		case 5: s.insert(0, "5"); break;
		case 6: s.insert(0, "6"); break;
		case 7: s.insert(0, "7"); break;
		case 8: s.insert(0, "8"); break;
		case 9: s.insert(0, "9"); break;
		}
	}
	if (dem > 0)
		s.insert(0, ".");
	if (kt == 0)
		s.insert(0, "0");
	while (kt > 0)
	{
		ld = kt % 10;
		kt /= 10;

		switch (ld)
		{
		case 0: s.insert(0, "0"); break;
		case 1: s.insert(0, "1"); break;
		case 2: s.insert(0, "2"); break;
		case 3: s.insert(0, "3"); break;
		case 4: s.insert(0, "4"); break;
		case 5: s.insert(0, "5"); break;
		case 6: s.insert(0, "6"); break;
		case 7: s.insert(0, "7"); break;
		case 8: s.insert(0, "8"); break;
		case 9: s.insert(0, "9"); break;
		}
	}
	if (d == 1)
		s.insert(0, "-");
	else s.insert(0, "+");
	return s;
}

float gia_tri1(string s)
{
	float c = 0;
	long thu = 1;

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')' || s[i] == '^')
		{
			if (s[i] == '-')
				c = -c;
			break;
		}
		else if (s[i] == '.')
		{
			c /= thu;
			thu = 1;
		}
		else
		{
			switch (s[i])
			{
			case '0': break;
			case '1': c += thu; break;
			case '2': c += 2 * thu; break;
			case '3': c += 3 * thu; break;
			case '4': c += 4 * thu; break;
			case '5': c += 5 * thu; break;
			case '6': c += 6 * thu; break;
			case '7': c += 7 * thu; break;
			case '8': c += 8 * thu; break;
			case '9': c += 9 * thu; break;
			}
			thu *= 10;
		}
	}
	return c;
}

float gia_tri2(string s)
{
	float c = 0;
	float thu;
	int i, j = 0;

	if (s[0] == '-' || s[0] == '+')
		j = 1;
	for (i = j; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			switch (s[i])
			{
			case '0': c = c * 10; break;
			case '1': c = c * 10 + 1; break;
			case '2': c = c * 10 + 2; break;
			case '3': c = c * 10 + 3; break;
			case '4': c = c * 10 + 4; break;
			case '5': c = c * 10 + 5; break;
			case '6': c = c * 10 + 6; break;
			case '7': c = c * 10 + 7; break;
			case '8': c = c * 10 + 8; break;
			case '9': c = c * 10 + 9; break;
			}
		}
		else break;
	}
	if (i < s.size() && s[i] == '.')
	{
		thu = 10;
		for (j = i + 1; j < s.size(); j++)
		{
			if (s[j] >= '0' || s[j] <= '9')
			{
				switch (s[j])
				{
				case '0': c += 0 / thu; break;
				case '1': c += 1 / thu; break;
				case '2': c += 2 / thu; break;
				case '3': c += 3 / thu; break;
				case '4': c += 4 / thu; break;
				case '5': c += 5 / thu; break;
				case '6': c += 6 / thu; break;
				case '7': c += 7 / thu; break;
				case '8': c += 8 / thu; break;
				case '9': c += 9 / thu; break;
				}
				thu *= 10;
			}
		}
	}
	if (s[0] == '-')
		c = -c;
	return c;
}

void change(string& s)
{
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == '+' && s[i + 1] == '+')
		{
			s.erase(i, 1);
		}
		else if (s[i] == '+' && s[i + 1] == '-')
		{
			s.erase(i, 1);
		}
		else if (s[i] == '-' && s[i + 1] == '+')
		{
			s.erase(i + 1, 1);
		}
		else if (s[i] == '-' && s[i + 1] == '-')
		{
			s.erase(i, 2);
			s.insert(i, "+");
		}
}

float tinh(string s)
{
	change(s);

	int n1, n2;
	string a, x;
	float x1, x2, kq = 0, n;

	while (check(s))
	{
		n2 = s.find(")");
		if (n2 >= 0)
		{
			change(s);

			n1 = s.rfind("(", n2);
			a = s.substr(n1 + 1, n2 - n1 - 1);
			n = tinh(a);
			x = rep(n);

			s.replace(n1, n2 - n1 + 1, x);
			change(s);
		}
	}
mu:;
	for (n = 0; n < s.size(); n++)
		if (s[n] == '^')
			break;
	if (n < s.size())
	{
		a = s.substr(0, n);
		x = s.substr(n + 1, s.size() - n - 1);
		x1 = gia_tri1(a);
		x2 = gia_tri2(x);
		if (s[n] == '^')
			kq = pow(x1, x2);
		for (n1 = n - 1; n1 >= 0; n1--)
			if (s[n1] == '+' || s[n1] == '-' || s[n1] == '*' || s[n1] == '/' || s[n1] == '(' || s[n1] == ')' || s[n1] == '^') break;
		if (n1 == -1)
			n1++;
		else if (s[n1] == '^' || s[n1] == '*' || s[n1] == '/')
			n1++;
		for (n2 = n + 2; n2 < s.size(); n2++)
			if (s[n2] == '+' || s[n2] == '-' || s[n2] == '*' || s[n2] == '/' || s[n2] == '(' || s[n2] == ')' || s[n2] == '^') break;
		n2--;
		a = rep(kq);
		s.replace(n1, n2 - n1 + 1, a);
		change(s);
		goto mu;
	}
nhanchia:;
	for (n = 0; n < s.size(); n++)
		if (s[n] == '*' || s[n] == '/')
			break;
	if (n < s.size())
	{
		a = s.substr(0, n);
		x = s.substr(n + 1, s.size() - n - 1);
		x1 = gia_tri1(a);
		x2 = gia_tri2(x);
		if (s[n] == '*')
			kq = x1 * x2;
		else kq = x1 / x2;
		for (n1 = n - 1; n1 >= 0; n1--)
			if (s[n1] == '+' || s[n1] == '-' || s[n1] == '*' || s[n1] == '/' || s[n1] == '(' || s[n1] == ')') break;
		if (n1 == -1)
			n1++;
		else if (s[n1] == '*' || s[n1] == '/')
			n1++;
		for (n2 = n + 2; n2 < s.size(); n2++)
			if (s[n2] == '+' || s[n2] == '-' || s[n2] == '*' || s[n2] == '/' || s[n2] == '(' || s[n2] == ')') break;
		n2--;
		a = rep(kq);
		s.replace(n1, n2 - n1 + 1, a);
		change(s);
		goto nhanchia;
	}
	else
	{
		int t;
		do {
			t = 0;
			for (n = 1; n < s.size(); n++)
				if (s[n] == '+' || s[n] == '-')
					break;
			if (n < s.size())
			{
				a = s.substr(0, n);
				x = s.substr(n + 1, s.size() - n - 1);
				x1 = gia_tri1(a);
				x2 = gia_tri2(x);
				if (s[n] == '+')
					kq = x1 + x2;
				else kq = x1 - x2;
				a = rep(kq);
				for (n2 = n + 1; n2 < s.size(); n2++)
					if (s[n2] == '+' || s[n2] == '-') break;
				n2--;
				s.replace(0, n2 + 1, a);
				change(s);
				t = 1;
			}
		} while (t);
	}
	kq = gia_tri1(s);
	return kq;
}

void play(string s)
{
	if (error(s) == true)
		cout << "du lieu nhap sai" << endl;
	else
	{
		cout << "gia tri cua: " << s << " la: " <<setprecision(3)<<fixed<< tinh(s) << endl;
	}
}

int main()
{
	string a;
	cout << "nhap bieu thuc: " << endl;
	getline(cin, a);
	string s = test(a);
	play(s);
	system("pause");
  return 0;
}