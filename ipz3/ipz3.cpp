#include <iostream>
#include <fstream>
using namespace std;

void checkValidInput()
{
	if (cin.fail())
	{
		throw "Incorrect input";
	}
}
void checkValidParams(double x, double b, double h, double n)
{
	if (h <= 0)
	{
		cout << "error: invalid h." << endl;
	}
	if (n < 1)
	{
		cout << "error: invalid n." << endl;
	}
}
double calculate(double x, double n)
{
	double y = 0;
	if (x >= 0)
	{
		for (int i = 0; i <= n; i++)
		{
			double t = 1;
			for (int j = 1; j <= n; j++)
			{
				t *= (x + i) / (i + j);
			}
			y += t;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			y += (i + x) * (i + x);
		}
	}
	return y;
}
void calculateInALoop(double x, double b, double h, double n, bool toSave)
{
	ofstream fout("Test.txt");
	for (x; x <= b; x += h)
	{
		if (toSave)
		{
			fout << "y = " << calculate(x, n) << endl;
			fout << "x = " << x << endl;
		}
		else
		{
			cout << "y = " << calculate(x, n) << endl;
			cout << "x = " << x << endl;
		}
	}
	if (toSave)
	{
		fout.close();
	}
}
int main()
{
	double x, b, h, n;
	bool toSave;
	try
	{
		cout << "Enter x, b, h, n: ";
		cin >> x >> b >> h >> n;
		checkValidInput();
		checkValidParams(x, b, h, n);
		cout << "Do you want to save data? 1/0" << endl;
		cin >> toSave;
		checkValidInput();
		calculateInALoop(x, b, h, n, toSave);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "unknown error" << endl;
		return -2;
	}
	return 0;
}