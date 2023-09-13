using System;

class Program
{
    static void Main()
    {
        int[] sayilar = new int[20];

        for (int i = 0; i < 20; i++)
        {
            Console.Write($"Sayı {i + 1}: ");
            if (int.TryParse(Console.ReadLine(), out int sayi))
            {
                sayilar[i] = sayi;
            }
            else
            {
                Console.WriteLine("Geçersiz bir sayı girdiniz. Tekrar deneyin.");
                i--;
            }
        }

        Array.Sort(sayilar);

        int[] enKucukUcSayi = new int[3];
        int[] enBuyukUcSayi = new int[3];

        Array.Copy(sayilar, enKucukUcSayi, 3);
        Array.Copy(sayilar, sayilar.Length - 3, enBuyukUcSayi, 0, 3);

        double enKucukUcOrtalama = ArrayAverage(enKucukUcSayi);
        double enBuyukUcOrtalama = ArrayAverage(enBuyukUcSayi);

        Console.WriteLine("\nEn Küçük 3 Sayılar:");
        foreach (int sayi in enKucukUcSayi)
        {
            Console.WriteLine(sayi);
        }
        Console.WriteLine($"En Küçük 3 Sayıların Ortalaması: {enKucukUcOrtalama}");

        Console.WriteLine("\nEn Büyük 3 Sayılar:");
        foreach (int sayi in enBuyukUcSayi)
        {
            Console.WriteLine(sayi);
        }
        Console.WriteLine($"En Büyük 3 Sayıların Ortalaması: {enBuyukUcOrtalama}");

        double toplamOrtalama = (enKucukUcOrtalama + enBuyukUcOrtalama) / 2;
        Console.WriteLine($"\nToplam Ortalama: {toplamOrtalama}");
    }

    static double ArrayAverage(int[] array)
    {
        int sum = 0;
        foreach (int sayi in array)
        {
            sum += sayi;
        }
        return (double)sum / array.Length;
    }
}
