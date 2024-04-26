#include "Record.h"
#define DEBUG
Record::Record()
{
	strcpy_s(name, 50, "Pupkin");
	nPhones = 1;
	phones = new char* [nPhones];
	phones[0] = new char[50] {"+380954206850"};

	strcpy_s(address, 50, "Kharkiv");
	strcpy_s(email, 50, "Pupkin@gmail.com");

#ifdef DEBUG

	cout << "Record(): " << name << endl;

#endif // DEBUG


}

Record::Record(const char* name, const char* phone, const char* address, const char* email)
{

	strcpy_s(this->name, 50, name);
	nPhones = 1;
    // виділення памяті для масиву рядків
	phones = new char* [nPhones]; 
	// виділення памяті під перший рядок
	phones[0] = new char[50] { "" };
	// Вносимо данні в цей рядок
	strcpy_s(this->phones[0], 50, phone);
	strcpy_s(this->address, 50, address);
	strcpy_s(this->email, 50, email);
#ifdef DEBUG

	cout << "Record(n, ph, add, email): " << endl;

#endif // DEBUG

}

Record::~Record()
{
#ifdef DEBUG

	cout << "~Record() " << name << endl;


#endif // DEBUG

	for (int i = 0; i < nPhones; i++)
	{
		delete[] phones[i];
	}
	delete[] phones;
}

void Record::showInfo()
{
	cout << "============================"  << endl;
	cout << "mame: " << name << endl;
	cout << "Phones: " << nPhones << endl;
	for (int i = 0; i <  nPhones; i++)
	{
		cout << "\t#" << i + 1 << ". " << phones[i] << endl;
	}
	cout << "Adress: " << address << endl;
	cout << "Email: " << email << endl;
	cout << "============================" << endl;
}


void Record::setName(const char* newName)
{
	if (strlen(newName) > 2) {
		strcpy_s(name, 50, newName);
	}
	else {
		cout << "Error strlen(newName): \n";
	};

}

void Record::setAddress(const char* newAddress)
{
	if (strlen(newAddress) > 5) {
		strcpy_s(name, 50, newAddress);
	}
	else {
		cout << "Error strlen(newAddress): \n";
	};
}

void Record::setEmail(const char* newEmail)
{
	if (strlen(newEmail) >= 5 && strstr(newEmail, "@") != NULL) {
		strcpy_s(email, 50, newEmail) ;
		

	}
	else {
		cout << "Error strlen(newEmail): <5 Not found @!!!\n";
	};
}

const char* Record::getName()
{
	return name;
}

int Record::getAmountPhones()
{
	return nPhones;
}

const char* Record::getAddress()
{
	return address;
}

const char* Record::getEmail()
{
	return email;
}
void Record::addPhoneNumbers(const char* number)
{
	if (strlen(number) > 5) {
		nPhones++;

		char** tmp = new char* [nPhones];
		for (int i = 0; i < nPhones; i++)
		{
			tmp[i] = phones[i];
		}delete[] phones;
		tmp[nPhones - 1] = new char[50] {""};
		strcpy_s(tmp[nPhones - 1], 50, number);

		phones = tmp;
	}
	else
	{
		cout << "Error !!! \n";
	}
}
