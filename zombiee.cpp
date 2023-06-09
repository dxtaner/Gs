#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


/* Oyundaki zombi sayısı:
   İplikleri düzenleyen bu değişkenin senkronize olması gerekiyor */
int zombieCounter = 0;
int killedZombies = 0; /* Öldürülen zombi sayısı */

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/* Odaya giren zombi sayısını takip eder. */
void zombieGirdi() {
    pthread_mutex_lock(&lock); /* Kritik bölge */
	zombieCounter++;
    pthread_mutex_unlock(&lock);
}

/* Öldürülen zombi sayısını takip eder. */
void zombieOlduruldu() {
    pthread_mutex_lock(&lock); /* Kritik bölge */
    zombieCounter--;
	killedZombies++;
    pthread_mutex_unlock(&lock);
}

/* Odadaki zombi sayısı 100'den büyük veya eşitse true döner. */
int odadaCokFazlaZombiVar() {
	if(zombieCounter >= 100){
	return 1;
	}
	else{
		return 0;
	}
}

/* 100'den fazla zombi öldürüldüyse true döner. */
int yuzZombiOlduruldu() {
	if(killedZombies >= 100){
		return 1;
	}
	else{
		return 0;
	}
}
	
/* En az bir zombi odada varsa true döner. */
int zombiVar() {
	if(zombieCounter > 0){
		return 1;
	}
	else{
		return 0;
	}
}

/* Öldürülen zombi sayısını döner. */
int oldurulenSayisi() {
	return killedZombies;
}

/* Odadaki zombi sayısını döner. */
int odadaSayisi() {
	return zombieCounter;
}

/* Kapıcı ipliği */
void *kapici(void *p){
    srand(time(NULL));          /* %50 olasılık için time kütüphanesinden fonksiyon kullanılır */
    unsigned int usecs = 2000;    
	usleep(usecs);              /* Kapıcı her 2 ms'de bir zombiyi alır (veya almaz)*/

	if(rand()%2 == 0){      /* %50 olasılık */
        if (odadaCokFazlaZombiVar() == 1)
        {
            printf("Hepiniz öldünüz.");    /* Odada 100 zombi varsa hepiniz ölürsünüz.*/
            pthread_exit(NULL);             /* Öldüysen ipliği sonlandır */
        }
         else if (yuzZombiOlduruldu() == 1) {        /* 100 zombiyi öldürdüysen hayatta kalırsın. */
            printf("HAYATTA KALDINIZ!! Başardınız!");
            pthread_exit(NULL);     /* Oyun bittiyse çık */
        }
        else
        {
            pthread_mutex_lock(&lock);
            zombieGirdi();                /* Kritik bölge. Oyun bitmediyse daha fazla zombi al. */
            pthread_mutex_unlock(&lock);
        }
    }
    pthread_exit(NULL);
    
}

/* avcı ipliği */
void *avci(void *p){
    int yerel_oldurulen = 0;        /* Her avcının yerel olarak öldürdüğü zombi sayısı */
    unsigned int usecs = 2000;
	usleep(usecs);

    if (odadaCokFazlaZombiVar() == 1)
    {
        printf("Hepiniz öldünüz.");
        pthread_exit(NULL);
    }
    else if (yuzZombiOlduruldu() == 1) {
        printf("HAYATTA KALDIK!! Başardık!");
        printf("%d zombi öldürdüm.", yerel_oldurulen);
        pthread_exit(NULL);
    }
    else{
        pthread_mutex_lock(&lock);
        zombieOlduruldu();
        yerel_oldurulen++;
        pthread_mutex_unlock(&lock);
    }

	
	pthread_exit(NULL);         /* Avcı ipliklerini bitir */
}

/* Simülasyon ana ipliği */
int main(int argc, char **argv){
	
	int n = 10;     /* Hayatta kalmak için kapıcı sayısı */
	
	pthread_t ptidAvcilar[3];        /* Avcı iplikleri */
	pthread_t ptidKapicilar[n];       /* Kapıcı iplikleri */
	
	for(int i = 0 ; i<n ; ++i){         /* Kapıcı ipliklerini oluştur */
		pthread_create(&ptidKapicilar[i], NULL, &kapici, NULL);
	}
	
	for(int i = 0 ; i<3; ++i){      /* Avcı ipliklerini oluştur */
		pthread_create(&ptidAvcilar[i], NULL, &avci, NULL);
	}
	
	for(int k = 0; k<10; ++k ){     /* Ana iplik bitmeden önce kapıcı ipliklerini bekle */
		pthread_join(ptidKapicilar[k],NULL);		
	}
	
	for(int m = 0; m<3; ++m ){      /* Ana iplik bitmeden önce avcı ipliklerini bekle */
		pthread_join(ptidAvcilar[m],NULL);		
	}
	
    if (yuzZombiOlduruldu() == 1)        /* Sonucu kontrol et: Kazandın mı yoksa öldün mü? */
    {
        printf("Tüm zombileri öldürdünüz. Şu an için güvendesiniz!");
    }
    else{
        printf("Sen ve arkadaşların öldü. Tanrı ruhlarınıza acısın.");
    }
    
	
	return 0;
}
