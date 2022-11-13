#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;


const int N = 20;

char map[N][N + 1] =
{
"####################",
"# # ^ #Y  ###Ma ^^##",
"# ^ M  ##M#######^##",
"#####M  #^     M#  #",
"#  ^   #MM M#M  ^^##",
"#  ##^ #^  ^#####  #",
"#M  ^^#M #MY^ ^## M#",
"# ^# M#^ ###^   #^M#",
"# ^# ^M M### # M#  #",
"#  #Ma#  MYM # ^#M^#",
"# ^  Ma# ###^#M^#  #",
"#^###### ###^#^^^  #",
"#^## M ^  ^ ^ ###  #",
"#^## ^^##M#a# ##  ##",
"#^## ^#^^Y#######^^#",
"#^   ## ###M #   ^^#",
"# ###aM^ ^^^^  # ###",
"# ########### ^#  ##",
"#             ^#M aM",
"####################",
};

int mainY = 1;
int mainX = 1;
int hp = 100;

void printAll() {

	system("cls");

	int x, y;
	for ( y = 0; y < N; y++)
	{
		for ( x = 0; x < N; x++)
		{
			if (x == mainX && y == mainY) cout << "¢Â";
			else if (map[y][x] == ' ') cout << "  ";
			else if (map[y][x] == 'a') cout << "¢¾";
			else if (map[y][x] == '^') cout << "¢Ô";
			else if (map[y][x] == '#') cout << "¡á";
			else if (map[y][x] == 'Y') cout << "¡Ù";
			else if (map[y][x] == 'M') cout << "¢Í";
		}
		cout << endl;
	}

	cout << "HP : " << hp << "\n";

}

int encounterMonster() {
	int flag = 0;
	if (map[mainY][mainX] == 'M') flag = 1;

	return flag;
}

int checkWall(int y, int x) {
	int flag = 0;

	if (map[y][x] == '#') flag = 1;

	return flag;
}

int getGrail() {
	int flag = 0;
	if (map[mainY][mainX] == 'Y') flag = 1;
	return flag;
}

int stepThorn(int y, int x) {
	int flag = 0;

	if (map[y][x] == '^') flag = 1;

	return flag;
}

void getApple(int y, int x) {
	if (map[y][x] == 'a') {
		hp = 100;
		map[y][x] = ' ';
	}
}

int main() {

	system("COLOR 0A");

	while (1) {

		printAll();

		if (GetAsyncKeyState(VK_UP) & 0x80001) {
			if (stepThorn(mainY - 1, mainX)) hp -= 10;
			if (!checkWall(mainY - 1, mainX)) mainY--;
		} 	
		else if (GetAsyncKeyState(VK_DOWN) & 0x80001) {
			if (stepThorn(mainY + 1, mainX)) hp -= 10;
			if (!checkWall(mainY + 1, mainX)) mainY++;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x80001) {
			if (stepThorn(mainY, mainX - 1)) hp -= 10;
			if (!checkWall(mainY, mainX - 1)) mainX--;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x80001) {
			if (stepThorn(mainY, mainX + 1)) hp -= 10;
			if (!checkWall(mainY, mainX + 1)) mainX++;		
		}

		getApple(mainY, mainX);

		if (encounterMonster() || hp == 0) {
			printAll();
			Sleep(500);
			system("cls");
			cout << "\n\n\n\n\t\t\t\GAME OVER\n\n\n\n";
			break;
		}

		if (getGrail()) {
			printAll();

			for (int i = 0; i < 5; i++) {
				system("COLOR 6F");
				Sleep(30);
				system("COLOR 7E");
				Sleep(70);
			}
			system("color 6F");
			Sleep(500);
			system("cls");
			cout << "\n\n\n\n\n\t\t\tWIN!! ( hp : " << hp << " )" << "\n\n\n\n\n\n";
			break;
		}

		Sleep(500);
	} 

	


	return 0;
}