#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

int count_syllables(const char *str) {
    setlocale(LC_ALL, "");
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '�' && str[i + 1] == '�') {
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
    // ������������ Windows-��������� CP1251 (��� ��������� ����)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char input[100];

    printf("������ �����, �� ���������� '/', '%%' ��� '$': ");
    scanf("%99s", input);

    int len = strlen(input);
    char last_char = input[len - 1];

    if (last_char == '/' || last_char == '%' || last_char == '$') {
        input[len - 1] = '\0';  // ��������� ������� ������

        int count = count_syllables(input);

        if (count > 0) {
            printf("ʳ������ ������ '��': %d\n", count);
        } else {
            reverse_string(input);
            printf("����� � ���������� �������: %s\n", input);
        }
    } else {
        printf("����������� ���! ����� ������� ������������ '/', '%%' ��� '$'.\n");
    }

    return 0;
}
