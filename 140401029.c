#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int sayi1,sayi2,sayi3,sayi4;    /** Bilgisayarin tahmin ettigi sayilar **/
int puan=250;                   /** Puan degiskeni **/
int carkpuan;                   /** Çark döndügünde gelen seçenegin tutuldugu degisken**/
int dogrutahmin;                /** Main fonksiyonuna gönderilen dogru tahmin sayisi**/

int main()
{

    char secim;    /** Kullanicinin seçim yapmasi için olusturulan degisken**/
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nCARK OYUNUNA HOS GELDINIZ...\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    do
    {
    printf("Carki Cevirmek Icin 'c' Giriniz\n");
    printf("Oyunu Kapatmak Icin 's' Giriniz\n");
    printf ("Seciminiz:");
    scanf(" %c",&secim);
    printf("\n");

    switch(secim)
    {
        case 'c':
            sayi_uret();
            cark_cevir();
            tahmin_gir();
            if(dogrutahmin==1)
            {
                    puan=puan+50;
                    printf("Tebrikler 50 Puan Kazandiniz!!\nToplam Puaniniz=%d\n-----------------------------------------------\n",puan);
            }
            else if(dogrutahmin==2)
            {
                    puan=puan+100;
                    printf("Tebrikler 100 Puan Kazandiniz!!\nToplam Puaniniz=%d\n-----------------------------------------------\n",puan);
            }
            else if(dogrutahmin==3)
            {
                    puan=puan+250;
                    printf("Tebrikler 250 Puan Kazandiniz!!\nToplam Puaniniz=%d\n-----------------------------------------------\n",puan);
            }
            else if(dogrutahmin==0)     /** Puan azaltma seçeneginin geldigini belirtmek için dogru tahmini sayisini 0 yaptim**/
            {
                    puan=(puan-(puan/4));
                    printf("Toplam Puaniniz=%d\n-----------------------------------------------\n",puan);
            }
            else if(dogrutahmin==4)     /** Iflas seçeneginin geldigini belirtmek için dogru tahmini sayisini 4 yaptim **/
            {
                    secim='s';
            }
            break;
        case 's':
            printf("\nGule Gule");
            break;
        default:
            printf("Hatali giris!\n");
    }
    }
    while(secim!='s');
    return 0;
}

void cark_cevir()
{
    srand(time(NULL));
    int cark;
    carkpuan=0;
    cark= 1 + rand()%6;         /** Çarkin üzerindeki 6 seçenegi 1-6 arasindaki sayilara atadim ve onlari rastgele buldurdum**/
    if(cark==1)
    {
        carkpuan=50;
    }
    else if(cark==2)
    {
        carkpuan=100;
    }
    else if(cark==3)
    {
        carkpuan=250;
    }
    else if(cark==4)
    {
        carkpuan=2; /** iflas secenegi geldigini belirtmek icin **/
    }
    else if(cark==5)
    {
        carkpuan=0;  /**pas secenegi geldigini belirtmek icin **/
    }
    else if(cark==6)
    {
        carkpuan=1;  /**puan azaltma oldugunu belirtmek icin **/
    }
    return 1;
}
void sayi_uret()
{
    srand(time(NULL));
    sayi1= 1 + rand()%10;
    sayi2=sayi1;
    sayi3=sayi1;
    sayi4=sayi1;
    while(sayi2==sayi1)
    {
    sayi2= 1 + rand()%10;
    }
    while(sayi3==sayi1 || sayi3==sayi2)
    {
    sayi3= 1 + rand()%10;
    }
    while(sayi4==sayi1 || sayi4==sayi2 || sayi4==sayi3)
    {
    sayi4= 1 + rand()%10;
    }
    return 1;
}

