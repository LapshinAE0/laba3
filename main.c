#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define INITIAL_SIZE 1024

char* read_text() {

    char* text = (char*)malloc(INITIAL_SIZE * sizeof(char));
	if (!text){
	        perror("error\n");
	        return NULL;
	}
	
    char c;
    int size = INITIAL_SIZE;
    int len = 0;

    while ((c = getchar()) != '!') {

        if (len >= size - 2) {
            size += INITIAL_SIZE;
            text = (char*)realloc(text, size * sizeof(char));
            if (!text){
            	perror("error\n");
                return NULL;
            }
     	}
        text[len++] = c;
	}
    text[len] = '\0';
    return text;
}


int check_capital_letters(const char* sentence){
	int uppercase_count = 0;
	for(int i = 0; sentence[i]; i++){
		if (isupper(sentence[i])){
			uppercase_count++;
		}
	}
	if(uppercase_count > 1){
		return 0;
	}else{
		return 1;
	}                                                      
}

void processed_text(char* text){
	int initial_count = 0;
    int formatted_count = 0;
    char* sentence = text;
    char* end = text;

    while (*end != '\0') {
    	
	    while (*end != '.' && *end != ';' && *end != '?' && *end != '\0') {
	        end++;
	    }

	    char delimiter = *end;
	    *end = '\0';

	    if (strcmp(sentence, " Dragon flew away") == 0) {
	    	printf("Dragon flew away!\n");
	    	break;
	    }

		
	    initial_count++;
		
		
	    while (*sentence == ' ' || *sentence == '\t' || *sentence =='\n') {
	        sentence++;
	    }

	    if (check_capital_letters(sentence)){
	        printf("%s%c\n", sentence, delimiter);
	        formatted_count++;
	    }
		
        *end = delimiter;
        end++;
        sentence = end;
    }

    printf("Количество предложений до %d и количество предложений после %d\n", initial_count, formatted_count);
}

int main() {
	    char* text = read_text();
	    if (text) {
	        processed_text(text);
	        free(text);
	    }
	    return 0;
	}
