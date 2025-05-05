#include <raylib.h>
#include <raymath.h>
#include <math.h>


Vector2 clampElipse(Vector2 eye, Vector2 size){
    Vector2 delta = (Vector2){GetMouseX() - eye.x, GetMouseY() - eye.y};
    Vector2 radius;

    double angle = atan2(delta.y, delta.x);

    radius = (Vector2){cos(angle) * size.x, sin(angle) * size.y};

    double maxDist = sqrt(pow(radius.x, 2) + pow(radius.y,2));
    double dist = fmin(Vector2Length(delta), maxDist * 0.66);

    return Vector2Add(eye, (Vector2){cos(angle) * dist, sin(angle) * dist});
}
