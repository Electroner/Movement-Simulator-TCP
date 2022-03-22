#ifndef AARM_H
#define AARM_H

#include "cube.h"
#include "cilindro.h"
#include "Abase.h"
#include "math.h"
#include "Aend.h"

class _Aarm
{
private:
    _cube body;
    _Cilindro pivot1;
    _Cilindro pivot2;
    _Cilindro lpivot1;
    _Cilindro lpivot2;

    _Abase Base;

    _Aend End;

    //De 0 a PI

    float position_pivot1;
    float position_pivot2;

    float angulo;

    float cosposition1;
    float sinposition2;
    float headposition;

public:
    _Aarm();
    ~_Aarm();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_lighted_flat_shading();
    void draw_lighted_smooth_shading();
    void draw_texture();
    
    void update(float _step=0.01);
};

#endif