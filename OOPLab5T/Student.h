#pragma once
#include <iostream>

class Student {
public:
	Student() {
		first_name = "NULL";
		second_name = "NULL";
		father_name = "NULL";
		course_name = "NULL";
		course_number = -1;
		id_code = -1;
	};

	Student(int _course_number, std::string _course_name, std::string _first_name, std::string _second_name,
														std::string _father_name = "NULL", int _id_code = -1) {
		first_name = _first_name;
		second_name = _second_name;
		father_name = _father_name;
		course_name = _course_name;
		course_number = _course_number;
		id_code = _id_code;
	} 
	~Student() {};

	std::string first_name;
	std::string second_name;
	std::string father_name;
	std::string course_name;
	std::string course;

	int course_number;
	int id_code;

	void print() {
		std::cout << "=| First name:  " << first_name << '\n';
		std::cout << "=| Second name: " << second_name << '\n';
		std::cout << "=| Father name: " << father_name << '\n';
		std::cout << "=| ID code:     " << id_code << '\n';
		std::cout << "=| Course #:    " << course_number << '\n';
		std::cout << "=| Course name: " << course_name << '\n';
 	}
};




class diploma_student : public Student {
public: 
	diploma_student() { std::cout << "nothing\n"; };
	diploma_student(int _course_number, std::string _course_name, std::string _diploma_name, std::string _first_name,
					std::string _second_name, std::string _father_name = "NULL", int _id_code = -1) :
					Student(_course_number, _course_name, _first_name, _second_name, _father_name,  _id_code) {
		diploma_name = _diploma_name;
	};
	~diploma_student() {};


	std::string diploma_name;

	void print() {
		Student::print();
		std::cout << "=| Diploma name: " << diploma_name << '\n';
	}
};
