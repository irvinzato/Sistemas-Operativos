import os
import time
import sys

from random import randint, uniform, random

def inicio():
	#print("----------------------------------------------------------")
	print("DAME EL NUMERO DE ELEMENTOS QUE QUIERES EN LA LISTA: ")
	n = int(input())
	Lista = list(range(n))

	for i in range(n):
		Lista[i] = int(uniform(1,100))

	print("La lista que se genero es la siguiente ")
	print(Lista)

	for i in range(4):
		#print("Entre al for")
		pid = os.fork()

		if pid == 0:
			print("SOY EL HIJO CON PID: ",os.getpid())
			#time.sleep(3)
			if i==0:
				os.execlp("python3", "python3", "pares.py", str(Lista), str(n))
				os._exit(0)
			elif i==1:
				os.execlp("python3", "python3", "impares.py", str(Lista), str(n))
				os._exit(0)
			elif i==2:
				os.execlp("python3", "python3", "primos.py", str(Lista), str(n))
				os._exit(0)
			elif i==3:
				os.execlp("python3", "python3", "perfecto.py", str(Lista), str(n))
				os._exit(0)
			break
		
		print("----------------------------------------------------------")
		hijo = os.wait()
		
inicio()
print("----------------------------------------------------------")