/****************************************************************************
**					               SAKARYA ÜNÝVERSÝTESÝ
**			              BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				                PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**			     	     ÖDEV NUMARASI.............: 2
**				         ÖÐRENCÝ ADI...............: Sedanur SARIKOÇ
**				         ÖÐRENCÝ NUMARASI..........: B181210110
**				         DERS GRUBU................: B
****************************************************************************/


#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//Program her çalýþtýðýnda farklý deðerlerler oluþturmak için
	srand(time(NULL)); 
	//Bir harf matrisi oluþturulur
    char harf_matrisi[5][10];
	//Matrisin elemanlarý oluþturuluyor
	for (int i = 0; i < 5; i++)  //Matrisin satýr sayýsý için 
	{
		for (int j = 0; j < 10; j++) //Matrisin sütun sayýsý için
		{
			//Rastegele harf oluþturmak için
			harf_matrisi[i][j] = 65 + rand() % 58;
			//Bir sütun büyük, bir sütun küçük olacak þekilde elemanlarý ayarlýyoruz
			{
				if (j % 2 == 0) //Modu 2'ye göre 0 olan sütunlardaki küçük harfleri büyük harfe dönüþtürüyoruz
				{
					if (islower(harf_matrisi[i][j])) //Harf küçük mü diye kontrol ediyoruz
						harf_matrisi[i][j] -= 32;
				}
				else //Diðer sütun elemanlarýnda büyük harf varsa küçük harfe dönüþtürüyoruz
				{
					if (isupper(harf_matrisi[i][j])) //Harf büyük mü diye kontrol ediyoruz
						harf_matrisi[i][j] += 32;
				}
			}

			//Ascii tablosunda belirtilen aralýkta harf olmayan elemanlar için tekrar deðer atamasý yapmak için
			if (harf_matrisi[i][j] > 90 && harf_matrisi[i][j] < 97)
				j--;
			//Yeni oluþturulan elemanýn önceden oluturulup oluþturulmadýðý kontrol ediliyor
			else
			{
				//Diðer elemanlarla karþýlaþtýrma yapabilmek için geçici deðerler oluþturuluyor
				int a = j;
				int gecici_satir = i;
				int gecici_sutun = j - 1;
				//1. satýr elemanýný için kontrol yapýcaksak bir önceki satýrdan devam edebilmek için 
				if (gecici_sutun == -1)
				{
					gecici_satir = i - 1;
					gecici_sutun = gecici_sutun + 10;
				}
				//Diðer elemanlar kontrol edilir ayný eleman varsa tekrar deðer atanmasý saðlanýr yoksa bir sonraki eleman için atama yapýlýr
				for (gecici_satir; gecici_satir >= 0 && a != j - 1; gecici_satir--) //Kontrol matrisin satýr sayýsý
				{
					for (gecici_sutun; gecici_sutun >= 0 && a != j - 1; gecici_sutun--) //Kontrol matrisin sütun sayýsý
					{
						//Eðer yeni oluþturduðumz eleman daha önceoluþturulmuþsa tekrar harf oluþturulmasýný saðlýyoruz
						if (harf_matrisi[gecici_satir][gecici_sutun] == harf_matrisi[i][j]) 
						{
							a = j - 1;
							j = j - 1;
						}
					}
					gecici_sutun = gecici_sutun + 10;
				}
			}
		}
	}
	cout << "\nTekrarsiz ve Rastgele Dizi\n";
	//Matrisin elemanlarý oluþturulma sýrarýyla ekrana yazdýrýlýyor
	for (int i = 0; i < 5; i++) //Matrisin satýrý
	{
			for (int j = 0; j < 10; j++) //Matrisin sütunu
				cout << harf_matrisi[i][j] << "\t";
			cout << "\n\n";
	}

	cout << "\nSiralanmis Dizi\n";
	//Matriste elemanlarýn yerlerini deðiþtirebilmek için	
	char gecici;
	//Matrisin bütün elemanlarý birbiriyle karþýlaþtýrýlarak büyükten küçüðe sýralanýr ve ekrana yazdýrýlýr
	for (int i = 0; i < 5; i++) //Matrisin satýr sayýsý
	{
		for (int j = 0; j < 10; j++) //Matrisin sütun sayýsý
		{
			int b = j + 1;
			for (int a = i; a < 5; a++) //Matrisin satýr sayýsý
			{
				for (b; b < 10; b++) //Matrisin sütun sayýsý
				{
					if (harf_matrisi[a][b] < harf_matrisi[i][j]) //Matrisin bir elemaný diðer bütün elemanlarla karþýlaþtýrýlýyor
					{
						//Büyük olan matris diðer matrisle yer deðiþtirilir
						gecici = harf_matrisi[i][j];
						harf_matrisi[i][j] = harf_matrisi[a][b];
						harf_matrisi[a][b] = gecici;
					}
				}
				b = b - 10;
		    }
			cout << harf_matrisi[i][j] << "\t";
		}
			cout << "\n\n";
	}

	system("pause");
	return 0;
}