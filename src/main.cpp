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

#include "Application.h"

#undef main
int main(int argc, char* argv[]){
	// 日志等级
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG);
	// 程序创建
	LSR::Application app(800, 600, "Lambert SoftRenderer");
	app.run();
	return 0;
}