using System;
using System.Collections;
using System.Linq;

class Program
{
    static void Main()
    {
        ArrayList asalSayilar = new ArrayList();
        ArrayList asalOlmayanSayilar = new ArrayList();

        int girilenSayi;
        int girilenSayiSayac = 0;

        while (girilenSayiSayac < 20)
        {
            Console.Write($"Pozitif bir sayı giriniz ({girilenSayiSayac + 1}/20): ");
            if (int.TryParse(Console.ReadLine(), out girilenSayi) && girilenSayi > 0)
            {
                if (AsalMi(girilenSayi))
                {
                    asalSayilar.Add(girilenSayi);
                }
                else
                {
                    asalOlmayanSayilar.Add(girilenSayi);
                }
                girilenSayiSayac++;
            }
            else
            {
                Console.WriteLine("Geçersiz giriş. Pozitif bir sayı giriniz.");
            }
        }

        asalSayilar.Sort();
        asalSayilar.Reverse();
        asalOlmayanSayilar.Sort();
        asalOlmayanSayilar.Reverse();

        Console.WriteLine("\nAsal Sayılar (Büyükten Küçüğe):");
        foreach (int sayi in asalSayilar)
        {
            Console.WriteLine(sayi);
        }

        Console.WriteLine("\nAsal Olmayan Sayılar (Büyükten Küçüğe):");
        foreach (int sayi in asalOlmayanSayilar)
        {
            Console.WriteLine(sayi);
        }

        double asalOrtalama = asalSayilar.Count > 0 ? asalSayilar.Cast<int>().Average() : 0;
        double asalOlmayanOrtalama = asalOlmayanSayilar.Count > 0 ? asalOlmayanSayilar.Cast<int>().Average() : 0;

        Console.WriteLine($"\nAsal Sayılar Ortalama: {asalOrtalama}");
        Console.WriteLine($"Asal Olmayan Sayılar Ortalama: {asalOlmayanOrtalama}");
        Console.WriteLine($"Asal Sayılar Toplam: {asalSayilar.Count}");
        Console.WriteLine($"Asal Olmayan Sayılar Toplam: {asalOlmayanSayilar.Count}");
        
    }

    static bool AsalMi(int sayi)
    {
        if (sayi < 2)
            return false;

        for (int i = 2; i < sayi; i++)
        {
            if (sayi % i == 0)
                return false;
        }

        return true;
    }
}
