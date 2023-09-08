using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        Rehber rehber = new Rehber();
        ÖrnekKişileriEkle(rehber);

        while (true)
        {
            Console.Clear(); // Her döngü başında ekranı temizle

            Console.WriteLine("Lütfen yapmak istediğiniz işlemi seçiniz:");
            Console.WriteLine("*******************************************");
            Console.WriteLine("(1) Yeni Numara Kaydetmek");
            Console.WriteLine("(2) Varolan Numarayı Silmek");
            Console.WriteLine("(3) Varolan Numarayı Güncelleme");
            Console.WriteLine("(4) Rehberi Listelemek");
            Console.WriteLine("(5) Rehberde Arama Yapmak");
            Console.WriteLine("*******************************************");

            int secim;
            if (int.TryParse(Console.ReadLine(), out secim))
            {
                switch (secim)
                {
                    case 1:
                        Console.WriteLine("Yeni Numara Kaydetmek");
                        Console.Write("İsim: ");
                        string yeniIsim = Console.ReadLine();
                        Console.Write("Soyisim: ");
                        string yeniSoyisim = Console.ReadLine();
                        Console.Write("Telefon Numarası: ");
                        string yeniTelefon = Console.ReadLine();

                        Kişi yeniKişi = new Kişi
                        {
                            İsim = yeniIsim,
                            Soyisim = yeniSoyisim,
                            TelefonNumarası = yeniTelefon
                        };

                        rehber.KişiEkle(yeniKişi);
                        break;

                    case 2:
                        Console.WriteLine("Varolan Numarayı Silmek");
                        Console.Write("Silmek istediğiniz kişinin İsim: ");
                        string silinecekIsim = Console.ReadLine();
                        Console.Write("Silmek istediğiniz kişinin Soyisim: ");
                        string silinecekSoyisim = Console.ReadLine();

                        List<Kişi> bulunanKişiler = rehber.KişiAra(silinecekIsim, 1); // İsim veya soyisime göre arama

                        if (bulunanKişiler.Count > 0)
                        {
                            Kişi silinecekKişi = bulunanKişiler[0];
                            Console.Write($"{silinecekKişi.İsim} {silinecekKişi.Soyisim} isimli kişi rehberden silinmek üzere, onaylıyor musunuz? (y/n): ");
                            string onay = Console.ReadLine();

                            if (onay.ToLower() == "y")
                            {
                                rehber.KişiSil(silinecekIsim, silinecekSoyisim);
                            }
                            else
                            {
                                Console.WriteLine("İşlem iptal edildi.");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Aradığınız kriterlere uygun kişi rehberde bulunamadı.");
                        }
                        break;

                    case 3:
                        Console.WriteLine("Varolan Numarayı Güncelleme");
                        Console.Write("Güncellemek istediğiniz kişinin İsim: ");
                        string güncellenecekIsim = Console.ReadLine();
                        Console.Write("Güncellemek istediğiniz kişinin Soyisim: ");
                        string güncellenecekSoyisim = Console.ReadLine();

                        rehber.KişiGüncelle(güncellenecekIsim, güncellenecekSoyisim);
                        break;

                    case 4:
                        Console.WriteLine("Rehberi Listeleme");
                        Console.WriteLine("Sıralama seçeneği: (A-Z) veya (Z-A)");
                        string sıralama = Console.ReadLine();
                        rehber.RehberiListele(sıralama);
                        break;

                    case 5:
                        Console.WriteLine("Rehberde Arama Yapmak");
                        Console.WriteLine("Arama yapmak istediğiniz tipi seçiniz:");
                        Console.WriteLine("(1) İsim veya Soyisime göre arama yapmak için");
                        Console.WriteLine("(2) Telefon numarasına göre arama yapmak için");
                        int aramaTipi;
                        if (int.TryParse(Console.ReadLine(), out aramaTipi) && (aramaTipi == 1 || aramaTipi == 2))
                        {
                            Console.Write("Arama terimi: ");
                            string aramaTerimi = Console.ReadLine();
                            rehber.KişiAra(aramaTerimi, aramaTipi);
                        }
                        else
                        {
                            Console.WriteLine("Geçersiz seçim, lütfen tekrar deneyin.");
                        }
                        break;

                    default:
                        Console.WriteLine("Geçersiz seçim, lütfen tekrar deneyin.");
                        break;
                }
            }
            else
            {
                Console.WriteLine("Geçersiz giriş, lütfen tekrar deneyin.");
            }

            Console.WriteLine("Devam etmek için bir tuşa basın...");
            Console.ReadKey();
        }
    }

    // Başlangıçta örnek kişileri rehbere eklemek için kullanılabilir
    static void ÖrnekKişileriEkle(Rehber rehber)
    {
        rehber.KişiEkle(new Kişi { İsim = "Taner", Soyisim = "Özer", TelefonNumarası = "555-1234567" });
        rehber.KişiEkle(new Kişi { İsim = "Ramiz", Soyisim = "Ronaldı", TelefonNumarası = "555-9876543" });
        rehber.KişiEkle(new Kişi { İsim = "Michael", Soyisim = "David", TelefonNumarası = "555-4567890" });
        rehber.KişiEkle(new Kişi { İsim = "MEssi", Soyisim = "RNEymar", TelefonNumarası = "555-7890123" });
        rehber.KişiEkle(new Kişi { İsim = "David", Soyisim = "Arda", TelefonNumarası = "555-2345678" });
    }
}
