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
* parse_helper:
*
*/
char* parse_helper(char* word, int totalChar) {

//Malloc argArr space to fit word
char* argArr = malloc(sizeof(char) * totalChar); 

//Set index to zero
int index = 0; 

//Iterate through word chars
for (char* p = word; *p !=  '\0'; p++) {

	//If char not space or ampersand
        if (*p != ' ' && *p != '&') {
		
		//Add character to index
		//Increment index by one
                argArr[index] = *p; 
                index++; 

	//If the char is a space
        } else if (*p == ' ') {

		//Increment index by one
		//Add null terminator, then return argArr
                index++; 
                argArr[index] = '\0'; 
                return argArr; 
        }
}

//Increment index by one
//Add null terminator, then return argArr
index++; 
argArr[index] = '\0'; 
return argArr; 
}



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


//count number words in line and detect use of &
//return null for invalid commands
int inWord = 0; 
*foreground = 1; //1 when no ampersand;  
int count = 0; 
int charCount = 0; 

for (char* p = line; *p != '\0'; p++) {

if (*p == '&') {
	if (*foreground == 0) { //it will be 0 if & already appeared 
		return NULL; 
	} else {
		if (inWord == 1) {
			count++; 
		}
		*foreground = 0; 
		inWord = 0; 		
	}
} else if (*p != ' ') {
	inWord = 1;
	charCount++;  
} else if (*p  == ' ' ) {
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
		return NULL; 
	}
}


if (inWord == 1) {
	count++;                          
}

inWord = 0; 
char** commandArr = malloc(sizeof(char*) * count+1);
char** p = commandArr; //it seems like we need this pointer but im a little confused as to 
//why we cant just commandArr++ instead lol 

for (char* p1 = line; *p1 != '\0'; p1++) { 
if (*p1 == '&') {
	inWord = 0;         
} else if (*p1 != ' ') {
        if (inWord == 0) {
		*p = parse_helper(p1, charCount); //parse_helper(p1, charCount) ; // so *commandArr is "world! please parse..
				//because *commandArr type is char* aka str 
                inWord = 1;
		p += 1; 
        }
} else if (*p1  == ' ' ) {
        inWord = 0;
}

}
p+=1; 
*p = NULL; 
return commandArr; 
}
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

