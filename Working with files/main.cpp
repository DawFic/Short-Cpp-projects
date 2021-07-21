#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{

	string tekst, sciezka, tekstZPliku;

	cout << "Podaj sciezke do pliku: " << endl;
	getline(cin , sciezka);
    fstream file;
    string typ;
    cout<<"Jesli chcesz otworzyc plik jako tekstowy wprowadz TXT, jesli chcesz otworzyc plik jako binarny wpisz BIN"<<endl;
    cin>>typ;
     cout<<endl;
	if (typ == "BIN")
	    file.open(sciezka, ios::binary | ios::in);
	else if (typ == "TXT")
	    file.open(sciezka, ios::in);
	else
	    return 0;

	if (!file.is_open())
	{
		cout << "Plik nie istnieje" << endl;
		return 0;
	}
	else {
		cout << "Dane w pliku: " << endl;
		while (getline(file, tekstZPliku)) {
			cout<<tekstZPliku;
            cout<<endl;
		}
		cout << endl;
	}
	file.close();
	cout<<"Jesli chcesz nadpisac plik wprowadz X, jesli chcesz dopisac do pliku wprowadz Z"<<endl;
	string komenda;
	cin>>komenda;
	cout<<endl;
	if(komenda == "X" && typ == "txt")
	    file.open(sciezka,ios::out);
	else if(komenda == "Z" && typ == "txt")
	    file.open(sciezka,ios::app);
	else if(komenda == "X" && typ == "dat")
	    file.open(sciezka,ios::out | ios::binary);
	else if(komenda == "Z" && typ == "dat")
	    file.open(sciezka, ios::app | ios::binary);
	else
	    return 0;
	cout << "Aby zakonczyc wprowadz EOF:" << endl;
	getline(cin, tekst);

	while (tekst != "EOF")
	{
        getline(cin , tekst);
        if(tekst == "EOF")
            break;
        file<<tekst;
        file<<std::endl;
	}

	file.close();

}

