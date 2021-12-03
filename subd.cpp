
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iomanip>

#include "Vector.h"
#include "Point.h"


int main()
{

    Point point0 = Point(-4.66635532059, -2.76664019908, -42.8339205358, 4.09053209536, 4.64917485271, 4.51460225105);
    Point point1 = Point(-0.995289677896, -2.60784433118, -44.9970454207, -3.5659057115, 1.71137863298, -2.57183829594);
    Point point2 = Point(-0.351475462457, 3.36058532522, -40.7822229235, -1.24994603091, 3.05958732205, -1.57120268413);
    Point point3 = Point(4.66161147923, 3.19920579046, -47.7352059517, -2.98313668222, 1.94751729013, 1.69170601817);
    Point point4 = Point(7.5310958635, -4.74173648552, -40.4538011609, -3.50740933751, 0.671513194154, -4.13090553684);
    Point point5 = Point(4.24473781681, 1.87655757442, -49.9121733511, -3.00393362942, -1.79628242051, 3.51160999256);
    Point point6 = Point(11.3653062808, -3.45799957849, -41.0441463511, -2.1248276945, -3.25443162464, -2.70813805588);
    Point point7 = Point(5.92641505025, -1.21492108245, -46.1102940295, -3.83159158671, -4.79160725905, -2.48523762933);
    Point point8 = Point(13.3221469724, 1.54142129899, -49.7183834507, -3.11562646823, 4.17417490691, -0.766334243044);
    Point point9 = Point(18.0383357784, -2.68134236792, -45.6714062854, -2.25568465354, -1.80910833921, -1.53928698053);
    Point point10 = Point(12.7220355232, 1.87942631928, -47.2636892774, -1.36565874246, 0.400006763075, -1.3850742469);

    std::vector<Point> point; 

    point.push_back(point0);
    point.push_back(point1);
    point.push_back(point2);
    point.push_back(point3);
    point.push_back(point4);
    point.push_back(point5);
    point.push_back(point6);
    point.push_back(point7);
    point.push_back(point8);
    point.push_back(point9);
    point.push_back(point10);


    Point tempPoint;
    Point originalPoint;
    double tempx;
    double tempy;
    double tempz;


    for (int subDivisions = 0; subDivisions < 5; subDivisions ++)
    {
        for (size_t i = 0; i < point.size() - 1; i += 2)
        {   
            tempx = (point[i].get_x() + point[i + 1].get_x()) / 2;
            tempy = (point[i].get_y() + point[i + 1].get_y()) / 2;
            tempz = (point[i].get_z() + point[i + 1].get_z()) / 2;

            tempPoint.set_x(tempx);
            tempPoint.set_y(tempy);
            tempPoint.set_z(tempz);

            point.insert(point.begin() + i + 1, tempPoint);
        }

        originalPoint = point[0];

        for (size_t i = 2; i < point.size() - 1; i += 2)
        {

            tempx = (originalPoint.get_x() + (6 * point[i].get_x()) + point[i + 2].get_x()) / 8;
            tempy = (originalPoint.get_y() + (6 * point[i].get_y()) + point[i + 2].get_y()) / 8;
            tempz = (originalPoint.get_z() + (6 * point[i].get_z()) + point[i + 2].get_z()) / 8;

            tempPoint.set_x(tempx);
            tempPoint.set_y(tempy);
            tempPoint.set_z(tempz);

            originalPoint = point[i];

            point[i] = tempPoint;
        }
    }


    std::ofstream myfile;
    myfile.open ("subd.txt");

    myfile << std::setprecision(15) << std::defaultfloat;

    for (size_t i = 0; i < point.size(); i ++)
    {   
        myfile << point[i].get_x() << " "; 
        myfile << point[i].get_y() << " ";
        myfile << point[i].get_z() << "\n";
    }

    myfile.close();

    return 0;
}
