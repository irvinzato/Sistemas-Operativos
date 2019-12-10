import os
import time
import sys

from random import randint, uniform, random

print(os.getpid(), "SOY QUIEN CONTARA LOS NUMEROS IMPARES")
Lista = sys.argv[1].split(', ')
#print(Lista)
Lista[0] = Lista[0].strip('[')
n = int(sys.argv[2])
Lista[n-1] = Lista[n-1].strip(']')
#for i in range(int(sys.argv[2])):
#	Lista[i] = Lista[i].strip('[')
#       Lista[i] = Lista[i].strip('[')
#       Lista[i] = Lista[i].strip(',')

Lista_Enteros = list(map(int,Lista))
#print(Lista_Enteros)


contadorPares = int(0)
contadorImpares = int(0)

for i in range(n):
	if Lista_Enteros[i]%2 == 0:
		contadorPares = contadorPares + 1

	else:
		contadorImpares = contadorImpares + 1

print("LA CANTIDAD DE NUMEROS IMPARES ES: ",contadorImpares)
print("SOY EL HIJO: ",os.getpid(),"TERMINE MIS CALCULOS")
