#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template<typename T>
void clear_arr(T arr[], int lenght, int key) {
	for (int i = 0; i < lenght; i++)
		if (arr[i] == key)
			arr[i] = 0;
}

template <typename T>
int index_sum(T arr1[], int lenght1, T arr2[], int lenght2, int index) {
	if (index > lenght1 - 1 || index > lenght2 - 1 || index < 0) {
		std::cout << "ERROR \n";
		return 0;
	}
	
	return arr1[index]+arr2[index];
}

void prime_range(int num1, int num2) {
	for (int i = num1; i <= num2; i++) {
		int counter{};
		for (int j = 1; j <= num2; j++) {
			if (i % j == 0)
				counter++;
		}
		if (counter == 2)
			std::cout << i << ", ";
	}
}

void prime_range(int num1) {
	for (int i = 1; i <= num1; i++) {
		int counter{};
		for (int j = 1; j <= num1; j++) {
			if (i % j == 0)
				counter++;
		}
		if (counter == 2)
			std::cout << i << ", ";
	}
}

template <typename T>
int compare_pare(T arr[], const int lenght, int num1, int num2) {
	for (int i = 0; i < lenght; i++)
		if (arr[i] == num1 && arr[i + 1] == num2)
			return i;
	return -1;
}

int main(){
	setlocale(LC_ALL, "Russian");

	int n{}, m{};
	
	std::cout << "Задача №1. \nИзначальный массив:\n";
	const int size1 = 10;
	int arr1[size1];
	fill_arr(arr1, size1, 10, 21);
	print_arr(arr1, size1);
	std::cout << "Введите число из массива, которое необходимо обнулить -> ";
	std::cin >> n;
	clear_arr(arr1, size1, n);
	print_arr(arr1, size1);

	std::cout << "\n\nЗадача №2. \n";
	const int size2 = 10;
	int arr2[size1];
	fill_arr(arr2, size2, 10, 20);
	const int size3 = 15;
	int arr3[size1];
	fill_arr(arr3, size3, 5, 20);
	print_arr(arr2, size2);
	print_arr(arr3, size3);
	int index = index_sum(arr2, size2, arr3, size3, m);
	if (index != 0) {
		std::cout << "Введите индекс, который необходимо проссумировать -> ";
		std::cin >> m;
		std::cout << "Сумма чисел: " << index_sum(arr2, size2, arr3, size3, m) << "\n\n";
	}
	if (index == 0) {
		std::cout << "ERROR";
	}

	std::cout << "\n\nЗадача №3. \n";
	std::cout << "Введите начало и конец диапазона -> ";
	std::cin >> n >> m;
	std::cout << "Простые числа из диапазона:\n";
	prime_range(n, m);
	std::cout << "\nВведите конец диапазона -> ";
	std::cin >> n;
	std::cout << "Простые числа из диапазона:\n";
	prime_range(n);
	std::cout << "\n\n";

	std::cout << "Задача №4. \nИзначальный массив:\n";
	const int size4 = 10;
	int arr4[size4];
	fill_arr(arr4, size4, 0, 20);
	print_arr(arr4, size4);
	int num1{}, num2{};
	std::cout << "Введите первое число -> ";
	std::cin >> num1;
	std::cout << "Введите второе число -> ";
	std::cin >> num2;
	std::cout << "Индекс первого числа из пары " << compare_pare(arr4, size4, num1, num2) << "\n";

	return 0;

}
