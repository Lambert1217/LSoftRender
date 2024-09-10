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

		// ColorBuffer
		void setColor(int x, int y, const Color& color);
		void clearColorBuffer(const Color& color);
		inline const uint32_t* getColorData() const { return m_ColorBuffer.data(); }
		// DepthBuffer
		void setDepth(int x, int y, float depth);
		void clearDepthBuffer(float depth = std::numeric_limits<float>::max());
	 private:
		inline int getIndex(int x, int y) const { return y * m_Width + x; }
		static uint32_t color2uint32_t(const Color& color);
	 private:
		int m_Width, m_Height;
		std::vector<uint32_t> m_ColorBuffer;
		std::vector<float> m_DepthBuffer;
	};

} // LSR
