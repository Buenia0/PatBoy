#pragma once
#include "Memory.h"

/**************************************************************************//**
 *
 * \brief Specific memory type that implements the MBC3 chip
 *
******************************************************************************/

class MBC3 : public MemoryChip {
	public:
		MBC3(Memory* memory, Cartridge* cartridge);
		byte read(word address) final override;
		void write(word address, byte data) final override;
    
	private:
		const byte SPECIAL_ROM_BANKS[4] = {0x00};
		const word RAM_BANK_SIZE		= 0x2000;
		const word ROM_BANK_SIZE		= 0x4000;


		byte currentRAMBank;
		byte currentROMBank;

		byte* ram;
		bool ramEnabled;

		byte readFromRamBank(word address);
		byte readFromRomBank(word address);

		void writeToRamBank(word address, byte data);
		void setRomBank(byte data);
		void setRamBank(byte data);
};
