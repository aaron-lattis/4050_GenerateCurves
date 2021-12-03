
#include "Point.h"
#include <math.h>
#include <iostream>


Point::Point(double X, double Y, double Z, double XT, double YT, double ZT)
{
    x = X;
    y = Y;
    z = Z;

    xT = XT;
    yT = YT;
    zT = ZT;
}

Point::Point()
{

}

Point::~Point()
{

}

void Point::set_x(double X)
{
    x = X;
}

void Point::set_y(double Y)
{
    y = Y;
}

void Point::set_z(double Z)
{
    z = Z;
}

void Point::set_xt(double XT)
{
    xT = XT;
}

void Point::set_yt(double YT)
{
    yT = YT;
}

void Point::set_zt(double ZT)
{
    zT = ZT;
}

double Point::get_x()
{
    return x;
}

double Point::get_y()
{
    return y;
}

double Point::get_z()
{
    return z;
}

double Point::get_xt()
{
    return xT;
}

double Point::get_yt()
{
    return yT;
}

double Point::get_zt()
{
    return zT;
}
  
   

  

