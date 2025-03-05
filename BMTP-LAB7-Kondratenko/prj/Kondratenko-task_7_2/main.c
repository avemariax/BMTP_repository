#include <stdio.h>
#include <locale.h>

#define SIZE 16  // Розмір масиву

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

    // Ввід масиву
    printf("Введіть %d дійсних чисел:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Елемент %d: ", i + 1);
        scanf("%lf", &numbers[i]);
    }

    // Пошук індексів мінімального та максимального елементів
    find_min_max(numbers, SIZE, &min_index, &max_index);

    // Вивід результату (номери починаються з 1)
    printf("Найменший елемент має номер: %d\n", min_index + 1);
    printf("Найбільший елемент має номер: %d\n", max_index + 1);

    return 0;
}
