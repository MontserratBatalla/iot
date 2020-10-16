import serial
import cayenne.client

# Cayenne authentication info. This should be obtained from the Cayenne Dashboard.

MQTT_USERNAME  = "9358a710-0d44-11eb-8779-7d56e82df461"
MQTT_PASSWORD  = "550eb11fb124920d06c59c18428f07900de8c6c3"
MQTT_CLIENT_ID = "c64bb680-0d44-11eb-b767-3f1a8f1211ba"
client = cayenne.client.CayenneMQTTClient()
client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID, port=1883)

ser = serial.Serial('/dev/ttyACM0',9600)

while True:
	client.loop()
	read_serial=ser.readline()
	print(read_serial)
	#if ( read_serial.contains("Temperature:")):
	#	Temperatura = read_serial.replace("Temperature:", "")
	#if ( read_serial.contains("Humidity:")):
	#	Humitat = read_serial.replace("Humidity:", "")
	stringFromSerial = str (read_serial)	
	if ("Temperature" in stringFromSerial):
		Temperatura = stringFromSerial
		client.virtualWrite(0,Temperatura)
	if ("Humidity" in stringFromSerial):
		Humitat = stringFromSerial
		client.virtualWrite(1,Humitat)
	
	# print("Temperatura: %-3.1f C" % Temperatura)
	# print("Humitat: %-3.1f C" % Humitat)
	# client.virtualWrite(0,Temperatura)
	# client.virtualWrite(1,Humitat)
time.sleep(10)	
	
# https://diyi0t.com/arduino-to-raspberry-pi-serial-communication/
