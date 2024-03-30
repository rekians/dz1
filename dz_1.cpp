
#include <iostream>
#include <cmath> // Для функции sqrt() и pow(), чтобы вычислить гипотенузу.
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
int sumOfdigits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    //1 Вычислить площадь трапеции с основаниями b1 и b2 и высотой h.
    float b1, b2, h;
    std::cout << "Введите длины оснований и высоту: ";
    std::cin >> b1 >> b2;
    std::cin >> h;
    std::cout << ((b2 + b1) / 2) * h << endl;

    //2 Вычислить длину окружности и площадь круга радиуса г.
   float r;
    float pi = 3.14;
    std::cout << "Введите радиус: ";
    std::cin >> r;
    std::cout << "Длина окружности: " << 2 * pi * r << "Площадь круга: " << pi * r * r << endl;

    //3 Вычислить площадь прямоугольного треугольника и гипотенузу.
    float a, b;
    std::cout << "Введите катеты: ";
    std::cin >> a >> b;
    std::cout << "Площадь: " << (a * b) / 2 << std::endl << "Гипотенуза: " << sqrt(a * a + b * b);

    //4 Дано десятичное четырехзначное число. Найти сумму его цифр
    int n, digit, sum = 0;
    cout << "Введите десятичное четырехзначное число: ";
    cin >> n;
    while (n > 0) {
        digit = n % 10;
        sum += digit;
        n /= 10;
    }
    cout << "Сумма цифр: " << sum << endl; 

    // Задача 5: Выполнить переход от декартовых координат к полярным.
    double x, y, phi;
    cout << "\nВведите декартовы координаты X и Y для перевода в полярные:";
    cout << "\nX: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    r = hypot(x, y); // вычисление радиус-вектора
    phi = atan2(y, x); // вычисление угла в радианах
    cout << "Полярные координаты (R, φ): "
        << "(" << r << ", " << phi << ")" << endl; 

    //6 Выполнить переход от полярных координат к декартовым.

    double radius, angle;

    cout << "\nВведите полярные координаты R и φ (угол в радианах) для перевода в декартовые:"
        << "\nR: ";
    cin >> radius;

    cout << "φ (в радианах): ";
    cin >> angle;

    
    x = radius * cos(angle);
    y = radius * sin(angle);

    cout << "Декартовы координаты (X,Y): "
        << "(" << x << ", " << y << ")" << endl; 

    //7  Найти корни квадратного уравнения.

    double a3, b3, c3; // Коэффициенты квадратного уравнения.

    cout << "\nВведите коэффициенты квадратного уравнения a, b и c:";
    cout << "\na3: ";
    cin >> a3;

    cout << "b3: ";
    cin >> b3;

    cout << "c3: ";
    cin >> c3;

    double d = b3 * b3 - 4 * a3 * c3; // Вычисление дискриминанта.

    if (d > 0) {
        double root1 = (-b3 + sqrt(d)) / (2 * a3);
        double root2 = (-b3 - sqrt(d)) / (2 * a3);
        cout << "Уравнение имеет два действительных корня: " << root1 << " и " << root2 << endl;
    }
    else if (d == 0) {
        double root = -b3 / (2 * a3);
        cout << "Уравнение имеет один действительный корень: " << root << endl;
    }
    else {
        cout << "Корни уравнения являются комплексными числами и не могут быть найдены в рамках данной задачи." << endl;
    }


    //8 Имеется треугольник со сторонами а, b, с. Найти медианы треугольника, сторонами которого являются медианы исходного треугольника

    double sideA, sideB, sideC; // Стороны исходного треугольника.

    cout << "\nВведите стороны треугольника а, b и с:"
        << "\na: ";
    cin >> sideA;

    cout << "b: ";
    cin >> sideB;

    cout << "c: ";
    cin >> sideC;

    double ma = 0.5 * sqrt(2 * sideB * sideB + 2 * sideC * sideC - sideA * sideA); // Медиана к стороне а.
    double mb = 0.5 * sqrt(2 * sideA * sideA + 2 * sideC * sideC - sideB * sideB); // Медиана к стороне b.
    double mc = 0.5 * sqrt(2 * sideA * sideA + 2 * sideB * sideB - sideC * sideC); // Медиана к стороне с.

    cout << "Медианы нового трегульника составленные из медиан первичного:"
        << "\nm(a): " << ma
        << "\nm(b): " << mb
        << "\nm(c): " << mc
        << endl; 

    //9 Идет k-я секунда суток. Определить, сколько целых часов и целых минут прошло с начала суток.
