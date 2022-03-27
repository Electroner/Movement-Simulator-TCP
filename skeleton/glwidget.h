#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <GL/gl.h>
#include <algorithm>
#include <iostream>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QImage>
#include <QImageReader>
#include <QInputDialog>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <thread>

#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "plyobj.h"
#include "revobj.h"
#include "cilindro.h"
#include "esfera.h"
#include "rueda.h"
#include "eje.h"
#include "rueda_eje.h"
#include "function.h"
#include "chess_board.h"
#include "Abase.h"
#include "Aarm.h"
#include "Atip.h"
#include "Aend.h"
#include "Acompass.h"
#include "Phone.h"

namespace _gl_widget_ne
{

	const float X_MIN = -.1;
	const float X_MAX = .1;
	const float Y_MIN = -.1;
	const float Y_MAX = .1;
	const float FRONT_PLANE_PERSPECTIVE = (X_MAX - X_MIN) / 2;
	const float BACK_PLANE_PERSPECTIVE = 1000;
	const float DEFAULT_DISTANCE = 2;
	const float ANGLE_STEP = 1;

	typedef enum
	{
		MODE_DRAW_POINT,
		MODE_DRAW_LINE,
		MODE_DRAW_FILL,
		MODE_DRAW_CHESS,
		MODE_ILLUMINATION_FLAT_SHADING
	} _mode_draw;
	typedef enum
	{
		OBJECT_TETRAHEDRON,
		OBJECT_CUBE,
		OBJECT_PLY,
		OBJECT_REV,
		OBJECT_CILINDRO,
		OBJECT_SPHERE,
		OBJECT_REVFX,
		OBJECT_WHEEL,
		OBJECT_EJE,
		OBJECT_RUEDA_EJE,
		OBJECT_CHESS_BOARD,
		OBJECT_COMPASS,
		OBJECT_ARM,
		OBJECT_END,
		OBJECT_TIP,
		OBJECT_BASE,
		OBJECT_PHONE
	} _object;
}

class _window;

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
	Q_OBJECT
public:
	_gl_widget(_window *Window1);

	void clear_window();
	void change_projection();
	void change_observer();

	void draw_axis();
	void draw_objects();
	void build_lights();
	void build_material(string _material);

	void set_animation();
	
	void SetTCP();
	void read_from_client();

	int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
	const char *ACK = "ACKDAT\n";
	char buffer[10240] = {0};
	string data;
	float sensordata[9];
	unsigned long long tiempo;

protected:
	void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;
	void initializeGL() Q_DECL_OVERRIDE;
	void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
	//void mousePressEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  	//void mouseReleaseEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  	void mouseMoveEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  	void wheelEvent(QWheelEvent *Event) Q_DECL_OVERRIDE;

protected slots:
	void tick();

private:
	_window *Window;

	_chess_board chess_board{1,8};
	_axis Axis;
	_tetrahedron Tetrahedron;
	_cube Cube;
	_plyObj plyobj;
	_revOBJ revOBJ{vector<_vertex3f>{_vertex3f(0, -0.5, 0), _vertex3f(0.5, -0.5, 0), _vertex3f(0, 0.5, 0)}, 10};
	_Cilindro Cilindro{50};
	_Esfera sphereOBJ{50,50};
	_revOBJ revFX;

	_rueda wheel;
	_eje eje;
	_rueda_eje rueda_eje;

	_Acompass Compass;
	_Aarm Arm;
	_Aend End;
	_Atip Tip;
	_Abase Base;

	_Phone Phone;

	_gl_widget_ne::_object Object;

	QImage Image; //Textura

	QTimer *Timer;

	bool Draw_point;
	bool Draw_line;
	bool Draw_fill;
	bool Draw_chess;
	bool Draw_flat_shading;
	bool Draw_smooth_shading;
	bool Draw_texture;
	bool Draw_axis;

	bool Translate;

	float Observer_angle_x;
	float Observer_angle_y;
	float Observer_distance;

	bool animation;

	bool light0_enabled;
	bool light1_enabled;
	string material;
	double angle_ligth;

	bool perspective; //TRUE = PERSPECTIVE, FALSE = ORTHO
	float reduction = 0.1;

	float last_x;	//CONTROL RELATIVE POSITION MOUASE
	float last_y;	

	float animation_speed = 0.01;

	float accelerometer_x;
	float accelerometer_y;
	float accelerometer_z;

	int Window_width;
  	int Window_height;
};

#endif
