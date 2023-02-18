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

  return NULL;
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

  // IMPLEMENT ME
  //char** p = command; 

for (char** p = command; *p != NULL; p++) {
	char* str = *p;  
	for (char* p2 = str; *p2 != '\0'; p2++) {
		if (*p2 == ' '){
			*p2 = '_';
		}
	}
	printf(str);
	printf("\n"); 
    }
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

  // IMPLEMENT ME

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

