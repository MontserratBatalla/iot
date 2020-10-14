#!/usr/bin/env python
import cayenne.client
import time
import logging
import sys

import RPi.GPIO as GPIO
import dht11 as dht11
import time

#seleccionar el mode de entrada BOARD
GPIO.setmode(GPIO.BOARD)
#pin on enxufarem el circuit de sortida
pin = 7
#temps que tindrem el let en cada posicio
sleeptime = 1
#al pin que seleccionem el fem de sortida
GPIO.setup(pin, GPIO.OUT)
GPIO.setwarnings(False)

sensor = dht11.DHT11(pin)


# Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
# MQTT_USERNAME  = "MQTT_USERNAME"
MQTT_USERNAME  = "9358a710-0d44-11eb-8779-7d56e82df461"
# MQTT_PASSWORD  = "MQTT_PASSWORD"
MQTT_PASSWORD  = "550eb11fb124920d06c59c18428f07900de8c6c3"
# MQTT_CLIENT_ID = "MQTT_CLIENT_ID"
MQTT_CLIENT_ID = "c64bb680-0d44-11eb-b767-3f1a8f1211ba"


client = cayenne.client.CayenneMQTTClient()
# client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID, loglevel=logging.INFO)
# For a secure connection use port 8883 when calling client.begin:
client.begin(MQTT_USERNAME, MQTT_PASSWORD, MQTT_CLIENT_ID, port=1883)

while True:
	client.loop()
	lectura = sensor.read()
	if lectura.is_valid():
		Temperatura = lectura.temperature
		Humitat = lectura.humidity

		print("Temperatura: %-3.1f C" % Temperatura)
		print("Temperatura: %-3.1f C" % Humitat)
		client.virtualWrite(0,Temperatura)
		client.virtualWrite(1,Humitat)
	else :
       	 	print("Error: %d" % lectura.error_code)
	time.sleep(10)

