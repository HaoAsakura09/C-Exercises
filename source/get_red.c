#include <stdio.h>

struct color
{
	int red;
	int green;
	int blue;
};

struct color make_color(int red, int green, int blue)
{
	struct color make;
	if(red < 0)
		make.red = 0;
	else if(red > 255)
		make.red = 255;
	else 
		make.red = red;
		
   if(green < 0)
   	make.green = 0;
   else if(green > 255)
   	make.green = 255;
   else
   	make.red = red;
   	
   if(blue < 0)
   	make.red = 0;
   else if(blue > 255)
   	make.blue = blue;
   else
   	make.blue = blue;
  
  return make;
};

int get_red(struct color c);

int main(void)
{
	struct color c;
	c = make_color(255, 255, 255);
	
	printf("Red: %d\n", get_red(c));
	return 0;
}

int get_red(struct color c)
{
	return c.red;
}
