/**
 ***************************************************************
 * @file            : Window.cpp
 * @author          : Lambert
 * @brief           : 窗口实现
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#include "Window.h"

namespace LSR
{
	Window::Window(int width, int height, const std::string& title)
		: m_Window(nullptr), m_Renderer(nullptr), m_Texture(nullptr), m_Running(true), m_Width(width), m_Height(height)
	{
		int check = SDL_Init(SDL_INIT_VIDEO);
		LOG_ASSERT(check >= 0);
		m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		LOG_ASSERT(m_Window);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_SOFTWARE);
		LOG_ASSERT(m_Renderer);
		m_Texture = SDL_CreateTexture(m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
		LOG_ASSERT(m_Texture);
		check = SDL_SetTextureBlendMode(m_Texture, SDL_BLENDMODE_BLEND);
		LOG_ASSERT(check == 0);
	}
	Window::~Window()
	{
		SDL_DestroyTexture(m_Texture);
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}
	void Window::processEvents()
	{
		SDL_Event m_event;
		while (SDL_PollEvent(&m_event))
		{
			if (m_event.type == SDL_QUIT)
			{
				m_Running = false;
			}
			else
			{
				m_FuncOnEvent(m_event);
			}
		}
	}
	void Window::showFrameBuffer(const FrameBuffer& frameBuffer)
	{
		SDL_RenderClear(m_Renderer);
		SDL_UpdateTexture(m_Texture, nullptr, frameBuffer.getData(), m_Width * sizeof(uint32_t));
		SDL_RenderCopy(m_Renderer, m_Texture, nullptr, nullptr);
		SDL_RenderPresent(m_Renderer);
	}
} // LSR