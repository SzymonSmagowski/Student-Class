

#include <iostream>
#include"UczeñIKlasa.h"
using namespace std;

int main()
{
    //================= PART 1 =====================
    cout << "================= PART 1 =====================" << endl;

    Student s1;
    s1.StudentCount();
    int g2[] = {1,2,3,4,5,6,7};
    Student s2("Szymon", "Smagowski", 7, g2,true);
    s1.StudentCount();
    int g3[] = { 1,2,3};
    Student s3("arek", "kordian", 3, g3, false);
    s1.StudentCount();
    Student s4;
    s1.StudentCount();
    cout << "Should be 4 students" << endl;

    //================= PART 2 =====================
    cout << "================= PART 2 =====================" << endl;

    cin >> s4;
    cout << "=========WORK ON S2:===========" << endl;
    cout << s2 << endl;
    cout << "Average:" << endl;
    cout << s2.GetAvg() << endl;  
    cout << "Passing for s2: " << s2.GetPass() << endl;
    s2.NotPassed();
    cout << s2 << endl;
    if (s2.IsBetter(s3)) {
        cout << "Student 2 is better. Good!" << endl;
    }
    s2.Passed();
    cout << s2;
    s2.AddGrade(5);
    cout << s2;
    s2.DeleteGrade(1);
    cout << s2;
    s2.DeleteGrade(4);
    cout << s2;
    Student s5;
    cout << s5 << endl;
    s5 = s3;
    cout << s5 << endl;
    Student s6(s5);
    cout << s6 << endl;

    //================= PART 3 =====================
    cout << "================= PART 3 =====================" << endl;

    Class c1;
    Student tab1[] = { s2,s3,s1 };
    Class c2("Mr. Br¹zowy", 3,tab1,Class::Extension::math);
    Class c3(c2);

    //================= PART 4 =====================
    cout << "================= PART 4 =====================" << endl;

    cout << "=======WORK ON C3===========" << endl;
    cout << "ID of a c3:" << endl;
    cout << GetID(c3) << endl;
    cout << c3 << endl;

    int g4[] = { 1,5,3 };
    Student s7("arek", "maciejewski", 3, g3, true);
    c3.AddPupil(s7);
    cout << c3 << endl;
    cout << "Should delete empty and not passing students:" << endl;
    c3.Fix();
    cout << c3 << endl;
    if (c3 == c2) {
        cout << "Those are the same classes" << endl;
    }
    else
    {
        cout << "Those are not the same classes. Good!" << endl;
    }
    if (c1 < c2) {
        cout << "Good" << endl;
    }
    if (c2 > c1) {
        cout << "Good" << endl;
    }
    Class c4(c3);
    if (c4 == c3) {
        cout << "Those are the same classes. Good!" << endl;
    }
    //================= PART 5 =====================
    cout << "================= PART 5 =====================" << "There should be info about destructors." << endl;
}

