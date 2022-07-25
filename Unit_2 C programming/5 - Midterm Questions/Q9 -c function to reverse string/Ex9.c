#include<stdio.h>
#include<string.h>

char*  reverseString(char str[])
{
	char  l=0 , h , temp;
	 h = strlen(str) -1;

	 while(h>l)
	 {
		 temp = str[l];
		 str[l] = str[h];
		 str[h]=temp;
		 l++;h--;
	 }
	 return str;
}
int main()
{
char str [50];

printf("Enter string: ");
fflush(stdout);
gets(str);


 printf("Reversed string: %s",reverseString(str));
}
