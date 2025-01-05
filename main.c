#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kayitBilgileriGuncelle(char isim[], char soyisim[], char adres[]) {
    printf("Yeni �sminizi Giriniz : ");
    scanf("%s", isim);
    printf("Yeni Soyisminizi Giriniz : ");
    scanf("%s", soyisim);
    printf("Yeni Adresinizi Giriniz : ");
    scanf("%s", adres);
    printf("Bilgileriniz ba�ar�yla g�ncellenmi�tir...\n");

    FILE *file = fopen("kullanici_bilgileri.txt", "w");
    if (file != NULL) {
        fprintf(file, "Isim: %s\n", isim);
        fprintf(file, "Soyisim: %s\n", soyisim);
        fprintf(file, "Adres: %s\n", adres);
        fclose(file);
    } else {
        printf("Dosya a�ma hatas�!\n");
    }
}

void silahSecimi(int silah, int sarjor) {
    char *silahlar[] = {"Canik", "Sars�lmaz", "Glock"};
    int fiyatlar[] = {450, 400, 500};

    if (silah >= 1 && silah <= 3) {
        printf("Ka� �arj�r istersiniz ? : ");
        scanf("%d", &sarjor);
        printf("%s marka tabancalar�m�zda her �arj�r %d TL'dir. Toplam �cret: %d TL'dir. Ho��akal�n...\n", 
            silahlar[silah - 1], fiyatlar[silah - 1], sarjor * fiyatlar[silah - 1]);
    } else {
        printf("Ge�ersiz silah numaras�. Ana men�ye y�nlendiriliyorsunuz...\n");
    }
}

void kullaniciBilgileriniYazdir(char isim[], char soyisim[], char adres[]) {
    printf("\nMevcut Kay�t Bilgileri:\n");
    printf("Isim: %s\n", isim);
    printf("Soyisim: %s\n", soyisim);
    printf("Adres: %s\n", adres);
}

void dosyadanKullaniciBilgileriniOku(char isim[], char soyisim[], char adres[]) {
    FILE *file = fopen("kullanici_bilgileri.txt", "r");
    if (file != NULL) {
        fscanf(file, "Isim: %s\n", isim);
        fscanf(file, "Soyisim: %s\n", soyisim);
        fscanf(file, "Adres: %s\n", adres);
        fclose(file);
    } 
}

int main() {
    char isim[20], soyisim[30], adres[150], secim;
    char adminGiris[5], yeni_isim[20];
    int giris, sifre = 4848; // admin giri� �ifresi
    int silah, sarjor, yeni_sifre;
    int uyeKayit = 0;

    dosyadanKullaniciBilgileriniOku(isim, soyisim, adres);

    while(1) {
        printf("Poligon48'e Ho�geldiniz... L�tfen giri�inizi se�iniz.\n\n");
        printf("1) Y�netici Giri�i\n2) �ye Giri�i\n3) ��k��\n");
        printf("L�tfen giri� numaras�n� giriniz : ");
        scanf("%d", &giris);

        if (giris == 1) {
            while (1) {
                printf("�sim: ");
                scanf("%s", adminGiris);
                printf("�ifre: ");
                scanf("%d", &sifre);
                
                if (strcmp(adminGiris, "admin") == 0 && sifre == 4848) {
                    printf("Giri� ba�ar�l�. Y�nlendiriliyorsunuz...\n\n");
                    break;
                } else {
                    printf("Hatal� giri�. L�tfen tekrar deneyin.\n");
                }
            }

            printf("Y�netici Sistemine Ho�geldiniz. Hangi i�lemi yapmak istersiniz?\n\n");
            printf("1) Admin Bilgileri G�ncelleme\n2) Ana Men�\n");
            printf("Hangi i�lemi yapmak istersiniz? : ");
            scanf("%d", &giris);

            if (giris == 1) {
                printf("Yeni �sim : ");
                scanf("%s", yeni_isim);
                printf("Yeni �ifre : ");
                scanf("%d", &yeni_sifre);

                printf("Bilgileriniz ba�ar�yla g�ncellenmi�tir... Ana men�ye y�nlendiriliyorsunuz...\n\n");
                continue;
            } else if (giris == 2) {
                continue;
            } else {
                printf("Ge�ersiz i�lem. Ana men�ye d�n�l�yor...\n");
                continue;
            }
        } else if (giris == 2) {
            if (uyeKayit == 0) {
                printf("Poligon48 Randevu Sistemine Ho�geldiniz... L�tfen �yelik olu�turunuz.\n");
                printf("L�tfen �sminizi Giriniz : ");
                scanf("%s", isim);
                printf("L�tfen Soyisminizi giriniz : ");
                scanf("%s", soyisim);
                printf("L�tfen Adresinizi giriniz : ");
                scanf("%s", adres);

                printf("Merhaba %s. Poligon48 sistemine �yeli�in olu�turulmu�tur. �stedi�in silah� se�erek randevu olu�turabilirsin.\n", isim);
                uyeKayit = 1;
            } else {
                printf("Ho�geldiniz %s. Mevcut kay�t bilgilerinizi g�rmek veya g�ncellemek i�in bir se�enek se�iniz...\n", isim);
                kullaniciBilgileriniYazdir(isim, soyisim, adres);
            }

            while (1) {
                printf("Keyifli at��lar! L�tfen yapmak istedi�iniz i�lemi se�iniz...\n\n");
                printf("A) Silah Se�imi\nB) Kay�t Bilgileri D�zenleme\nC) Ana Men�\n");
                printf("L�tfen yapmak istedi�iniz i�lemi A, B veya C olarak yaz�n�z : ");
                scanf(" %c", &secim);

                if (secim == 'b' || secim == 'B') {
                    printf("Kay�t bilgilerinizi g�ncellemeye y�nlendiriliyorsunuz...\n");
                    kayitBilgileriGuncelle(isim, soyisim, adres);
                } else if (secim == 'a' || secim == 'A') {
                    printf("S�LAHLARIMIZ :\n\n");
                    printf("1) Canik\n2) Sars�lmaz\n3) Glock\n");
                    printf("L�tfen se�ti�iniz silah�n numaras�n� yaz�n�z : ");
                    scanf("%d", &silah);
                    silahSecimi(silah, sarjor);
                } else if (secim == 'c' || secim == 'C') {
                    break;
                } else {
                    printf("Ge�ersiz giri� yapt�n�z...\n");
                }
            }
        } else if (giris == 3) {
            printf("��k�� yap�l�yor...\n");
            break;
        } else {
            printf("Ge�ersiz se�enek. L�tfen ge�erli bir numara giriniz.\n");
        }
    }

    return 0;
}

