/****************************************************************************
**					                     SAKARYA �N�VERS�TES�
**			                  B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				                  B�LG�SAYAR M�HEND�SL��� B�L�M�
**				                     PROGRAMLAMAYA G�R��� DERS�
**
**				                �DEV NUMARASI.............: Proje
**				                ��RENC� ADI...............: Sedanur SARIKO�
**				                ��RENC� NUMARASI..........: b181210110
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
int			ucak�lkKonum_x = 1;
int			ucak�lkKonum_y = 1;
int			dusmanID = 0;
int			mermiID = 0;
char	    tuslar[256];
char        sahne[genislik][yukseklik];
class Dusman
{
public:
	int			dusman�lkKonum_x;
	int			dusman�lkKonum_y;
	char		dusmanKarakteri;
	Dusman()
	{
		dusman�lkKonum_x = genislik - 2;
		dusman�lkKonum_y = rand() % 15 + 1;
		dusmanKarakteri = char(177);
	}

};
class Mermi
{
public:
	int			mermi�lkKonum_x;
	int			mermi�lkKonum_y;
	char		mermiKarakteri;
	void mermi�lkDegerAta()
	{
		mermi�lkKonum_x = ucak�lkKonum_x + ucakGenislik;
		mermi�lkKonum_y = ucak�lkKonum_y + ucakUzunluk - ucakGenislik;
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
	int j = ucak�lkKonum_y;
	//U�ak konumuna g�re �izdiriliyor 
	for (int i = ucak�lkKonum_x; i < ucak�lkKonum_x + ucakGenislik; i++, j++)
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
	//W tu�una bast���m�zda u�a��n y koordinat�n� azaltarak yeniden �izdiriyoruz
	//yukar� y�nde hareket etmesini sa�l�yoruz.
	if (tuslar['W'] != 0 && ucak�lkKonum_y > 1)
	{
		ucak�lkKonum_y -= 1;
		ucakOlustur();
	}
	//S tu�una bast���m�zda u�a��n y koordinat�n� artt�rarak yeniden �izdiriyoruz
	//a�a�� y�nde hareket etmesini sa�l�yoruz.
	if (tuslar['S'] != 0 && ucak�lkKonum_y < yukseklik - ucakUzunluk - 1)
	{
		ucak�lkKonum_y += 1;
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
	// Her bo�lu�a bast���m�zda yeni mermi �izdirilmesini sa�l�yoruz.
	if (tuslar[' '] != 0)
	{
		mermi[mermiID + 1].mermi�lkDegerAta();
		mermiOlustur(mermi[mermiID + 1].mermi�lkKonum_x, mermi[mermiID + 1].mermi�lkKonum_y , mermiID + 1);
	}
	//Merminin hareket etmesini sa�l�yoruz.
	if (sahne[mermi[mermiID].mermi�lkKonum_x + 1][mermi[mermiID].mermi�lkKonum_y] = mermi[mermiID].mermiKarakteri
		&& mermi[mermiID].mermi�lkKonum_x < genislik - 2)
	{
		mermiOlustur(mermi[mermiID].mermi�lkKonum_x + 1, mermi[mermiID].mermi�lkKonum_y , mermiID);
		mermi[mermiID].mermi�lkKonum_x++;
	}
	//Mermi s�n�r �izgisine gelirse yeni mermiIDsi at�yoruz.
	else
	{
		mermiID++;
	}
	{
		//�kinci merminin hareket etmesini sa�l�yoruz.
		if (sahne[mermi[mermiID + 1].mermi�lkKonum_x + 1][mermi[mermiID + 1].mermi�lkKonum_y] = mermi[mermiID + 1].mermiKarakteri
			&& mermi[mermiID + 1].mermi�lkKonum_x < genislik - 2)
		{
			mermiOlustur(mermi[mermiID + 1].mermi�lkKonum_x + 1, mermi[mermiID + 1].mermi�lkKonum_y , mermiID + 1);
			mermi[mermiID + 1].mermi�lkKonum_x++;
		}
	}
}
void dusmanOlustur(int dusmanID)
{
	int k = dusman[dusmanID].dusman�lkKonum_x;
	int l = dusman[dusmanID].dusman�lkKonum_y;

	//D��man �eklinin her bir kenar� i�in ayr� bir for d�ng�� kullanarak d��man� �izdiriyoruz.

	for (; k > dusman[dusmanID].dusman�lkKonum_x - 2; k--)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
	for (; l < dusman[dusmanID].dusman�lkKonum_y + 2; l++)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
	for (; k < dusman[dusmanID].dusman�lkKonum_x; k++)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
	for (; l > dusman[dusmanID].dusman�lkKonum_y; l--)
	{
		sahne[k][l] = dusman[dusmanID].dusmanKarakteri;
	}
}
void dusmanHareketEttir()
{
	//Her iki d��man�nda x koordinat�n� azalt�p yeniden �izdirerek hareket etmesini sa�l�yoruz.
	//S�n�r �izgisine gelen d��man�n yerine yeni d��man �retiyoruz.

	if (dusman[dusmanID].dusman�lkKonum_x > 0)
	{
		dusman[dusmanID].dusman�lkKonum_x--;
		dusmanOlustur(dusmanID);
	}
	else
	{
		srand(time(NULL));
		dusmanID++;
	}
	if (dusman[dusmanID].dusman�lkKonum_x < genislik - 10)
	{
		if (dusman[dusmanID + 1].dusman�lkKonum_x > 0)
		{
			dusman[dusmanID + 1].dusman�lkKonum_x--;
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
	int mermi1_x = mermi[mermiID].mermi�lkKonum_x;
	int mermi1_y = mermi[mermiID].mermi�lkKonum_y;
	int mermi2_x = mermi[mermiID + 1].mermi�lkKonum_x;
	int mermi2_y = mermi[mermiID + 1].mermi�lkKonum_y;
	int dusman1_x = dusman[dusmanID].dusman�lkKonum_x;
	int dusman1_y = dusman[dusmanID].dusman�lkKonum_y;
	int dusman2_x = dusman[dusmanID + 1].dusman�lkKonum_x;
	int dusman2_y = dusman[dusmanID + 1].dusman�lkKonum_y;

	//Her iki mermi ver her iki d��man i�in x ve y koordinatlar�n�n ayn� olup olmad��� kontrol edilir.
	//Ayn�ysa d��man yok edilir ve yerine yeni d��man �retilir.

	//1. mermi ve 1. d��man i�in kontrol yap�l�r.
	if (   (mermi1_x == dusman1_x - 4 && mermi1_y == dusman1_y) 
		|| (mermi1_x == dusman1_x - 4 && mermi1_y == dusman1_y + 1) 
		|| (mermi1_x == dusman1_x - 4 && mermi1_y == dusman1_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID].dusman�lkKonum_x = genislik - 2;
		dusman[dusmanID].dusman�lkKonum_y = rand() % 15 + 1;
	}

	//2. mermi ve 1. d��man i�in kontrol yap�l�r.
	if (   (mermi2_x == dusman1_x - 4 && mermi2_y == dusman1_y)
		|| (mermi2_x == dusman1_x - 4 && mermi2_y == dusman1_y + 1)
		|| (mermi2_x == dusman1_x - 4 && mermi2_y == dusman1_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID].dusman�lkKonum_x = genislik - 2;
		dusman[dusmanID].dusman�lkKonum_y = rand() % 15 + 1;
	}

	//1. mermi ve 2. d��man i�in kontrol yap�l�r.
	if (   (mermi1_x == dusman2_x - 4 && mermi1_y == dusman2_y)
		|| (mermi1_x == dusman2_x - 4 && mermi1_y == dusman2_y + 1)
		|| (mermi1_x == dusman2_x - 4 && mermi1_y == dusman2_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID + 1].dusman�lkKonum_x = genislik - 2;
		dusman[dusmanID + 1].dusman�lkKonum_y = rand() % 15 + 1;
	}

	//2. mermi ve 2. d��man i�in kontrol yap�l�r.
	if (   (mermi2_x == dusman2_x - 4 && mermi2_y == dusman2_y)
		|| (mermi2_x == dusman2_x - 4 && mermi2_y == dusman2_y + 1)
		|| (mermi2_x == dusman2_x - 4 && mermi2_y == dusman2_y + 2))
	{
		srand(time(NULL));
		dusman[dusmanID + 1].dusman�lkKonum_x = genislik - 2;
		dusman[dusmanID + 1].dusman�lkKonum_y = rand() % 15 + 1;
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