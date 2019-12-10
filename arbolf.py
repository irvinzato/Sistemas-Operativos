import os
import time 

def inicio():
	
	ram = int(input("DAME LA RAMIFICACION: "))
	prof = int(input("DAME LA PROFUNDIDAD: "))
	arbol(ram,prof)

def arbol(ram,prof):
	auxram = 0
	auxprof = 0
	tid=0
	for auxprof in range(prof):
		if(tid != 0):
			break
		for auxram in range(ram):
			tid=os.fork()
			
			if(tid==0):
				print("SOY EL PROCESO:", os.getpid(), "Y MI PADRE ES:", os.getppid());
				break
	time.sleep(10)

inicio()
