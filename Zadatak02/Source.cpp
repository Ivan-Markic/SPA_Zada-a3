#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

//STUPAC JE OVO S LIJEVA NA DESNO STO IDE DO 40 - Ws
//REDAK JE OVO STO IDE OD GORE PREMA DOLE STO IDE DO 20 - Wr

//Napravio si da nalazi najbolji put, ali sad jos trebas potraziti bugove tip sta ako se ne moze proci ili sto ako je zid los

void input(int& As, int& Ar, int& Bs, int& Br, int& Wr, int& Ws, int& WSize)
{
	do
	{
		cout << "A redak: ";
		cin >> Ar;

		cout << "A stupac: ";
		cin >> As;

		cout << "B redak: ";
		cin >> Br;

		cout << "B stupac: ";
		cin >> Bs;

		cout << endl << "Pozicija koju cete sada upisati odnosi se na gornji pocetak zida \n stoga duzina zida moze biti maksimalno 21 - redak = 0" << endl << endl;

		cout << "Unesite Redak pocetka zida: ";
		cin >> Wr;

		cout << "Unesite Stupac pocetka zida: ";
		cin >> Ws;

		cout << "Unesite duzinu zida: ";
		cin >> WSize;

		system("cls");
		// u nastavku while uvjeta upisi da ako je size + Wr veci od 20 da ponovno ide upis i ako se zid nalazi na istoj poziciji kao A ili B - Msm da je to sve
	} while (As < 1 || As > 40 || Ar < 1 || Ar > 20 || Bs < 1 || Bs > 40 || Br < 1 || Br > 20 || (As == Bs && Ar == Br) || (Ar >= Wr && Ar <= (Wr + WSize) && As == Ws) || Wr + WSize > 21 || (Br >= Wr && Br <= (Wr + WSize) && Bs == Ws));
}

void start(vector<vector<char>>& mapa, int& As, int& Ar, int& Bs, int& Br, int Ws, int Wr, int WSize)
{
	for (int i = 0; i < 20; i++)
	{
		vector<char> znak;
		for (int j = 0; j < 40; j++)
		{
			if (j == (Ws - 1) && i == (Wr - 1) )
			{
				if (WSize > 1)
				{
					Wr++;
					WSize--;
				}
				cout << "*";
				znak.push_back('*');
			}

			else if (j == (As - 1) && i == (Ar - 1))
			{
				cout << "A";
				znak.push_back('A');
			}

			else if (j == (Bs - 1) && i == (Br - 1))
			{
				cout << "B";
				znak.push_back('B');
			}

			else
			{
				cout << "-";
				znak.push_back('-');
			}
		}
		cout << endl;
		mapa.push_back(znak);
	}
}

void check(vector<vector<char>>& mapa, int& As, int& Ar, int& Bs, int& Br, int Ws, int Wr, int WSize, int Xs, int Xr, bool& up, bool& CanUp, bool& CanDown)
{
	int CounterUp = 0;
	int CounterDown = 0;
	int tempXs = Xs;
	int tempXr = Xr;
	up = true;

	if (Xs!=Bs)
	{
		if(Xs < Bs || tempXs < Bs)
		{
			//staviti ovaj slucaj u jednu do petlju i za drugi(dolje) staviti u drugu do petlju - TAKO VJEROVATNO NAPRAVITI I ZA KRETANJE GORE DESNO( IF( Xr!= Br)
			//tu radim za gore
			do
			{
						if ((Xs + 1) == Ws && (Xr >= Wr && Xr < Wr + WSize))
						{

							if (Xr > 1)
							{
								Xr--;
								CounterUp++;
							}

							else
							{
								CanUp = false;
							}
						}
						else
						{
							Xs++;
							CounterUp++;
						}

			} while (Xs!=Bs && CanUp == true);

				//tu radim za dolje
			do
			{
					if ((tempXs + 1) == Ws && (tempXr >= Wr && tempXr < Wr + WSize))
					{
						if (tempXr < 20)
						{
							tempXr++;
							CounterDown++;
						}

						else
						{
							CanDown = false;
						}
					}

					else
					{
						tempXs++;
						CounterDown++;
					}
			} while (tempXs < Bs && CanDown == true);

		}

		else
		{
			//tu ide kad je veci Xs od Bs
			do
			{
				//tu radim za gore
				if (Xs > Bs)
				{
					if ((Xs - 1) == Ws && (Xr >= Wr && Xr <= Wr + WSize))
					{

						if (Xr > 1)
						{
							Xr--;
							CounterUp++;
						}

						else
						{
							CanUp = false;
						}
					}

					else
					{
						Xs--;
						CounterUp++;
					}
				}
			} while (Xs > Bs && CanUp == true);

			do
			{
				//tu radim za dolje
					if ((tempXs - 1) == Ws && (tempXr >= Wr && tempXr < Wr + WSize))
					{
						if (tempXr < 20)
						{
							tempXr++;
							CounterDown++;
						}

						else
						{
							CanDown = false;
						}
					}

					else
					{
						tempXs--;
						CounterDown++;
					}
			} while (tempXs > Bs && CanDown == true);
		}
	}

	if (Xr!= Br)
	{
		if (Xr < Br || tempXr < Br)
		{
			do
			{
				if (CanUp && Xr < Br)
				{
					if (Xr != Br)
					{
						Xr++;
						CounterUp++;
					}
				}

				else if (CanDown && tempXr < Br)
				{
					if (tempXr != Br)
					{
						tempXr++;
						CounterDown++;
					}
				}

				else
				{
					up = false;
				}

			} while ((up));
		}

		up = true;

		if (Xr > Br || tempXr > Br )
		{
			do
			{
				if (CanUp && Xr > Br)
				{
					if (Xr != Br)
					{
						Xr--;
						CounterUp++;
					}
				}

				else if (CanDown && tempXr > Br)
				{
					if (tempXr != Br)
					{
						tempXr--;
						CounterDown++;
					}
				}

				else
				{
					up = false;
				}

			} while ((up));
		}
	}


	if (CanUp && CanDown)
	{
		if (CounterUp < CounterDown)
		{
			up = true;
		}

		else
		{
			up = false;
		}
	}

	else if (CanUp)
	{
		up = true;
	}

	else if (CanDown)
	{
		up = false;
	}
}

