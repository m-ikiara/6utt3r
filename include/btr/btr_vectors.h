#ifndef _BTR_VECTORS_H_
#define _BTR_VECTORS_H_

/**
 * @brief The Vectors we'll be using in the Development of Butter
 */
typedef struct Vector1D {
  int *x0;
  int *y0;
} vec1;

typedef struct Vector2D {
  int *x0;
  int *y0;
  int *x1;
  int *y1;
} vec2;

typedef struct Vector3D {
  int *x0;
  int *y0;
  int *z0;
  int *x1;
  int *y1;
  int *z1;
} vec3;

#endif // !_BTR_VECTORS_H_
