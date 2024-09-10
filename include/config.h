/**
 ***************************************************************
 * @file            : config.h
 * @author          : Lambert
 * @brief           : 配置文件
 * @attention       : None
 * @data            : 2024/9/10
 ***************************************************************
 */
//

#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <functional>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_log.h"
#include "SDL2/SDL_assert.h"

struct Color{
	uint8_t R;
	uint8_t G;
	uint8_t B;
	uint8_t A;

	constexpr Color(uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255) : R(r), G(g), B(b), A(a)
	{
	}
};

// 绑定函数
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
