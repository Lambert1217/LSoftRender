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

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cassert>
#include <functional>

struct Color{
	uint8_t R {255};
	uint8_t G {255};
	uint8_t B {255};
	uint8_t A {255};
};

// 日志输出
#define LOG_TRACE(X) std::cout << "[TRACE]: " << X << std::endl;
#define LOG_ERROR(X) std::cerr << "[ERROR] (" << __FILE__ << ":" << __LINE__ << "): " << X << std::endl;
#define LOG_ASSERT(X) assert(X);

// 位偏移
#define BIT(N,X) (N << X)

// 绑定函数
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
