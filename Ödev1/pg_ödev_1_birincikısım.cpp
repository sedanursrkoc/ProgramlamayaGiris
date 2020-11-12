/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:1. ödev -1
**				ÖÐRENCÝ ADI...............: Sedanur SARIKOÇ
**				ÖÐRENCÝ NUMARASI.:B181210110
**				DERS GRUBU…………:B
****************************************************************************/

#include <iostream>

using namespace std;
int main()
{
	for (int i = 0; i < 6; i++) //satýr sayýsý(kaç satýr yýldýz yazdýrmak istiyorsak)
	{
		for (int j = i+1; j <6; j++) //sütun sayýsý(bir satýrdaki yýldýz sayýsý)
		{
			cout << "*  ";
		}

		for (int a = 0;a<=i*4 ;a+=2 ) // arada býrakýlýcak boþluk için de bir döngü oluþturuyoruz
		{
			cout << "   ";
		}
		
		for (int j = i + 1; j < 6; j++) //sütun sayýsý(bir satýrdaki yýldýz sayýsý)
		{
			cout << " * ";
		}
		cout << "\n";
	}
	
	for (int k = 5; k > 0 ; k--) //satýr sayýsý(kaç satýr yýldýz yazdýrmak istiyorsak)
	{
		for (int j = 5; j >k-1 ; j--) //sütun sayýsý(bir satýrdaki yýldýz sayýsý)
		{
			cout << "*  ";
		}

		for (int a = (4*k)-1; a >1 ; a-=2) // arada býrakýlýcak boþluk için de bir döngü oluþturuyoruz
		{
			cout << "   ";
		}

		for (int j = 6; j >=k+1; j--) //sütun sayýsý(bir satýrdaki yýldýz sayýsý)
		{
			cout << " * ";
		}
		cout << "\n";
		
	}
	system("pause");
}