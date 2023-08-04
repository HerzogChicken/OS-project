//
// Created by oran on 8/4/2023.
//

//
// UEFI Spec Release 2.10 section 5.2.3 Protective MBR
//

#ifndef EFI_OS_PMBR_H
#define EFI_OS_PMBR_H

#define PMBR_SIGNATURE   0xAA55


#pragma pack(1)

//
// Table 5.3: Protective MBR
//
typedef struct {
  UINT8             BootIndicator;
  UINT8             StartingCHS[3];
  UINT8             OSType;
  UINT8             EndingCHS[3];
  UINT32            StartingLBA;
  UINT32            SizeInLBA;
}   PROTECTIVE_MBR_PARTITION_RECORD;

//
// Table 5.4: Protective MBR Partition Record protecting the entire disk*
//
typedef struct {
  UINT8             BootCode[440];
  UINT32            UniqueMBRDiskSignature;
  UINT16            Unknown;
  PROTECTIVE_MBR_PARTITION_RECORD            PartitionRecord[4];
  UINT16            Signature;
//UINT8             Reserved[];
}   PROTECTIVE_MASTER_BOOT_RECORD;


#pragma pack()

#endif //EFI_OS_PMBR_H
