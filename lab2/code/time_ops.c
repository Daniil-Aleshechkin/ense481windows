#include "util.h"
#include "time_ops.h"
#include <stdint.h>

const double ROOT_3 = 1.73205080;
const double SIN_30 = 1.0/2.0;
const double COS_30 = ROOT_3/2.0;

const double SIN_22_5 = 0.3826834323;
const double SIN_45 = 0.707106781;
const double SIN_67_5 = 0.92387953251;

const double COS_22_5 = 0.92387953251;
const double COS_45 = 0.707106781;
const double COS_67_5 = 0.3826834323;

const double PI = 3.14159265358;
const double PI_CUBED = 31.00627668029982;
const double PI_OVER_6 = PI / 6.0;

double sin_horner_BAM(double x) {
		uint16_t bamIn = (uint16_t)((x/(2*PI)*(0x10000)));
		int n = ((bamIn) >> 12) % 16;
		uint16_t bamShifted = bamIn - n * 4096;
	
		uint64_t z = bamShifted*bamShifted;
		uint64_t s1 = 0x3243F6A8885A3;
		uint64_t s2 = 0x14ABBD;
	
    double sine = (double)(bamShifted*(s1-z*s2));
    
		uint64_t c1 = 0x8000000000000000;
		uint64_t c2 = 0x9DE9E64DF;
		uint64_t c3 = 0x20;
		
		double cosine = (double)(c1-z*(c2+c3*z));
		double output;
		
    switch (n) {
        case 0:
            output = sine; break;
        case 1:
            output = COS_22_5 * sine + SIN_22_5 * cosine; break;
        case 2:
            output = COS_45 * sine + SIN_45 * cosine; break;
				case 3:
            output = COS_67_5 * sine + SIN_67_5 * cosine; break;
        case 4:
            output = cosine; break;
        case 5:
            output = -SIN_22_5 * sine + COS_22_5 * cosine; break;
        case 6:
            output = -SIN_45*sine + COS_45*cosine; break;
				case 7:
            output = -SIN_67_5 * sine + COS_67_5 * cosine; break;
				case 8:
            output = -sine; break;
        case 9:
            output = -COS_22_5*sine - SIN_22_5*cosine; break;
        case 10:
            output = -COS_45*sine - SIN_45*cosine; break;
				case 11:
            output = -COS_67_5 * sine - SIN_67_5 * cosine; break;
				case 12:
            output = -cosine; break;
        case 13:
            output = SIN_22_5*sine - COS_22_5*cosine; break;
        case 14:
            output = SIN_45*sine - COS_45*cosine; break;
				case 15:
            output = SIN_67_5 * sine - COS_67_5 * cosine; break;
		}
	output /= (double)(0x8000000000000000);
	return output;
}


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