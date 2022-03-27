#include "Phone.h"

_Phone::_Phone() {
	anglex = 0.0;
	angley = 0.0;
	anglez = 0.0;
}

void _Phone::draw_lighted_flat_shading()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(anglex, 1, 0, 0);
	glRotatef(angley, 0, 1, 0);
	glRotatef(anglez, 0, 0, 1);

	glPushMatrix();
	glScalef(1.75, 0.1, 1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Gray);
	glMaterialf(GL_FRONT, GL_SHININESS, 0);
	body.draw_lighted_flat_shading();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.05, 0);
	glScalef(1.5, 0.05, 0.75);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Black);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Black);
	glMaterialf(GL_FRONT, GL_SHININESS, 0);
	screen.draw_lighted_flat_shading();
	glPopMatrix();

	glPopMatrix();
}

void _Phone::draw_lighted_smooth_shading()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(anglex, 1, 0, 0);
	glRotatef(angley, 0, 1, 0);
	glRotatef(anglez, 0, 0, 1);

	glPushMatrix();
	glScalef(1.75, 0.1, 1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Gray);
	glMaterialf(GL_FRONT, GL_SHININESS, 0);
	body.draw_lighted_smooth_shading();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.05, 0);
	glScalef(1.5, 0.05, 0.75);
	glMaterialfv(GL_FRONT, GL_AMBIENT, Black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Black);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Black);
	glMaterialf(GL_FRONT, GL_SHININESS, 0);
	screen.draw_lighted_smooth_shading();
	glPopMatrix();

	glPopMatrix();
}

void _Phone::update(const float (&_sensors)[9]){

	float temp_anglex = atan(_sensors[0]/9.807)*(360/M_PI);
	//float temp_anglex = atan((_accelerometer_y/9.81) / sqrt(pow((_accelerometer_x/9.81), 2) + pow((_accelerometer_z/9.81), 2))) * 180 / M_PI;
	float temp_anglez = -atan(_sensors[1]/9.807)*(360/M_PI);
	//float temp_anglez = atan(-1*(_accelerometer_x/9.81) / sqrt(pow((_accelerometer_y/9.81), 2) + pow((_accelerometer_z/9.81), 2))) * 180 / M_PI;
	
	//Low pass filter
	anglex = 0.95*anglex + 0.05*temp_anglex;
	anglez = 0.95*anglez + 0.05*temp_anglez;	

}
