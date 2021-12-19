/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;

/*****************************************************************************/ /**
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1) : Window(Window1)
{
	setMinimumSize(300, 300);
	setFocusPolicy(Qt::StrongFocus);
}

/*****************************************************************************/ /**
                                                                                 * Evento tecla pulsada
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
	switch (Keyevent->key())
	{
	case Qt::Key_1:
		Object = OBJECT_TETRAHEDRON;
		break;
	case Qt::Key_2:
		Object = OBJECT_CUBE;
		break;
	case Qt::Key_3:
		plyobj.File((QFileDialog::getOpenFileName(this, tr("Open PLY"), "/", tr("PLY Files (*.ply)"))).toStdString());
		Object = OBJECT_PLY;
		break;
	case Qt::Key_4:
		Object = OBJECT_REV;
		break;
	case Qt::Key_5:
		Object = OBJECT_CILINDRO;
		break;
	case Qt::Key_6:
		Object = OBJECT_SPHERE;
		break;
	case Qt::Key_7:
		Object = OBJECT_WHEEL;
		break;
	case Qt::Key_8:
		Object = OBJECT_EJE;
		break;
	case Qt::Key_9:
		Object = OBJECT_RUEDA_EJE;
		break;

	case Qt::Key_F1:
		Draw_point = !Draw_point;
		break;
	case Qt::Key_F2:
		Draw_line = !Draw_line;
		break;
	case Qt::Key_F3:
		Draw_fill = !Draw_fill;
		break;
	case Qt::Key_F4:
		Draw_chess = !Draw_chess;
		break;
	case Qt::Key_F5:
		Draw_flat_shading = !Draw_flat_shading;
		break;
	case Qt::Key_F6:
		Draw_smooth_shading = !Draw_smooth_shading;
		break;
	case Qt::Key_F7:
		Draw_texture = !Draw_texture;
		break;

	case Qt::Key_Left:
		Observer_angle_y -= ANGLE_STEP;
		break;
	case Qt::Key_Right:
		Observer_angle_y += ANGLE_STEP;
		break;
	case Qt::Key_Up:
		Observer_angle_x -= ANGLE_STEP;
		break;
	case Qt::Key_Down:
		Observer_angle_x += ANGLE_STEP;
		break;
	case Qt::Key_PageUp:
		Observer_distance *= 1.2;
		break;
	case Qt::Key_PageDown:
		Observer_distance /= 1.2;
		break;
	}

	update();
}

/*****************************************************************************/ /**
                                                                                 * Limpiar ventana
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::clear_window()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/*****************************************************************************/ /**
                                                                                 * Funcion para definir la transformación de proyeccion
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::change_projection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
	// Front_plane>0  Back_plane>PlanoDelantero)
	glFrustum(X_MIN, X_MAX, Y_MIN, Y_MAX, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
}

/*****************************************************************************/ /**
                                                                                 * Funcion para definir la transformación de vista (posicionar la camara)
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::change_observer()
{
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -Observer_distance);
	glRotatef(Observer_angle_x, 1, 0, 0);
	glRotatef(Observer_angle_y, 0, 1, 0);
}

/*****************************************************************************/ /**
                                                                                 * Funcion que dibuja los objetos
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::draw_objects()
{
	Axis.draw_line();

	if (Draw_point)
	{
		glPointSize(5);
		glColor3fv((GLfloat *)&BLACK);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_point();
			break;

		case OBJECT_CUBE:
			Cube.draw_point();
			break;

		case OBJECT_PLY:
			plyobj.draw_point();
			break;

		case OBJECT_REV:
			revOBJ.draw_point();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_point();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_point();
			break;

		case OBJECT_WHEEL:
			wheel.draw_point();
			break;

		case OBJECT_EJE:
			eje.draw_point();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_point();
			break;

		default:
			break;
		}
	}

	if (Draw_line)
	{
		glLineWidth(3);
		glColor3fv((GLfloat *)&BLACK);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_line();
			break;

		case OBJECT_CUBE:
			Cube.draw_line();
			break;

		case OBJECT_PLY:
			plyobj.draw_line();
			break;

		case OBJECT_REV:
			revOBJ.draw_line();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_line();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_line();
			break;

		case OBJECT_WHEEL:
			wheel.draw_line();
			break;

		case OBJECT_EJE:
			eje.draw_line();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_line();
			break;

		default:
			break;
		}
	}

	if (Draw_fill)
	{
		glColor3fv((GLfloat *)&BLUE);
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_fill();
			break;

		case OBJECT_CUBE:
			Cube.draw_fill();
			break;

		case OBJECT_PLY:
			plyobj.draw_fill();
			break;

		case OBJECT_REV:
			revOBJ.draw_fill();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_fill();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_fill();
			break;

		case OBJECT_WHEEL:
			wheel.draw_fill();
			break;

		case OBJECT_EJE:
			eje.draw_fill();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_fill();
			break;

		default:
			break;
		}
	}

	if (Draw_chess)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_chess();
			break;

		case OBJECT_CUBE:
			Cube.draw_chess();
			break;
		case OBJECT_PLY:
			plyobj.draw_chess();
			break;

		case OBJECT_REV:
			revOBJ.draw_chess();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_chess();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_chess();
			break;

		case OBJECT_WHEEL:
			wheel.draw_chess();
			break;

		case OBJECT_EJE:
			eje.draw_chess();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_chess();
			break;

		default:
			break;
		}
	}

	if (Draw_flat_shading)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_lighted_flat_shading();
			break;

		case OBJECT_CUBE:
			Cube.draw_lighted_flat_shading();
			break;

		case OBJECT_PLY:
			plyobj.draw_lighted_flat_shading();
			break;

		case OBJECT_REV:
			revOBJ.draw_lighted_flat_shading();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_lighted_flat_shading();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_lighted_flat_shading();
			break;

		case OBJECT_WHEEL:
			wheel.draw_lighted_flat_shading();
			break;

		case OBJECT_EJE:
			eje.draw_lighted_flat_shading();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_lighted_flat_shading();
			break;

		default:
			break;
		}
	}

	if (Draw_smooth_shading)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_lighted_smooth_shading();
			break;

		case OBJECT_CUBE:
			Cube.draw_lighted_smooth_shading();
			break;

		case OBJECT_PLY:
			plyobj.draw_lighted_smooth_shading();
			break;

		case OBJECT_REV:
			revOBJ.draw_lighted_smooth_shading();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_lighted_smooth_shading();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_lighted_smooth_shading();
			break;

		case OBJECT_WHEEL:
			wheel.draw_lighted_smooth_shading();
			break;

		case OBJECT_EJE:
			eje.draw_lighted_smooth_shading();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_lighted_smooth_shading();
			break;

		default:
			break;
		}
	}

	if (Draw_texture)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON:
			Tetrahedron.draw_texture();
			break;

		case OBJECT_CUBE:
			Cube.draw_texture();
			break;

		case OBJECT_PLY:
			plyobj.draw_texture();
			break;

		case OBJECT_REV:
			revOBJ.draw_texture();
			break;

		case OBJECT_CILINDRO:
			Cilindro.draw_texture();
			break;

		case OBJECT_SPHERE:
			sphereOBJ.draw_texture();
			break;

		case OBJECT_WHEEL:
			wheel.draw_texture();
			break;

		case OBJECT_EJE:
			eje.draw_texture();
			break;

		case OBJECT_RUEDA_EJE:
			rueda_eje.draw_texture();
			break;

		default:
			break;
		}
	}
}

/*****************************************************************************/ /**
                                                                                 * Evento de dibujado
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::paintGL()
{
	clear_window();
	change_projection();
	change_observer();
	draw_objects();
}

/*****************************************************************************/ /**
                                                                                 * Evento de cambio de tamaño de la ventana
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
	glViewport(0, 0, Width1, Height1);
}

/*****************************************************************************/ /**
                                                                                 * Inicialización de OpenGL
                                                                                 *
                                                                                 *
                                                                                 *
                                                                                 *****************************************************************************/

