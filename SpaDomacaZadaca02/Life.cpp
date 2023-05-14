#include "Life.h"
#include <iostream>

bool Life::random_bool()
{	
	std::uniform_int_distribution<int> distribution(1,4);
	//std::cout << distribution(generator) << endl;
	return (distribution(generator)==2);
}

bool Life::is_alive(int x, int y){
	return alive[x][y];
}

Life::Life()
{
	//stvori random start
	alive.resize(REDAKA);
	for (int i = 0; i < REDAKA; i++)
	{
		alive[i].resize(STUPACA);
		for (int j = 0; j < STUPACA; j++) {
			alive[i][j] = random_bool();
		}
	}

	////Testiranje glidera
	//alive[5][5] = true;
	//alive[6][6] = true;
	//alive[4][7] = true;
	//alive[5][7] = true;
	//alive[6][7] = true;

	//for (int i = 0; i < 20; i++)
	//{
	//	for (int j = 0; j < 20; j++)
	//	{
	//		alive[50 + i][50 + j]=true;
	//	}
	//}
}

void Life::step()
{
	/*trebo 8 okolo provjerit
	[x-1,y-1][x,y-1][x+1,y-1]
	[x-1,y  ][x,y  ][x+1,y  ]
	[x-1,y+1][x,y+1][x+1,y+1]
	Treba varijabla za vidit koliko ih zivo u blizini
	*/
	brojcelija = 0;
	Temp_alive = alive;
	int brojZivih = 0;
	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{

			brojZivih = 0;

			if (x == 0 and y == 0)//gore livo
			{

				if (Temp_alive[x + 1][y])
					brojZivih++;

				if (Temp_alive[x][y + 1])
					brojZivih++;
				if (Temp_alive[x + 1][y + 1])
					brojZivih++;
			}
			else if (x == REDAKA - 1 and y == 0)//gore desno
			{

				if (Temp_alive[x - 1][y])
					brojZivih++;

				if (Temp_alive[x - 1][y + 1])
					brojZivih++;
				if (Temp_alive[x][y + 1])
					brojZivih++;
			}
			else if (x == 0 and y == STUPACA - 1)//dole livo
			{
				if (Temp_alive[x][y - 1])
					brojZivih++;
				if (Temp_alive[x + 1][y - 1])
					brojZivih++;

				if (Temp_alive[x + 1][y])
					brojZivih++;

			}
			else if (x == REDAKA - 1 and y == STUPACA - 1)//dole desno
			{
				if (Temp_alive[x - 1][y - 1])
					brojZivih++;
				if (Temp_alive[x][y - 1])
					brojZivih++;

				if (Temp_alive[x - 1][y])
					brojZivih++;
			}
			else if (x==0)
			{
;
				if (Temp_alive[x][y - 1])
					brojZivih++;
				if (Temp_alive[x + 1][y - 1])
					brojZivih++;

				if (Temp_alive[x + 1][y])
					brojZivih++;

				if (Temp_alive[x][y + 1])
					brojZivih++;
				if (Temp_alive[x + 1][y + 1])
					brojZivih++;
			}
			else if (y==0)
			{

				if (Temp_alive[x - 1][y])
					brojZivih++;
				if (Temp_alive[x + 1][y])
					brojZivih++;

				if (Temp_alive[x - 1][y + 1])
					brojZivih++;
				if (Temp_alive[x][y + 1])
					brojZivih++;
				if (Temp_alive[x + 1][y + 1])
					brojZivih++;
			}
			else if (x==REDAKA-1)
			{
				if (Temp_alive[x - 1][y - 1])
					brojZivih++;
				if (Temp_alive[x][y - 1])
					brojZivih++;

				if (Temp_alive[x - 1][y])
					brojZivih++;

				if (Temp_alive[x - 1][y + 1])
					brojZivih++;
				if (Temp_alive[x][y + 1])
					brojZivih++;

			}
			else if (y==STUPACA-1)
			{
				if (Temp_alive[x - 1][y - 1])
					brojZivih++;
				if (Temp_alive[x][y - 1])
					brojZivih++;
				if (Temp_alive[x + 1][y - 1])
					brojZivih++;

				if (Temp_alive[x - 1][y])
					brojZivih++;
				if (Temp_alive[x + 1][y])
					brojZivih++;

			}
			else {
				if (Temp_alive[x - 1][y - 1])
					brojZivih++;
				if (Temp_alive[x][y - 1])
					brojZivih++;
				if (Temp_alive[x + 1][y - 1])
					brojZivih++;

				if (Temp_alive[x - 1][y])
					brojZivih++;
				if (Temp_alive[x + 1][y])
					brojZivih++;

				if (Temp_alive[x - 1][y + 1])
					brojZivih++;
				if (Temp_alive[x][y + 1])
					brojZivih++;
				if (Temp_alive[x + 1][y + 1])
					brojZivih++;
			}

			

			/*
			Ako je bio zivi a ima 2 ili 3 ostaje
			umire ako je manje od 2 ili vise od 3
			u praznoj se rada novi ako je tocno 3

			3->ziv
			2->ostaje kako je i bio
			else->umire
			*/


			if (brojZivih<2)
			{
				if (alive[x][y] != false)
				{
					brojcelija++;
				}
				alive[x][y] = false;
			}
			else if (brojZivih==3)
			{
				if (alive[x][y] != true)
				{
					brojcelija++;
				}
				alive[x][y] = true;
			}
			else if (brojZivih>3)
			{
				if (alive[x][y]!=false)
				{
				brojcelija++;
				}
				alive[x][y] = false;
			}
		}
	}
}

vector<vector<bool>> Life::GetLife()
{
	return alive;
}

int Life::GetBrojCelija()
{
	return brojcelija;
}
