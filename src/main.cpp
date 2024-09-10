/**
 ***************************************************************
 * @file            : main.cpp
 * @author          : Lambert
 * @brief           : 程序入口
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#include "config.h"
#include "Application.h"

int WinMain(){
	LSR::Application app(800, 600, "Lambert SoftRenderer");
	app.run();
	return 0;
}