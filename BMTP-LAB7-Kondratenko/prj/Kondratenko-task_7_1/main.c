#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

int count_syllables(const char *str) {
    setlocale(LC_ALL, "");
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'к' && str[i + 1] == 'у') {
            count++;
        }
    }
    return count;
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    // Встановлюємо Windows-кодування CP1251 (для української мови)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char input[100];

    printf("Введіть слово, що закінчується '/', '%%' або '$': ");
    scanf("%99s", input);

    int len = strlen(input);
    char last_char = input[len - 1];

    if (last_char == '/' || last_char == '%' || last_char == '$') {
        input[len - 1] = '\0';  // Видаляємо останній символ

        int count = count_syllables(input);

        if (count > 0) {
            printf("Кількість складів 'ку': %d\n", count);
        } else {
            reverse_string(input);
            printf("Рядок у зворотному порядку: %s\n", input);
        }
    } else {
        printf("Некоректний ввід! Слово повинно закінчуватися '/', '%%' або '$'.\n");
    }

    return 0;
}
