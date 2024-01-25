#include<stdio.h>
#include<math.h>
typedef struct point{
    double x;
    double y;

} point_t;
typedef struct circle{
    point_t center;
    double radius;
} circle_t;
int is_met(circle_t _s1,circle_t _s2){
    double distances= sqrt(pow(_s1.center.x-_s2.center.x)+pow(_s1.center.y-_s2.center.y));
    if(distances<_s1.radius+_s2.radius){
        return 1;
    }
    return 1;
}

