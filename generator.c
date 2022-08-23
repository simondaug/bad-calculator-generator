#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function Definitions
void writeToFile(char * str, FILE * fp);
void writeNum(int num, FILE * fp);

// Takes user input and generates a .c file that compiles
// to a working calculator comprised of "if" statements
int main() {
  // Get input from user
  printf("Please enter the highest number you want to support: ");
  int max = 0;
  scanf("%d", &max);
  // Verify valid input
  if (max <= 0) {
    printf("Invalid response\n");
    return 0;
  } // if
  //Create the file
  printf("Generating addition calculator that supports up to %d\n", max);
  printf("Creating file...\n");
  FILE * badcalc = fopen("badcalculator.c", "w");
  //Insert some boilerplate
  printf("Inserting basic logic...\n");
  writeToFile("#include <stdio.h>\n\nint main() {\n  printf(\"Enter the first number to add: \");\n  int a = 0;\n  scanf(\"%d\", &a);\n  printf(\"Enter the second number to add: \");\n  int b = 0;\n  scanf(\"%d\", &b);\n\n", badcalc);
  //Insert if statements
  printf("Making if statements...\n");
  for(int i = 0; i < max; i++) {
    for(int j = 0; j < max; j++) {
      writeToFile("  if (a == ", badcalc);
      writeNum(i+1, badcalc);
      writeToFile(" && b == ", badcalc);
      writeNum(j+1, badcalc);
      writeToFile(") {\n    printf(\"The answer is ", badcalc);
      writeNum(i+j+2, badcalc);
      writeToFile("\\n\");\n  }\n", badcalc);
    } // for
  } // for
  //Finish up and close file
  printf("Writing finishing bits...\n");
  writeToFile("}", badcalc);
  printf("Cleaning up...\n");
  fclose(badcalc);
  printf("Done!\n");
} // main


// Takes in a char array and a file pointer and writes the array to the file
void writeToFile(char * str, FILE * fp) {
  fputs(str, fp);
} // writeToFile

// Takes in an int and a file pointer and writes the int to the file
void writeNum(int num, FILE * fp) {
  int size = sizeof(num);
  char numStr[size];
  sprintf(numStr, "%d", num);
  fputs(numStr, fp);
} // writeNum
