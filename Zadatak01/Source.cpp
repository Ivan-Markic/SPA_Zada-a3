#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <Windows.h>

using namespace std;
using namespace chrono;


void input(int& As, int& Ar, int& Bs, int& Br)
{
	do
	{
		cout << "A redak : ";
		cin >> Ar;

		cout << "A stupac: ";
		cin >> As;
		
		cout << "B redak: ";
		cin >> Br;

		cout << "B stupac: ";
		cin >> Bs;
		system("cls");
	} while (As < 1 || As > 40 || Ar < 1 || Ar > 20 || Bs < 1 || Bs > 40 || Br < 1 || Br > 20 || (As == Bs && Ar == Br));
}

void draw(int& As, int& Ar, int& Bs, int& Br, int& Xs, int& Xr)
{
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (j == (As - 1) && i == (Ar - 1))
			{
				cout << "A";
			}

			else if (j == (Xs - 1) && i == (Xr - 1))
			{
				cout << "x";
			}

			else if (j == (Bs - 1) && i == (Br - 1))
			{
				cout << "B";
			}

			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}


}

void update(int& As, int& Ar, int& Bs, int& Br, int& Xs, int& Xr)
{
	do
	{
		if (Bs != Xs)
		{
			if (Bs > Xs)
			{
				Xs++;

			}

			else
			{
				Xs--;
			}

		}

		else if (Br != Xr)
		{
			if (Br > Xr)
			{
				Xr++;

			}

			else
			{
				Xr--;
			}
		}

		draw(As, Ar, Bs, Br, Xs, Xr);
		Sleep(100);
	} while (Xs != Bs || Xr != Br);
}

int main()
{
	int Ar;
	int As;
	int Br;
	int Bs;
	input(As, Ar, Bs, Br);
	int Xs = As;
	int Xr = Ar;

	update(As, Ar, Bs, Br, Xs, Xr);

	return 0;
}