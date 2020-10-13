import RPi.GPIO as GPIO
import dht11 as dht11

pin = 7

GPIO.setmode(GPIO.BOARD)
GPIO.setup(pin, GPIO.OUT)
GPIO.setwarnings(False)

sensor = dht11.DHT11(pin)

lectura = sensor.read() 

if lectura.is_valid():
	Temperatura = lectura.temperature
	Humitat = lectura.humidity
		
	print("Temperatura: %-3.1f C" % Temperatura)
	print("Temperatura: %-3.1f C" % Humitat)
	
else	
	print("Error: %d" % lectura.error_code)
		
