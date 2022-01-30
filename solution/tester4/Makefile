CC = g++
CCARGS = -O2 -Wall -Wshadow -std=gnu++1z

# compile scripts
A: A.py
	echo "OAO"

A-j: A-j.java
	cp A-j.java A.java
	javac A.java

B: B.cpp
	$(CC) $(CCARGS) -o B B.cpp

B-merge: B-merge.cpp
	$(CC) $(CCARGS) -o B-merge B-merge.cpp

B_1-floyd: B_1-floyd.cpp
	$(CC) $(CCARGS) -o B_1-floyd B_1-floyd.cpp

B_1_WA-ver1: B_1_WA-ver1.cpp
	$(CC) $(CCARGS) -o B_1_WA-ver1 B_1_WA-ver1.cpp

B_1_WA-ver2: B_1_WA-ver2.cpp
	$(CC) $(CCARGS) -o B_1_WA-ver2 B_1_WA-ver2.cpp

B_3_WA-ver1: B_3_WA-ver1.cpp
	$(CC) $(CCARGS) -o B_3_WA-ver1 B_3_WA-ver1.cpp

B_3_WA-ver2: B_3_WA-ver2.cpp
	$(CC) $(CCARGS) -o B_3_WA-ver2 B_3_WA-ver2.cpp

C: C.cpp
	$(CC) $(CCARGS) C.cpp -o C

C-j: C-j.java
	cp C-j.java C.java
	javac C.java

D: D.cpp
	$(CC) $(CCARGS) D.cpp -o D

D-j: D-j.java
	cp D-j.java D.java
	javac D.java

D_WA: D_WA.cpp
	$(CC) $(CCARGS) D_WA.cpp -o D_WA

E: E.cpp
	$(CC) $(CCARGS) E.cpp -o E

E-j: E-j.java
	cp E-j.java E.java
	javac E.java

# run scripts
run_A: A.py
	python3 A.py

run_A-j: A.class
	java A

run_B: B
	./B

run_B-merge: B-merge
	./B-merge

run_B_1-floyd: B_1-floyd
	./B_1-floyd

run_B_1_WA-ver1: B_1_WA-ver1
	./B_1_WA-ver1

run_B_1_WA-ver2: B_1_WA-ver2
	./B_1_WA-ver2

run_B_3_WA-ver1: B_3_WA-ver1
	./B_3_WA-ver1

run_B_3_WA-ver2: B_3_WA-ver2
	./B_3_WA-ver2

run_C: C
	./C

run_C-j: C.class
	java C

run_D: D
	./D

run_D-j: D.class
	java D

run_D_WA: D_WA
	./D_WA

run_E: E
	./E

run_E-j: E.class
	java E
