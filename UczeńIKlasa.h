#pragma once
#include <iostream>
#include<string.h>
using namespace std;

class Student {
	friend class Class;
	string name;
	string surname;
	int gradeSize;
	int* grades;
	bool passing;
	static int studentCount;
public:
	Student(string _name, string _surname, int _gradeSize = 0, int* _grades = nullptr, bool _passing = true);
	Student();
	Student(const Student& d);
	~Student();
	void Free();
	void Init(int n);
	void Fill(int* n,int size);
	double GetAvg();
	bool GetPass() { return passing; };
	void Passed();
	void NotPassed();
	void AddGrade(int n);
	void DeleteGrade(int n);
	void StudentCount() { cout<< "Current students count:" << this->studentCount << endl; };
	bool IsBetter(Student& v);
	friend istream& operator>>(istream& in, Student& d);
	friend ostream& operator<<(ostream& out, const Student& d);
	bool operator==(const Student& d);
	Student& operator=(const Student& d);
};


class Class {
	string teacher;
	int pupilCount;
	Student* pupils;
	int classID;
	static int classCount;
public:
	enum class Extension {
		math,
		physics,
		biology,
		polish,
		history
	};
	Extension ex;
	Class(string _teacher, int _pupilCOunt, Student* _pupils,Extension _ex);
	Class();
	Class(const Class& c);
	~Class();
	friend int GetID(Class c) { return c.classID; };
	void Init(int n);
	void Fill(Student* n, int size);
	void Fix();
	void AddPupil(Student& s);
	void DeletePupil(Student& s);
	string GetEx();
	Class& operator=(const Class& c);
	bool operator==(const Class& c);
	friend ostream& operator<<(ostream& out,Class& d);
	bool operator>(Class f);
	bool operator<(Class f);
};





