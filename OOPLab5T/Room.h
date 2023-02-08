#pragma once
#include <iostream>

class Room {
public:
	Room() {
		square = -1;
	};
	Room(float _square) {
		square = _square;
	}
	~Room() {};
	float square;


	void setSquare(float _square) {
		square = _square;
	}
	float getSquare() {
		return square;
	}
};



class Appartament {
public:
	Appartament() {};
	Appartament( float sleeping_room_square, float kitchen_square) {
		kitchen.setSquare(kitchen_square);
		sleeping_room.setSquare(sleeping_room_square);
	};
	~Appartament() {};

	Room kitchen;
	Room sleeping_room;


	void print() {
		std::cout << "=| Sleeping room square: " << sleeping_room.square << '\n';
		std::cout << "=| Kitchen square:       " << kitchen.square << '\n';
	}
};



class Level {
public:
	Level() {
		appartaments_cout = 0;
		appartaments = 0;
	}
	Level(int _appartaments_count) {
		appartaments_cout = _appartaments_count;
		appartaments = new Appartament[_appartaments_count];
	}
	~Level() {
		if (appartaments) {
			delete[] appartaments;
		}
	}

	Appartament* appartaments;
	int appartaments_cout;

	void print() {
		if (appartaments) {
			std::cout << "============ Level info ============\n";
			for (int appIndex = 0; appIndex < appartaments_cout; appIndex++) {
				std::cout << "\n=| Room nuber: " << appIndex + 1 << "\n";
				appartaments[appIndex].print();
			}
			std::cout << "====================================\n";
		}
	}
};




class Labeled_Appartament : public Appartament {
public:
	Labeled_Appartament() {};
	Labeled_Appartament(std::string _city_name, float kitchen_square, float sleeping_room_square) : 
						Appartament(kitchen_square, sleeping_room_square) {
		city_name = _city_name;
	};
	~Labeled_Appartament() {};

	Appartament appartament;
	std::string city_name;

	void print() {
		std::cout << "=| City namee: " << city_name << "\n\n";
		appartament.print();
	}
};