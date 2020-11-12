/****************************************************************************
**					                     SAKARYA ÜNİVERSİTESİ
**			                  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				                  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				                     PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				                ÖDEV NUMARASI.............: Proje
**				                ÖĞRENCİ ADI...............: Sedanur SARIKOÇ
**				                ÖĞRENCİ NUMARASI..........: b181210110
**				                DERS GRUBU................: 1B
****************************************************************************/

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

const int	genislik = 80;
const int	yukseklik = 20;
const int   ucakGenislik = 3;
const int   ucakUzunluk = 5;
int			ucakİlkKonum_x = 1;
int			ucakİlkKonum_y = 1;
int			dusmanID = 0;
int			mermiID = 0;
char	    tuslar[256];
char        sahne[genislik][yukseklik];
class Dusman
{
public:
	int			dusmanİlkKonum_x;
	int			dusmanİlkKonum_y;
	char		dusmanKarakteri;
	Dusman()
	{
		dusmanİlkKonum_x = genislik - 2;
		dusmanİlkKonum_y = rand() % 15 + 1;
		dusmanKarakteri = char(177);
	}

};
class Mermi
{
public:
	int			mermiİlkKonum_x;
	int			mermiİlkKonum_y;
	char		mermiKarakteri;
	void mermiİlkDegerAta()
	{
		mermiİlkKonum_x = ucakİlkKonum_x + ucakGenislik;
		mermiİlkKonum_y = ucakİlkKonum_y + ucakUzunluk - ucakGenislik;
		mermiKarakteri = char(220);
	}

};

Dusman dusman[500];
Mermi  mermi[1000];

