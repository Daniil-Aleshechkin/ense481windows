#include "util.h"
#include "time_ops.h"

const double ROOT_3 = 1.73205080;
const double SIN_30 = 1.0/2.0;
const double COS_30 = ROOT_3/2.0;
const double PI = 3.14159265358;
const double PI_OVER_6 = PI / 6.0;

double sin_horner(double x) {
		long n = (long)(x/PI_OVER_6);
		
		double shiftedValue = x - n * PI_OVER_6;
    double z = shiftedValue * shiftedValue;
    double sine = ((z/20.0 - 1) * z/6.0+1) * shiftedValue;
    double cosine = ((z/30.0 + 1) * z/12.0-1) * z/2.0 + 1;
	
		n = n % 12;
		
    switch (n) {
        case 0:
            return sine;
        case 1:
            return COS_30 * sine + SIN_30 * cosine;
        case 2:
            return SIN_30 * sine + COS_30 * cosine;
        case 3:
            return cosine;
        case 4:
            return -SIN_30 * sine + COS_30 * cosine;
        case 5:
            return -COS_30*sine + SIN_30*cosine;
        case 6:
            return -sine;
        case 7:
            return -COS_30*sine - SIN_30*cosine;
        case 8:
            return -SIN_30*sine - COS_30*cosine;
        case 9:
            return -cosine;
        case 10:
            return SIN_30*sine - COS_30*cosine;
        case 11:
            return COS_30*sine - SIN_30*cosine;
	}

}

double cos_horner(double x) {
		long n = (long)(x/PI_OVER_6);
		
		double shiftedValue = x - n * PI_OVER_6;
    double z = shiftedValue * shiftedValue;
    double sine = ((z/20.0 - 1) * z/6.0+1) * shiftedValue;
    double cosine = ((z/30.0 + 1) * z/12.0-1) * z/2.0 + 1;
		
		n = n % 12;

    switch (n) {
        case 0:
            return cosine;
        case 1:
            return -SIN_30 * sine + COS_30 * cosine;
        case 2:
            return -COS_30 * sine + SIN_30 * cosine;
        case 3:
            return -sine;
        case 4:
            return -COS_30*sine - SIN_30*cosine;
        case 5:
            return -SIN_30*sine - COS_30*cosine;
        case 6:
            return -cosine;
        case 7:
            return  SIN_30*sine - COS_30*cosine;
        case 8:
            return COS_30*sine - SIN_30*cosine;
        case 9:
            return sine;
        case 10:
            return COS_30*sine + SIN_30*cosine;
        case 11:
            return SIN_30*sine + COS_30*cosine;
	}
}