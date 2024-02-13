#ifndef _BTR_VECTORS_H_
#define _BTR_VECTORS_H_

/***************************************************************************
 * @brief VECTOR MANAGEMENT
 ***************************************************************************/
typedef struct {
  int *x0;
  int *y0;
} Vector1D;

typedef struct {
  int *x0;
  int *y0;
  int *x1;
  int *y1;
} Vector2D;

typedef struct Vector3D {
  int *x0;
  int *y0;
  int *z0;
  int *x1;
  int *y1;
  int *z1;
} Vector3D;

#endif // !_BTR_VECTORS_H_

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Defines 6utt3r's Mechanics configuration.
 ***************************************************************************/