int tahmin_gir()
{
     int tahmin1,tahmin2,tahmin3,tahmin4;
     dogrutahmin=5;  /** Program her döndügünde bir önceki dogru tahmin sayisi döndürülmesin diye farkli bir deger yapiyorum
     cunku mesela pas seçeneginde dogru tahmini sayisinda degisiklik olmaz**/

        if(carkpuan==50)
            {
                printf("Cark Puani=50\n");
                printf("50 Puan Kazanmak Icin 1-10 Arasi 4 Sayi Tahmini Giriniz\n(En az 1 dogru tahmin gerekir)\n");
                printf("1. Sayiyi Giriniz=");
                scanf("%d",&tahmin1);
                printf("2. Sayiyi Giriniz=");
                scanf("%d",&tahmin2);
                printf("3. Sayiyi Giriniz=");
                scanf("%d",&tahmin3);
                printf("4. Sayiyi Giriniz=");
                scanf("%d",&tahmin4);
                if(tahmin1==sayi1 || tahmin2==sayi1 || tahmin3==sayi1 || tahmin4==sayi1)
                {
                    dogrutahmin=1;
                }
                else if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                {
                    dogrutahmin=1;
                }
                else if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                {
                    dogrutahmin=1;
                }
                else if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                {
                    dogrutahmin=1;
                }
                else
                {
                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                }

            }
        else if(carkpuan==100)
            {
                printf("Cark Puani=100\n");
                printf("100 Puan Kazanmak Icin 1-10 Arasi 4 Sayi Tahmini Giriniz\n(En az 2 dogru tahmin gerekir)\n");
                printf("1. Sayiyi Giriniz=");
                scanf("%d",&tahmin1);
                printf("2. Sayiyi Giriniz=");
                scanf("%d",&tahmin2);
                printf("3. Sayiyi Giriniz=");
                scanf("%d",&tahmin3);
                printf("4. Sayiyi Giriniz=");
                scanf("%d",&tahmin4);
                if(tahmin1==sayi1 || tahmin2==sayi1 || tahmin3==sayi1 || tahmin4==sayi1)
                    {
                        if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                                {
                                    dogrutahmin=2;
                                }
                        else
                                {
                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                }
                    }
                else if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                {
                        if(tahmin1==sayi1 || tahmin2==sayi1 || tahmin3==sayi1 || tahmin4==sayi1)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                                {
                                    dogrutahmin=2;
                                }
                        else
                                {
                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                }
                }
                else if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                {
                        if(tahmin1==sayi1 || tahmin2==sayi1 || tahmin3==sayi1 || tahmin4==sayi1)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                                {
                                    dogrutahmin=2;
                                }
                        else
                                {
                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                }
                }
                else if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                {
                        if(tahmin1==sayi1 || tahmin2==sayi1 || tahmin3==sayi1 || tahmin4==sayi1)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                                {
                                    dogrutahmin=2;
                                }
                        else if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                                {
                                    dogrutahmin=2;
                                }
                        else
                                {
                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                }
                }
                else
                {
                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                }
            }
            else if(carkpuan==250)
                {
                    printf("Cark Puani=250\n");
                    printf("250 Puan Kazanmak Icin 1-10 Arasi 4 Sayi Tahmini Giriniz\n(En az 3 dogru tahmin gerekir)\n");
                    printf("1. Sayiyi Giriniz=");
                    scanf("%d",&tahmin1);
                    printf("2. Sayiyi Giriniz=");
                    scanf("%d",&tahmin2);
                    printf("3. Sayiyi Giriniz=");
                    scanf("%d",&tahmin3);
                    printf("4. Sayiyi Giriniz=");
                    scanf("%d",&tahmin4);
                    if(tahmin1==sayi1 || tahmin2==sayi1 || tahmin3==sayi1 || tahmin4==sayi1)
                        {
                            if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                                {
                                        if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                                            {
                                                    dogrutahmin=3;
                                            }
                                        else if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                                            {
                                                    dogrutahmin=3;
                                            }
                                        else
                                            {
                                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                            }
                                }
                            else if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                                {
                                        if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                                            {
                                                    dogrutahmin=3;
                                            }
                                        else
                                            {
                                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                            }
                                }
                            else
                                {
                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                }
                        }
                    else if(tahmin1==sayi2 || tahmin2==sayi2 || tahmin3==sayi2 || tahmin4==sayi2)
                        {
                            if(tahmin1==sayi3 || tahmin2==sayi3 || tahmin3==sayi3 || tahmin4==sayi3)
                                {
                                        if(tahmin1==sayi4 || tahmin2==sayi4 || tahmin3==sayi4 || tahmin4==sayi4)
                                            {
                                                    dogrutahmin=3;
                                            }
                                        else
                                            {
                                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                            }
                                }
                            else
                                {
                                    printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                                }
                        }
                    else
                        {
                            printf("Basarili tahmin yapilamadi!!\n-----------------------------------------------\n");
                        }
                    }
            else if(carkpuan==0)
                    {
                        printf("Pas!!\n\n-----------------------------------------------\n");
                    }
            else if(carkpuan==1)
                    {
                        printf("Puan azaltma!!! puaniniz %25 azaldi\n-----------------------------------------------\n");
                        dogrutahmin=0;   /** puan azaltma seceneginin geldigini belirtmek icin **/
                    }
            else if(carkpuan==2)
                    {
                        printf("iflas!!!!! Oyun Bitti!!!");
                        dogrutahmin=4;   /** iflas seçeneginin geldigini belirtmek için **/
                    }
    return 1;
}
