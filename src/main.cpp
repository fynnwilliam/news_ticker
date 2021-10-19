#include "slide.h"
#include <iostream>

int main(int argc, char** argv)
{
	slide& s = slide::get_slide();
	s.message(argc, argv);
	s.display();
}
