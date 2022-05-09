/*****************************************************************************
*
* File: "dsp.cpp"
* Author: Jackson Cornell
* Date: 5/9/22
* Description: Drivers for peripherals and system for Real-Time DSP Workshop.
*
*****************************************************************************/

#include "dsp.h"
#include "daisy_seed.h"
#include "daisysp.h"

using namespace daisy;
using namespace daisysp;
using namespace daisy::seed;

/********************** CIRCULAR BUFFER **************************/

// Initialize buffer of size 0
CircularBuffer::CircularBuffer() {
	buffer = nullptr;
	size = 0;
	read_addr = 0;
	write_addr = 0;
}

// Initialize buffer with size
CircularBuffer::CircularBuffer(int size) {
	this->size = size;
	read_addr = 0;
	write_addr = 0;
	T DSY_SDRAM_BSS temp_buffer[size];
	buffer = temp_buffer;
}

// Circular buffer deconstructor
CircularBuffer::~CircularBuffer() {
	delete[] buffer;
}

// Read value from read pointer and increment said pointer
T CircularBuffer::Read() {
	data = buffer[read_addr%size];
	read_addr++;
	return data;
}

// Read value from read pointer without incrementing
T CircularBuffer::ReadNoInc() {
	return buffer[read_addr%size];
}

// Write value to write pointer and increment said pointer
void CircularBuffer::Write(T data) {
	buffer[write_addr%size] = data;
	write_addr++;
}

// Write value to write pointer without incrementing
void CircularBuffer::WriteNoInc(T data) {
	buffer[write_addr%size] = data;
}

// Delete buffer and replace with new buffer of different size
void CircularBuffer::SetSize(int size) {
	this->size = size;
	T DSY_SDRAM_BSS temp_buffer[size];
	delete[] buffer;
	buffer = temp_buffer;
	read_addr = 0;
	write_addr = 0;
}

// Get buffer size
int CircularBuffer::GetSize() {
	return size;
}

// Set read pointer
void CircularBuffer::SetReadAddr(int read_addr) {
	this->read_addr = read_addr;
}

// Get read pointer
int CircularBuffer::GetReadAddr() {
	return read_addr;
}

// Read value at specified address
int CircularBuffer::ReadAt(int addr) {
	return buffer[addr%size];
}

// Set write pointer
void CircularBuffer::SetWriteAddr(int write_addr) {
	this->write_addr = write_addr;
}

// Get write pointer
int CircularBuffer::GetWriteAddr() {
	return write_addr;
}

// Write value to specified address
void CircularBuffer::WriteAt(int addr, T data) {
	buffer[addr%size] = data;
}

// Set all buffer values to 0
int CircularBuffer::EmptyBuffer() {
	for (int i = 0; i < size; i++) {
		buffer[i] = 0;
	}
	return size;
}

/*******************************************************************/

/************************ MISC. SYSTEM *****************************/

// Initializes ADC0-2 connected to potentiometers
void InitPots() {
	AdcChannelConfig my_adc_config[3];
	my_adc_config[0].InitSingle(A0);
	my_adc_config[1].InitSingle(A1);
	my_adc_config[2].InitSingle(A2);
	hw.adc.Init(my_adc_config, 3);
	hw.adc.Start();
}

// Get int value of pot1
int GetPot1() {
	return hw.adc.Get(0);
}

// Get int value of pot2
int GetPot2() {
	return hw.adc.Get(1);
}

// Get int value of pot3
int GetPot3() {
	return hw.adc.Get(2);
}

// Get float value of pot1
float GetPot1Float() {
	return hw.adc.GetFloat(0);
}

// Get float value of pot2
float GetPot2Float() {
	return hw.adc.GetFloat(1);
}

// Get float value of pot3
float GetPot3Float() {
	return hw.adc.GetFloat(2);
}

// Initializes system with Daisy Seed hardware object
void SysInit() {
	hw.Init();
}

/*****************************************************************/