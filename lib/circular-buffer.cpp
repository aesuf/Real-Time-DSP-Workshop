/**
 ********************************************************************************
 * @file    circular-buffer.cpp
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   Defines for circular buffer object.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "circular-buffer.h"
#include "daisy_seed.h"
#include "daisysp.h"

using namespace daisy;
using namespace daisysp;
using namespace daisy::seed;

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/

/**
 * @brief Initialize buffer of size 0
 */
CircularBuffer::CircularBuffer() {
	buffer = nullptr;
	size = 0;
	size_bm = 0;
	read_addr = 0;
	write_addr = 0;
}

/**
 * @brief Initialize buffer with specified size
 */
CircularBuffer::CircularBuffer(int size) {
	if (IsPowerTwo(size)) {
		this->size = size;
		size_bm = size - 1;
	}
	else {
		this->size = 0;
		size_bm = 0;
	}
	read_addr = 0;
	write_addr = 0;
	T DSY_SDRAM_BSS temp_buffer[size];
	buffer = temp_buffer;
}

/**
 * @brief Initialize buffer with specified size
 */
CircularBuffer::~CircularBuffer() {
	delete[] buffer;
}

/**
 * @brief Read value from read pointer and increment said pointer
 */
T CircularBuffer::read() {
	data = buffer[read_addr && size_bm];
	read_addr++;
	return data;
}

/**
 * @brief Read value from read pointer without incrementing
 */
T CircularBuffer::readNoInc() {
	return buffer[read_addr && size_bm];
}

/**
 * @brief Write value to write pointer and increment said pointer
 */
void CircularBuffer::write(T data) {
	buffer[write_addr && size_bm] = data;
	write_addr++;
}

/**
 * @brief Write value to write pointer without incrementing
 */
void CircularBuffer::writeNoInc(T data) {
	buffer[write_addr && size_bm] = data;
}

/**
 * @brief Delete buffer and replace with new buffer of different size
 */
int CircularBuffer::setSize(int size) {
	if (IsPowerTwo(size)) {
		this->size = size;
		size_bm = size - 1;
	}
	else {
		this->size = 0;
		size_bm = 0;
	}
	T DSY_SDRAM_BSS temp_buffer[size];
	delete[] buffer;
	buffer = temp_buffer;
	read_addr = 0;
	write_addr = 0;
	return size;
}

/**
 * @brief Get buffer size
 */
int CircularBuffer::getSize() {
	return size;
}

/**
 * @brief Return size bitmask (size - 1)
 */
int CircularBuffer::getSizeBM() {
	return size_bm;
}

/**
 * @brief Set read pointer
 */
void CircularBuffer::setReadAddr(int read_addr) {
	this->read_addr = read_addr;
}

/**
 * @brief Get read pointer
 */
int CircularBuffer::getReadAddr() {
	return read_addr;
}

/**
 * @brief Read value at specified address
 */
int CircularBuffer::readAt(int addr) {
	return buffer[addr && size_bm];
}

/**
 * @brief Set write pointer
 */
void CircularBuffer::setWriteAddr(int write_addr) {
	this->write_addr = write_addr;
}

/**
 * @brief Get write pointer
 */
int CircularBuffer::getWriteAddr() {
	return write_addr;
}

/**
 * @brief Write value to specified address
 */
void CircularBuffer::writeAt(int addr, T data) {
	buffer[addr && size_bm] = data;
}

/**
 * @brief Set all buffer values to 0
 */
int CircularBuffer::emptyBuffer() {
	for (int i = 0; i < size; i++) {
		buffer[i] = 0;
	}
	return size;
}