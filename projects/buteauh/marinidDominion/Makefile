CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
#testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

#badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
#	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

#testGetCost: unittest1.c dominion.o rngs.o
#	gcc -o unit1test -g  unittest1.c dominion.o rngs.o $(CFLAGS)

#$testUpdateCoin: unittest2.c dominion.o rngs.o
#	gcc -o unit2test -g  unittest2.c dominion.o rngs.o $(CFLAGS)

#testIsGameOver: unittest3.c dominion.o rngs.o
#	gcc -o unit3test -g  unittest3.c dominion.o rngs.o $(CFLAGS)

#testFullDeckCount: unittest4.c dominion.o rngs.o
#	gcc -o unit4test -g  unittest4.c dominion.o rngs.o $(CFLAGS)

testSmithy: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

testAdventurer: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS) 

testVillage: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

testGreatHall: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testRan1: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)  

testRan2: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

testRan3: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)


#randomtestadventurer.out: testRan1 dominion.c
#	./randomtestadventurer >> randomtestadventurer.out
#	 gcov dominion.c -b >> randomtestadventurer.out
#	cat dominion.c.gcov >> randomtestadventurer.out	 

randomtestcard1.out: testRan2 dominion.c
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c -b >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out


randomtestcard2.out: testRan3 dominion.c
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c -b >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

testSmithy.out: testSmithy dominion.c
	./cardtest1 >> testSmithy.out
	gcov dominion.c -b >> testSmithy.out
	cat dominion.c.gcov >> testSmithy.out

testAdventurer.out: testAdventurer dominion.c
	./cardtest2 >> testAdventurer.out
	gcov dominion.c -b >> testAdventurer.out
	cat dominion.c.gcov >> testAdventurer.out

testOutpost.out: testVillage dominion.c
	./cardtest3 >> testOutpost.out
	gcov dominion.c -b >> testOutpost.out
	cat dominion.c.gcov >> testOutpost.out


testGreatHall.out: testGreatHall dominion.c
	./cardtest4 >> testGreatHall.out
	gcov dominion.c -b >> testGreatHall.out
	cat dominion.c.gcov >> testGreatHall.out


runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: testSmithy testAdventurer testVillage testGreatHall  testRan1 testRan2 testRan3 randomtestcard1.out randomtestcard2.out randomtestadventurer.out testSmithy.out testAdventurer.out testOutpost.out testGreatHall.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
