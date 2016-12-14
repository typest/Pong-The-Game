#include <gl/freeglut.h>

class Reflector
{
public:
	float reflector_x;
	float reflector_y;
	float reflector_depth;
	float ref_speed;
	bool ref_R;
	bool ref_L;
	float reflector_vx;
	int level = 0;
	int b_level = 0;
	int wp = 10000;
	Reflector();
	Reflector(float x, float y, float speed,float depth)
	{
		reflector_x = x;
		reflector_y = y;
		reflector_depth = depth;
		ref_speed = speed;
		ref_L = false;
		ref_R = false;
	}
	void ref_move(float x);
	void ref_draw();
};

void Reflector::ref_draw()
{
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-reflector_x + reflector_vx , reflector_y);
	glVertex2f(-reflector_x + reflector_vx, reflector_depth + reflector_y);
	glVertex2f(reflector_x + reflector_vx, reflector_depth + reflector_y);
	glVertex2f(reflector_x + reflector_vx, +reflector_y);
}

void Reflector::ref_move(float x)
{
	if (reflector_vx <= x - 59 && reflector_vx >= -x + 60){
		if ((ref_L) && (!ref_R))
			reflector_vx += -ref_speed;

		if ((ref_R) && (!ref_L))
			reflector_vx += ref_speed;
	}
	else if (reflector_vx >= x - 59)
		reflector_vx = x - 59;
	else if (reflector_vx <= -x + 60)
		reflector_vx = -x + 60;
}