void update(vector<vector<char>>& mapa, int& Bs, int& Br, int Ws, int Wr, int WSize, bool& up, int& Xs, int& Xr)
{
	if (Bs != Xs)
	{
		if (Bs > Xs)
		{
			if (mapa[Xr - 1][Xs] == '*')
			{
				if (up)
				{
					mapa[Xr - 1][Xs - 1] = 'A';
					mapa[Xr - 2][Xs - 1] = 'x';
					Xr--;
				}

				else
				{
					mapa[Xr - 1][Xs - 1] = 'A';
					mapa[Xr][Xs - 1] = 'x';
					Xr++;
				}

			}

			else
			{
				mapa[Xr - 1][Xs - 1] = 'A';
				mapa[Xr - 1][Xs] = 'x';
				Xs++;
			}
		}

		else
		{
			if (mapa[Xr - 1][Xs - 2] == '*')
			{
				if (up)
				{
					mapa[Xr - 1][Xs - 1] = 'A';
					mapa[Xr - 2][Xs - 1] = 'x';
					Xr--;
				}

				else
				{
					mapa[Xr - 1][Xs - 1] = 'A';
					mapa[Xr][Xs - 1] = 'x';
					Xr++;
				}

			}

			else
			{
				mapa[Xr - 1][Xs - 1] = 'A';
				mapa[Xr - 1][Xs - 2] = 'x';
				Xs--;
			}
		}

	}

	else if (Br != Xr)
	{
		if (Br > Xr)
		{
			mapa[Xr - 1][Xs - 1] = 'A';
			mapa[Xr][Xs - 1] = 'x';
			Xr++;

		}

		else
		{
			mapa[Xr - 1][Xs - 1] = 'A';
			mapa[Xr - 2][Xs - 1] = 'x';
			Xr--;
		}
	}

	do
	{
		Sleep(100);
		system("cls");
		if (Bs != Xs)
		{
			if (Bs > Xs)
			{
				if (mapa[Xr - 1][Xs] == '*')
				{
					if (up)
					{
						mapa[Xr - 1][Xs - 1] = '-';
						mapa[Xr - 2][Xs - 1] = 'x';
						Xr--;
					}

					else
					{
						mapa[Xr - 1][Xs - 1] = '-';
						mapa[Xr][Xs - 1] = 'x';
						Xr++;
					}

				}

				else
				{
					mapa[Xr - 1][Xs - 1] = '-';
					mapa[Xr - 1][Xs] = 'x';
					Xs++;
				}
			}

			else
			{
				if (mapa[Xr - 1][Xs - 2] == '*')
				{
					if (up)
					{
						mapa[Xr - 1][Xs - 1] = '-';
						mapa[Xr - 2][Xs - 1] = 'x';
						Xr--;
					}

					else
					{
						mapa[Xr - 1][Xs - 1] = '-';
						mapa[Xr][Xs - 1] = 'x';
						Xr++;
					}

				}

				else
				{
					mapa[Xr - 1][Xs - 1] = '-';
					mapa[Xr - 1][Xs - 2] = 'x';
					Xs--;
				}
			}

		}

		else if (Br != Xr)
		{
			if (Br > Xr)
			{
				mapa[Xr - 1][Xs - 1] = '-';
				mapa[Xr][Xs - 1] = 'x';
				Xr++;

			}

			else
			{
				mapa[Xr - 1][Xs - 1] = '-';
				mapa[Xr - 2][Xs - 1] = 'x';
				Xr--;
			}
		}

		for (int i = 0; i < mapa.size(); i++)
		{
			for (int j = 0; j < mapa[i].size(); j++)
			{
				cout << mapa[i][j];
			}
			cout << endl;
		}

	} while (Xs!= Bs || Xr!= Br);

}

int main()
{
	vector<vector<char>> mapa;
	int Ar;
	int As;
	int Br;
	int Bs;
	int Wr;
	int Ws;
	int WSize;
	input(As, Ar, Bs, Br, Wr, Ws, WSize);
	int Xs = As;
	int Xr = Ar;
	bool up;
	bool CanUp = true;
	bool CanDown = true;
	start(mapa, As, Ar, Bs, Br, Ws, Wr, WSize);

	check(mapa, As, Ar, Bs, Br, Ws, Wr, WSize, Xs, Xr, up, CanUp, CanDown);

	if (!CanUp && !CanDown)
	{
		cout << endl << "Nije moguce doci do B" << endl;
		return 1;
	}

	update(mapa, Bs, Br, Ws, Wr, WSize, up, Xs, Xr);


	return 0;
}