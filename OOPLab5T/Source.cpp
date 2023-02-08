#include <iostream>
#include "student.h"
#include "Room.h"
#include "Game.h"

void test_1() {
	std::string sFirName = "Adam";
	std::string sSecName = "Newell";
	std::string sFatName = "Rudgerd";
	std::string sCouName = "CSN 231a";
	int sCouNum = 4;
	int sID = 5481792893;

	std::string sDipName = "CNN image recognition";
	diploma_student asd(sCouNum, sCouName, sDipName, sFirName, sSecName, sFatName, sID);
	asd.print();





	std::cout << "\n\nNot all data\n";

	std::string sFirName2 = "Rick";
	std::string sSecName2 = "Hexel";
	std::string sCouName2 = "CSN 231a";
	int sCouNum2 = 3;


	std::string sDipName2 = "Autoncoder denoise";
	diploma_student asd2(sCouNum2, sCouName2, sDipName2, sFirName2, sSecName);
	asd2.print();
}


void test_2() {
	Room room(2.4);
	std::cout << "Room square: " << room.getSquare() << "\n\n";


	Appartament apps(4.3, 5.2);
	apps.print();
	std::cout << '\n';


	Labeled_Appartament lapps("Kyiv", 1.3, 5.78);
	lapps.print();
	std::cout << '\n';


	Level level(3);
	level.print();
}


void test_3() {
	Football game(4);

	game.players[0].first_name = std::string("Jos");
	game.players[1].first_name = std::string("Rick");
	game.players[2].first_name = std::string("Oliver");
	game.players[3].first_name = std::string("Peper");

	std::cout << game;


	Football f2(game);
	Football f3 = f2;
	std::cout << f2;
	std::cout << f3;

}

int main() {

	char choice;
	while (1) {
		std::cout << "Input task number 1, 2 ,3: ";
		std::cin >> choice;
		system("cls");

		if (choice == '1') {
			test_1();
		}
		if (choice == '2') {
			test_2();
		}
		if (choice == '3') {
			test_3();
		}
	}
}