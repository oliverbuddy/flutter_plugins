//
//  RTKBTGeneralDefines.h
//  RTKLEFoundation
//
//  Created by jerome_gu on 2019/4/10.
//  Copyright © 2022 Realtek. All rights reserved.
//

#ifndef RTKBTGeneralDefines_h
#define RTKBTGeneralDefines_h

#import <Foundation/Foundation.h>

/**
 * A block type to be called when some task did complete.
 *
 * @param success Indicating if task finish successfully.
 * @param error Contains a error object if task failed.
 *
 * @discussion By convention, when a block of this type get called, the @b success argument with YES set and @b error with nil set indicates that task succeed. If task fail, the @b success argument is set to NO, and @b error argument is probabaly set to a valid error object.
 */
typedef void(^RTKLECompletionBlock)(BOOL success, NSError *_Nullable error);


#pragma pack(push, 1)

/**
 * A structure used to describe each byte of a BDAddress bytes.
 */
struct BDAddressByteStruct {
    uint8_t part0;
    uint8_t part1;
    uint8_t part2;
    uint8_t part3;
    uint8_t part4;
    uint8_t part5;
};

/**
 * A structure describe how a BDAddress byte is stored.
 */
typedef union {
    struct {
        uint64_t intValue : 48;
    } value;
    struct {
        uint16_t NAP;
        uint8_t UAP;
        uint32_t LAP : 24;
    } parts;
    struct BDAddressByteStruct components;
} BDAddressType;

#pragma pack(pop)


/// Check and return a boolean indicating if the passed value is a valid BDAddress value.
#define BDAddressIsValid(addr) ((addr).parts.NAP>0 && (addr).parts.UAP>0)

/// Check and return a boolean indicating if the two passed address value is equal.
#define BDAddressIsEqual(addr1, addr2) ((addr1).value.intValue == (addr2).value.intValue)

/// Return a NSString object which represent BDAddress in String format.
#define BDAddressString(addr) [NSString stringWithFormat:@"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", (addr).components.part0, (addr).components.part1, (addr).components.part2, (addr).components.part3, (addr).components.part4, (addr).components.part5]

#define BDAddressRandom ^BDAddressType(void){NSData *addrData = [NSData dataByRandomBytesWithLength:6]; \
BDAddressType *addr = (BDAddressType*)addrData.bytes; \
return *addr;\
}

#define BDAddressNull ^BDAddressType(void){\
BDAddressType addr; \
addr.value.intValue = 0; \
return addr;\
}

#endif /* RTKBTGeneralDefines_h */
