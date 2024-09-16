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
	uint8_t R {255};
	uint8_t G {255};
	uint8_t B {255};
	uint8_t A {255};
};

// 位偏移
#define BIT(N,X) (N << X)

// 绑定函数
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
