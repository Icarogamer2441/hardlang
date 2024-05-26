#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// made with chatgpt and me (i made the interpreter and chatgpt the file opening system)

#define MAX_SIZE 100000

void interpret(char code[]) {
    int letterapos = 0;
    int letterbpos = 0;
    int lettercpos = 0;
    for(int i = 0; code[i] != '\0'; i++) {
        if(code[i] == 'a') {
            letterapos++;
        } else if(code[i] == 'b') {
            letterbpos++;
        } else if(code[i] == 'c') {
            lettercpos++;
        } else if(code[i] == 's') {
            letterapos--;
        } else if(code[i] == 'n') {
            letterbpos--;
        } else if(code[i] == 'h') {
            lettercpos--;
        } else if(code[i] == 'p') {
            if(letterapos == 2) {
                if(letterbpos == 1) {
                    printf("\n");
                } else if(letterbpos == 3) {
                    printf(" ");
                }
            }
            else if(letterapos == 3) {
                if(letterbpos == 2) {
                    printf("a");
                } else if (lettercpos == 3) {
                    printf("b");
                } else if (letterbpos == 4) {
                    if(lettercpos == 2) {
                        printf("c");
                    }
                }
            }
            else if(letterapos == 5) {
                if(letterbpos == 1) {
                    printf("d");
                } else if(letterbpos == 3) {
                    printf("e");
                } else if(lettercpos == 2) {
                    printf("f");
                }
            }
            else if(letterapos == 7) {
                if(lettercpos == 5) {
                    printf("g");
                } else if(letterbpos == 6) {
                    printf("h");
                } else if(letterbpos == 7) {
                    printf("i");
                } else if(letterbpos == 9) {
                    printf("j");
                } else if(lettercpos == 2) {
                    printf("k");
                }
            }
            else if(letterapos == 6) {
                if(lettercpos == 1) {
                    printf("l");
                } else if(letterbpos == 3) {
                    printf("m");
                } else if(lettercpos == 4) {
                    printf("n");
                } else if(lettercpos == 2) {
                    printf("o");
                } else if(letterbpos == 9) {
                    printf("p");
                } else if(letterbpos == 10) {
                    printf("q");
                } else if(lettercpos == 3) {
                    printf("r");
                }
            }
            else if(letterapos == 8) {
                if(letterbpos == 5) {
                    printf("s");
                } else if(letterbpos == 7) {
                    printf("t");
                } else if(lettercpos == 2) {
                    printf("u");
                } else if(letterbpos == 3) {
                    printf("v");
                } else if(letterbpos == 6) {
                    printf("w");
                } else if(lettercpos == 7) {
                    printf("x");
                } else if(letterbpos == 9) {
                    printf("y");
                } else if(letterbpos == 10) {
                    printf("z");
                }
            }
            else if(letterapos == 9) {
                if(letterbpos == 1) {
                    printf(";");
                } else if(letterbpos == 2) {
                    printf(":");
                } else if(letterbpos == 3) {
                    printf(".");
                } else if(letterbpos == 4) {
                    printf(",");
                } else if(letterbpos == 5) {
                    printf(".");
                } else if(letterbpos == 6) {
                    printf("!");
                } else if(letterbpos == 7) {
                    printf("?");
                } else if(letterbpos == 8) {
                    printf("(");
                } else if(letterbpos == 9) {
                    printf(")");
                } else if(letterbpos == 10) {
                    printf("\"");
                } else if(lettercpos == 2) {
                    printf("'");
                } else if(lettercpos == 3) {
                    printf("ç");
                } else if(lettercpos == 4) {
                    printf("*");
                } else if(lettercpos == 5) {
                    printf("-");
                } else if(lettercpos == 6) {
                    printf("/");
                } else if(lettercpos == 7) {
                    printf("@");
                } else if(lettercpos == 8) {
                    printf("&");
                } else if(lettercpos == 9) {
                    printf("{");
                } else if(lettercpos == 10) {
                    printf("}");
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char content[MAX_SIZE + 1];

    if(argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (strcmp(strrchr(argv[1], '.'), ".hard") != 0) {
        printf("Error: the file extension have to be '.hard'\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error while opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(content, sizeof(content), file) != NULL) {
        interpret(content);
    }

    fclose(file);

    return 0;
}
