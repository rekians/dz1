#include <iostream>
#include <time.h>

template <typename T>

// сортировка методом Bubble Sort
void bubbleSort(T arr[], int size_arr)
{
	// прохождение по всему массиву
	for (int i = 0; i < size_arr; i++)
	{
		for (int j = 0; j < size_arr - 1; j++)
		{
			// сравнение между собой пар соседних ячеек - если при сравнении оказывается, что значение ячейки j больше, чем значение ячейки j + 1, то мы меняем значения этих ячеек местами
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j]; // создание дополнительной переменной 
				// при помощи доп. переменной меняем значения ячеек местами так, что меньшее значение встает на ячейку j, большее - на ячейку j+1
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	// вывод отсортированного массива
	std::cout << "Отсортированный массив методом BubbleSort: ";
	for (int i = 0; i < size_arr; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>

// сортировка методом Selection Sort
void selectionSort(T arr[], int size_arr)
{
	// создание дополнительных переменных: pos_min - номер ячейки, в которой находится минимальный элемент, temp - для перестановки значений местами
	int pos_min, temp;
	// сортировка сначала выполняется с начального массива и обходит его весь
	for (int i = 0; i < size_arr - 1; i++)
	{
		pos_min = i; // устанавливаем pos_min на текущий индекс массива

		// переменная 'j' проходит через массив в поисках значения, меньшего, чем 'min'.
		for (int j = i + 1; j < size_arr; j++) // если бы индекс 'j' начинался с индекса 'i', то 'min' сравнивался бы с самим собой, очевидно, в этом нет необходимости
		{
			if (arr[j] < arr[pos_min]) // если такое значение найдено, индекс меняется
				pos_min = j;
		}
		// если pos_min больше не равно i, продолжаем искать меньшее значение, поэтому производим перестановку значений местами
		if (pos_min != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
		// текущий индекс i увеличивается, теперь до 1 и т.д., алгоритм повторяется
	}
	// вывод отсортированного массива
	std::cout << "Отсортированный массив методом SelectionSort: ";
	for (int i = 0; i < size_arr; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>

// сортировка методом Insertion Sort
void insertionSort(T arr[], int size_arr) {
	// предполагаем, что первый элемент массива уже отсортирован
	for (int step = 1; step < size_arr; step++) {
		int key = arr[step]; // возьмем следующий элемент массива и будем хранить его отдельно внутри key
		int j = step - 1;

		while (key < arr[j] && j >= 0) { // сравнение key c предыдущим элементом массива - если предыдущий больше, чем key, то key помещается перед предыдущим элементом
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
		// для каждого "прохода" сравниваем текущий элемент со всеми предыдущими и перемещаем их влево, в нужное положение
	}
	// вывод отсортированного массива
	std::cout << "Отсортированный массив методом InsertionSort: ";
	for (int i = 0; i < size_arr; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	// ввод переменной size_arr (размерность массива) с клавиатуры
	int size_arr;
	std::cout << "Введите размерность массива: ";
	std::cin >> size_arr;
	std::cout << std::endl;

	// создание массива (использую динамический массив, т.к. размерность вводится с клавиатуры)
	int* arr = new int[size_arr];

	// заполнение массива случайными числами в диапазоне от 0 до 999 включительно
	srand(time(NULL)); // функция, инициализирующая "генератор" случайных чисел - при каждом запуске time возвращает разные числа
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size_arr; i++)
	{
		arr[i] = rand() % 1000;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// вызов функций сортировки - Bubble Sort, Selection Sort, Insertion Sort
	bubbleSort(arr, size_arr);
	selectionSort(arr, size_arr);
	insertionSort(arr, size_arr);

	// удаление массива для освобождения памяти
	delete[]arr;
	return 0;
}