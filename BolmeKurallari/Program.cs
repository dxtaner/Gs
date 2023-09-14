using System;

class Program
{
    static void Main()
    {
        Console.Write("Kaç tane pozitif sayı gireceksiniz? (n): ");
        if (int.TryParse(Console.ReadLine(), out int n) && n > 0)
        {
            Console.Write("Bölme işlemi için bir sayı girin (m): ");
            if (int.TryParse(Console.ReadLine(), out int m) && m > 0)
            {
                int[] sayilar = new int[n];

                for (int i = 0; i < n; i++)
                {
                    Console.Write($"Sayı {i + 1}: ");
                    if (int.TryParse(Console.ReadLine(), out int sayi) && sayi > 0)
                    {
                        sayilar[i] = sayi;
                    }
                    else
                    {
                        Console.WriteLine("Geçersiz bir sayı girdiniz. Tekrar deneyin.");
                        i--;
                    }
                }

                Console.WriteLine($"\n{m}'e eşit veya tam bölünen sayılar:");
                foreach (int sayi in sayilar)
                {
                    if (sayi % m == 0)
                    {
                        Console.WriteLine(sayi);
                    }
                }
            }
            else
            {
                Console.WriteLine("Geçersiz giriş! Pozitif bir tam sayı girin.");
            }
        }
        else
        {
            Console.WriteLine("Geçersiz giriş! Pozitif bir tam sayı girin.");
        }
    }
}