int k = 0;
cout << "Введите секунду:" << std::endl;
cin >> k;
cout << "Количество целых минут:" << k / 60 << std::endl;
cout << "Количество целых часов:" << k / 3600 << std::endl;

//10  Определить, является ли треугольник со сторонами a, b, c равнобедренным.
float a5, b5, c;
cout << "введите стороны треугольника: ";
cin >> a5 >> b5 >> c;
if ((a5 < (b5 + c)) && (b5 < (a5 + c)) && (c < (a5 + b5))) {
    if (a5 == b5 || b5 == c || a5 == c)
        cout << "треугольник равнобедренный";
    else
        cout << "треугольник не равнобедренный";
}
else
cout << "это не треугольник, попробуй ещё раз";

//11 Вычислить стоимость покупки с учётом скидки. Скидка в 10% предоставляется, если сумма покупки превышает 1000 рублей.

float check = 0;
cout << "введите сумму чека:" << std::endl;
cin >> check;
if (check > 1000) {
    std::cout << "стоимость покупки составит:" << check * 0.9 << endl;
}
else {
    cout << "стоимость покупки составит:" << check << endl;
} 

//12 Дать рекомендации пользователю с известным ростом и весом похудеть или поправиться, если идеальный вес определяется формулой (рост - 100 = идеальный вес).

int height = 0;
int weight = 0;

cout << "введите рост" << std::endl;
cin >> height;
cout << "введите вес" << std::endl;
cin >> weight;

if (height - 100 == weight) {
    cout << "у вас идеальный вес!" << std::endl;
}
if (height - 100 < weight) {
    cout << "вам надо набрать " << -(height - 100 - weight) << " килограмм" << endl;
}
if (height - 100 > weight) {
    cout << "вам надо скинуть " << height - weight - 100 << " килограмм" << endl;
} 

//13  Программа генерирует два случайных числа в диапазоне от 1 до 9. Тестируемый вводит результат произведения этих чисел. Программа сообщает тестируемому ошибся он или нет.
srand(time(0)); // Инициализация генератора случайных чисел.

int number1 = rand() % 9 + 1; // Случайное число от 1 до 9
int number2 = rand() % 9 + 1; // Случайное число от 1 до 9

cout << "Сколько будет " << number1 << " * " << number2 << "? ";

int answer;
cin >> answer;

if (answer == number1 * number2) {
    cout << "Правильно!" << endl;
}
else {
    cout << "Неправильно. Правильный ответ: " << number1 * number2 << "." << endl;
} 

//14  Написать программу вычисления стоимости переговоров, если по субботам и воскресеньям предоставляется скидка 20%. Ввести продолжительность разговора и день недели(число от 1 до 7).
int length = 0;
int day = 0;
float cost = 0;
int sum1 = 0;

cout << "введите длительность переговоров" << endl;
cin >> length;

cout << "введите день начала переговоров" << endl;
cin >> day;

cout << "введите стоимость дня переговоров" << endl;
cin >> cost;

while (length > 0) {
    if (day == 6 or day == 7) {
        sum += cost * 0.8;
    }
    else {
        sum += cost;
    }
    length -= 1;
    if (day == 7) {
        day = 1;
    }
    else {
        day += 1;
    }
}
cout << "Итого выйдет в: " << sum << endl; 

//15  Ввести с клавиатуры номер месяца. Выдать сообщение о названии месяца и времени года

