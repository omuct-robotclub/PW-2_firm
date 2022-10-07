/*
 * NeoPixel.h
 *
 *  Created on: Mar 23, 2022
 *      Author: paripal
 */

#ifndef NeoPixel_H_
#define NeoPixel_H_

#include "stm32f3xx_hal.h"

namespace ws2812 {
constexpr uint8_t byte = 8;
constexpr uint8_t color_num = 3;
constexpr uint8_t pixel_num = 4;
constexpr uint8_t data_len = byte * color_num * pixel_num;
constexpr uint8_t reset_bit = 1;

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} color;

class NeoPixel {
private:
	TIM_HandleTypeDef *htim;
	uint32_t Channel;
	DMA_HandleTypeDef *hdma;
	uint8_t high;
	uint8_t low;
	uint8_t write_buffer[data_len + reset_bit];
	void update_write_buffer();
public:
	color colors[pixel_num];
	void rend();
	NeoPixel(TIM_HandleTypeDef *htim, uint32_t Channel, DMA_HandleTypeDef *hdma, uint8_t high_level_pulse_len, uint8_t low_level_pulse_len);
};

} /* namespace ws2812 */

#endif /* NeoPixel_H_ */
