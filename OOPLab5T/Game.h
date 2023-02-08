#pragma once
#include <iostream>

class Player {
public:
	Player() {
		first_name = "NULL";
		second_name = "NULL";
		father_name = "NULL";
		additional_info = "NULL";
		id_code = -1;
		score = 0;
	};

	Player(std::string _first_name, std::string _second_name, std::string _additional_info,
		int _score, std::string _father_name = "NULL", int _id_code = -1) {
		first_name = _first_name;
		second_name = _second_name;
		father_name = _father_name;
		additional_info = _additional_info;
		id_code = _id_code;
		score = _score;
	}
	Player(Player& source) {
		first_name = source.first_name;
		second_name = source.second_name;
		father_name = source.father_name;
		additional_info = source.additional_info;
		id_code = source.id_code;
		score = source.score;
	}
	~Player() {};

	std::string first_name;
	std::string second_name;
	std::string father_name;
	std::string additional_info;

	int id_code;
	int score;


	void print() {
		std::cout << "=| First name:  " << first_name << '\n';
		std::cout << "=| Second name: " << second_name << '\n';
		std::cout << "=| Father name: " << father_name << '\n';
		std::cout << "=| ID code:     " << id_code << '\n';
		std::cout << "=| Score:      " << score << '\n';
		std::cout << "=| Add. info:   " << additional_info << '\n';
	}

	void print(std::ostream& os) {
		os << "=| First name:  " << first_name << '\n';
		os << "=| Second name: " << second_name << '\n';
		os << "=| Father name: " << father_name << '\n';
		os << "=| ID code:     " << id_code << '\n';
		os << "=| Score:      " << score << '\n';
		os << "=| Add. info:   " << additional_info << '\n';
	}
};

class Game {
public:
	Game() {
		players_count = 0;
		players = 0;
	}

	Game(int _players_count) {
		players_count = _players_count;
		players = new Player[players_count];
	}

	Game(Game& source) {
		players_count = source.players_count;
		game_name = source.game_name;
		rules = source.rules;
		players = new Player[source.players_count];

		for (int plIndex = 0; plIndex < players_count; plIndex++) {
			players[plIndex] = source.players[plIndex];
		}
	}

	~Game() {
		if (players) {
			delete[] players;
		}
	}


	std::string game_name;
	std::string rules;

	int players_count;
	Player* players;



	void print() {
		std::cout << "=| Game name: " << game_name << '\n';
		std::cout << "=| Rules :    " << rules << '\n';
	}


	void setGameName(std::string _game_name) {
		game_name = _game_name;
	}

	void setRules(std::string _rules) {
		rules = _rules;
	}

	void setPlayersCount(int _players_cout) {
		players_count = _players_cout;
	}

	friend std::ostream& operator<<(std::ostream& os, Game& game) {
		os << "=| Game name:      " << game.game_name << '\n';
		os << "=| Rules :\n" << game.rules << '\n';
		os << "=| Players count : " << game.players_count << '\n';
		
		std::cout << "============ Players info ============\n";
		for (int plIndex = 0; plIndex < game.players_count; plIndex++) {
			std::cout << "\n=| Student number: " << plIndex << '\n';
			game.players[plIndex].print(os);
		}
		std::cout << "======================================\n";

		return os;
	}

	void operator=(Game& source) {
		players_count = source.players_count;
		game_name = source.game_name;
		rules = source.rules;
		players = new Player[source.players_count];

		for (int plIndex = 0; plIndex < players_count; plIndex++) {
			players[plIndex] = source.players[plIndex];
		}
	}

};


class Football : public Game{
public:
	Football() : Game() {
		game_name = "Football";
		rules = std::string("\tMaximum 11 players\n") +
				std::string("\tOnly 2 teams\n") +
				std::string("\tOnly goalkeeper can touch ball with hands\n") +
				std::string("\tAny other player can`t touch ball with hands\n") +
				std::string("\tThe main goal is to kick the ball into the goal\n") +
				std::string("\tA match consists of two 45 minutes halves with a 15 minute rest period in between\n");
	}

	Football(Football& source) : Game() {
		game_name = "Football";
		rules = std::string("\tMaximum 11 players\n") +
			std::string("\tOnly 2 teams\n") +
			std::string("\tOnly goalkeeper can touch ball with hands\n") +
			std::string("\tAny other player can`t touch ball with hands\n") +
			std::string("\tThe main goal is to kick the ball into the goal\n") +
			std::string("\tA match consists of two 45 minutes halves with a 15 minute rest period in between\n");

		players_count = source.players_count;
		game_name = source.game_name;
		rules = source.rules;
		players = new Player[source.players_count];

		for (int plIndex = 0; plIndex < players_count; plIndex++) {
			players[plIndex] = source.players[plIndex];
		}
	}

	Football(int _players_count) : Game(_players_count) {
		game_name = "Football";
		rules = std::string("\tMaximum 11 players\n") +
			std::string("\tOnly 2 teams\n") +
			std::string("\tOnly goalkeeper can touch ball with hands\n") +
			std::string("\tAny other player can`t touch ball with hands\n") +
			std::string("\tThe main goal is to kick the ball into the goal\n") +
			std::string("\tA match consists of two 45 minutes halves with a 15 minute rest period in between\n");
	}

	void operator=(Football& source) {
		Football();
		players_count = source.players_count;
		game_name = source.game_name;
		rules = source.rules;
		players = new Player[source.players_count];

		for (int plIndex = 0; plIndex < players_count; plIndex++) {
			players[plIndex] = source.players[plIndex];
		}
	}
};