int number_month;
cout << "Введите номер месяца: ";
cin >> number_month;
if (number_month >= 1 && number_month <= 12) {
    switch (number_month)
    {
    case 1:
        cout << "Месяц: январь" << '\n' << "Время года: зима";
        break;
    case 2:
        cout << "Месяц: февраль" << '\n' << "Время года: зима";
        break;
    case 3:
        cout << "Месяц: март" << '\n' << "Время года: весна";
        break;
    case 4:
        cout << "Месяц: апрель" << '\n' << "Время года: весна";
        break;
    case 5:
        cout << "Месяц: май" << '\n' << "Время года: весна";
        break;
    case 6:
        cout << "Месяц: июнь" << '\n' << "Время года: лето";
        break;
    case 7:
        cout << "Месяц: июль" << '\n' << "Время года: лето";
        break;
    case 8:
        cout << "Месяц: август" << '\n' << "Время года: лето";
        break;
    case 9:
        cout << "Месяц: сентябрь" << '\n' << "Время года: осень";
        break;
    case 10:
        cout << "Месяц: октябрь" << '\n' << "Время года: осень";
        break;
    case 11:
        cout << "Месяц: ноябрь" << '\n' << "Время года: осень";
        break;
    case 12:
        cout << "Месяц: декабрь" << '\n' << "Время года: осень";
        break;
    }
}
else
cout << "Нет такого месяца" << endl; 

//16 Определить, является ли шестизначное число "счастливым"
int n2;
    std::cout << "Введите шестизначное число: ";
    std::cin >> n2;
    int left_side = n2 / 1000;
    int right_side = n2 % 1000;
    if (sumOfdigits(left_side) == sumOfdigits(right_side))
        std::cout << "Поздравляю! Это счастливое число!";
    else
        std::cout << "ОУ! Это не счастливое число."; 
//18 Дано натуральное четырехзначное число. Выяснить, является ли оно палиндромом.
int chislo = 0;
int firstlet = 0;
int secondlet = 0;
int thirdlet = 0;
int fourthlet = 0;

std:cout << "Введите натуральное четырехзначное число" << std::endl;
std::cin >> chislo;

fourthlet = chislo % 10;
thirdlet = chislo / 10 % 10;
secondlet = chislo / 100 % 10;
firstlet = chislo / 1000;

if (firstlet == fourthlet and secondlet == thirdlet) {
    std::cout << "Это палиндром!" << std::endl;
}
else {
    std::cout << "Это не палиндром!" << std::endl;
} 

//19 Дано трёхзначное число. Определить: 19.1 является ли произведение его цифр больше числа b 19.2 кратна ли 7 сумма его цифр.
int chislo1 = 0;
 int firstlet1 = 0;
int secondlet1 = 0;
int thirdlet1 = 0;
int b7 = 0;

std::cout << "Введите натуральное трехзначное число" << std::endl;
std::cin >> chislo1;

thirdlet1 = chislo1 % 10;
secondlet1 = chislo1 / 10 % 10;
firstlet1 = chislo1 / 100;

std::cout << "введите b" << std::endl;
std::cin >> b;

if (firstlet1 * secondlet1 * thirdlet1 > b7) {
    std::cout << "19.1 Да, больше b" << std::endl;
}
else {
    std::cout << "19.1 Нет, меньше b" << std::endl;
}

if (firstlet1 + secondlet1 + thirdlet1 % 7 == 0) {
    std::cout << "19.2 Да, кратна семи" << std::endl;
}
else {
    std::cout << "19.2 Нет, не кратна семи" << std::endl;
} 

//20 Даны вещественные положительные числа a, b, c, d. Выяснить, можно ли прямоугольник со сторонами a, b поместить в прямоугольник со сторонами c, d так,
//   чтобы стороны одного прямоугольника были параллельны сторонам другого.

int a8 = 0;
int b8 = 0;
int c8 = 0;
int d8 = 0;

std::cout << "Введите стороны прямоугольников через пробел" << std::endl;
std::cin >> a8 >> b8 >> c8 >> d8;

if ((a8 < c8 and b8 < d8) or (a8 < d8 and b8 < c8)) {
    std::cout << "можно" << std::endl;
}
else {
    std::cout << "нельзя" << std::endl;
} 

//21 
std::cout << "char: " << sizeof(char) << " байт" << std::endl;
std::cout << "int: " << sizeof(int) << " байта" << std::endl;
std::cout << "short int: " << sizeof(short int) << " байта" << std::endl;
std::cout << "long int: " << sizeof(long int) << " байтов" << std::endl;
std::cout << "float: " << sizeof(float) << " байта" << std::endl;
std::cout << "double:" << sizeof(double) << "байтов" << std::endl;
std::cout << "bool:" << sizeof(bool) << "байт" << std::endl;


    return 0;
}
