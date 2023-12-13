#include <stdio.h>
#include <math.h>


int isInsideSphere(double x, double y, double z, double R) {
    double distance = sqrt(x * x + y * y + z * z);
    if (distance <= R) {
        return 1; 
    }
    else {
        return 0; 
    }
}

int main() {
    double x = 2.0; 
    double y = 3.0; 
    double z = 1.0; 
    double R = 5.0; 

    int result = isInsideSphere(x, y, z, R);

    if (result == 1) {
        printf("point (%.2f, %.2f, %.2f) belongs to a sphere with radius %.2f and the center at the origin of coordinates\n", x, y, z, R);
    }
    else {
        printf("point (%.2f, %.2f, %.2f) does not belong to a sphere with a radius %.2f and the center at the origin of coordinates\n", x, y, z, R);
    }

    return 0;
}