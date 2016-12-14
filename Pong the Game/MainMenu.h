#include <gl/freeglut.h>

class MainMenu
{	
protected:
	char*start;
	char*exit;
	char *classic = "Classic Mode";
	char *tunning = "Tunning Room";
	char* ref_sp = "Racket Speed";
	char *ball_sp = "Ball Reflection Speed";
	float field_x;
	float field_y;
	float field_depth;
	float field_dx;
	float field_dy;
	float field_l_start;
	float field_h;
	float field_l_exit;
public:
	unsigned short int select = 0;//Start & Exit 
	unsigned short int mode_sel = 0;//Classic & Tunning Room
	unsigned short int tun_sel = 0;//Reflector speed & Ball Reflection speed
	MainMenu(){
		field_x = 50;
		field_y = -150;
		field_dx = 15;
		field_dy = -100;
		field_l_start = 150;
		field_l_exit = 120;
		field_h = 40;
		field_depth = 10;
		start = "START";
		exit = "EXIT";
	}
	void draw_field();
	void draw_Tittle();
	void draw_Menu();
	void draw_Menu_in_Start();
	void select_menu();
	void draw_field2();
	void draw_menu_tun();
	void draw_field3();
};

void MainMenu::draw_Tittle()
{
	//'O'
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0, 50);
	glVertex2f(100, 50);
	glVertex2f(100, 250);
	glVertex2f(0, 250);

	glColor3f(0, 0, 0);
	glVertex2f(30, 80);
	glVertex2f(70, 80);
	glVertex2f(70, 220);
	glVertex2f(30, 220);
	// 'P'
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-30, 50);
	glVertex2f(-130, 50);
	glVertex2f(-130, 250);
	glVertex2f(-30, 250);

	glColor3f(0, 0, 0);
	glVertex2f(-30, 50);
	glVertex2f(-100, 50);
	glVertex2f(-100, 150);
	glVertex2f(-30, 150);

	glVertex2f(-60, 180);
	glVertex2f(-100, 180);
	glVertex2f(-100, 220);
	glVertex2f(-60, 220);
	// 'N'
	glColor3f(1, 1, 1);
	glVertex2f(130, 50);
	glVertex2f(130, 250);
	glVertex2f(230, 250);
	glVertex2f(230, 50);

	glColor3f(0, 0, 0 );
	glVertex2f(160, 150);
	glVertex2f(160, 50);
	glVertex2f(200, 50);
	glVertex2f(200, 49);

	glVertex2f(160, 250);
	glVertex2f(200, 250);
	glVertex2f(200, 150);
	glVertex2f(161, 250);
	//'G'
	glColor3f(1, 1, 1);
	glVertex2f(260, 50);
	glVertex2f(260, 250);
	glVertex2f(380, 250);
	glVertex2f(380, 50);

	glColor3f(0, 0, 0);
	glVertex2f(290, 220);
	glVertex2f(380, 220);
	glVertex2f(380, 160);
	glVertex2f(290, 160);

	glColor3f(0, 0, 0);
	glVertex2f(290, 190);
	glVertex2f(320, 190);
	glVertex2f(320, 80);
	glVertex2f(290, 80);

	glColor3f(0, 0, 0);
	glVertex2f(320,80);
	glVertex2f(350,80);
	glVertex2f(350, 120);
	glVertex2f(320, 120);
}

void MainMenu::draw_Menu()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(field_x, field_y);
		for (int n = 0; n <= sizeof(start)+1; n++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, start[n]);
	glColor3f(1, 1, 1);
	glRasterPos2f(field_x + field_dx, field_y + field_dy);
		for (int n = 0; n <= sizeof(exit)+1; n++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exit[n]);

}

void MainMenu::draw_field()
{
	if (select == 0){
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(field_x - 10, field_y - 10);
		glVertex2f(field_x + field_l_start - 10, field_y - 10);
		glVertex2f(field_x + field_l_start - 10, field_y + field_h);
		glVertex2f(field_x - 10, field_y + field_h);
	}
	else if (select == 1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(field_x - 10 + field_dx, field_y - 10 + field_dy);
		glVertex2f(field_x + field_l_exit - 10 + field_dx, field_y - 10 + field_dy);
		glVertex2f(field_x + field_l_exit - 10 + field_dx, field_y + field_h + field_dy);
		glVertex2f(field_x - 10 + field_dx, field_y + field_h + field_dy);
	}
}
void MainMenu::draw_Menu_in_Start()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(field_x-40, field_y);
	for (int n = 0; n <= 12; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, classic[n]);
	glColor3f(1, 1, 1);
	glRasterPos2f(field_x + field_dx-70, field_y + field_dy);
	for (int n = 0; n <= 12; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tunning[n]);
}

void MainMenu::draw_field2()
{
	if (mode_sel == 0){
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(field_x - 50, field_y - 10);
		glVertex2f(field_x + field_l_start +60, field_y - 10);
		glVertex2f(field_x + field_l_start +60, field_y + field_h);
		glVertex2f(field_x - 50, field_y + field_h);
	}
	else if (mode_sel == 1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(field_x - 80 + field_dx, field_y - 10 + field_dy);
		glVertex2f(field_x + field_l_exit + field_dx+90, field_y - 10 + field_dy);
		glVertex2f(field_x + field_l_exit + field_dx+90, field_y + field_h + field_dy);
		glVertex2f(field_x - 80 + field_dx, field_y + field_h + field_dy);
	}
}
void MainMenu::draw_menu_tun()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(field_x - 40, field_y);
	for (int n = 0; n <= 12; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ref_sp[n]);
	glColor3f(1, 1, 1);
	glRasterPos2f(field_x + field_dx - 120, field_y + field_dy);
	for (int n = 0; n <= 20; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ball_sp[n]);
}
void MainMenu::draw_field3()
{
	if (tun_sel == 0){
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(field_x - 50, field_y - 10);
		glVertex2f(field_x + field_l_start + 60, field_y - 10);
		glVertex2f(field_x + field_l_start + 60, field_y + field_h);
		glVertex2f(field_x - 50, field_y + field_h);
	}
	else if (tun_sel == 1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(field_x - 130 + field_dx, field_y - 10 + field_dy);
		glVertex2f(field_x + field_l_exit + field_dx + 140, field_y - 10 + field_dy);
		glVertex2f(field_x + field_l_exit + field_dx + 140, field_y + field_h + field_dy);
		glVertex2f(field_x - 130 + field_dx, field_y + field_h + field_dy);
	}
}