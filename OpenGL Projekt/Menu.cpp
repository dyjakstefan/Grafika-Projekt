#include "Menu.h"
#include "const.h"


Menu::Menu()
{
	TwInit(TW_OPENGL, NULL);
	TwWindowSize(WIDTH, HEIGHT);
	myBar = TwNewBar("Menu drukarki");
	TwAddVarRW(myBar, "kol1", TW_TYPE_INT8, &lineColorNum, "label='Kolor filamentu' ");
	TwAddVarRW(myBar, "kol2", TW_TYPE_INT8, &lightColorNum, "label='Kolor oswietlenia' ");

}


Menu::~Menu()
{
}
