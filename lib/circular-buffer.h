/**
 ********************************************************************************
 * @file    circular-buffer.h
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   Circular buffer object declaration.
 ********************************************************************************
 */

#ifndef POTENTIOMETER_INTF_H_
#define POTENTIOMETER_INTF_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/

/************************************
 * MACROS AND DEFINES
 ************************************/

/**
 * @brief Starting SRAM address
 */
#define SDRAM_ADDR 0xC0000000

/************************************
 * TYPEDEFS
 ************************************/

template <class T>
class CircularBuffer {
	private:
		int size, read_addr, write_addr, size_bm;
		T* buffer;
	public:
		CircularBuffer();
		CircularBuffer(int size);
		~CircularBuffer();
		T read();
		T readNoInc();
		void write(T data);
		void writeNoInc(T data);
		int setSize(int size);
		int getSize();
		int getSizeBM();
		void setReadAddr(int read_addr);
		int getReadAddr();
		T read();
		T readNoInc();
		T readAt(int addr);
		void setWriteAddr(int write_addr);
		int getWriteAddr();
		void write(T data);
		void writeNoInc(T data);
		void writeAt(int addr, T data);
		int emptyBuffer();
};

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/


#ifdef __cplusplus
}
#endif

#endif 