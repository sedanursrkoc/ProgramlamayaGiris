/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 1. �dev -2
**				��RENC� ADI...............: Sedanur SARIKO�
**				��RENC� NUMARASI.: B181210110
**				DERS GRUBU����: B
****************************************************************************/

#include <iostream>
#include <locale.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //Sonu� ekran�nda T�rk�e karakter kullan�m� i�in

	//Girilicek metindeki sesli harflerin say�lar�n� tutmak i�in saya�lar olu�turuyoruz 
	int sayacA = 0;
	int sayacE = 0;
	int sayaci = 0;
	int sayaci_noktasiz = 0;
	int sayacO = 0;
	int sayacO_noktali = 0;
	int sayacU = 0;
	int sayacU_noktali = 0;

	//Metin giri�i yap�l�yor
	cout << "Metin giriniz: ";
	char metin[1000];

	//Enter tu�una bas�na veri almay� durdurmas� i�in 
	while (1)
	{
		cin.get(metin, 1000);
		if (char metin = '\n')break;
	}

	//Girilen metindeki t�m karakterler kontrol edilerek saya� de�erleri harf say�s�na g�re artt�r�l�yor
	for (int i = 0; i < 1000; i++)
	{
		
		if (metin[i] == 97 || metin[i] == 65)
		{
			sayacA++;
		}

		if (metin[i] == 101 || metin[i] == 69)
		{
			sayacE++;
		}
		
		if (metin[i] == 105 || metin[i] == -104)
		{
			sayaci++;
		}

		if (metin[i] == -115 || metin[i] == 73)
		{
			sayaci_noktasiz++;
		}

		if (metin[i] == 117 || metin[i] == 85)
		{
			sayacU++;
		}

		if (metin[i] == -127 || metin[i] == -102)
		{
			sayacU_noktali++;
		}
		
		
		if (metin[i] == 111 || metin[i] == 79)
		{
			sayacO++;
		}

		if (metin[i] == -108 || metin[i] == -103)
		{
			sayacO_noktali++;
		}
		
	}

	//Kar��la�t�rma yapabilmek i�in saya� de�erlerini diziye at�yoruz
	int sayac[8] = { sayacA,sayacE,sayaci,sayaci_noktasiz,sayacU,sayacU_noktali,sayacO,sayacO_noktali };
	int sayac_enbuyuk = sayac[0];

	//En b�y�k sayac� bulmak i�in dizideki b�t�n de�erler birbiriyle kontrol ediliyor
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (sayac[i] < sayac[j])
			{
				sayac_enbuyuk = sayac[j];
			}
		}
	}

	//Tabloyu olu�turuyoruz. En b�y�k saya� de�eri kadar say� yazd�rmas� i�in bir d�ng� olu�turuyoruz.
	cout << "H\t" << "TS\t";
	for (int j = 1; j <= sayac_enbuyuk; j++)
	{
		cout << j << "  ";
	}

	cout << "\n";

	//Girilen harflerin ekrana tekrar say�s� ve tekrar say�s� kadar harfin ��kart�lmas� i�in 
	if (sayacA != 0)
	{
		cout << "a\t" << sayacA<<"\t";
		for (int i = 0; i < sayacA; i++)
		{
			cout << "a  ";
		}
		cout << "\n";
	}

	if (sayacE != 0)
	{
		cout << "e\t" << sayacE << "\t";
		for (int i = 0; i < sayacE; i++)
		{
			cout << "e  ";
		}
		cout << "\n";
	}

	if (sayaci != 0)
	{
		cout << "i\t" << sayaci << "\t";
		for (int i = 0; i < sayaci; i++)
		{
			cout << "i  ";
		}
		cout << "\n";
	}

	if (sayaci_noktasiz != 0)
	{
		cout << "�\t" << sayaci_noktasiz << "\t";
		for (int i = 0; i < sayaci_noktasiz ; i++)
		{
			cout << "�  ";
		}
		cout << "\n";
	}

	if (sayacU != 0)
	{
		cout << "u\t" << sayacU << "\t";
		for (int i = 0; i < sayacU; i++)
		{
			cout << "u  ";
		}
		cout << "\n";
	}
	
	if (sayacU_noktali != 0)
	{
		cout << "�\t" << sayacU_noktali << "\t";
		for (int i = 0; i < sayacU_noktali ; i++)
		{
			cout << "�  ";
		}
		cout << "\n";
	}

	if (sayacO != 0)
	{
		cout << "o\t" << sayacO << "\t";
		for (int i = 0; i < sayacO; i++)
		{
			cout << "o  ";
		}
		cout << "\n";
	}

	if (sayacO_noktali != 0)
	{
		cout << "�\t" << sayacO_noktali << "\t";
		for (int i = 0; i < sayacO_noktali; i++)
		{
			cout << "�  ";
		}
		cout << "\n";
	}
	system("pause");
	
}