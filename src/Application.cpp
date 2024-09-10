/**
 ***************************************************************
 * @file            : Application.cpp
 * @author          : Lambert
 * @brief           : None
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#include "Application.h"

namespace LSR
{
	Application::Application(int width, int height, const std::string& title)
		: m_Window(width, height, title), m_FrameBuffer(width, height)
	{
		m_Window.setFuncOnEvent(BIND_EVENT_FN(Application::onEvent));
	}
	void Application::run()
	{
		while(!m_Window.shouldClose())
		{
			m_Window.processEvents();
			update(0);
			m_Window.showFrameBuffer(m_FrameBuffer);
			m_Window.updateFPS();
		}
	}

	void Application::update(float delta)
	{
		cColor = {100, 100, 100, 255};
		m_FrameBuffer.clearColorBuffer(cColor);
		m_FrameBuffer.clearDepthBuffer();
		m_FrameBuffer.setColor(100, 100, { 255, 0, 0, 255 });
		m_FrameBuffer.setColor(100, 101, { 255, 0, 0, 255 });
		m_FrameBuffer.setColor(101, 101, { 255, 0, 0, 255 });
		m_FrameBuffer.setColor(101, 100, { 255, 0, 0, 255 });
		m_FrameBuffer.setDepth(100, 100, 100.f);
	}
	void Application::onEvent(const SDL_Event& event)
	{
		if(event.type == SDL_KEYDOWN)
		{
			SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%d", event.key.keysym.sym);
		}
	}
} // LSR
