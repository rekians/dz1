#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>

using namespace std;

struct Point {
public:
    //координаты х и у
    double x, y;

    //дефолтный конструктор 
    Point() {}

    //конструктор с объявлением
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

//метод для создания точек, чтобы можно было вводить точки с консоли
Point createPoint() {
    double x, y;
    cin >> x >> y;

    return Point(x, y);
}

//аббревиатура
typedef vector<Point> vPt;


//класс, представляющий из себя треугольники
class Triangle {
private:
    //вершины треугольника инкапсулированны и недоступны снаружи
    vPt verts;

public:
    //конструктор для ввода с клавиатуры
    Triangle() {
        setVerts();
    }

    //конструктор для ручного ввода точек
    Triangle(Point p1, Point p2, Point p3) {
        verts.push_back(p1);
        verts.push_back(p2);
        verts.push_back(p3);
    }

    //установка точек с клавиатуры через функцию set verts
    void setVerts() {
        //на случай обновления точек очищаем вершины
        verts.clear();

        verts.push_back(createPoint());
        verts.push_back(createPoint());
        verts.push_back(createPoint());
    }

    //функция чтобы получить точки
    vPt getVerts() {
        return verts;
    }

    //функция чтобы найти площадь
    double area() {
        return 0.5 * abs((verts[1].x - verts[0].x) * (verts[2].y - verts[0].y) - (verts[2].x - verts[0].x) * (verts[1].y - verts[0].y));
    }
};



//функция проверки пересечения отрезков треугольников
pair<bool, Point> segmentIntersection(Point a, Point b, Point c, Point d) {
    //результат пересечения
    bool result = false;
    //точка пересечения
    Point intersectionPoint;

    //векторная алгебра
    //ищем два вектора которые указывают на одну и ту же точку пересечения из точек А и C
    //числители
    double num1 = (d.x - c.x) * (c.y - a.y) - (d.y - c.y) * (c.x - a.x);
    double num2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    //знаменатель
    double denum = (d.x - c.x) * (b.y - a.y) - (d.y - c.y) * (b.x - a.x);

    //если знаменатель равен нулю, то отрезки параллельны и не точно не пересекаются
    if (denum != 0) {
        double alpha = num1 / denum;
        double beta = num2 / denum;
        //отрезки пересекаются если коэффициенты 
        if (alpha <= 1 && alpha > 0 && beta <= 1 && beta > 0) {
            result = true;
            intersectionPoint.x = a.x + alpha * (b.x - a.x);
            intersectionPoint.y = a.y + alpha * (b.y - a.y);
        }
    }

    return make_pair(result, intersectionPoint);
}


//функция чтобы проверить, находится ли точка внутри треугольника
bool pointIsInside(Point p, Triangle t) {
    //суть в том, что из точки проводится луч вправо и надо понять, сколько раз он пересекает треугольник
    bool res = false;

    //получаем вершины треугольника
    vPt verts = t.getVerts();

    //перебираем все стороны, проверяя количество пересечений. если их чётное количество, то точка снаружи, если нечётное, то внутри
    for (int i = 0; i <= 2; i++) {
        Point l1 = verts[i];
        Point l2;

        //чтобы не было ошибок индекса
        if (i == 2) {
            l2 = verts[0];
        }
        else {
            l2 = verts[i + 1];
        }

        //если отрезок параллелен оси Y, то он, очевидно, не учитывается
        if (l1.y == l2.y) continue;

        //проверяем пересечение луча с отрезком через подобие треугольников
        bool conditionY = (p.y < l1.y) != (p.y < l2.y);
        bool conditionX = p.x < (l1.x + ((p.y - l1.y) / (l2.y - l1.y)) * (l2.x - l1.x));
        if (conditionX && conditionY) {
            res = !res;
        }
    }

    return res;
}

//ищем точки пересечения треугольников и точки внутри
vPt findIntersectionPoints(Triangle& trg1, Triangle& trg2) {
    //вектор, который хранит в себе точки многоугольника, который образуется в результате пересечения
    vPt intersectionPolygon;
    //лямбда-функция, чтобы вставлялось без повторений
    auto uniqueInsert = [&intersectionPolygon](Point p) {
        bool flag = false;
        //проверяем, есть ли такая точка в векторе
        for (Point i : intersectionPolygon) {
            if ((i.x == p.x) && (i.y == p.y)) {
                check = true;
                break;
            }
        }
        //если нет, то вставляем
        if (!flag) intersectionPolygon.push_back(p);
        };

  

    //берём вершины этих треугольников
    vPt verts1 = trg1.getVerts();
    vPt verts2 = trg2.getVerts();

    //добавляем точки, которые находятся внутри какого-либо треугольника, перебирая все точки
    for (Point i : verts1) {
        if (pointIsInside(i, trg2)) {
            uniqueInsert(i);
        }
    }

    for (Point i : verts2) {
        if (pointIsInside(i, trg1)) {
            uniqueInsert(i);
        }
    }

    //ищем точки точки пересечения
    //i - для вершин первого треугольника
    for (int i = 0; i <= 2; i++) {
        //берём две точки, образующих сторону
        Point a1 = verts1[i];
        Point a2;
        //чтобы не было ошибок индекса
        if (i == 2) {
            a2 = verts1[0];
        }
        else {
            a2 = verts1[i + 1];
        }
        //j - для вершин второго треугольника
        for (int j = 0; j <= 2; j++) {
            //берём две точки, образующих сторону
            Point b1 = verts2[j];
            Point b2;
            //чтобы не было ошибок индекса
            if (j == 2) {
                b2 = verts2[0];
            }
            else {
                b2 = verts2[i + 1];
            }
            //проверяем пересечение этих сторон
            pair<bool, Point> res = segmentIntersection(a1, a2, b1, b2);
            //если пересекаются, то вставляем в вектор, хранящий точки пересечения
            if (res.first == true) {
                uniqueInsert(res.second);
            }
        }
    }

    //возвращаем точки пересечения
    return intersectionPolygon;
}

//ищем площадь получившегося многоугольника
double polygonArea(vPt polygon) {
    int size = polygon.size();
    if (size <= 2) return 0;
    //анонимный объект
    if (size == 3) return Triangle(polygon[0], polygon[1], polygon[2]).area();
    //сортировка точек по часовой стрелке

    //ищем центральную точку как среднее арифметичексое соотв. координат
    Point center(0, 0);
    for (Point i : polygon) {
        center.x += i.x;
        center.y += i.y;
    }
    center.x /= size;
    center.y /= size;

    //функция из <alghorithm> с кастомной лямбда-функцией сравнения положения точек относительно центра(по углу)
    sort(polygon.begin(), polygon.end(), [&center](Point& a, Point& b) {
        return atan2(a.x - center.x, a.y - center.y) < atan2(b.x - center.x, b.y - center.y);
        });


    //
    //триангуляция
    double area = 0;
    //пока не остался треугольник, берём треугольник из первых 3 вершин и убираем первую
    while (polygon.size() > 3) {
        area += Triangle(polygon[0], polygon[1], polygon[2]).area();
        polygon.erase(polygon.begin());
    }
    //прибавляем оставшийся кусок
    area += Triangle(polygon[0], polygon[1], polygon[2]).area();

    return area;
}

int main() {
    Triangle trg1;
    Triangle trg2;

    //просто выводим площадь многоугольника(точки пересечения(треугольник 1, треугольник 2)). считывание из консоли автоматически сделает функция createpoint() 
    //внутри функции setVerts() класса Triangle
    cout << polygonArea(findIntersectionPoints(trg1, trg2));

}