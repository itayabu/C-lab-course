
MyStrLen.o: MyStrLen.c
	gcc -c MyStrLen.c
MyStrLen: MyStrLen.o
	gcc MyStrLen.o -o MyStrLen
	
MyStrCmp.o: MyStrCmp.c
	gcc -c MyStrCmp.c
MyStrCmp: MyStrCmp.o
	gcc MyStrCmp.o -o MyStrCmp
	
Decrypt.o: Decrypt.c
	gcc -c Decrypt.c
Decrypt: Decrypt.o
	gcc Decrypt.o -o Decrypt
	
CheckDependency.o: CheckDependency.c
	gcc -c CheckDependency.c
	
CheckDependency: CheckDependency.o
	gcc CheckDependency.o -o CheckDependency
	
clean:
	rm *.o MyStrLen MyStrCmp Decrypt CheckDependency
	
PHONY: clean

all: Decrypt MyStrCmp MyStrLen CheckDependency
