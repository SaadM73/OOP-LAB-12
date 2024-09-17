#pragma once
#include<iostream>
using namespace std;


class Processor {
	string processName;
	float price;

public:
	Processor() {
		processName = "";
		price = 0;
	}
	Processor(string s, float p) {
		processName = s;
		price = p;
	}

	string getProcessname() {
		return processName;
	}

	float getPrice() {
		return price;
	}

	void setProcessName(string s) {
		processName = s;
	}

	void setPrice(float p) {
		price = p;
	}
};

class MainMemory {
	int size;
	float price;

public:
	MainMemory() {
		size = 0;
		price = 0;
	}

	MainMemory(int s, float p) {
		size = s;
		price = p;
	}

	int getSize() {
		return size;
	}

	float getPrice() {
		return price;
	}

	void setSize(int x) {
		size = x;
	}

	void setPrice(float p) {
		price = p;
	}

};

class MotherBoard {
	string compName;

public:
	MotherBoard() {
		compName = "Intel";
	}

	void setcompName(string s) {
		compName = s;
	}

	string getcompName() {
		return compName;
	}
};

class Computer {
	Processor* proc;
	MainMemory* ram;
	MotherBoard* mboard;

public:
	Computer(Processor* p, MainMemory* m): proc(p), ram(m) {
		mboard = new MotherBoard;
	}

	~Computer() {
		delete mboard;
	}

	friend ostream& operator<<(ostream& out, Computer comp);


	//friend class Processor;
	//friend class MainMemory;
	//friend class MotherBoard;
};

ostream& operator<<(  ostream&  out, Computer comp) {
	out << "Processor : \n Name: " << comp.proc->getProcessname() << endl << "Price : " << comp.proc->getPrice() << endl << endl;
	out << "Main Memory : \n Size: " << comp.ram->getSize() << endl << "Price : " << comp.ram->getPrice() << endl << endl;
	cout << "MotherBoard : \n Name: " << comp.mboard->getcompName() << endl << endl;
	return out;
}


