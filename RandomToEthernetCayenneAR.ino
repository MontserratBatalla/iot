#include <time.h>
#include <Ethernet.h>
#include <CayenneMQTTEthernet.h>
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
EthernetClient client;

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "9358a710-0d44-11eb-8779-7d56e82df461";
char password[] = "550eb11fb124920d06c59c18428f07900de8c6c3";
char clientID[] = "c64bb680-0d44-11eb-b767-3f1a8f1211ba";

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Cayenne.begin(username, password, clientID);

}

void loop() {
  // put your main code here, to run repeatedly:
  Cayenne.loop();
  int r = rand() % 20;
  
  if (Ethernet.begin(mac) == 0)
   {
      Serial.println("Failed to configure Ethernet using DHCP");
      Ethernet.begin(mac, ip);
   }
  
  Serial.println(r); // imprimeix i nova linia
  Cayenne.virtualWrite(0, r);

  delay(1000);        // delay in between reads for stability
 return;

}
