#include <string.h>
#include <stdio.h>
int main(void)
{
    char string[] = "A string of tokens and some more tokens";
    char seps[] = " ";
    char* token = NULL;
    char* next_token = NULL;
    printf("Tokens:\n");
// Establish string and get the first token:
    token = strtok_s(string, seps, &next_token);
// While there are tokens in "string"
//    while ((token != NULL) )
//    {
// Get next token:
        printf(" %s\n", token);
        token = strtok_s(NULL, seps, &next_token);
//    }
}