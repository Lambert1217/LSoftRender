/**
 ***************************************************************
 * @file            : Window.h
 * @author          : Lambert
 * @brief           : 窗口
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#pragma once

#include "config.h"
#include "FrameBuffer.h"
#include "FPSCounter.h"

namespace LSR
{
	using FuncOnEvent = std::function<void(SDL_Event &)>;

	class Window
	{
	 public:
		Window(int width, int height, const std::string& title);
		~Window();

		inline bool shouldClose() { return !m_Running; }
		void processEvents();
		void showFrameBuffer(const FrameBuffer& frameBuffer);
		void setFuncOnEvent(const FuncOnEvent& func) { m_FuncOnEvent = func; }
		void updateFPS();
	 private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
		SDL_Texture* m_Texture;
		bool m_Running;
		int m_Width, m_Height;
		std::string m_Title;
		std::unique_ptr<FPSCounter> m_FPSCounter;
		FuncOnEvent m_FuncOnEvent;
	};

} // LSR
