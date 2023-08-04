//
// Created by oran on 8/4/2023.
//

#ifndef EFI_OS_BASE_H
#define EFI_OS_BASE_H
//
// https://github.com/tianocore/edk2/blob/master/MdePkg/Include/Base.h#L218
//

///
/// 128 bit buffer containing a unique identifier value.
/// Unless otherwise specified, aligned on a 64 bit boundary.
///
typedef struct {
    UINT32    Data1;
    UINT16    Data2;
    UINT16    Data3;
    UINT8     Data4[8];
} GUID;



#endif //EFI_OS_BASE_H
