//
// Created by oran on 8/4/2023.
//

//
// UEFI Spec Release 2.10 section 5.3.3 GPT Partition Entry Array
//

#ifndef EFI_OS_UEFIGPT_H
#define EFI_OS_UEFIGPT_H

#pragma pack(1)

typedef struct {
  UINT64            Signature;
  UINT32            Revision;
  UINT32            HeaderSize;
  UINT32            HeaderCRC32;
  UINT32            Reserved1;
  UINT64            MyLBA;
  UINT64            AlternateLBA;
  UINT64            FirstUsableLBA;
  UINT64            LastUsableLBA;
  GUID              DiskGUID;
  UINT64            PartitionEntryLBA;
  UINT32            NumberOfPartitionEntries;
  UINT32            SizeOfPartitionEntry;
  UINT32            PartitionEntryArrayCRC32;
  UINT8             Reserved2[512 - 92];
}   GPT_HEADER;



typedef struct {
  EFI_GUID          PartitionTypeGUID;
  EFI_GUID          UniquePartitionGUID;
  EFI_LBA           StartingLBA;
  EFI_LBA           EndingLBA;
  UINT64            Attributes;
  CHAR16            PartitionName[36];
}   EFI_PARTITION_ENTRY;

#pragma pack()

#endif //EFI_OS_UEFIGPT_H
