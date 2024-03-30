#include <iostream>
#include <random>


using namespace std;

random_device dev;
mt19937 gen(dev());
int getRandomInt(int min = 0, int max = 100) {
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}


int add(int& a, int& b) {
    return a + b;
}

int subtract(int& a, int& b) {
    return a - b;
}

int multiply(int& a, int& b) {
    return a * b;
}

int divide(int& a, int& b) {
    return a / b;
}

int** create_2d_array(int lines, int columns) {
    int** p = new int* [lines];
    for (int i = 0; i < lines; i++) {
        p[i] = new int[columns];
    }
    return p;
}

void fill_2d_array(int** p, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int jakob = 0; jakob < columns; jakob++) {
            p[i][jakob] = getRandomInt();
        }
    }
}

void print_2d_array(int** p, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int jakob = 0; jakob < columns; jakob++) {
            cout << p[i][jakob] << " ";
        }
        cout << endl;
    }
}

void delete_2d_array(int** p, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        delete[] p[i];
    }
    delete[] p;
}

int main() {
    setlocale(LC_ALL, "Russian");
    //1.1
    const float par_1 = 10;
    const float* const p_1 = &par_1;

    //1.2 
    long* p2;

    //1.3
    double* p3;

    //1.4
    const short par_4 = 10;
    const short* p_4;

    //1.5
    const float par_5 = 10;
    const float* const p_5 = &par_5;

    //1.6
    const char par_6 = '6';
    const char* p_6 = &par_6;

    //1.7
    double par_7 = 7;
    double* const p7 = &par_7;

    //1.8
    unsigned par_8 = 8;
    unsigned* const p8 = &par_8;



    //2
    char input;
    int size;
    //pointer to arr
    double* cluqki2 = nullptr;
    while (true) {
        cout << "0 - создать новый массив; 1 - выйти;" << endl;
        cin >> input;
        if (input == '0') {
            //ввод
            cout << "Введите размер массива" << endl;
            cin >> size;
            //memory allocation
            cluqki2 = new double[size];

            //fill arr
            for (int i = 0; i < size; i++) {
                cluqki2[i] = getRandomInt();
            }

            //print
            for (int i = 0; i < size; i++) {
                cout << cluqki2[i] << " ";
            }

            //clear memory
            delete[] cluqki2;
            cout << endl;

        }
        else if (input == '1') {
            break;
        }
        else {

        }
    }
    cout << endl;



    //3
    int* cluqki3 = new int[12];
    cout << "Начальный массив: " << endl;
    for (int i = 0; i < 12; i++) {
        cluqki3[i] = getRandomInt();
        cout << cluqki3[i] << " ";
    }
    cout << endl;
    cout << "Итог: " << endl;
    for (int i = 0; i < 12; i += 2) {
        int temp = cluqki3[i];
        cluqki3[i] = cluqki3[i + 1];
        cluqki3[i + 1] = temp;
        cout << cluqki3[i] << " " << cluqki3[i + 1] << " ";
    }
    delete[] cluqki3;
    cout << endl;
    cout << endl;


    //4
    int** p = nullptr;
    int lines;
    int columns;
    cout << "строки: " << endl;
    cin >> lines;
    cout << "столбцы: " << endl;
    cin >> columns;
    cout << endl;
    p = create_2d_array(lines, columns);
    fill_2d_array(p, lines, columns);
    print_2d_array(p, lines, columns);
    delete_2d_array(p, lines, columns);
    cout << endl;



    //5
    char os = ' ';
    int a;
    int b;
    int (*op)(int& a, int& b);
    while (os != '0') {
        cout << "a: " << endl;
        cin >> a;
        cout << "b: " << endl;
        cin >> b;
        cout << "операция: " << endl;
        cin >> os;
        switch (os) {
            case '+':
                op = add;
                break;
            case '-':
                op = subtract;
                break;
            case '*':
                op = multiply;
                break;
            case '/':
                op = divide;
                break;
            default:
                op = nullptr;
                break;
        }

        if (os != '0') {
            cout << op(a, b) << endl;
        }
    }

    cout << endl;




    return 0;
}