/**
 * Lab 2 - Program Pointers
 *
 * <YOUR NAME(S) HERE>
 *
 * command.c - Source file with your parsing library implementation.
 *
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"

/**
 * command_parse:
 *
 * Parse a command-line string, report foreground/background status,
 * and return a command array.  Each element in the command array
 * corresponds to one word in the command string, in order.
 *
 * A command with '&' after the last word is a background command.
 * The '&' is not part of the resulting command array.  Repetitions or
 * other placements of '&' constitute invalid command lines.
 *
 * Parameters:
 *
 * - line: non-NULL pointer to a command-line string.
 *
 * - foreground: non-NULL pointer to an int where foreground (1)/
 *   background (0) status of the command line should be stored.
 * 
 * Return:
 *
 * - a pointer to a NULL-terminated array of strings (char**) if given
 *   a valid command-line string.
 *
 * - NULL if given a command-line string with invalid placement of '&'
 */
char** command_parse(char* line, int* foreground) {
  // Check arguments: must be non-NULL pointers.
  assert(line);
  assert(foreground);

  // IMPLEMENT ME

int inWord = 0; 
*foreground = 1; //1 when no ampersand;  
int count = 0; 
//int countA  = 0; 


for (char* p = line; *p != '\0'; p++) {
if (*p == '&') {
	if (*foreground == 0) { //it will be 0 if & already appeared 
	printf("here INVALID"); 	
	return NULL; 
	} else {
		*foreground = 0; 
//		countA = count; 	
	}
}else if (*p != ' ') {
	inWord = 1; 
} else if (*p  == ' ') {
	if (inWord == 1) {
		count++; 
		inWord = 0; 
	} else {
		inWord = 0; 
	}
}
}

if (*foreground == 0) {
if (inWord == 1) {
printf("NEW INVLAID"); 
return NULL; 
}
}


//if (countA != count) {
//	printf("there INVALID "); 
//		return NULL;
//}
//}


if (inWord == 1) {
count++;
}

printf("%d", count); 
printf("\n"); 

return NULL;
}


//count number words in line and detect use of &
//return null for invalid commands


//allocate top-level command array

//for each word, allocate space to hold word as null terminated string, 
//copy word into the space, save it in command array  
//return NULL;
//}

/**
 * command_show:
 *
 * Print the structure of a command array.
 *
 * Parameters:
 *
 * - command: a non-NULL pointer to the command array to print.
 *

 A variation on command_print intended for use while debugging.
 The output should make it clear what strings the command array holds, but
 the exact format is up to you (as opposed to command_print, 
where the format is prescribed). For example, you might choose
 to print each word of the command array on separate lines to clearly delineate 
the word boundaries. Make sure that the output lets you distinguish correct words 
from incorrect words. For example, your output should let you distinguish 
the valid, isolated word "ls" versus the string "ls  " that has trailing spaces 
in the string and therefore is not a valid word.


*/
void command_show(char** command) {
  // Check argument: must be non-NULL pointer.
  assert(command);

// _ indicates start and end of elmenet
// _ clearly delineates word boundaries of command array
// _ makes it easy to see if there is a space before the last _ (which indicates 
//that the element has a trailing space, and therefore invalid. 
for (char** p = command; *p != NULL; p+=1) {
	printf("_"); 
	printf(*p); 
}
printf("_"); 
printf("\n");
}


/**
 * command_print:
 *
 * Print a command array in the form of a command-line string.
 * You should *not* include a newline at the end.
 *
 * Parameters:
 *

array:
{ "gcc", "-Wall", "-o", "foo", "foo.c", NULL };

desired output: 
 gcc -Wall -o foo foo.c


 * - command: non-NULL pointer to the command array to print.
 
Print a command array in the form of a command line, 
with the command words separated by single spaces. 
It is fine if there is a space after the final word. 
However, do not include quotes, ampersands (for background commands), or newline characters ('\n'). 
You should use the printf function here.*/

void command_print(char** command) {
  // Check argument: must be non-NULL pointer.
  assert(command);

for (char** p = command; *p != NULL; p+=1) {
	printf (*p); 
	printf(" "); 
}
}


/**
 * command_free:
 *
 * Free all parts of a command array created by command_parse.
 *
 * Parameters:
 *
 * - command: non-NULL pointer to the command array to free.
 */
void command_free(char** command) {
  // Check argument: must be non-NULL pointer.
  assert(command);

  // IMPLEMENT ME

}

