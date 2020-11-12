/****************************************************************************
**					               SAKARYA �N�VERS�TES�
**			              B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				              B�LG�SAYAR M�HEND�SL��� B�L�M�
**				                PROGRAMLAMAYA G�R��� DERS�
**
**			     	     �DEV NUMARASI.............: 2
**				         ��RENC� ADI...............: Sedanur SARIKO�
**				         ��RENC� NUMARASI..........: B181210110
**				         DERS GRUBU................: B
****************************************************************************/


#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//Program her �al��t���nda farkl� de�erlerler olu�turmak i�in
	srand(time(NULL)); 
	//Bir harf matrisi olu�turulur
    char harf_matrisi[5][10];
	//Matrisin elemanlar� olu�turuluyor
	for (int i = 0; i < 5; i++)  //Matrisin sat�r say�s� i�in 
	{
		for (int j = 0; j < 10; j++) //Matrisin s�tun say�s� i�in
		{
			//Rastegele harf olu�turmak i�in
			harf_matrisi[i][j] = 65 + rand() % 58;
			//Bir s�tun b�y�k, bir s�tun k���k olacak �ekilde elemanlar� ayarl�yoruz
			{
				if (j % 2 == 0) //Modu 2'ye g�re 0 olan s�tunlardaki k���k harfleri b�y�k harfe d�n��t�r�yoruz
				{
					if (islower(harf_matrisi[i][j])) //Harf k���k m� diye kontrol ediyoruz
						harf_matrisi[i][j] -= 32;
				}
				else //Di�er s�tun elemanlar�nda b�y�k harf varsa k���k harfe d�n��t�r�yoruz
				{
					if (isupper(harf_matrisi[i][j])) //Harf b�y�k m� diye kontrol ediyoruz
						harf_matrisi[i][j] += 32;
				}
			}

			//Ascii tablosunda belirtilen aral�kta harf olmayan elemanlar i�in tekrar de�er atamas� yapmak i�in
			if (harf_matrisi[i][j] > 90 && harf_matrisi[i][j] < 97)
				j--;
			//Yeni olu�turulan eleman�n �nceden oluturulup olu�turulmad��� kontrol ediliyor
			else
			{
				//Di�er elemanlarla kar��la�t�rma yapabilmek i�in ge�ici de�erler olu�turuluyor
				int a = j;
				int gecici_satir = i;
				int gecici_sutun = j - 1;
				//1. sat�r eleman�n� i�in kontrol yap�caksak bir �nceki sat�rdan devam edebilmek i�in 
				if (gecici_sutun == -1)
				{
					gecici_satir = i - 1;
					gecici_sutun = gecici_sutun + 10;
				}
				//Di�er elemanlar kontrol edilir ayn� eleman varsa tekrar de�er atanmas� sa�lan�r yoksa bir sonraki eleman i�in atama yap�l�r
				for (gecici_satir; gecici_satir >= 0 && a != j - 1; gecici_satir--) //Kontrol matrisin sat�r say�s�
				{
					for (gecici_sutun; gecici_sutun >= 0 && a != j - 1; gecici_sutun--) //Kontrol matrisin s�tun say�s�
					{
						//E�er yeni olu�turdu�umz eleman daha �nceolu�turulmu�sa tekrar harf olu�turulmas�n� sa�l�yoruz
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
	//Matrisin elemanlar� olu�turulma s�rar�yla ekrana yazd�r�l�yor
	for (int i = 0; i < 5; i++) //Matrisin sat�r�
	{
			for (int j = 0; j < 10; j++) //Matrisin s�tunu
				cout << harf_matrisi[i][j] << "\t";
			cout << "\n\n";
	}

	cout << "\nSiralanmis Dizi\n";
	//Matriste elemanlar�n yerlerini de�i�tirebilmek i�in	
	char gecici;
	//Matrisin b�t�n elemanlar� birbiriyle kar��la�t�r�larak b�y�kten k����e s�ralan�r ve ekrana yazd�r�l�r
	for (int i = 0; i < 5; i++) //Matrisin sat�r say�s�
	{
		for (int j = 0; j < 10; j++) //Matrisin s�tun say�s�
		{
			int b = j + 1;
			for (int a = i; a < 5; a++) //Matrisin sat�r say�s�
			{
				for (b; b < 10; b++) //Matrisin s�tun say�s�
				{
					if (harf_matrisi[a][b] < harf_matrisi[i][j]) //Matrisin bir eleman� di�er b�t�n elemanlarla kar��la�t�r�l�yor
					{
						//B�y�k olan matris di�er matrisle yer de�i�tirilir
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