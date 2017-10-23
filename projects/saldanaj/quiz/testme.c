
/*
 Student: Joaquin Saldana
 
 Random Testing Quiz
 
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
 Function returns a char. It should return either one of the following
 chars: "[({ ax})]"
 */
char inputChar()
{
	// string that holds the chars that can change the state value
	char * charString = "[({ ax})]";

	// return the char value via a randomized index value
    return charString[rand() % 9];
}


/*
 Function returns a string.  The string is composed of chars from the
 test string that holds all of the chars that could create the word
 "reset".  In otherwords, that string holds the letters r, e, s and t.
 
 The string is comprised of random chars and the random number generator
 choose a random index.
 */
char *inputString()
{
	char * testString = "rest";
	
	char str[6];
	
	int i;
	
	for(i = 0; i < 5; i++)
	{
		str[i] = testString[rand()%4];
	}
	
	str[5] = '\0';
	
	char *final = str;
	
	printf("String generated: %s\n", final);
	
	return final;
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

		if (c == '[' && state == 0)
			state = 1;
		if (c == '(' && state == 1)
			state = 2;
		if (c == '{' && state == 2)
			state = 3;
		if (c == ' '&& state == 3)
			state = 4;
		if (c == 'a' && state == 4)
			state = 5;
		if (c == 'x' && state == 5)
			state = 6;
		if (c == '}' && state == 6)
			state = 7;
		if (c == ')' && state == 7)
			state = 8;
		if (c == ']' && state == 8)
			state = 9;

		// exit from the loop if the string has the following string input: reset\0
		if (s[0] == 'r' && s[1] == 'e'&& s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
		{
		  printf("error ");
		  exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
	// seed the random number generator
    srand(time(NULL));

	testme();
	
	return 0;
}
