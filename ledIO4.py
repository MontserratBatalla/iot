# importar entrada sortida de GP i temps
import RPi.GPIO as GPIO
import time

#seleccionar el mode de entrada BOARD
GPIO.setmode(GPIO.BOARD)
#pin on enxufarem el circuit de sortida
pin = 7
#temps que tindrem el let en cada posicio
sleeptime = 1
#al pin que seleccionem el fem de sortida
GPIO.setup(pin, GPIO.OUT)

while True:
	GPIO.output(pin, GPIO.HIGH)
	time.sleep(sleeptime)
	print("let on")
	GPIO.output(pin, GPIO.LOW)
	time.sleep(sleeptime)
	print("let off")
