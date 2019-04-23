#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
	//pulling our character stats from a text file into the game
	string line;
	ifstream file("CharStats.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << "\n";
		}
		file.close();
	}
	//drawing our screen in output
	Game* game = new Game(800, 600);

	game->GameLoop();

	//deleting game on destroy
	delete game;

	cin.get();

	return 0;
}