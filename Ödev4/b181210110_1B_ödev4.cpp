/****************************************************************************
**					                     SAKARYA ÜNÝVERSÝTESÝ
**			                  BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				                  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				                     PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				                ÖDEV NUMARASI.............: 4
**				                ÖÐRENCÝ ADI...............: Sedanur SARIKOÇ
**				                ÖÐRENCÝ NUMARASI..........: b181210110
**				                DERS GRUBU................: 1B
****************************************************************************/
#ifndef Sifre_h
#define Sifre_h

using namespace std;

class Sifre
{
public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char*	sifrele(char *sifre);
	char*	sifreCoz(char* sifre);
	void	sifreKelimesiAta(char*);

private:
	char* alfabe;
	char* sifreKelimesi;
};
#endif

#include <iostream>

using namespace std;

int main()
{
	char alfabe[100];
	char sifre[100];
	char metin[100];
	char sifreKelimesi[100];
	char desifreMetin[100];

	cout << "ALFABE		   :";
	cin >> alfabe;
	cout << "SIFRE		   :";
	cin >> sifre;
	cout << "METIN		   :";
	cin >> metin;
	int alfabeUzunluk = strlen(alfabe);
	int  metinUzunluk = strlen(metin);
	int  sifreUzunluk = strlen(sifre);
	cout << "SIFRELENMIS METIN  :";
	int j = 0;
	for (int i = 0; i < metinUzunluk; i++)
	{
		sifreKelimesi[i] = int(metin[i]) + (int(sifre[j]) - alfabe[0]) + 1;
		if (sifreKelimesi[i] > alfabe[alfabeUzunluk - 1])
		{
			sifreKelimesi[i] = alfabe[0] + sifreKelimesi[i] - alfabe[alfabeUzunluk - 1] - 1;
		}
		cout << sifreKelimesi[i];
		if (j == sifreUzunluk - 1)
			j = 0;
		else
			j++;
	}
	
	cout << "\nDESIFRE METIN	   :";
	j = 0;
	for (int i = 0; i < metinUzunluk; i++)
	{
		desifreMetin[i] = sifre[j];
		desifreMetin[i] = int(sifreKelimesi[i]) - (int(desifreMetin[i]) - alfabe[0]) - 1;
		if (desifreMetin[i] < alfabe[0] && sifreKelimesi[i] > sifre[j])
		{
			desifreMetin[i] = alfabe[alfabeUzunluk - 1] - (int(sifreKelimesi[i]) - int(sifre[j]));
		}
		if (desifreMetin[i] < alfabe[0] && sifreKelimesi[i] < sifre[j])
		{
			desifreMetin[i] = alfabe[alfabeUzunluk - 1] - (int(sifre[j]) - int(sifreKelimesi[i]));
		}
		
		cout << desifreMetin[i];
		if (j == sifreUzunluk - 1)
			j = 0;
		else
			j++;
	}

	cout << endl;
	system("pause");
}

