
#include "Vector.h"

#ifndef POINT_H
#define POINT_H


class Point
{

    public:

        Point(double X, double Y, double Z, double XT, double YT, double ZT);

        Point();

        ~Point();

        void set_x(double X);

        void set_y(double Y);

        void set_z(double Z);

        void set_xt(double XT);

        void set_yt(double YT);

        void set_zt(double ZT);

        double get_x();

        double get_y();

        double get_z();

        double get_xt();

        double get_yt();

        double get_zt();

    
    private:

        double x;
        double y;
        double z;
        double xT;
        double yT;
        double zT;

    
};

#endif
