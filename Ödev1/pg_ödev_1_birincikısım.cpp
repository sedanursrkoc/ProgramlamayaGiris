/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...:1. �dev -1
**				��RENC� ADI...............: Sedanur SARIKO�
**				��RENC� NUMARASI.:B181210110
**				DERS GRUBU����:B
****************************************************************************/

#include <iostream>

using namespace std;
int main()
{
	for (int i = 0; i < 6; i++) //sat�r say�s�(ka� sat�r y�ld�z yazd�rmak istiyorsak)
	{
		for (int j = i+1; j <6; j++) //s�tun say�s�(bir sat�rdaki y�ld�z say�s�)
		{
			cout << "*  ";
		}

		for (int a = 0;a<=i*4 ;a+=2 ) // arada b�rak�l�cak bo�luk i�in de bir d�ng� olu�turuyoruz
		{
			cout << "   ";
		}
		
		for (int j = i + 1; j < 6; j++) //s�tun say�s�(bir sat�rdaki y�ld�z say�s�)
		{
			cout << " * ";
		}
		cout << "\n";
	}
	
	for (int k = 5; k > 0 ; k--) //sat�r say�s�(ka� sat�r y�ld�z yazd�rmak istiyorsak)
	{
		for (int j = 5; j >k-1 ; j--) //s�tun say�s�(bir sat�rdaki y�ld�z say�s�)
		{
			cout << "*  ";
		}

		for (int a = (4*k)-1; a >1 ; a-=2) // arada b�rak�l�cak bo�luk i�in de bir d�ng� olu�turuyoruz
		{
			cout << "   ";
		}

		for (int j = 6; j >=k+1; j--) //s�tun say�s�(bir sat�rdaki y�ld�z say�s�)
		{
			cout << " * ";
		}
		cout << "\n";
		
	}
	system("pause");
}