CC = g++
CCARGS = -O2 -H -Wall -Wshadow -std=gnu++1z

PCH_SRC = testlib.h
PCH_OUT = testlib.h.gch

# compile scripts

# precompile header
$(PCH_OUT): $(PCH_SRC)
	$(CC) $(CCARGS) -o $@ $^

%.o: %.cpp $(PCH_OUT)
	$(CXX) $(CCARGS) -include $(PCH_SRC) -c -o $@ $<

A: A.o
	$(CC) $(CCARGS) -o A A.o

A_1: A_1.o
	$(CC) $(CCARGS) -o A_1 A_1.o

B: B.o
	$(CC) $(CCARGS) -o B B.o

B_1: B_1.o
	$(CC) $(CCARGS) -o B_1 B_1.o

B_2: B_2.o
	$(CC) $(CCARGS) -o B_2 B_2.o

C: C.o
	$(CC) $(CCARGS) -o C C.o

C_1: C_1.o
	$(CC) $(CCARGS) -o C_1 C_1.o

C_2: C_2.o
	$(CC) $(CCARGS) -o C_2 C_2.o

D: D.o
	$(CC) $(CCARGS) -o D D.o

D_1: D_1.o
	$(CC) $(CCARGS) -o D_1 D_1.o

D_2: D_2.o
	$(CC) $(CCARGS) -o D_2 D_2.o

D_3: D_3.o
	$(CC) $(CCARGS) -o D_3 D_3.o

E: E.o
	$(CC) $(CCARGS) -o E E.o

E_1: E_1.o
	$(CC) $(CCARGS) -o E_1 E_1.o

E_2: E_2.o
	$(CC) $(CCARGS) -o E_2 E_2.o

E_3: E_3.o
	$(CC) $(CCARGS) -o E_3 E_3.o

# run scripts

run_A: A
	./A

run_A_1: A_1
	./A_1

run_B: B
	./B

run_B_1: B_1
	./B_1

run_B_2: B_2
	./B_2

run_C: C
	./C

run_C_1: C_1
	./C_1

run_C_2: C_2
	./C_2

run_D: D
	./D

run_D_1: D_1
	./D_1

run_D_2: D_2
	./D_2

run_D_3: D_3
	./D_3

run_E: E
	./E

run_E_1: E_1
	./E_1

run_E_2: E_2
	./E_2

run_E_3: E_3
	./E_3
