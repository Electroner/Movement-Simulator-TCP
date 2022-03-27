#ifndef PHONE_H
#define PHONE_H

#include "object3d.h"
#include "cube.h"
#include "vertex.h"

class _Phone : public _object3D
{
private:
	_cube screen;
	_cube body;

    float anglex;
    float angley;
    float anglez;

    GLfloat Black [4] = {0.0, 0.0, 0.0, 1.0};
    GLfloat Gray [4] = {0.5, 0.5, 0.5, 1.0};

public:
	_Phone();

    void draw_point();
	void draw_line();
	void draw_fill();
	void draw_chess();
	void draw_lighted_flat_shading();
	void draw_lighted_smooth_shading();
	void draw_texture();

    void update(const float (&_sensors)[9]);
};

#endif