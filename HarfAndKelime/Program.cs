using System;

class Program
{
    static void Main()
    {
        Console.Write("Bir cümle yazınız: ");
        string cumle = Console.ReadLine();

        int harfSayisi = 0;
        int kelimeSayisi = 0;

        // Boşluklara göre cümleyi kelimelere ayır
        string[] kelimeler = cumle.Split(' ', StringSplitOptions.RemoveEmptyEntries);

        foreach (string kelime in kelimeler)
        {
            kelimeSayisi++; // Her kelimeyi say

            foreach (char karakter in kelime)
            {
                if (char.IsLetter(karakter))
                {
                    harfSayisi++; // Her harfi say
                }
            }
        }

        Console.WriteLine($"Toplam Harf Sayısı: {harfSayisi}");
        Console.WriteLine($"Toplam Kelime Sayısı: {kelimeSayisi}");
    }
}
