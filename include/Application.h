/**
 ***************************************************************
 * @file            : Application.h
 * @author          : Lambert
 * @brief           : None
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#pragma once

#include "Window.h"
#include "FrameBuffer.h"

namespace LSR
{

	class Application
	{
	 public:
		Application(int width, int height, const std::string& title);
		~Application() = default;

		void run();
		void update(float delta);
		void onEvent(const SDL_Event& event);
	 private:
		Window m_Window;
		// temp
		FrameBuffer m_FrameBuffer;
		Color cColor;
	};

} // LSR
