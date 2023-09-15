using System;

class Program
{
    static void Main()
    {
        Console.Write("Kaç kelime gireceksiniz? (pozitif bir tam sayı girin): ");
        if (int.TryParse(Console.ReadLine(), out int n) && n > 0)
        {
            string[] kelimeler = new string[n];

            for (int i = 0; i < n; i++)
            {
                Console.Write($"Kelime {i + 1}: ");
                kelimeler[i] = Console.ReadLine();
            }

            Console.WriteLine("\nGirilen Kelimeler (Sondan Başa Doğru):");
            for (int i = n - 1; i >= 0; i--)
            {
                Console.WriteLine(kelimeler[i]);
            }
        }
        else
        {
            Console.WriteLine("Geçersiz giriş! Pozitif bir tam sayı girin.");
        }
    }
}
