// Example testing sketch for various DHT humidity/temperature sensors
// Escrit per ladyada, domini públic
// Requereix les llibreries a
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor


#include <DHT.h>
#define DHTPIN 2 // Si el pin digital per les dades del sensor DHT11 es el 2.
#define DHTTYPE DHT11 // Especifiquem que el sensor es el DHT11
DHT dht(DHTPIN, DHTTYPE); // Inicialitzacio 1

//#include <CayenneMQTTSerial.h>

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "9358a710-0d44-11eb-8779-7d56e82df461";
char password[] = "550eb11fb124920d06c59c18428f07900de8c6c3";
char clientID[] = "c64bb680-0d44-11eb-b767-3f1a8f1211ba";


void setup() {
 Serial.begin(9600); // Inicialitzacio Comunicació Sèrie i Velocitat.
 dht.begin(); // Inicialitzacio 3
// Cayenne.begin(username, password, clientID);
}
void loop() {
 //Cayenne.loop();
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
 //Cayenne.virtualWrite(0,t);
 //Cayenne.virtualWrite(1,h);
} 
