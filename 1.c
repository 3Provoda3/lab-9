#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Функція для міняння місцями першої і останньої літери слова
void swapFirstAndLastLetter(char* word) {
    int length = strlen(word);
    if (length <= 1) {
        return; // Якщо слово складається з однієї літери, немає потреби у заміні
    }
  
    char temp = word[0];
    word[0] = word[length - 1];
    word[length - 1] = temp;
}

// Функція для видалення слів, що починаються з малої літери
void removeLowerCaseWords(char* sentence) {
    const char* delimiter = " ";
    char* word = strtok(sentence, delimiter);
    char* previous = NULL;

    while (word != NULL) {
        if (!islower(word[0])) {
            if (previous != NULL) {
                printf(" ");
            }
            printf("%s", word);
            previous = word;
        }
        word = strtok(NULL, delimiter);
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("Введіть речення: ");
    fgets(input, sizeof(input), stdin);

    // Видалення символу нового рядка з введення
    input[strcspn(input, "\n")] = '\0';

    // а) Міняємо місцями першу і останню літери кожного слова
    char* sentence = strdup(input); // Створюємо копію речення
    char* word = strtok(sentence, " ");
    char* modifiedSentence = malloc(MAX_LENGTH);

    while (word != NULL) {
        swapFirstAndLastLetter(word);
        strcat(modifiedSentence, word);
        strcat(modifiedSentence, " ");
        word = strtok(NULL, " ");
    }

    printf("Результат (а): %s\n", modifiedSentence);
  
    // б) Видаляємо всі слова, що починаються з малої літери
    printf("Результат (б): ");
    removeLowerCaseWords(input);
    printf("\n");

    free(sentence);
    free(modifiedSentence);

    return 0;
}
