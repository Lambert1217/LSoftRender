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
#include <limits>

namespace LSR
{
	FrameBuffer::FrameBuffer(int width, int height)
		: m_Width(width), m_Height(height)
	{
		m_ColorBuffer.resize(width * height, color2uint32_t(Color()));
		m_DepthBuffer.resize(width * height, std::numeric_limits<float>::max());
	}
	void FrameBuffer::setPixel(int x, int y, const Color& color)
	{
		SDL_assert(x >= 0 && x < m_Width && y >= 0 && y < m_Height);
		m_ColorBuffer[getIndex(x, y)] =  color2uint32_t(color);
	}
	void FrameBuffer::setDepth(int x, int y, float depth)
	{
		SDL_assert(x >= 0 && x < m_Width && y >= 0 && y < m_Height);
		m_DepthBuffer[getIndex(x, y)] = depth;
	}
	void FrameBuffer::clearColor(const Color& color)
	{
		std::fill(m_ColorBuffer.begin(), m_ColorBuffer.end(), color2uint32_t(color));
	}
	void FrameBuffer::clearDepth()
	{
		std::fill(m_DepthBuffer.begin(), m_DepthBuffer.end(), std::numeric_limits<float>::max());
	}
	uint32_t FrameBuffer::color2uint32_t(const Color& color)
	{
		return  BIT((uint32_t)color.R, 24)  |
				BIT((uint32_t)color.G, 16)  |
				BIT((uint32_t)color.B, 8)   |
				(uint32_t)color.A;
	}
} // LSR