#include <iostream>
#include <locale.h>
using namespace std;

int **common_array (int m, int n) { //Ввод двумерного массива
    
    int **p = new int* [m]; //Указатель на начало массива
    for (int i=0; i<m; i++) { 
        p [i] = new int [n]; //Для каждой строчки m выделяем память для n-элементов (n-кол-во стобцов)
    }
    for (int i=0; i<m; i++) { //Заполняем массив (сначала по строчкам, потом по столбцам)
        for (int j=0; j<n; j++) {
            cout << "Введите элемент в " <<i << " строке и в " << j << " столбце: ";
            cin >> p[i][j];
        }
    }
    return p; //Возвращаем ссылку на полученный массив
}

int minrow (int **k, int m, int n) { //Находим строку с наим знач элемента
    int num_min = 0; //Строка с наим знач эл
    int array_min = k[0][0]; //Наим эл в массиве
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (k[i][j]< array_min) {
                array_min = k[i][j];
                num_min = i;
                }
            }
        }
    return num_min; //Возвращаем строку с наим знач эл
}
void exchange_new (int **k, int m, int n) { //Меняем первую строку местами со строкой с наим знач эл
    int a = minrow (k, m, n); //Функция поиска строки с наим знач эл
    int *t = k [0]; //Запоминаем указатель на первую строку в старом массиве
    k [0] = k [a];  //Присваиваем указателю первой строки нового массива указатель строки с наим знач эл
    k [a] = t;      //Присваиваем указателю строки с наим знач эл указатель на указатель первой строки в старом массиве
}

int main () {

    setlocale(LC_ALL, "rus");

    int m = 0;
    int n = 0;
    cout << "Введите количество строк в массиве: ";
    cin >> m;
    int **p; 
    cout << "Введите количество столбцов в массиве: ";
    cin >> n; 

    p = common_array (m, n); //Функция создания и заполнения двумерного массива

    exchange_new (p, m, n); //Функция меняет 1-ую строку со строкой с наим знач эл

    cout << "Результат: " << endl;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout << p[i][j] << " ";
            }
        cout << "\n";
        }
    delete[] p;             //Удаляем массив
    return 0;
}
