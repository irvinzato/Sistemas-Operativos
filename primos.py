import os
import time
import sys

from random import randint, uniform, random

print(os.getpid(), "SOY QUIEN CONTARA LOS NUMEROS PRIMOS")

Lista = sys.argv[1].split(', ')
#print(Lista)
Lista[0] = Lista[0].strip('[')
n = int(sys.argv[2])
Lista[n-1] = Lista[n-1].strip(']')


Lista_Enteros = list(map(int,Lista))
#print(Lista_Enteros)


contadorPrimos = int(0)

def primo(aux):
	if aux<2:
		return False
	for j in range(2,aux):
		if aux%j == 0:
			return False
	return True


for i in range(n):
	aux = Lista_Enteros[i]
	if primo(aux)==True:
		contadorPrimos = contadorPrimos + 1

print("LA CANTIDAD DE NUMEROS PRIMOS ES: ",contadorPrimos)
print("SOY EL HIJO: ",os.getpid(),"TERMINE MIS CALCULOS")
