#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2 // pin yang digunakan untuk input data dari sensor dht 11 
#define DHTTYPE DHT11 // kalian bisa mengganti DHT11 dengan DHT 22 /DHT 21 tergantung sensor yang kalian gunakan 
DHT dht(DHTPIN, DHTTYPE); 
void setup() 
{ 
Serial.begin(9600);
Serial.println("DHTxx test!");
dht.begin(); 
} 
void loop() 
{ 
delay(2000); 
float h = dht.readHumidity(); 
float t = dht.readTemperature(); // baca temperatur dalam celcius, jika ingin mengganti fahrenheit kalian bisa menggunakan float f = dht.readTemperature(true); 
// cek apakah koneksi benar, jika salah print error
if (isnan(h) || isnan(t)) 
{ 
Serial.println("Failed to read from DHT sensor!");
return; 
} 
Serial.print("Kelembapan: "); 
Serial.print(h); // menampilkan kelembapan di serial monitor
Serial.print(" %\t");
Serial.print("Temperature: "); 
Serial.print(t); // menampilkan temperatur di serial monitor
Serial.println(" *C "); 
} 
