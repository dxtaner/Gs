using System;
using System.Collections.Generic;
using System.Linq;

public class Rehber
{
    private List<Kişi> kişiler = new List<Kişi>();

    public void KişiEkle(Kişi kişi)
    {
        kişiler.Add(kişi);
        Console.WriteLine("Kişi başarıyla eklendi.");
    }

    public void KişiSil(string isim, string soyisim)
    {
        Kişi silinecekKişi = kişiler.FirstOrDefault(k => k.İsim == isim && k.Soyisim == soyisim);

        if (silinecekKişi != null)
        {
            kişiler.Remove(silinecekKişi);
            Console.WriteLine($"{isim} {soyisim} isimli kişi rehberden başarıyla silindi.");
        }
        else
        {
            Console.WriteLine("Aradığınız kriterlere uygun kişi rehberde bulunamadı.");
        }
    }

    public void KişiGüncelle(string isim, string soyisim)
    {
        Kişi güncellenecekKişi = kişiler.FirstOrDefault(k => k.İsim == isim && k.Soyisim == soyisim);

        if (güncellenecekKişi != null)
        {
            Console.Write("Yeni telefon numarası: ");
            string yeniTelefon = Console.ReadLine();

            güncellenecekKişi.TelefonNumarası = yeniTelefon;
            Console.WriteLine($"{isim} {soyisim} isimli kişinin telefon numarası başarıyla güncellendi.");
        }
        else
        {
            Console.WriteLine("Aradığınız kriterlere uygun kişi rehberde bulunamadı.");
        }
    }

    public List<Kişi> RehberiListele(string sıralama)
    {
        if (sıralama == "A-Z")
        {
            kişiler.Sort((x, y) => string.Compare(x.İsim, y.İsim));
        }
        else if (sıralama == "Z-A")
        {
            kişiler.Sort((x, y) => string.Compare(y.İsim, x.İsim));
        }

        Console.WriteLine("Telefon Rehberi");
        Console.WriteLine("**********************************************");

        foreach (var kişi in kişiler)
        {
            Console.WriteLine($"İsim: {kişi.İsim} Soyisim: {kişi.Soyisim} Telefon Numarası: {kişi.TelefonNumarası}");
        }

        return kişiler;
    }

    public List<Kişi> KişiAra(string aramaTerimi, int aramaTipi)
    {
        List<Kişi> bulunanKişiler = new List<Kişi>();

        if (aramaTipi == 1)
        {
            bulunanKişiler = kişiler.Where(k => k.İsim.Contains(aramaTerimi) || k.Soyisim.Contains(aramaTerimi)).ToList();
        }
        else if (aramaTipi == 2)
        {
            bulunanKişiler = kişiler.Where(k => k.TelefonNumarası.Contains(aramaTerimi)).ToList();
        }

        Console.WriteLine("Arama Sonuçlarınız:");
        Console.WriteLine("**********************************************");

        foreach (var kişi in bulunanKişiler)
        {
            Console.WriteLine($"İsim: {kişi.İsim} Soyisim: {kişi.Soyisim} Telefon Numarası: {kişi.TelefonNumarası}");
        }

        return bulunanKişiler;
    }
}
