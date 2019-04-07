/*
 *******************************************************************************
 * Copyright (c) 2018, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#pragma once
#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "PeripheralPins.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
*        Pins
*----------------------------------------------------------------------------*/
extern const PinName digitalPin[];


#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7
#define PA8 8
#define PA9 9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13
#define PA14 14
#define PA15 15
#define PB0 16
#define PB1 17
#define PB2 18
#define PB3 19
#define PB4 20
#define PB5 21
#define PB6 22
#define PB7 23
#define PB8 24
#define PB9 25
#define PB10 26
#define PB11 27
#define PB12 28
#define PB13 29
#define PB14 30
#define PB15 31
#define PC0 32
#define PC1 33
#define PC2 34
#define PC3 35
#define PC4 36
#define PC5 37
#define PC6 38
#define PC7 39
#define PC8 40
#define PC9 41
#define PC10 42
#define PC11 43
#define PC12 44
#define PC13 45
#define PC14 46
#define PC15 47
#define PD0 48
#define PD1 49
#define PD2 50
#define PD3 51
#define PD4 52
#define PD5 53
#define PD6 54
#define PD7 55
#define PD8 56
#define PD9 57
#define PD10 58
#define PD11 59
#define PD12 60
#define PD13 61
#define PD14 62
#define PD15 63
#define PE0 64
#define PE1 65
#define PE2 66
#define PE3 67
#define PE4 68
#define PE5 69
#define PE6 70
#define PE7 71
#define PE8 72
#define PE9 73
#define PE10 74
#define PE11 75
#define PE12 76
#define PE13 77
#define PE14 78
#define PE15 79
#define PF0 80
#define PF1 81
#define PF2 82
#define PF3 83
#define PF4 84
#define PF5 85
#define PF6 86
#define PF7 87
#define PF8 88
#define PF9 89
#define PF10 90
#define PF11 91
#define PF12 92
#define PF13 93
#define PF14 94
#define PF15 95
#define PG0 96
#define PG1 97
#define PG2 98
#define PG3 99
#define PG4 100
#define PG5 101
#define PG6 102
#define PG7 103
#define PG8 104
#define PG9 105
#define PG10 106
#define PG11 107
#define PG12 108
#define PG13 109
#define PG14 110
#define PG15 111
#define PH0 112
#define PH1 113
#define PH2 114
#define PH3 115
#define PH4 116
#define PH5 117
#define PH6 118
#define PH7 119
#define PH8 120
#define PH9 121
#define PH10 122
#define PH11 123
#define PH12 124
#define PH13 125
#define PH14 126
#define PH15 127
#define PI0 128
#define PI1 129
#define PI2 130
#define PI3 131
#define PI4 132
#define PI5 133
#define PI6 134
#define PI7 135
#define PI8 136
#define PI9 137
#define PI10 138
#define PI11 139
#define PI12 140
#define PI13 141
#define PI14 142
#define PI15 143
#define PJ0 144
#define PJ1 145
#define PJ2 146
#define PJ3 147
#define PJ4 148
#define PJ5 149
#define PJ6 150
#define PJ7 151
#define PJ8 152
#define PJ9 153
#define PJ10 154
#define PJ11 155
#define PJ12 156
#define PJ13 157
#define PJ14 158
#define PJ15 159
#define PK0 160
#define PK1 161
#define PK2 162
#define PK3 163
#define PK4 164
#define PK5 165
#define PK6 166
#define PK7 167
#define PK8 168
#define PK9 169
#define PK10 170
#define PK11 171
#define PK12 172
#define PK13 173
#define PK14 174
#define PK15 175


#define PIN_SPI_MOSI PD7
#define PIN_SPI_MISO PG9
#define PIN_SPI_SCK PG11

// PIN definition
#define NUM_DIGITAL_PINS (int)PK15+1
#define NUM_ANALOG_INPUTS 1// Placeholders to shut the Arduino framework up. We dont use the native AnalogRead of the main CPU
#define NUM_ANALOG_FIRST (int)PK15

// PWM resolution
#define PWM_RESOLUTION          8
#define PWM_FREQUENCY           20000 // >= 20 Khz => inaudible noise for fans
#define PWM_MAX_DUTY_CYCLE      255


// Timer Definitions

// Do not use timer used by PWM pins when possible. See PinMap_PWM.
#define TIMER_TONE TIM6

// Do not use basic timer: OC is required
#define TIMER_SERVO TIM3 //TODO: advanced-control timers don't work


//// I2C Definitions
#define PIN_WIRE_SDA -1
#define PIN_WIRE_SCL -1

// UART Definitions
#define SERIAL_UART_INSTANCE 1
#define ENABLE_HWSERIAL1
#define ENABLE_HWSERIAL2

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
#define SERIAL_PORT_MONITOR Serial
#define SERIAL_PORT_HARDWARE Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
