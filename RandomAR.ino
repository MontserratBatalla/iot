/*

*/
include <time.h>
void setup() {
    Serial.begin(9600);
}

void loop() {
 
  int i = srand (time(NULL));
  
  Serial.println("Número Random "+ "%d\n", i); // imprimeix i nova linia
 return;
    
}
