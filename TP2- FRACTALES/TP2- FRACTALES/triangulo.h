
#ifndef TRIANGULO_H
#define TRIANGULO_H
typedef struct {
	float x;
	float y;
}point_t;

void TriangleRecursion(point_t StartPosition, float lStart, float lEnd, float RightAngle, float LeftAngle);


#endif // _TRIANGULO_H