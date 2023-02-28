/**
 * Lab 2 - Program Pointers
 *
 * <Diyaa Yaqub, Khalil Jackson>
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
* Counts the number of characters in a word, and then loops 
* through the argument character by character, to create a pointer to an array of characters (a string) 
* that is the first word in the argument. This will then be used by commmand_parser since an elemnet in command**
* will point to this char* string. 
*
* Parameter:
* word - line passed in parser method but starting from the 
* the word that will be stored in returned char*   
* Return: 
* -  pointer to char* string containing one word from the command
*/
char* parse_helper(char* word) {
int charCount = 0; //character count for a single word the line

for (char* p = word; *p !=  ' '; p++) {
	//word might end with null terminator instead of space
	if (*p == '\0') { 
		break; 
 }
       //count all characters except ampersand
	//since they will not appear in command array
        if (*p != '&') {           
                charCount+=1; 
	}
}

//need space to hold all characters in word and \0
char* argArr = malloc(sizeof(char) * charCount + 1); 

//pointer to elements in argArr containing each char in a word
char* pArgArr = argArr; 

//loop through each char in line passed in as arg
for (char*p = word; *p !=  ' '; p++) {
 	if (*p == '\0') {
                break; 
	}

	//don't include & in arr
        if (*p != '&') {		
		//have pointer store pointer to char in word
		 *pArgArr = *p; 

		//increment pointer so that new pointer is reference to next char in word                
		pArgArr++; 
	}
}
//Add null terminator
*pArgArr = '\0'; 

//return base pointer
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

//boolean value (if char* in loop is a reference to a character part of a word, it is 1)
int inWord = 0; 

*foreground = 1; //1 when no ampersand;  

int wordCount = 0; 

//loop counts number words in line and detects use of &
//returns null for invalid commands
for (char* p = line; *p; p++) {
if (*p == '&') {
	//if & has already appeared, *foregaround = 0, and 
	//more than one & is invalid
	if (*foreground == 0) {  
		return NULL; 
	} else {
		//when & appears after a word with no space in between
		if (inWord == 1) {
			wordCount++; 
		}
		//sets *foreground to 0 since & character indicates background command
		*foreground = 0; 
		
		//& indicates end of a word
		inWord = 0; 		
	}
} else if (*p != ' ') {
	inWord = 1;
} else if (*p  == ' ' ) {
	//when previous char was part of word, and this char is a space
	//indicates that it is the end of a word, and wordCount incremented
	if (inWord == 1) {
		wordCount++; 
	}
	inWord = 0; 
}
}

//no word can appear after an &
if (*foreground == 0) {
	if (inWord == 1) {
		return NULL; 
	}
}

//since wordCount incremented when there is a space in loop
//if word ends with something else, inWord still is 1, wordCount must still be incremneted
if (inWord == 1) {
	wordCount++;                          
}

//resets inWord
inWord = 0; 

//initialises top level array
char** commandArr = malloc(sizeof(char*) * wordCount+1);

//pointer to commandArr
char** pCommandArr = commandArr;  

//loops through characters in line with pointer p
for (char* p = line; *p; p++) { 
if (*p == '&' || *p == ' ') {
	inWord = 0;         
} else if (*p != ' ') {
	//if *p is a non-space char, and inWord == 0, it means
	// that *p is first letter of a word 
        if (inWord == 0) {
		// *pCommandArr is a pointer to a single word (single element in commandArr) 
		*pCommandArr = parse_helper(p);  
		inWord = 1;
		//increments pointer so that next word can be added to commandArr
		pCommandArr += 1; 
        }
}
}
*pCommandArr = NULL; 
return commandArr; 
}

/**
 * command_show:
 *
 * Print the structure of a command array. Prints strings that command array holds and in between each 
 * string is a '_'. _ indicates start and end of element, clearly delineates word boundaries of command array and 
 * makes it easy to see if there is a space before the last _ (which indicates 
 * that the element has a trailing space, and therefore invalid. 
 * Parameters:
 * - command: a non-NULL pointer to the command array to print.
 *
*/
void command_show(char** command) {
// Check argument: must be non-NULL pointer.
assert(command);

//p is pointer to each element in command arra
//loops and prints every string in command array
for (char** p = command; *p; p+=1) {
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
 * - command: non-NULL pointer to the command array to print.
 */
 
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

//frees each char* that command array references
for (char** p = command; *p; p++) {	
	free(*p); 
}
free(command); 
}

