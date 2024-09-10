/**
 ***************************************************************
 * @file            : FrameBuffer.h
 * @author          : Lambert
 * @brief           : 帧缓冲
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#pragma once

#include "config.h"

namespace LSR
{

	class FrameBuffer
	{
	 public:
		FrameBuffer(int width, int height);
		~FrameBuffer() = default;

		void setPixel(int x, int y, const Color& color);
		void clear(const Color& color);
		inline const uint32_t* getData() const { return m_Pixels.data(); }
	 private:
		inline int getIndex(int x, int y) const { return y * m_Width + x; }
		static uint32_t color2uint32_t(const Color& color);
	 private:
		int m_Width, m_Height;
		std::vector<uint32_t> m_Pixels;
	};

} // LSR
