/* ------------------Projekt Inteligentnego Biurka------------------
 *  Opis projektu:
 *  Biurko ma przypominac o rzeczach o ktorych najczesciej zapominamy
 *  przed wyjsciem z domu przez podswietlanie konkretnych miejsc na biurku
 *  przy pomocy ledow adresowalnych ws2812b.
 *  Zalozenia:
 *  1. Liniowy Czujnik halla przymocowany do haka wyzwala sekwencje odpalania ledow.
 *  2. Każda kieszen do innego wyprowadzenia
 *  3. Sekwencja gaszenia odpalania
 *  
 *  Linki:
 *  - Czujnik halla pryklad:
 *  http://www.openplatform.cc/index.php/home/index/details/apiid/103
 *
 *   *  Autor: Karol Brauza
 */
//---------Diody
 #include <Adafruit_NeoPixel.h> //biblioteka do oblsugi diod
 #define PIN 4 // pin sygnalowy dla diod
 #define PINa 5 // pin sygnalowy dla 
 #define PINb 6 // pin sygnalowy dla 
 #define PINc 7 // pin sygnalowy dla 
 #define NUMPIXELS 24 // liczba diod
 
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //deklaracja paska ledowego o nazwie"pixels"
 Adafruit_NeoPixel pixelsa = Adafruit_NeoPixel(NUMPIXELS, PINa, NEO_GRB + NEO_KHZ800); //deklaracja paska ledowego o nazwie"pixels"
 Adafruit_NeoPixel pixelsb = Adafruit_NeoPixel(NUMPIXELS, PINb, NEO_GRB + NEO_KHZ800); //deklaracja paska ledowego o nazwie"pixels"
 Adafruit_NeoPixel pixelsc = Adafruit_NeoPixel(NUMPIXELS, PINc, NEO_GRB + NEO_KHZ800); //deklaracja paska ledowego o nazwie"pixels"

uint32_t white = pixels.Color(255, 244, 102); // zmienna "white" przechowujaca kolor swiecenia kazdej z diod (r, g, b) w zakresie 0-255
uint32_t whitea = pixelsa.Color(255, 178, 102); // zmienna "white" przechowujaca kolor swiecenia kazdej z diod (r, g, b) w zakresie 0-255
uint32_t whiteb = pixelsb.Color(255, 178, 102); // zmienna "white" przechowujaca kolor swiecenia kazdej z diod (r, g, b) w zakresie 0-255
uint32_t whitec = pixelsc.Color(255, 178, 102); // zmienna "white" przechowujaca kolor swiecenia kazdej z diod (r, g, b) w zakresie 0-255

uint32_t black = pixels.Color(0, 0, 0);
int al = 10; // zmienna pomocnicza do odliczania zapalania diod
//---------Czujnik Halla
int hallPin = A5;
int ledPin = 13;
int hallWartosc = 0;

  void setup () {
    Serial.begin (9600);
    pinMode (PIN, OUTPUT);
    pinMode (PINa, OUTPUT);
    pinMode (PINb, OUTPUT);
    pinMode (PINc, OUTPUT);

  }

  void loop () {
    hallWartosc = analogRead (hallPin);
    Serial.print("Wartosc: ");
    Serial.println (hallWartosc, DEC);
    if(hallWartosc < 100){  
      for(int i=0;i<24;i++)
      {
      pixels.setPixelColor(i, white);
      pixelsa.setPixelColor(i, whitea);
      pixelsb.setPixelColor(i, whiteb);
      pixelsc.setPixelColor(i, whitec);
      pixels.show();
      pixelsa.show();
      pixelsb.show();
      pixelsc.show();
      delay(150);
      }
      pixels.clear();
      pixelsa.clear();
      pixelsb.clear();
      pixelsc.clear();
      pixels.show();
      pixelsa.show();
      pixelsb.show();
      pixelsc.show();
       for(int i=0;i<24;i++)
      {
      pixels.setPixelColor(i, white);
      pixelsa.setPixelColor(i, whitea);
      pixelsb.setPixelColor(i, whiteb);
      pixelsc.setPixelColor(i, whitec);
      pixels.show();
      pixelsa.show();
      pixelsb.show();
      pixelsc.show();
      delay(150);
      }
      delay(40000);
      pixels.clear();
      pixelsa.clear();
      pixelsb.clear();
      pixelsc.clear();
      pixels.show();
      pixelsa.show();
      pixelsb.show();
      pixelsc.show();  
      
  }
  }
