#pragma once
#include<iostream>
using namespace std;

class Professor {
	string name;
	int employeeID;
	string designation;

public:
	Professor() {
		name = "";
		employeeID = 0;
		designation = "";

	}

	Professor(string n, int x, string d) {
		name = n;
		employeeID = x;
		designation = d;
	}

	void setname(string s) {
		name = s;
	}

	void setemployeeID(int x) {
		employeeID = x;
	}

	void setDesignation(string s) {
		designation = s;
	}

	string getName() {
		return name;
	}
	int getID() {
		return employeeID;
	}

	string getDesignation() {
		return designation;
	}
};


class Department {
	string name;
	int deptID;
	Professor* profList;
	int noOfProfessors;

public:
	Department() {
		name = "";
		deptID = 0;
		profList = nullptr;
		noOfProfessors = 5;
	}
	Department(string n, int x, Professor* p, int size) {
		name = n;
		deptID = x;
		profList = p;
		noOfProfessors = size;
	}


	string getName() {
		return name;
	}

	void setName(string s) {
		name = s;
	}

	int getDeptID() {
		return deptID;
	}
	void setID(int x) {
		deptID = x;
	}

	Professor* getProfList() {
		return profList;
	}

	void setList(Professor* p) {
		profList = p;
	}
	int getNoOfProfessors() {
		return noOfProfessors;
	}

	void setNoOfProf(int no) {
		noOfProfessors = no;
	}

	bool addProfessor(Professor p) {
		Professor* temp;
		noOfProfessors++;
		temp = new Professor[noOfProfessors];
		int x = 0;

		while (x < noOfProfessors-1) {
			temp[x]=profList[x];
			x++;
		}
		temp[noOfProfessors-1] = p;
	}


	bool deleteProfessor(int id) {
		int x = 0;
		int check = -1;
		while (x < noOfProfessors) {
			if (profList[x].getID() == id) {
				check = x;
			}
		}

		if (check == -1) {
			return false;
		}

		for (int i = x; i < noOfProfessors-1; i++) {
			profList[x].setname(profList[x + 1].getName());
			profList[x].setDesignation(profList[x + 1].getDesignation());
			profList[x].setemployeeID(profList[x + 1].getID());
		}

		noOfProfessors--;

	}

	void display() {
		int x = 0;
		while (x < noOfProfessors) {
			cout << "Name : " << name << endl;
			cout << " deptID : " << deptID << endl;
			x++;
		}
	}

};

class University {
	string name;
	Department* dept;
	int numberOfDepartments;
public:
	University(string s, Department* d, int x) {
		name = s;
		dept = new Department[x];
		numberOfDepartments = x;
		int y = 0;
		while (y<x ) {
			dept[y] = d[y];
			y++;
		}
	}

	bool addDepartment(Department D) {
		bool flag = false;
		Department* temp = new Department[numberOfDepartments];
	//	(D.getName(), D.getDeptID(), D.getProfList(), numberOfDepartments);
		int y = 0;
		while (y < numberOfDepartments) {
			temp[y] = dept[y];
			y++;
		}
		numberOfDepartments++;

		delete[] dept;
		dept = new Department[numberOfDepartments];
		int x = 0;

		while (x < numberOfDepartments-1) {
			dept[x] = temp[x];
		}
		
		dept[numberOfDepartments-1] = D;

	}

	bool deleteDepartment(string name) {
		int x = 0;
		int check = -1;
		while (x < numberOfDepartments) {
			if (dept[x].getName() == name) {
				check = x;
			}
			x++;
		}
		if (check == -1) {
			return false;
		}
		for (int i = x; i < numberOfDepartments-1; i++) {
			dept[x].setName(dept[x+1].getName());
			dept[x].setList(dept[x + 1].getProfList());
			dept[x].setID(dept[x + 1].getDeptID());
			dept[x].setNoOfProf(dept[x + 1].getNoOfProfessors());
		}
		numberOfDepartments--;
	}

	void display() {
		cout << "NAME : " << name << endl;
		cout << "NUMBER OF DEPTS : " << numberOfDepartments << endl;
		int x = 0 ;
		while (x<numberOfDepartments) {
			cout << dept[x].getDeptID() << endl;
			cout << dept[x].getName() << endl;
			cout << dept[x].getNoOfProfessors() << endl;
			x++;
		}
	}


	~University() {
		delete[] dept;
	}


};


