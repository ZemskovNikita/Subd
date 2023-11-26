#include <iostream>
#include <random>
#include <stdexcept>
#include <string>

using namespace std;
/**
 * @brief Функция заполнения массива arr случайными числами от 0 до 100
 * @param arr массив
 * @param size размер массива
 */
void fillRandomNumbers(int* arr, size_t size);

/**
 * @brief Фунция сотировки ...
 * @param arr массив
 * @param size размер массива
 * @return ...
 */
void insertionSort(int* array, const size_t size_);

/**
 * @brief Функция вывода элементов массива в строку
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, size_t size);

/**
 * @brief Функция сложения всех элементов массива
 * @param arr массив
 * @param size размер массива
 * @return Возвращает сумму всех элементов массива
*/
int calculateSum(const int* arr, size_t size);

/**
 * @brief Функция ввода размера массива
 * @return Возвращает размер массива, который должен быть больше или равен 0
 */
size_t getArraySize();

int main() {

    setlocale(LC_ALL, "RUS");
    string message = "Введите размер массива: ";
    size_t size = 0;

    try {
        size = getArraySize();
    }
    catch (out_of_range& e) {
        cerr << e.what() << endl;
        return -1;
    }

    int* arr = new int[size];

    fillRandomNumbers(arr, size);

    cout << "Элементы массива: ";
    printArray(arr, size);
    cout << endl;

    insertionSort(arr, size);

    printArray(arr, size);


    cout << endl << "Сумма массива: " << calculateSum(arr, size);


    if (arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;
    }

    return 0;
}

void fillRandomNumbers(int* arr, size_t size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(0, 100);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = uniformIntDistribution(gen);
    }
}

int calculateSum(const int* arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

void printArray(const int* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << "[" << arr[i] << "] ";
    }
}

size_t getArraySize() {
    int size = -1;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size < 0) {
        throw out_of_range(
            "Неправильный размер. Значение должно быть больше или равно нулю.");
    }

    return static_cast<size_t>(size);
}

void insertionSort(int* array, const size_t size_)
{
    for (size_t i = 1; i < size_; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1])
        {
            swap(array[j], array[j + 1]);
            j--;
        }
    }
}
