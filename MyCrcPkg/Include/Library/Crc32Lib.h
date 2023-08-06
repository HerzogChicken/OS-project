//
// Created by oran on 8/6/2023.
//
/** @file
  CRC32 library functions and definitions.

  This library provides CRC32 calculation routines required for various
  UEFI operations.
**/
#ifndef EFI_OS_CRC32LIB_H
#define EFI_OS_CRC32LIB_H

#include "../../../efi.h"


/**
  Compute the CRC32 value of a data buffer.

  @param[in]  Buffer         Pointer to the new buffer on which the CRC32 should be computed.
  @param[in]  BufferSize     Size of the buffer.
  @param[out] CrcOut         The computed CRC32 for the target data.

  @retval  EFI_SUCCESS             Successfully calculated the CRC32 of the data buffer.
  @retval  EFI_INVALID_PARAMETER   At least one parameter is invalid, CRC32 is not calculated.

**/
EFI_STATUS
EFIAPI
CalculateCrc32 (
  IN  VOID            *Buffer,
  IN  UINTN           BufferSize,
  OUT UINT32          *CrcOut
  );


#endif //EFI_OS_CRC32LIB_H
