/**
 ***************************************************************
 * @file            : FrameBuffer.cpp
 * @author          : Lambert
 * @brief           : 帧缓冲实现
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#include "FrameBuffer.h"

namespace LSR
{
	FrameBuffer::FrameBuffer(int width, int height)
		: m_Width(width), m_Height(height)
	{
		m_Pixels.resize(width * height);
	}
	void FrameBuffer::setPixel(int x, int y, const Color& color)
	{
		LOG_ASSERT(x >= 0 && x < m_Width && y >= 0 && y < m_Height);
		m_Pixels[getIndex(x, y)] =  color2uint32_t(color);
	}
	void FrameBuffer::clear(const Color& color)
	{
		std::fill(m_Pixels.begin(), m_Pixels.end(), color2uint32_t(color));
	}
	uint32_t FrameBuffer::color2uint32_t(const Color& color)
	{
		return  BIT((uint32_t)color.R, 24)  |
				BIT((uint32_t)color.G, 16)  |
				BIT((uint32_t)color.B, 8)   |
				(uint32_t)color.A;
	}
} // LSR