#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
	int min = 32;
	int max = 125;
	

	char random = (rand() % (max - min + 1) + min);
	if (random >= 65 && random <= 90)
		random += 32;
	return random;
	
}

char *inputString()
{
	int min = 101;
	int max = 116;
	int size = 6;
	
	char stringArr[6];
	
	

	int x;
	for(x = 0; x < size - 1; x++)
	{
		stringArr[x] = (rand() % (max - min + 1) + min);
	}
	
	return stringArr; 

}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
