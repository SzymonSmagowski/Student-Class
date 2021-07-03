#include"UczeñIKlasa.h"

int Student::studentCount = 0;
Student::Student(string _name, string _surname, int _gradeSize, int* _grades, bool _passing)
{
	name = _name;
	surname = _surname;
	passing = _passing;
	Init(_gradeSize);
	Fill(_grades,_gradeSize);
	studentCount++;
}

Student::Student()
{
	name = "";
	surname = "";
	gradeSize = 0;
	grades = nullptr;
	passing = false;
	studentCount++;
}

Student::Student(const Student& d) {
	*this = d;
}



Student::~Student()
{
	Free();
	cout << "Destructor " << endl;
}

void Student::Free()
{
	if (this->grades != nullptr) {
		delete[] grades;
	}
	else
	{
		return;
	}
}

void Student::Init(int n)
{
	if (n < 0) {
		cout << "Size of grades should be positive or 0!" << endl;
		grades = nullptr;
		gradeSize = 0;
		return;
	}
	if (n == 0) {
		grades = nullptr;
		gradeSize = 0;
		return;
	}
	this->grades = new int[n];
	this->gradeSize = n;
	for (int i = 0; i < n; i++) {
		grades[i] = 0;
	}
	return;
}

void Student::Fill(int *n,int size)
{
	if (size != gradeSize) {
		cout << "To fill grades both sizes should be equal!" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		grades[i] = n[i];
	}
	return;
}

double Student::GetAvg()
{
	if (gradeSize == 0) {
		cout << "Cannot count avarage without grades" << endl;
		return 0;
	}
	double avg = 0;
	double sum = 0;
	for (int i = 0; i < gradeSize; i++) {
		sum += grades[i];
	}
	avg = sum / gradeSize;
	return avg;
}

void Student::NotPassed()
{
	if (passing == true) {
		passing = false;
	}
}

void Student::AddGrade(int n)
{
	gradeSize++;
	int* tmp=new int [gradeSize];
	for (int i = 0; i < gradeSize-1; i++) {
		tmp[i] = grades[i];
	}
	tmp[gradeSize - 1] = n;
	Init(n);
	Fill(tmp, gradeSize);
}

void Student::DeleteGrade(int n)
{
	bool thereIs = false;
	if (gradeSize == 0) {
		cout << "Can't delete grade from empty notebook" << endl;
		return;
	}
	for (int k = 0; k < gradeSize; k++) {
		if (grades[k] == n) {
			thereIs = true;
		}
	}
	if (thereIs != true) {
		cout << "Grade is not in this notebook" << endl;
		return;
	}
	gradeSize--;
	int* tmp = new int[gradeSize];
	int i=0;
	for (; i < gradeSize; i++) {
		if (grades[i]==n) {
			break;
		}
		tmp[i] = grades[i];
	}
	for (; i < gradeSize; i++) {
		tmp[i] = grades[i+1];
	}
	Init(n);
	Fill(tmp, gradeSize);
}

