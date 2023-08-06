//
// Created by oran on 8/6/2023.
//

#include "../../../efi.h"

//
// Precomputed table for polynomial 0xedb88320.
//
static UINT32 Crc32Table[256];

/**

  Initialize the CRC32 lookup table

**/
VOID
Crc32InitTable (
  VOID
  )
{
  UINT32 Crc;
  for (UINT32 TableEntry = 0; TableEntry < 256; ++TableEntry) {
    Crc = TableEntry;
    for (UINT8 j = 8; j > 0; j--) {
      if (Crc & 1) {
        Crc = (Crc >> 1) ^ 0xedb88320UL;
      } else {
        Crc >>= 1;
      }
    }
    Crc32Table[TableEntry] = Crc;
  }
}

/**

  Compute CRC32 value for input data

**/
//
// TODO: check if the init table check needs to be atomic
//
EFI_STATUS
EFIAPI
CalculateCrc32 (
  IN  VOID            *Buffer,
  IN  UINTN           BufferSize,
  OUT UINT32          *CrcOut
  )
{
  static BOOLEAN IsTableInit = FALSE;

  if(Buffer == NULL || BufferSize == 0 || CrcOut == NULL)
    return EFI_INVALID_PARAMETER;

  if(!IsTableInit) {
    Crc32InitTable();
    IsTableInit = TRUE;
  }

  UINT32 Crc = 0xffffffff;
  UINT8 *Ptr = Buffer;
  for(UINT8 i = 0 ; i < BufferSize ; ++i, ++Ptr) {
    UINT8 byte = *Ptr++;
    Crc = (Crc >> 8) ^ Crc32Table[(Crc ^ byte) & 0xFF];
  }
  *CrcOut = Crc ^ 0xffffffff;
  return EFI_SUCCESS;
}