#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isConsonant(char ch) {
    ch = tolower(ch);
    return (ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u');
}

bool hasDoubleConsonant(const char* word) {
    while (*word != '\0' && *word != '\n') {
        if (isConsonant(*word) && *word == *(word + 1)) {
            return true;
        }
        word++;
    }
    return false;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int totalWords = 0;
    int wordsWithDoubleConsonant = 0;

    char word[100]; // Максимальна довжина слова

    while (fscanf(file, "%s", word) != EOF) {
        totalWords++;
        if (hasDoubleConsonant(word)) {
            wordsWithDoubleConsonant++;
        }
    }

    fclose(file);

    float percentage = ((float)wordsWithDoubleConsonant / totalWords) * 100;
    printf("Percentage of words with a doubled consonant: %.2f%%\n", percentage);

    return 0;
}