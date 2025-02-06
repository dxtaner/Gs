#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define GemiAdetMiktari 4
#define GemiBoyutlari 5,4,3,2
#define GemiMiktarlari 1,2,3,4

void goster(int, char[][10]);
void yerlestir(int[], int[], int, char[][10]);
void oyna(int, int, int, char[][10], char[][10]);
int alan(int[], int[], int);

char a[10][10]; // gemi tablosu
char b[10][10]; // 1. oyuncu tablosu
char c[10][10]; // 2. oyuncu tablosu

int main()
{
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            a[i][j] = '-';
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
        {
            b[i][j] = '-';
            c[i][j] = '-';
        }

    int gemiler[GemiAdetMiktari] = {GemiBoyutlari};
    int miktar[GemiAdetMiktari] = {GemiMiktarlari};
    int ToplamAlan = alan(gemiler, miktar, GemiAdetMiktari);

    if (ToplamAlan > 40)
    {
        printf("KOD HATASI\n");
        return 1;
    }

    yerlestir(gemiler, miktar, GemiAdetMiktari, b);
    yerlestir(gemiler, miktar, GemiAdetMiktari, c);

    printf("OYUN MODU:\n");
    printf("1. Kolay\n");
    printf("2. Orta\n");
    printf("3. Zor\n");
    int mod;
    scanf("%d", &mod);

    int hak;
    if (mod == 1)
        hak = ToplamAlan * 2;
    else if (mod == 2)
        hak = ToplamAlan * 1.5;
    else if (mod == 3)
        hak = ToplamAlan;
    else
    {
        printf("Geçersiz oyun modu seçimi!\n");
        return 1;
    }

    oyna(hak, 0, ToplamAlan, b, c);
    goster(0, b);
    printf("1. Oyuncu tamamlandı.\n");

    printf("Sıra 2. oyuncuda...\n");
    oyna(hak, 0, ToplamAlan, c, b);
    goster(0, c);
    printf("2. Oyuncu tamamlandı.\n");

    int puan_bir = alan(gemiler, miktar, GemiAdetMiktari) - KalanGemiler(b);
    int puan_iki = alan(gemiler, miktar, GemiAdetMiktari) - KalanGemiler(c);

    printf("1. Oyuncunun Puanı: %d\n", puan_bir);
    printf("2. Oyuncunun Puanı: %d\n", puan_iki);

    if (puan_bir > puan_iki)
        printf("1. Oyuncu Kazandı!\n");
    else if (puan_bir < puan_iki)
        printf("2. Oyuncu Kazandı!\n");
    else
        printf("Berabere!\n");

    return 0;
}

void oyna(int h, int hatali, int Kalan, char oyuncu_tablosu[][10], char rakip_tablosu[][10])
{
    system("clear");
    goster(1, oyuncu_tablosu);

    if (Kalan == 0)
    {
        printf("\t\t  KAZANDINIZ!\n");
        return;
    }
    else if (h == 0 || h < Kalan)
    {
        printf("\t\t  Hakkiniz Bitti!\n");
        return;
    }
    else if (hatali == 1)
        printf("\n\tYanlis Girildi.");
    else if (hatali == 2)
        printf("\n\tZaten Daha Once Bu Konumu Kullandiniz.");
    else
        printf("\n");
    hatali = 0;

    char k;
    int l, m;
    printf("\n\tHak Sayisi = %d , Kalan Vurulacak Alan = %d\n\tOnce Karakteri Sonra Sayiyi Girerek\n\tHamlenizi Yapacaginiz Koordinatlari Giriniz-->", h, Kalan);
    scanf(" %c%d", &k, &l);
    system("clear");

    if (k >= 'a' && k <= 'j')
        m = k - 'a';
    else if (k >= 'A' && k <= 'J')
        m = k - 'A';
    else
    {
        hatali = 1;
        goto hata;
    }
    if (l < 0 || l > 9)
    {
        hatali = 1;
        goto hata;
    }

    if (rakip_tablosu[m][l] == '-')
    {
        if (oyuncu_tablosu[m][l] == 'O')
        {
            rakip_tablosu[m][l] = 'X';
            --Kalan;
        }
        else
            rakip_tablosu[m][l] = 'O';
    }
    else
    {
        hatali = 2;
        goto hata;
    }
    h--;
hata:
    oyna(h, hatali, Kalan, oyuncu_tablosu, rakip_tablosu);
}

void goster(int k, char tablo[][10])
{
    int i, j;
    printf("\n\t\t    0 1 2 3 4 5 6 7 8 9\n");
    for (i = 0; i < 10; i++)
    {
        printf("\n\t\t%c   ", (i + 'A'));
        for (j = 0; j < 10; j++)
        {
            if (k == 0)
                printf("%c ", tablo[i][j]);
            else
                printf("%c ", tablo[i][j] == 'O' ? '-' : tablo[i][j]);
        }
    }
    printf("\n\n");
}

void yerlestir(int g[], int miktar[], int sayi, char tablo[][10])
{
    int i, j;
    for (i = 0; i < sayi; i++)
    {
        for (j = miktar[i]; j != 0; j--)
        {
            int t = 11 - g[i];
            while (1)
            {
                int yon = (rand() % 2); // yon = 0 > asagi , yon = 1 > sag
                int y, x, n;
                if (yon == 0)
                {
                    y = (rand() % t);
                    x = (rand() % 10);
                }
                else
                {
                    y = (rand() % 10);
                    x = (rand() % t);
                }
                int k = y;
                int l = x;
                int hata = 0;
                for (n = 0; n < g[i]; n++)
                {
                    if (tablo[k][l] == '-' && ((tablo[k + 1][l] == '-') || k == 9) && ((tablo[k - 1][l] == '-') || k == 0) &&
                        ((tablo[k][l + 1] == '-') || l == 9) && ((tablo[k][l - 1] == '-') || l == 0))
                    {
                        if (yon == 0)
                            k++;
                        else
                            l++;
                    }
                    else
                    {
                        hata = 1;
                        break;
                    }
                }
                if (hata == 1)
                    continue;
                else
                {
                    for (n = 0; n < g[i]; n++)
                    {
                        tablo[y][x] = 'O';
                        if (yon == 0)
                            y++;
                        else
                            x++;
                    }
                    break;
                }
            }
        }
    }
}

int alan(int g[], int miktar[], int sayi)
{
    int i, toplam = 0;
    for (i = 0; i < sayi; i++)
        toplam += g[i] * miktar[i];
    return toplam;
}

int KalanGemiler(char tablo[][10])
{
    int i, j, kalan = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (tablo[i][j] == 'O')
                kalan++;
        }
    }
    return kalan;
}
