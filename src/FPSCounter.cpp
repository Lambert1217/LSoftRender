/**
 ***************************************************************
 * @file            : FPSCounter.cpp
 * @author          : Lambert
 * @brief           : 帧率计数器实现
 * @attention       : None
 * @data            : 2024/9/5
 ***************************************************************
 */
//

#include "FPSCounter.h"

namespace LSR
{
	FPSCounter::FPSCounter() : m_lastTime(0), m_frameCount(0), m_fps(0.0f)
	{
		m_lastTime = SDL_GetTicks();  // 初始化时获取当前时间
	}

	void FPSCounter::frame()
	{
		// 获取当前时间
		Uint32 currentTime = SDL_GetTicks();
		Uint32 deltaTime = currentTime - m_lastTime;

		// 每帧计数
		m_frameCount++;

		// 每秒更新一次帧率
		if (deltaTime >= 1000)  // 1000 ms = 1 second
		{
			// 计算帧率 (每秒的帧数)
			m_fps = (int)(m_frameCount / (deltaTime / 1000.0f));

			// 重置帧计数和时间
			m_frameCount = 0;
			m_lastTime = currentTime;
		}
	}
}