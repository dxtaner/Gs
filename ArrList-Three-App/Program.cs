using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        Console.Write("Bir cümle giriniz: ");
        string cumle = Console.ReadLine().ToLower(); // Girilen cümleyi küçük harflere çeviriyoruz

        List<char> sesliHarfListesi = new List<char>();
        
        foreach (char karakter in cumle)
        {
            if ("aeiou".Contains(karakter)) // Sesli harfleri kontrol ediyoruz
            {
                if (!sesliHarfListesi.Contains(karakter)) // Daha önce eklenmemişse ekliyoruz
                {
                    sesliHarfListesi.Add(karakter);
                }
            }
        }

        sesliHarfListesi.Sort(); // Sesli harfleri sıralıyoruz

        Console.WriteLine("\nSesli Harfler Sıralı:");
        foreach (char harf in sesliHarfListesi)
        {
            Console.WriteLine(harf);
        }
    }
}
