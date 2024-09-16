/**
 ***************************************************************
 * @file            : FPSCounter.h
 * @author          : Lambert
 * @brief           : 帧率计数器
 * @attention       : None
 * @data            : 2024/9/5
 ***************************************************************
 */
//

#pragma once
#include <SDL2/SDL.h>

namespace LSR
{
	class FPSCounter
	{
	 public:
		FPSCounter();
		~FPSCounter() = default;

		// 在每帧结束时调用
		void frame();

		// 获取当前 FPS 值
		inline int getFPS() const { return m_fps; }

	 private:
		Uint32 m_lastTime;  // 上一帧的时间点
		Uint32 m_frameCount;  // 计算帧率的帧数
		int m_fps;  // 当前帧率
	};
}
