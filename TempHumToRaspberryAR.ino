// Example testing sketch for various DHT humidity/temperature sensors
// Escrit per ladyada, domini públic
// Requereix les llibreries a
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor


#include <DHT.h>
#define DHTPIN 2 // Si el pin digital per les dades del sensor DHT11 es el 2.
#define DHTTYPE DHT11 // Especifiquem que el sensor es el DHT11
DHT dht(DHTPIN, DHTTYPE); // Inicialitzacio 1

void setup() {
 Serial.begin(9600); // Inicialitzacio Comunicació Sèrie i Velocitat.
 dht.begin(); // Inicialitzacio 3

}
void loop() {

 delay(2000); // Espera 2 segons entre mesures. El sensor no llegeix de forma instantània.
 float h = dht.readHumidity(); // lectura de la Humitat com a decimal a la variable h
 float t = dht.readTemperature(); // lectura de la Temperatura com a decimal a la variable t.
 // Comprova si alguna lectura falla, surt per provar de nou.
 if (isnan(h) || isnan(t)) {
    Serial.println("Errada en llegir el sensor DHT11 !"); // imprimeix i nova linia
    return;
 }
 
 Serial.print("Temperature: "); //imprimeix paraula i mateixa linia
 Serial.print(t); // imprimeix valor de temperatura
 Serial.print("\n"); // Canvi de linia
 Serial.print("Humidity: "); // imprimeix paraula i mateixa linia
 Serial.print(h); // imprimeix valor de humitat
 Serial.print("\n"); // canvi de linia

} 
