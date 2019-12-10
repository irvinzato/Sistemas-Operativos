import os
import time
import sys

from random import randint, uniform, random

print(os.getpid(), "SOY QUIEN CONTARA LOS NUMEROS PERFECTOS")

Lista = sys.argv[1].split(', ')
Lista[0] = Lista[0].strip('[')
n = int(sys.argv[2])
Lista[n-1] = Lista[n-1].strip(']')


Lista_Enteros = list(map(int,Lista))

contadorPerfecto = int(0)

def NumeroPerfecto(aux):
  suma = 0

  for j in range(1,aux):

    if (aux%j == 0):

      suma = suma + j

  if aux == suma:
    return True
  else:
    return False


for i in range(n):
	aux = Lista_Enteros[i]
	if NumeroPerfecto(aux):
		contadorPerfecto = contadorPerfecto + 1
  		#print("%s es un numero perfecto" % num)

print("LA CANTIDAD DE NUMEROS PERFECTOS ES: ",contadorPerfecto)
print("SOY EL HIJO: ",os.getpid(),"TERMINE MIS CALCULOS")
