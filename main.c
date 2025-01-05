#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kayitBilgileriGuncelle(char isim[], char soyisim[], char adres[]) {
    printf("Yeni Ýsminizi Giriniz : ");
    scanf("%s", isim);
    printf("Yeni Soyisminizi Giriniz : ");
    scanf("%s", soyisim);
    printf("Yeni Adresinizi Giriniz : ");
    scanf("%s", adres);
    printf("Bilgileriniz baþarýyla güncellenmiþtir...\n");

    FILE *file = fopen("kullanici_bilgileri.txt", "w");
    if (file != NULL) {
        fprintf(file, "Isim: %s\n", isim);
        fprintf(file, "Soyisim: %s\n", soyisim);
        fprintf(file, "Adres: %s\n", adres);
        fclose(file);
    } else {
        printf("Dosya açma hatasý!\n");
    }
}

void silahSecimi(int silah, int sarjor) {
    char *silahlar[] = {"Canik", "Sarsýlmaz", "Glock"};
    int fiyatlar[] = {450, 400, 500};

    if (silah >= 1 && silah <= 3) {
        printf("Kaç þarjör istersiniz ? : ");
        scanf("%d", &sarjor);
        printf("%s marka tabancalarýmýzda her þarjör %d TL'dir. Toplam ücret: %d TL'dir. Hoþçakalýn...\n", 
            silahlar[silah - 1], fiyatlar[silah - 1], sarjor * fiyatlar[silah - 1]);
    } else {
        printf("Geçersiz silah numarasý. Ana menüye yönlendiriliyorsunuz...\n");
    }
}

void kullaniciBilgileriniYazdir(char isim[], char soyisim[], char adres[]) {
    printf("\nMevcut Kayýt Bilgileri:\n");
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
    int giris, sifre = 4848; // admin giriþ þifresi
    int silah, sarjor, yeni_sifre;
    int uyeKayit = 0;

    dosyadanKullaniciBilgileriniOku(isim, soyisim, adres);

    while(1) {
        printf("Poligon48'e Hoþgeldiniz... Lütfen giriþinizi seçiniz.\n\n");
        printf("1) Yönetici Giriþi\n2) Üye Giriþi\n3) Çýkýþ\n");
        printf("Lütfen giriþ numarasýný giriniz : ");
        scanf("%d", &giris);

        if (giris == 1) {
            while (1) {
                printf("Ýsim: ");
                scanf("%s", adminGiris);
                printf("Þifre: ");
                scanf("%d", &sifre);
                
                if (strcmp(adminGiris, "admin") == 0 && sifre == 4848) {
                    printf("Giriþ baþarýlý. Yönlendiriliyorsunuz...\n\n");
                    break;
                } else {
                    printf("Hatalý giriþ. Lütfen tekrar deneyin.\n");
                }
            }

            printf("Yönetici Sistemine Hoþgeldiniz. Hangi iþlemi yapmak istersiniz?\n\n");
            printf("1) Admin Bilgileri Güncelleme\n2) Ana Menü\n");
            printf("Hangi iþlemi yapmak istersiniz? : ");
            scanf("%d", &giris);

            if (giris == 1) {
                printf("Yeni Ýsim : ");
                scanf("%s", yeni_isim);
                printf("Yeni Þifre : ");
                scanf("%d", &yeni_sifre);

                printf("Bilgileriniz baþarýyla güncellenmiþtir... Ana menüye yönlendiriliyorsunuz...\n\n");
                continue;
            } else if (giris == 2) {
                continue;
            } else {
                printf("Geçersiz iþlem. Ana menüye dönülüyor...\n");
                continue;
            }
        } else if (giris == 2) {
            if (uyeKayit == 0) {
                printf("Poligon48 Randevu Sistemine Hoþgeldiniz... Lütfen Üyelik oluþturunuz.\n");
                printf("Lütfen Ýsminizi Giriniz : ");
                scanf("%s", isim);
                printf("Lütfen Soyisminizi giriniz : ");
                scanf("%s", soyisim);
                printf("Lütfen Adresinizi giriniz : ");
                scanf("%s", adres);

                printf("Merhaba %s. Poligon48 sistemine üyeliðin oluþturulmuþtur. Ýstediðin silahý seçerek randevu oluþturabilirsin.\n", isim);
                uyeKayit = 1;
            } else {
                printf("Hoþgeldiniz %s. Mevcut kayýt bilgilerinizi görmek veya güncellemek için bir seçenek seçiniz...\n", isim);
                kullaniciBilgileriniYazdir(isim, soyisim, adres);
            }

            while (1) {
                printf("Keyifli atýþlar! Lütfen yapmak istediðiniz iþlemi seçiniz...\n\n");
                printf("A) Silah Seçimi\nB) Kayýt Bilgileri Düzenleme\nC) Ana Menü\n");
                printf("Lütfen yapmak istediðiniz iþlemi A, B veya C olarak yazýnýz : ");
                scanf(" %c", &secim);

                if (secim == 'b' || secim == 'B') {
                    printf("Kayýt bilgilerinizi güncellemeye yönlendiriliyorsunuz...\n");
                    kayitBilgileriGuncelle(isim, soyisim, adres);
                } else if (secim == 'a' || secim == 'A') {
                    printf("SÝLAHLARIMIZ :\n\n");
                    printf("1) Canik\n2) Sarsýlmaz\n3) Glock\n");
                    printf("Lütfen seçtiðiniz silahýn numarasýný yazýnýz : ");
                    scanf("%d", &silah);
                    silahSecimi(silah, sarjor);
                } else if (secim == 'c' || secim == 'C') {
                    break;
                } else {
                    printf("Geçersiz giriþ yaptýnýz...\n");
                }
            }
        } else if (giris == 3) {
            printf("Çýkýþ yapýlýyor...\n");
            break;
        } else {
            printf("Geçersiz seçenek. Lütfen geçerli bir numara giriniz.\n");
        }
    }

    return 0;
}

