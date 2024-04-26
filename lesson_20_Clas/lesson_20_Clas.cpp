// lesson_20_Clas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Record.h"



int main()
{
// Конструктор за замовчуванням
    Record a; 


// Конструктор з параметрами
    Record b("Iskorostenskyi M", "+380954206850", "Kharkiv", "mykola@gmail.com");

    a.showInfo();

    b.showInfo();

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    a.setName(" ");// error
    a.setName("levshenko Y ");

    b.setAddress("Bezlludovka ");

    cout << a.getName() << "Live in " << a.getAddress() << endl;
    cout << b.getName() << "Live in " << b.getAddress() << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    a.addPhoneNumbers("0505892080");
    a.addPhoneNumbers("12-25-58");
    a.addPhoneNumbers("8888-8888");

    b.addPhoneNumbers("7777-77777");
    a.showInfo();
    b.showInfo();

}

