
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <math.h>
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

    std::vector<Point> newPoint;

    Point tempPoint;

    chromeball::Vector p0;
    chromeball::Vector p1;
    chromeball::Vector t0;
    chromeball::Vector t1;
    double t;

    chromeball::Vector a;
    chromeball::Vector b;
    chromeball::Vector c;
    chromeball::Vector d;

    chromeball::Vector tempPointAsVector;

    int size = point.size();

    for (int i = 0; i < size - 1; i ++)
    {
        newPoint.push_back(point[i]);

        for (int pointsPerSegment = 0; pointsPerSegment < 30; pointsPerSegment ++)
        {   
            t = pointsPerSegment / 30.0;

            p0 = chromeball::Vector(point[i].get_x(), point[i].get_y(), point[i].get_z());
            p1 = chromeball::Vector(point[i + 1].get_x(), point[i + 1].get_y(), point[i + 1].get_z());

            t0 = chromeball::Vector(point[i].get_xt(), point[i].get_yt(), point[i].get_zt());
            t1 = chromeball::Vector(point[i + 1].get_xt(), point[i + 1].get_yt(), point[i + 1].get_zt());

            a = p0;

            b = t0;

            c = 3 * (p1 - p0) - t1 - 2 * t0;

            d = t1 + t0 - 2 * (p1 - p0);

            tempPointAsVector = a + b * t + c * pow(t, 2) + d * pow(t, 3);

            tempPoint.set_x(tempPointAsVector.getX());
            tempPoint.set_y(tempPointAsVector.getY());
            tempPoint.set_z(tempPointAsVector.getZ());

            newPoint.push_back(tempPoint);
        }
    }

    newPoint.push_back(point[10]);


    std::ofstream myfile;
    myfile.open ("catrom.txt");

    myfile << std::setprecision(15) << std::defaultfloat;

    for (size_t i = 0; i < newPoint.size(); i ++)
    {   
        myfile << newPoint[i].get_x() << " "; 
        myfile << newPoint[i].get_y() << " ";
        myfile << newPoint[i].get_z() << "\n";
    }

    myfile.close();

    return 0;
}
