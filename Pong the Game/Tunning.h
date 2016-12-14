#include <gl/freeglut.h>

class Tunning
{
public:
	float field_x;
	float field_y;
	float stick_x=50;
	float stick_y=50;
	float stick_dy;
	float pos_x;
	float pos_y;
	char* racket_sp = "RACKET SPEED";
	char*upgrade = "UPGRADE";
	char *level = "LEVEL";
	char*ball_sp = "BALL REFLECTION SPEED";
	char *back = "MAIN MENU";
	short int RS_sel = 0;
	short int BS_sel = 0;
	Tunning(float x, float y,float dy) :pos_x(x), pos_y(y),stick_dy(dy){}
	void draw_stick();
	void draw_text_RS();
	void draw_text_BS();
	void draw_field();
	void draw_field_BS();
};
void Tunning::draw_field()
{
	if (RS_sel == 0){
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2f(20, -410);
		glVertex2f(240, -410);
		glVertex2f(240, -350);
		glVertex2f(20, -350);
		glEnd();
	}
	else if (RS_sel == 1){
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2f(0, -520);
		glVertex2f(270, -520);
		glVertex2f(270, -450);
		glVertex2f(0, -450);
		glEnd();
	}
}

void Tunning::draw_field_BS()
{
	if (BS_sel == 0){
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2f(20, -410);
		glVertex2f(240, -410);
		glVertex2f(240, -350);
		glVertex2f(20, -350);
		glEnd();
	}
	else if (BS_sel == 1){
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2f(0, -520);
		glVertex2f(270, -520);
		glVertex2f(270, -450);
		glVertex2f(0, -450);
		glEnd();
	}
}
void Tunning::draw_stick()
{
	glColor3f(1,1,1);
	glVertex2f(stick_x+pos_x,stick_y+stick_dy);
	glVertex2f(stick_x+pos_x, -stick_y);
	glVertex2f(-stick_x+pos_x, -stick_y);
	glVertex2f(-stick_x+pos_x, stick_y+stick_dy);
}

void Tunning::draw_text_RS()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(-20,400);
	for (int n = 0; n <= 12; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, racket_sp[n]);
	glColor3f(1, 1, 1);
	glRasterPos2f(30,-200);
	for (int n = 0; n <= 5; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level[n]);
	glRasterPos2f(220, -200);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0'+reflector1.level);
	glColor3f(1, 1, 1);
	glRasterPos2f(30,-400);
	for (int n = 0; n <= 7; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, upgrade[n]);
	glRasterPos2f(10, -500);
	for (int n = 0; n <= 11; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, back[n]);
}

void Tunning::draw_text_BS()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(-120, 400);
	for (int n = 0; n <= 20; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ball_sp[n]);
	glColor3f(1, 1, 1);
	glRasterPos2f(30, -200);
	for (int n = 0; n <= 5; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, level[n]);
	glRasterPos2f(220, -200);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + reflector1.b_level);
	glColor3f(1, 1, 1);
	glRasterPos2f(30, -400);
	for (int n = 0; n <= 7; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, upgrade[n]);
	glRasterPos2f(10, -500);
	for (int n = 0; n <= 11; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, back[n]);
}