void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void sahneyiCiz()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			cout << sahne[x][y];
		}

		cout << endl;
	}
}
void sahneyiTemizle()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			sahne[x][y] = ' ';
		}

	}
}
void sinirlariOlustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}

	for (int y = 0; y < yukseklik; y++)
	{
		sahne[0][y] = 219;
		sahne[genislik - 1][y] = 219;
	}

}
void ucakOlustur()
{
	int j = ucakİlkKonum_y;
	//Uçak konumuna göre çizdiriliyor 
	for (int i = ucakİlkKonum_x; i < ucakİlkKonum_x + ucakGenislik; i++, j++)
	{
		gotoxy(i, j);
		sahne[i][j] = char(219);
	}
	for (int i = ucakGenislik - 1; i > 0; i--, j++)
	{
		gotoxy(i, j);
		sahne[i][j] = char(219);
	}
}
void ucakHareketEttir()
{
	klavyeOku(tuslar);
	//W tuşuna bastığımızda uçağın y koordinatını azaltarak yeniden çizdiriyoruz
	//yukarı yönde hareket etmesini sağlıyoruz.
	if (tuslar['W'] != 0 && ucakİlkKonum_y > 1)
	{
		ucakİlkKonum_y -= 1;
		ucakOlustur();
	}
	//S tuşuna bastığımızda uçağın y koordinatını arttırarak yeniden çizdiriyoruz
	//aşağı yönde hareket etmesini sağlıyoruz.
	if (tuslar['S'] != 0 && ucakİlkKonum_y < yukseklik - ucakUzunluk - 1)
	{
		ucakİlkKonum_y += 1;
		ucakOlustur();
	}
}
void mermiOlustur(int a, int b , int mermiID)
{
	sahne[a + 1][b] = mermi[mermiID].mermiKarakteri;
	sahne[a][b] = ' ';
}
void mermiHareketEttir()
{
	// Her boşluğa bastığımızda yeni mermi çizdirilmesini sağlıyoruz.
	if (tuslar[' '] != 0)
	{
		mermi[mermiID + 1].mermiİlkDegerAta();
		mermiOlustur(mermi[mermiID + 1].mermiİlkKonum_x, mermi[mermiID + 1].mermiİlkKonum_y , mermiID + 1);
	}
	//Merminin hareket etmesini sağlıyoruz.
	if (sahne[mermi[mermiID].mermiİlkKonum_x + 1][mermi[mermiID].mermiİlkKonum_y] = mermi[mermiID].mermiKarakteri
		&& mermi[mermiID].mermiİlkKonum_x < genislik - 2)
	{
		mermiOlustur(mermi[mermiID].mermiİlkKonum_x + 1, mermi[mermiID].mermiİlkKonum_y , mermiID);
		mermi[mermiID].mermiİlkKonum_x++;
	}
	//Mermi sınır çizgisine gelirse yeni mermiIDsi atıyoruz.
	else
	{
		mermiID++;
	}
	{
		//İkinci merminin hareket etmesini sağlıyoruz.
		if (sahne[mermi[mermiID + 1].mermiİlkKonum_x + 1][mermi[mermiID + 1].mermiİlkKonum_y] = mermi[mermiID + 1].mermiKarakteri
			&& mermi[mermiID + 1].mermiİlkKonum_x < genislik - 2)
		{
			mermiOlustur(mermi[mermiID + 1].mermiİlkKonum_x + 1, mermi[mermiID + 1].mermiİlkKonum_y , mermiID + 1);
			mermi[mermiID + 1].mermiİlkKonum_x++;
		}
	}
}
void dusmanOlustur(int dusmanID)
{
	int k = dusman[dusmanID].dusmanİlkKonum_x;
	int l = dusman[dusmanID].dusmanİlkKonum_y;

	//Düşman şeklinin her bir kenarı için ayrı bir for döngüü kullanarak düşmanı çizdiriyoruz.

	for (; k > dusman[dusmanID].dusmanİlkKonum_x - 2; k--)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
	for (; l < dusman[dusmanID].dusmanİlkKonum_y + 2; l++)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
	for (; k < dusman[dusmanID].dusmanİlkKonum_x; k++)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
	for (; l > dusman[dusmanID].dusmanİlkKonum_y; l--)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
}
void dusmanHareketEttir()
{
	//Her iki düşmanında x koordinatını azaltıp yeniden çizdirerek hareket etmesini sağlıyoruz.
	//Sınır çizgisine gelen düşmanın yerine yeni düşman üretiyoruz.

	if (dusman[dusmanID].dusmanİlkKonum_x > 0)
	{
		dusman[dusmanID].dusmanİlkKonum_x--;
		dusmanOlustur(dusmanID);
	}
	else
	{
		srand(time(NULL));
		dusmanID++;
	}
	if (dusman[dusmanID].dusmanİlkKonum_x < genislik - 10)
	{
		if (dusman[dusmanID + 1].dusmanİlkKonum_x > 0)
		{
			dusman[dusmanID + 1].dusmanİlkKonum_x--;
			dusmanOlustur(dusmanID + 1);
		}
		else
		{
			srand(time(NULL));
			dusmanID += 2;
		}
	}
}
void dusmanYokEt()
{
	sahne[1][0] = char(219);
	int mermi1_x = mermi[mermiID].mermiİlkKonum_x;
	int mermi1_y = mermi[mermiID].mermiİlkKonum_y;
	int mermi2_x = mermi[mermiID + 1].mermiİlkKonum_x;
	int mermi2_y = mermi[mermiID + 1].mermiİlkKonum_y;
	int dusman1_x = dusman[dusmanID].dusmanİlkKonum_x;
	int dusman1_y = dusman[dusmanID].dusmanİlkKonum_y;
	int dusman2_x = dusman[dusmanID + 1].dusmanİlkKonum_x;
	int dusman2_y = dusman[dusmanID + 1].dusmanİlkKonum_y;

	//Her iki mermi ver her iki düşman için x ve y koordinatlarının aynı olup olmadığı kontrol edilir.
	//Aynıysa düşman yok edilir ve yerine yeni düşman üretilir.

	//1. mermi ve 1. düşman için kontrol yapılır.
	if (   (mermi1_x == dusman1_x - 4 && mermi1_y == dusman1_y) 
		|| (mermi1_x == dusman1_x - 4 && mermi1_y == dusman1_y + 1) 
		|| (mermi1_x == dusman1_x - 4 && mermi1_y == dusman1_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID].dusmanİlkKonum_x = genislik - 2;
		dusman[dusmanID].dusmanİlkKonum_y = rand() % 15 + 1;
	}

	//2. mermi ve 1. düşman için kontrol yapılır.
	if (   (mermi2_x == dusman1_x - 4 && mermi2_y == dusman1_y)
		|| (mermi2_x == dusman1_x - 4 && mermi2_y == dusman1_y + 1)
		|| (mermi2_x == dusman1_x - 4 && mermi2_y == dusman1_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID].dusmanİlkKonum_x = genislik - 2;
		dusman[dusmanID].dusmanİlkKonum_y = rand() % 15 + 1;
	}

	//1. mermi ve 2. düşman için kontrol yapılır.
	if (   (mermi1_x == dusman2_x - 4 && mermi1_y == dusman2_y)
		|| (mermi1_x == dusman2_x - 4 && mermi1_y == dusman2_y + 1)
		|| (mermi1_x == dusman2_x - 4 && mermi1_y == dusman2_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID + 1].dusmanİlkKonum_x = genislik - 2;
		dusman[dusmanID + 1].dusmanİlkKonum_y = rand() % 15 + 1;
	}

	//2. mermi ve 2. düşman için kontrol yapılır.
	if (   (mermi2_x == dusman2_x - 4 && mermi2_y == dusman2_y)
		|| (mermi2_x == dusman2_x - 4 && mermi2_y == dusman2_y + 1)
		|| (mermi2_x == dusman2_x - 4 && mermi2_y == dusman2_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID + 1].dusmanİlkKonum_x = genislik - 2;
		dusman[dusmanID + 1].dusmanİlkKonum_y = rand() % 15 + 1;
	}
}
int main()
{
	kursoruGizle();

	while (true)
	{
		sahneyiTemizle();
		sinirlariOlustur();

		ucakHareketEttir();
		ucakOlustur();

		mermiHareketEttir();
		mermiHareketEttir();

		dusmanYokEt();
		dusmanHareketEttir();
		
		gotoxy(0, 0);
		sahneyiCiz();
	}
}