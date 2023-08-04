//
// Created by oran on 8/2/2023.
//

//
// UEFI Spec Release 2.10 section 5.2.1 Legacy Master Boot Record (MBR)
//
#ifndef EFI_OS_MBR_H
#define EFI_OS_MBR_H

#define MBR_SIGNATURE   0xAA55


#pragma pack(1)
///
/// MBR Partition Entry
///
typedef struct {
  UINT8             BootIndicator;
  UINT8             StartHead;
  UINT8             StartSector;
  UINT8             StartTrack;
  UINT8             OSIndicator;
  UINT8             EndHead;
  UINT8             EndSector;
  UINT8             EndTrack;
  UINT8             StartingLBA[4];
  UINT8             SizeInLBA[4];
}   MBR_PARTITION_RECORD;

///
/// MBR Partition Table
///
typedef struct {
  UINT8                 BoostStrapCode[440];
  UINT8                 UniqueMbrSignature[4];
  UINT8                 Unknown[2];
  MBR_PARTITION_RECORD  Partition[4];
  UINT16                Signature;
}   MASTER_BOOT_RECORD;

#pragma pack()

#endif //EFI_OS_MBR_H
