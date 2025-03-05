#include <stdio.h>
#include <locale.h>

#define SIZE 16  // ����� ������

void find_min_max(double arr[], int size, int *min_index, int *max_index) {
    *min_index = 0;
    *max_index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[*min_index]) {
            *min_index = i;
        }
        if (arr[i] > arr[*max_index]) {
            *max_index = i;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    double numbers[SIZE];
    int min_index, max_index;

    // ��� ������
    printf("������ %d ������ �����:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("������� %d: ", i + 1);
        scanf("%lf", &numbers[i]);
    }

    // ����� ������� ���������� �� ������������� ��������
    find_min_max(numbers, SIZE, &min_index, &max_index);

    // ���� ���������� (������ ����������� � 1)
    printf("��������� ������� �� �����: %d\n", min_index + 1);
    printf("��������� ������� �� �����: %d\n", max_index + 1);

    return 0;
}
