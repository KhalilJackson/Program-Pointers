/**
 * Write tests for your command parsing library here.
 * 
 * If you wish to call helper functions from command.c besides
 * command_parse, command_free, and command_print, you must add their
 * headers to command.h first.
 */
#include <stdlib.h>
#include <stdio.h>
#include "command.h"

/*
 * Test command arrays.
 *
 * These are hard-coded command arrays which allow you to test
 * command_print and command_show without having implemented
 * command_parse yet.
 *
 * Adding to these tests requires (1) adding new hardcoded array lines,
 * and (2) adding them to the hardcoded COMMAND_ARRAYS array.
 *
 * Once you are implementing command_parse, put your command line tests
 * (not command array tests) in COMMAND_LINES.
 */
static char* NANO_CMD[] = { "nano", "foo.c", NULL };
static char* NANO_SPACE_CMD[] = {"nano  ", "foo.c	", "broccoli ", NULL};
static char* GCC_CMD[] = { "gcc", "-Wall", "-o", "foo", "foo.c", NULL };
static char* YOUR_CMD[] = { "YOUR", "COMMAND", "ARRAY", "HERE", NULL };
static char* LS_CMD[] = {"ls", "-l" "fcs-labs", NULL};



static char** COMMAND_ARRAYS[] = {
  NANO_CMD,
  NANO_SPACE_CMD,
  GCC_CMD,
  YOUR_CMD,
  LS_CMD
};

/*
 * Test command lines.
 *
 * These are hard-coded strings that will be parsed into command arrays
 * via command_parse.
 *
 * You should add many (many!) more tests to this array to make sure
 * that you are following the full parsing specification!
 */
static char* COMMAND_LINES[] = {
  "Hello world!  Please parse    me.",
  " & this is invalid",
  "YOUR COMMAND LINE HERE",
};


/**
 * Tests the behavior of all library functions on the given command line.
 */
void test_all(char* command) {
  int foreground;
  char** c;
  printf("Parsing: \"%s\"\n", command);
  c = command_parse(command, &foreground);
  if (c) {
    printf("Command type: %s\n", (foreground ? "foreground" : "background"));
    command_show(c);
    printf("As command line: ");
    command_print(c);
    printf("\n");
    command_free(c);
    printf("Freed command array.\n\n");
  } else {
    printf("Invalid command.\n\n");
  }
}

/**
 * Entry function. Tests all the specified command arrays and command lines.
*/
int main(int argc, char** argv) {

  // Test command_show and command_print. At first, you will get no
  // output from these (since they aren't implemented).

  // C note - we can compute the length of the array here only because it
  // is statically declared (this wouldn't work with a regular pointer).
  int num_command_arrays = sizeof(COMMAND_ARRAYS) / sizeof(char**);
  printf("Testing command_show and command_print...\n\n");
  for (int i = 0; i < num_command_arrays; i++) {
    printf("Command array %d: command_show on next line:\n", i);
    command_show(COMMAND_ARRAYS[i]);
    printf("Command array %d: command_print on next line:\n", i);
    command_print(COMMAND_ARRAYS[i]);
    printf("\n");
  }

  // Test command_parse. At first, everything will be flagged as
  // an invalid command (since command_parse always returns NULL).

  int num_command_lines = sizeof(COMMAND_LINES) / sizeof(char*);
  printf("Testing command_parse...\n\n");
  for (int i = 0; i < num_command_lines; i++) {
    test_all(COMMAND_LINES[i]);
  }
  
  printf("All tests finished.\n");
  // by convention, returning 0 from mains means success,
  // while returning nonzero means an error occurred.
  return 0;
}

