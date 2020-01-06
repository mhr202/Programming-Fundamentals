#include <iostream>
#include <conio.h>
#include <math.h>
#include "help.h"
#include<cstdlib>
#include<time.h>
#include<amp_graphics.h>

using namespace std;




bool collision_check(int centre_x1, int centre_x2, int centre_y1, int centre_y2, int radius)
{

	int d = sqrt((centre_x2 - centre_x1)*(centre_x2 - centre_x1) + (centre_y2 - centre_y1) *(centre_y2 - centre_y1));
	if (d <= radius)
		return true;
	else
		return false;

}




int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);   //Fullscreen//


																						  //INITIALIZATIONS **************//
	float p1 = 0;
	float p2 = 0;
	int array[1400][1400] = { { 0 } };
	int height = 715;
	int width = 1335;
	int circlesize1 = 0;
	int circlesize2 = 0;
	srand(time(0));
	bool t;
	int key = 0;
	int green = 255, blue = 255, red = 100;
	int green1 = 255, blue1 = 255, red1 = 255;
	float x1 = 250, y1 = 340, x2 = 290, y2 = 380, a = 0, b, c, x = 0, y, z, x3 = 1000, y3 = 340, x4 = 1040, y4 = 380;
	int w = 1;
	float P1 = 0;
	float P2 = 0;
	int speed;
	int flag1 = 1;
	int flag2 = 1;
	int slow;
	int flag3 = 0;
	int player_2_win = 0;
	int player_1_win = 0;
	int flag4=0;

	//Menu*****************
	

	cout << "\n\n\n\n\n\n\n\t    PRESS  c  KEY TO CONTINUE";

	cout << "\n\n\n\n\n\n\n\t press  the  e  key to exit the game";

	if (_kbhit)
		key = _getch();
		
	if (key == 'c')
	{
		system("cls");

		//Time Bar*****************
		while (w <= 3)
		{
			float x1 = 250, y1 = 340, x2 = 290, y2 = 380, a = 0, b, c, x = 0, y, z, x3 = 1000, y3 = 340, x4 = 1040, y4 = 380;
			for (int j = 0; j < 46; j++)
			{
				cout << endl;
			}
			cout << "  Round " << w << "     Time";
			myRect(158, 733, 1322, 758, 160, 32, 255, 0, 0, 0);



			//MOVEMENT**************//

			//PLAYER 1//
			myRect(158, 733, 1322, 758, 160, 32, 255, 0, 0, 0);


			for (float i = 0; i < 1140; i = i = i + 1)
			{




				t = isCursorKeyPressed(key);
				if (flag1 == 1)
				{
					b = sin(a)*(4);
					c = cos(a)*(4);
				}

				if (flag1 == 0)
				{
					b = sin(a)*1.5;
					c = cos(a)*1.5;
				}

				if (flag4 == 2)
				{
					b = sin(a) * 7;
					c = cos(a) * 7;
				}
				x1 = x1 + c;
				y1 = y1 + b;
				x2 = x2 + c;
				y2 = y2 + b;


				if (t == true && key == 1)
					a = a + 0.175;

				if (t == true && key == 3)
					a = a - 0.175;


				if (x1 >= 10 && x2 <= width&&y1 >= 10 && y2 <= height)                     //Adding Boundary Limits//
					myEllipse(x1, y1, x2, y2, 255, 0, 0, 255, 100, 90);

				if (x1 < 10 || x2 > width)                                            //Boundary Conditions//
				{
					x1 = x1 - c;
					x2 = x2 - c;
				}

				if (y1 < 10 || y2 > height)                                           //Boundary Conditions//
				{
					y1 = y1 - b;
					y2 = y2 - b;
				}

				myEllipse(x1, y1, x2 + circlesize1, y2 + circlesize1, red, 0, 0, red, 100, 90);

				Sleep(15);




				//PLAYER2//
				if (flag1 == 1)
				{
					y = sin(x)*(4);
					z = cos(x)*(4);
				}
				if (flag1 == 0)
				{
					y = sin(x)*1.5;
					z = cos(x)*1.5;
				}

				if (flag4 == 3)
				{
					y = sin(x) * 7;
					z = cos(x) * 7;
				}
				x3 = x3 - z;
				y3 = y3 - y;
				x4 = x4 - z;
				y4 = y4 - y;

				if (t == true && key == 2)
					x = x + 0.175;

				if (t == true && key == 4)
					x = x - 0.175;


				if (x3 >= 10 && x4 <= width && y3 >= 10 && y4 <= height)                           //Adding Boundary Limits//
					myEllipse(x3, y3, x4, y4, 255, 0, 0, 100, 0, 100);

				if (x3 < 10 || x4 > width)                                                  // Boundary Conditions//
				{
					x3 = x3 + z;
					x4 = x4 + z;

				}

				if (y3 < 10 || y4 > height)                                                //Boundary Conditions//
				{
					y3 = y3 + y;
					y4 = y4 + y;
				}
				if (flag3 == 0)
					myEllipse(x3, y3, x4 + circlesize2, y4 + circlesize2, red1, 0, 0, 0, red1, 0);

				myEllipse(x3, y3, x4 + circlesize2, y4 + circlesize2, red1, 0, 0, 0, red1, 0);
				if (flag3 == 2)
				{
					int X3 = 1440;
					int Y3 = 1200;
					myEllipse(X3 - i, Y3 - i, (X3 + 30) - i + circlesize2, (Y3 + 40) - i + circlesize2, 0, 0, 0, 0, 0, 0);
				}






				//PIXEL COUNT ***********************//

				//Player 1//
				for (int i = x1; i <= x2; i++)
				{
					for (int j = y1; j <= y2; j++)
					{
						array[i][j] = 1;
					}
				}


				//Player 2//
				for (int i = x3; i <= x4; i++)
				{
					for (int j = y3; j <= y4; j++)
					{
						array[i][j] = 2;
					}
				}


				//collisions *******************//
				int centre_x2, centre_x1, centre_y2, centre_y1;
				centre_x1 = (x1 + x2) / 2;
				centre_x2 = (x3 + x4) / 2;
				centre_y1 = (y1 + y2) / 2;
				centre_y2 = (y3 + y4) / 2;

				unsigned int Radius = (x2 - x1) / 2;
				int R = Radius * 2;
				bool col = collision_check(centre_x1, centre_x2, centre_y1, centre_y2, R);
				if (col == true)
				{
					for (int h = 0; h < 30; h = h + 5)
					{

						x1 = x1 - h;
						x2 = x2 - h;
						x3 = x3 + h;
						x4 = x4 + h;
						myEllipse(x3, y3, x4, y4, 255, 0, 0, 100, 0, 100);
						Sleep(50);

						myEllipse(x1, y1, x2, y2, 255, 0, 0, 255, 100, 90);

						if (x3 < 10 || x4 > width)                                                  // Boundary Conditions//
						{
							x3 = x3 - h;
							x4 = x4 - h;
						}

						if (y3 < 10 || y4 > height)                                                //Boundary Conditions//
						{
							y3 = y3 - h;
							y4 = y4 - h;
						}
						if (x1 < 10 || x2 > width)                                                  // Boundary Conditions//
						{
							x1 = x1 + h;
							x2 = x2 + h;
						}

						if (y1 < 10 || y2 > height)                                                //Boundary Conditions//
						{
							y1 = y1 + h;
							y2 = y2 + h;
						}
						b = b + 180;
						c = c + 180;
						z = z + 180;
						x = x + 180;
					}
					//Speed Slow After Collision//
					flag1 = 0;
					flag2 = 0;
				}
				if (flag2 == 0)
				{
					slow = 0;
				}
				flag2 = 1;

				if (flag1 == 0)
					slow++;

				if (slow >= 100)
					flag1 = 1;

				//powerup - 1 size increase

				int k = 100;
				int l = 500;
				if (i + 160 == 450)
				{
					myEllipse(k, l, k + 40, l + 40, 160, 32, 255, 160, 100, 255);

				}
				if (collision_check(centre_x1, k + 20, centre_y1, l + 20, 20) == true)
				{
					circlesize1 = 30;

				}

				if (collision_check(centre_x2, k + 20, centre_y2, l + 20, 20) == true)
				{
					circlesize2 = 30;
				}
				k = 1400, l = 1444;
				myEllipse(k, l, k + 50, l + 50, 0, 0, 0, 0, 0, 0);
				if (flag1 == 0)
				{
					circlesize1 = 0;
					circlesize2 = 0;
				}


				////powerup 2 colorless
				//{
				//	int k1 = 700, l1 = 500;
				//	if (i + 160 == 860) {/*
				//						 k1 = rand() % 1330;
				//						 l1 = rand() % 715;*/
				//		myEllipse(k1, l1, k1 + 40, l1 + 40, 255, 224, 32, 255, 224, 32);
				//	}
				//	if (collision_check(centre_x2, k1 + 20, centre_y2, l1 + 20, 20))
				//	{
				//		flag3 = 1;
				//	}
				//	if (collision_check(centre_x1, k1 + 20, centre_y1, l1 + 20, 20))
				//	{
				//		flag3 = 2;
				//	}
				//	if (flag3 == 1||flag3==2)
				//	{
				//		
	
				//	}

				//}
				
				//Power Up 3 - Speed Up
				int k2 = 500;
				int l2 = 500;
				if (i + 160 == 160)
				{
					myEllipse(k2, l2, k2 + 40, l2 + 40, 100, 0, 0, 100, 200, 250);
				}
				if (collision_check(centre_x1, k2 + 20, centre_y1, l2 + 20, 20) == true)
				{
					flag4 = 2;
				}

				if (collision_check(centre_x2, k2 + 20, centre_y2, l2 + 20, 20) == true)
				{
					flag4 = 3;
				}

			



				//TIME BAR**********************//		
				myEllipse(160, 736, 178, 754, 100, 0, 0, 100, 0, 0);
				myEllipse(860, 736, 878, 754, 255, 224, 32, 255, 224, 32);
				myEllipse(160 + i, 737, 177 + i, 754, 255, 208, 160, 255, 208, 160);
				myEllipse(450, 736, 468, 754, 160, 32, 255, 160, 100, 255);


				Sleep(20);
				//Boundary ***********************//

				myLine(10, 10, 1335, 10, 255, 0, 0);
				myLine(10, 10, 10, 715, 255, 0, 0);
				myLine(10, 715, 1335, 715, 255, 0, 0);
				myLine(1335, 10, 1335, 715, 255, 0, 0);

			}


			//PIXEL COUNT*********************//

			//Plyaer 1//
			for (int i = 0; i < 1400; i++)
			{
				for (int j = 0; j < 1400; j++)
				{
					if (array[i][j] == 1)
						p1++;
				}
			}

			//Player 2//
			for (int i = 0; i < 1400; i++)
			{
				for (int j = 0; j < 1400; j++)
				{
					if (array[i][j] == 2)
						p2++;
				}
			}


			//Percentage Calculation ******************//
			int TotalPixel = (715 * 1335);
			P1 = (p1 / TotalPixel) * 100;
			P2 = (p2 / TotalPixel) * 100;

			system("cls");
			/*	char pp;
			if (w>3)
			w++;
			cout << "Player1  " << P1 << "%     " << endl << " Player2 " << P2 << "%" << endl << "Press Any Key To Continue To Round:" << w;
			cin >> pp;

			system("cls");*/

			//Winner***********************//
			cout << "\n\n\n\n\n\n\n\n\n\t  Player1  " << P1 << "%     " << endl << "n\n\n\t Player2 " << P2 << "%" << endl;

			if (P1 > P2)
			{
				cout << "n\n\n\n\n\t  Player1  wins  the round   ";
				player_1_win = player_1_win + 1;

			}
			else
				if (P2 > P1)
				{
					cout << "n\n\n\n\n\t  Player2  wins  the round   ";
					player_2_win = player_2_win + 1;

				}
				else if (P2 == P1)
				{
					cout << "\n\n\n\n\n\n\n\n\n\t  game is drawn  ";
				}

			cout << "n\n\n\n    press any key to continue to next  round ";
			char oo;
			cin >> oo;
			system("cls");

			w++;

		}

		if (player_1_win > player_2_win)
		{


			cout << "\n\n\n\n\n\n\n\n\n\t  player one has won  the totol  : " << player_1_win << "  rounds";

			cout << "\n\n\n\n\n\n\n\n\n\t  player one is the winner";
		}
		else if (player_1_win < player_2_win)
		{

			cout << "\n\n\n\n\n\n\n\n\n\t  player two has won  the totol  : " << player_2_win << "  rounds";

			cout << "\n\n\n\n\n\n\n\n\n\t  player two is the winner";


			cout << "\n\n\n\n\n\n\n\n\n\\n\n\n\n\t   press any key to continue";

			if (player_1_win == player_2_win)
			{
				cout << "\n\n\n\n\n\n\n\n\n\t  game is drawn  ";
			}



		}
		_getch();

	}




	system("pause");
}


















