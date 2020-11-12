/****************************************************************************
**					                     SAKARYA ÜNÝVERSÝTESÝ
**			                  BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				                  BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				                     PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				                ÖDEV NUMARASI.............: 3
**				                ÖÐRENCÝ ADI...............: Sedanur SARIKOÇ
**				                ÖÐRENCÝ NUMARASI..........: b181210110
**				                DERS GRUBU................: 1B
****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

const int maxboyut = 5;
const int minboyut = 2;
int giris_boyut = 0;

struct Islem
{
	int giris[8][8] = { 1,4,6,1,1,0,0,0,
					    2,1,3,1,1,1,1,1,
						1,2,3,0,1,2,2,2,
						1,1,1,1,1,3,3,3,
						2,2,2,2,2,4,4,4,
	                    5,2,4,3,1,0,4,1,
	                    8,1,0,3,2,4,5,6,
	                    1,2,4,3,5,4,7,5 };
    int cekirdek[maxboyut][maxboyut];
	int sonuc[100][100];
	int kayma_miktari;
	int cekirdek_boyutu;
	int sonuc_matris;
};     

Islem cekirdek;
Islem boyut;
Islem kayma;
Islem eleman;

int matrisiCarp(int satir,int sutun,int boyut_)
{ 
	int sonuc = 0;
	int gecici = 0;
	Islem gecici1;

	//sonuc matrisinin elemanlarý oluþturulur
    for (int i = 0; i < boyut_; i++) //cekirdek matrisinin satýr sayýsý
	{
		for (int j = 0; j < boyut_; j++) //cekirdek matrisinin sütun sayýsý
		{
			gecici = gecici1.giris[satir][sutun] * cekirdek.cekirdek[i][j];
			sonuc += gecici;
			sutun++;
		}
		sutun = sutun - boyut.cekirdek_boyutu, satir++;
	}
	return sonuc;
}

int main()
{
	Islem kontrol;
	//giris matrisinin boyutunu hesaplýyoruz
	for (int i = 0; i < 100; i++)
	{
		//matrisin köþegen elemanlarý tanýmlý olduðu sürece sayac arttýrýlarak giris matrisinin boyutu bulunur
		if ((kontrol.giris[i][i]) >= -100)
			giris_boyut++;
		//eleman tanýmsýz olduðu zaman sayac arttýrma iþlemi bitirilir
		else
			break;
	}
	
	cout << "cekirdek boyutunu giriniz:  ";
	cin >> boyut.cekirdek_boyutu;
	cout << "kayma miktarini giriniz:  ";
	cin >> kayma.kayma_miktari;

	boyut.sonuc_matris = ((giris_boyut - boyut.cekirdek_boyutu) / kayma.kayma_miktari) + 1;
	float sonuc_boyut_kontrol = ((float)(giris_boyut - boyut.cekirdek_boyutu) / kayma.kayma_miktari);
	//iþlem yapýlamayacak durumlar kontrol ediliyor
	if (sonuc_boyut_kontrol != (int)sonuc_boyut_kontrol || sonuc_boyut_kontrol <= 0 || giris_boyut < boyut.cekirdek_boyutu || 
		     minboyut > boyut.cekirdek_boyutu || boyut.cekirdek_boyutu > maxboyut || kayma.kayma_miktari <= 0  )
	{
		cout << "\nbu islem yapilamaz..." << endl;
	}

	//iþlem yapýlmasý için gereken koþullar saðlanýrsa gerekli iþlemler yapýlýr
	else
	{
		//çekirdek matrisin elemalarý oluþturulur
		for (int i = 0; i < boyut.cekirdek_boyutu; i++) //çekirdek matrisinin satýr sayýsý
	    {
		    for (int j = 0; j < boyut.cekirdek_boyutu; j++) //çekirdek matrisinin sütun sayýsý
		    {
			    cout << "\ncekirdek[" << i << "][" << j << "]=";
			    cin >> cekirdek.cekirdek[i][j];
		    }
	    }
	    cout << endl << endl;
		
		//sonuc matrisinin elemanlarý yazdýrýlýr
		for (int i = 0; i < boyut.sonuc_matris * kayma.kayma_miktari; i += kayma.kayma_miktari) //sonuc matrisinin satýr sayýsý
		{
			for (int j = 0; j < boyut.sonuc_matris * kayma.kayma_miktari; j += kayma.kayma_miktari) // sonuc matrisinin sütun sayýsý
			{
				eleman.sonuc[i][j] = matrisiCarp(i, j, boyut.cekirdek_boyutu);
				cout << left << setw(8) << eleman.sonuc[i][j];
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}
