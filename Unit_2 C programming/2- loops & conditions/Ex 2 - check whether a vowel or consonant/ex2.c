/*
 * ex2.c
 *
 *  Created on: Jul 16, 2022
 *      Author: phelp
 */

/*
 * check vowel or consonant
 */

#include<stdio.h>

int main()
{
char c;
printf("Enter character you want to check: ");
fflush(stdout);
scanf("%c", &c);
if(c == 'a' || c== 'A' || c == 'e' || c == 'E'|| c == 'i'|| c=='I'|| c=='o'|| c=='O'|| c=='u'|| c=='U')
	printf("%c is vowel",c);
else
	printf("%c is consonant",c);
}
