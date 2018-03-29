#include <stdio.h>
#include <stdlib.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include <math.h>

void trace_pixel(int x, int y);
void trace_seg_diff(int x1, int y1, int x2, int y2);
void trace_seg_bresenham_float(int x1, int y1, int x2, int y2);
void trace_seg_bresenham_int(int x1, int y1, int x2, int y2);