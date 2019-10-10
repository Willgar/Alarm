#include <stdio.h>                                      //William Axbrink, 9905300670, williamaxb@gmail.com waxbrink@kth.se
int timeHour(int), timeMinute(int), timeSecond(int);    //Initialiserar int-funktioner
void tellTime(int), clockRotation(int, int);            //Initialiserar void-funktioner
int main(){                                             //Funktioner och variabler är namngivna på engelska i lowerCamelCase-format
    int currentTime, alarmTime;                         //Deklarerar varaibler för nuvarande tid samt alarmet
    printf("Vad är klockan? Format HHMMSS \n");         //Frågar användaren om tider för att definera ovanstående variabler
    scanf("%d", &currentTime);                          //Ingen felhantering implementerad enligt uppgiftsinstruktioner
    printf("Vilken tid vill du sätta ditt alarm? \n");
    scanf("%d", &alarmTime);
    printf("Alarm satt "); tellTime(alarmTime);         //Kallar void-funktionen tellTime för att skriva ut alarm-tiden
    clockRotation(currentTime, alarmTime);              //Klockfunktion inför att tiden == alarmtiden då den bryts
    printf("ALARM");                                    //När "loop-funktionen" är bruten så printas larmet
    scanf("%d", &currentTime);
    return 0;
    
}
void clockRotation(int currentTime, int alarmTime){     //En funktion för en klocka som räknar timme, minut och sekund och avbryts när tiden är alarmdags
    while(timeHour(currentTime) < 24){                  //Loopen forsätter fram till att timmen är 24 och då ändras tiden till 000000       
        while(timeMinute(currentTime ) < 60){           //Loopen forsätter fram till att minuten är 60 och då läggs en timme till samt minuten nollas 
            while(timeSecond(currentTime) < 60){        //-||- sekunden är 60
                tellTime(currentTime);                  //Anropar en funktion för att skriva ut tiden
                if(currentTime == alarmTime) return;    //Ifall klockan är alarmdags så bryts hela funktionen genom att den returnerar tillbaka till main
                currentTime++;                          //Lägger till en sekund
                //sleep(1);                             //För att ge klockan en fördröjning, dvs närmare "realtid". Utkommenterad för det var ej nödvändigt för uppgiften
            }
            currentTime = (timeHour(currentTime) * 10000) + (timeMinute(currentTime) * 100) + 100; //Ändrar tiden till en minut framåt och sekunden nollad
        }
        currentTime = (timeHour(currentTime) * 10000) + 10000;  //Sätter fram tiden en timme och minuten nollad
        if(timeHour(currentTime) >= 24){currentTime = 0;}       //När timmen är 24 så nollas värdet
    }
}
void tellTime(int time){                                //En funktion för att skriva ut tiden med kolon och 0:a framför (där det behövs)
    printf("%02d:%02d:%02d \n", timeHour(time), timeMinute(time), timeSecond(time));
}  
int timeHour(int hour)      { return hour/10000; }      //får fram dem två första siffrorna från currentTime-talet via divison
int timeSecond(int second)  { return second%100; }      //får fram dem två sista siffrorna från currentTime-talet via modulusräkning
int timeMinute(int minute)  { return minute/100%100; }  //får fram dem två mellersta siffrorna från currentTime-talet via först divison och sedan modulusräkning