void _gl_widget::initializeGL()
{
	const GLubyte *strm;

	strm = glGetString(GL_VENDOR);
	std::cerr << "Vendor: " << strm << "\n";
	strm = glGetString(GL_RENDERER);
	std::cerr << "Renderer: " << strm << "\n";
	strm = glGetString(GL_VERSION);
	std::cerr << "OpenGL Version: " << strm << "\n";

	if (strm[0] == '1')
	{
		std::cerr << "Only OpenGL 1.X supported!\n";
		exit(-1);
	}

	strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cerr << "GLSL Version: " << strm << "\n";

	int Max_texture_size = 0;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
	std::cerr << "Max texture size: " << Max_texture_size << "\n";

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	Observer_angle_x = 0;
	Observer_angle_y = 0;
	Observer_distance = DEFAULT_DISTANCE;

	Draw_point = false;
	Draw_line = true;
	Draw_fill = false;
	Draw_chess = false;
	Draw_flat_shading = false;

	QString File_name("/home/carlos/Cosas/Imagenes/dia.jpg");
	QImageReader Reader(File_name);
	Reader.setAutoTransform(true);
	Image = Reader.read();
	if (Image.isNull())
	{
		QMessageBox::information(this, QGuiApplication::applicationDisplayName(), tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
		exit(-1);
	}
	Image = Image.mirrored();
	Image = Image.convertToFormat(QImage::Format_RGB888);

	// Code to control the application of the texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Code to pass the image to OpenGL to form a texture 2D
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Image.width(), Image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, Image.bits());
}