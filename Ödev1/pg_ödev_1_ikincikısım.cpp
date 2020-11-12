/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 1. ödev -2
**				ÖÐRENCÝ ADI...............: Sedanur SARIKOÇ
**				ÖÐRENCÝ NUMARASI.: B181210110
**				DERS GRUBU…………: B
****************************************************************************/

#include <iostream>
#include <locale.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish"); //Sonuç ekranýnda Türkçe karakter kullanýmý için

	//Girilicek metindeki sesli harflerin sayýlarýný tutmak için sayaçlar oluþturuyoruz 
	int sayacA = 0;
	int sayacE = 0;
	int sayaci = 0;
	int sayaci_noktasiz = 0;
	int sayacO = 0;
	int sayacO_noktali = 0;
	int sayacU = 0;
	int sayacU_noktali = 0;

	//Metin giriþi yapýlýyor
	cout << "Metin giriniz: ";
	char metin[1000];

	//Enter tuþuna basýna veri almayý durdurmasý için 
	while (1)
	{
		cin.get(metin, 1000);
		if (char metin = '\n')break;
	}

	//Girilen metindeki tüm karakterler kontrol edilerek sayaç deðerleri harf sayýsýna göre arttýrýlýyor
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

	//Karþýlaþtýrma yapabilmek için sayaç deðerlerini diziye atýyoruz
	int sayac[8] = { sayacA,sayacE,sayaci,sayaci_noktasiz,sayacU,sayacU_noktali,sayacO,sayacO_noktali };
	int sayac_enbuyuk = sayac[0];

	//En büyük sayacý bulmak için dizideki bütün deðerler birbiriyle kontrol ediliyor
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

	//Tabloyu oluþturuyoruz. En büyük sayaç deðeri kadar sayý yazdýrmasý için bir döngü oluþturuyoruz.
	cout << "H\t" << "TS\t";
	for (int j = 1; j <= sayac_enbuyuk; j++)
	{
		cout << j << "  ";
	}

	cout << "\n";

	//Girilen harflerin ekrana tekrar sayýsý ve tekrar sayýsý kadar harfin çýkartýlmasý için 
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
		cout << "ý\t" << sayaci_noktasiz << "\t";
		for (int i = 0; i < sayaci_noktasiz ; i++)
		{
			cout << "ý  ";
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
		cout << "ü\t" << sayacU_noktali << "\t";
		for (int i = 0; i < sayacU_noktali ; i++)
		{
			cout << "ü  ";
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
		cout << "ö\t" << sayacO_noktali << "\t";
		for (int i = 0; i < sayacO_noktali; i++)
		{
			cout << "ö  ";
		}
		cout << "\n";
	}
	system("pause");
	
}