bool Student::IsBetter(Student& v)
{
	if (this->GetAvg() > v.GetAvg()) {
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::operator==(const Student& d)
{
	if (this->name != d.name) {
		return false;
	}
	if (this->surname != d.surname) {
		return false;
	}
	if (this->gradeSize != d.gradeSize) {
		return false;
	}
	if (this->passing != d.passing) {
		return false;
	}
	for (int i = 0; i < gradeSize; i++) {
		if (this->grades[i] != d.grades[i]) {
			return false;
		}
	}
	return true;
}

Student& Student::operator=(const Student& d)
{
	this->name = d.name;
	this->surname = d.surname;
	this->passing = d.passing;
	this->Init(d.gradeSize);
	this->Fill(d.grades,d.gradeSize);
	return *this;
}

void Student::Passed()
{
	if (passing == false) {
		passing = true;
	}
}

istream& operator>>(istream& in, Student& d)
{

	cout << "Enter the name of student:" << endl;
	in >> d.name;
	cout << "Enter the surname of student:" << endl;
	in >> d.surname;
	cout << "Enter the number of grades:" << endl;
	in >> d.gradeSize;
	cout << "Enter all grades after enter:" << endl;
	d.Init(d.gradeSize);
	for (int i = 0; i < d.gradeSize; i++) {
		in >> d.grades[i];
	}
	string s;
	cout << "If you want student to pass press yes, otherwise no." << endl;
	in >> s;
	while (!(s == "yes" || s == "no")) {
		cout << "Write yes or no:" << endl;
		in >> s;
	}
	if (s == "yes") {
		d.passing = true;
	}
	else
	{
		d.passing = false;
	}
	return in;
}

ostream& operator<<(ostream& out, const Student& d)
{
	out << d.name << " " << d.surname << endl;
	out << "Grades: " << endl;
	for (int i = 0; i < d.gradeSize; i++) {
		out << d.grades[i] << " ";
	}
	out << endl;
	if (d.passing == true) {
		out << "Student is passing." << endl;
	}
	else
	{
		out << "Student is not passing." << endl;
	}
	out << endl;
	return out;
}

ostream& operator<<(ostream& out, Class& d)
{
	out << "The class: " << d.classID << ":" << endl;
	out << "The educator is: " << d.teacher << ":" << endl;
	out << "The extension is " << d.GetEx() << endl;
	out << "Number of students: " << d.pupilCount << endl;
	out << "Students: " << endl;
	for (int i = 0; i < d.pupilCount; i++) {
		out << d.pupils[i];
	}
	return out;
}

int Class::classCount = 0;

Class::Class(string _teacher, int _pupilCount, Student* _pupils, Extension _ex)
{
	teacher = _teacher;
	classCount++;
	classID = classCount;
	Init(_pupilCount);
	Fill(_pupils, _pupilCount);
	ex = _ex;
}

Class::Class()
{
	teacher = "";
	classCount++;
	classID = classCount;
	pupilCount = 0;
	pupils = nullptr;
	ex = Extension::math;
}

Class::Class(const Class& c)
{
	*this = c;
}

Class::~Class()
{
	if (this->pupils != nullptr) {
		delete[] pupils;
		cout << "class destructor" << endl;
	}
	else
	{
		cout << "class destructor" << endl;
		return;
	}
}

void Class::Init(int n)
{
	if (n < 0) {
		cout << "Size of pupils should be positive or 0!" << endl;
		pupils = nullptr;
		pupilCount = 0;
		return;
	}
	if (n == 0) {
		pupils = nullptr;
		pupilCount = 0;
		return;
	}
	this->pupils = new Student[n];
	this->pupilCount = n;
	return;
}

void Class::Fill(Student* n, int size)
{
	if (size != pupilCount) {
		cout << "To fill pupils both classes shall be equal" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		pupils[i] = n[i];
	}
	return;
}

void Class::Fix()
{
	for (int i = 0; i < pupilCount; i++) {
		if (pupils[i].GetPass() == false) {
			DeletePupil(pupils[i]);
		}
		if (pupils[i].name == "") {
			DeletePupil(pupils[i]);
		}
	}
}

void Class::AddPupil(Student& s)
{
	pupilCount++;
	Student* tmp = new Student[pupilCount];
	for (int i = 0; i < pupilCount - 1; i++) {
		tmp[i] = pupils[i];
	}
	tmp[pupilCount - 1] = s;
	Init(pupilCount);
	Fill(tmp, pupilCount);
}

void Class::DeletePupil(Student& s)
{
	bool thereIs = false;
	if (pupilCount == 0) {
		cout << "Can't delete pupil from empty class" << endl;
		return;
	}
	for (int k=0; k < pupilCount; k++) {
		if (pupils[k] == s) {
			thereIs = true;
		}
	}
	if (thereIs != true) {
		cout << "Pupil is not in this class" << endl;
		return;
	}
	pupilCount--;
	Student* tmp = new Student[pupilCount];
	int i = 0;
	for (; i < pupilCount; i++) {
		if (pupils[i] == s) {
			break;
		}
		tmp[i] = pupils[i];
	}
	for (; i < pupilCount; i++) {
		tmp[i] = pupils[i + 1];
	}
	Init(pupilCount);
	Fill(tmp, pupilCount);
}

string Class::GetEx()
{
	string temp = "";
	if (this->ex == Extension::biology) {
		temp = "biology";
	}
	if (this->ex == Extension::math) {
		temp = "math";
	}
	if (this->ex == Extension::history) {
		temp = "history";
	}
	if (this->ex == Extension::physics) {
		temp = "physics";
	}
	if (this->ex == Extension::polish) {
		temp = "polish";
	}
	return temp;
}

Class& Class::operator=(const Class& c)
{
	this->classID = c.classID;
	this->ex = c.ex;
	this->teacher = c.teacher;
	this->pupilCount = c.pupilCount;
	this->Init(pupilCount);
	this->Fill(c.pupils, pupilCount);
	return *this;
}

bool Class::operator==(const Class& c)
{
	if (this->ex != c.ex) {
		return false;
	}
	if (this->teacher != c.teacher) {
		return false;
	}
	if (this->classID != c.classID) {
		return false;
	}
	if (this->pupilCount != c.pupilCount) {
		return false;
	}
	for (int i = 0; i < pupilCount; i++) {
		if (this->pupils[i] == c.pupils[i]) {
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Class::operator>(Class f)
{
	if (this->pupilCount > f.pupilCount) {
		return true;
	}
	return false;
}

bool Class::operator<(Class f)
{
	if (this->pupilCount < f.pupilCount) {
		return true;
	}
	return false;
}
