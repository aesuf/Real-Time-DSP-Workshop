/*****************************************************************************
*
* File: "dsp.h"
* Author: Jackson Cornell
* Date: 5/9/22
* Description: Drivers for peripherals and system for Real-Time DSP Workshop.
*
*****************************************************************************/

#pragma once
#ifndef DSP_H
#define DSP_H

#define SDRAM_ADDR 0xC0000000

// Global Daisy Seed hardware object
DaisySeed hw;

// Circular buffer class
template <class T>
class CircularBuffer {
	private:
		int size, read_addr, write_addr;
		T* buffer;
	public:
		CircularBuffer();
		CircularBuffer(int size);
		~CircularBuffer();
		T Read();
		T ReadNoInc();
		void Write(T data);
		void WriteNoInc(T data);
		void SetSize(int size);
		int GetSize();
		void SetReadAddr(int read_addr);
		int GetReadAddr();
		T Read();
		T ReadNoInc();
		T ReadAt(int addr);
		void SetWriteAddr(int write_addr);
		int GetWriteAddr();
		void Write(T data);
		void WriteNoInc(T data);
		void WriteAt(int addr, T data);
		int EmptyBuffer();
};

// Drivers for ADC0-2 conected to potentiometers
void InitPots();
int GetPot1();
int GetPot2();
int GetPot3();
float GetPot1Float();
float GetPot2Float();
float GetPot3Float();

// Initialize Daisy Seed hardware object
void SysInit();

#endif