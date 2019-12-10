import os
import time
import sys

from random import randint, uniform, random

print(os.getpid(), "SOY QUIEN CONTARA LOS NUMEROS PARES")

Lista = sys.argv[1].split(', ')
#print(Lista)
Lista[0] = Lista[0].strip('[')
n = int(sys.argv[2])
Lista[n-1] = Lista[n-1].strip(']')

"""
print(Lista[0])
print(Lista[n-1])
print("La nueva lisa es la siguiente ")
print(Lista)
"""
Lista_Enteros = list(map(int,Lista))
#print(Lista_Enteros)

contadorPares = int(0)
contadorImpares = int(0)

for i in range(n):
	if Lista_Enteros[i]%2 == 0:
		contadorPares = contadorPares + 1

	else:
		contadorImpares = contadorImpares + 1

print("LA CANTIDAD DE NUMEROS PARES ES: ",contadorPares)
print("SOY EL HIJO: ",os.getpid(),"TERMINE MIS CALCULOS")
