//
//  RTKOTADeviceInfo.h
//  RTKOTASDK
//
//  Created by jerome_gu on 2020/3/9.
//  Copyright © 2022 Realtek. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef RTK_SDK_IS_STATIC_LIBRARY
#import "libRTKLEFoundation.h"
#import "RTKOTAUpgradeBin.h"
#else
#import <RTKLEFoundation/RTKLEFoundation.h>
#import <RTKOTASDK/RTKOTAUpgradeBin.h>
#endif


typedef enum : NSUInteger {
    RTKOTAProtocolTypeGATTSPP  =  0x0000,
    RTKOTAProtocolTypeGATT  =   0x0010,
    RTKOTAProtocolTypeSPP =   0x0011,
} RTKOTAProtocolType;


/**
 * Values that represents the ear bud information about the remote device.
 */
typedef enum : NSUInteger {
    RTKOTAEarbudUnkown,     ///< The earbud info is not known.
    RTKOTAEarbudPrimary,    ///< The earbud is primary bud.
    RTKOTAEarbudSecondary,  ///< The earbud is secondary bud.
    RTKOTAEarbudSingle,     ///< The earbud is a single bud.
} RTKOTAEarbud;


/**
 * Values that represents the bank info about the remote device.
 */
typedef enum : NSInteger {
    RTKOTABankTypeInvalid   =   -1, ///< The bank info is not valid.
    RTKOTABankTypeSingle    = 0x00, ///< A single bank.
    RTKOTABankTypeBank0,            ///< The primary Bank in a dual bank case.
    RTKOTABankTypeBank1,            ///< The secondary Bank in a dual bank case.
} RTKOTABankType;

/**
 * Values that represents the encryption method used for image byte encrption.
 */
typedef enum : NSInteger {
    RTKOTAImageDataEncryptionMethod_first16Bytes,   ///< Encrypt first 16 bytes of a image byte packet.
    RTKOTAImageDataEncryptionMethod_allBytes,       ///< Encrypt all bytes of a image byte packet.
} RTKOTAImageDataEncryptionMethod;



NS_ASSUME_NONNULL_BEGIN

/**
 * An object that you use to access information related to upgrade and installed images of a remote connected device.
 *
 * @discussion Use an @c RTKOTADeviceInfo object to access information about what configurations of device, how can upgrade the device, what images installed in this device. You can get a @c RTKOTADeviceInfo object by call @c -getOTAInformationWithCompletionHandler: on a @c RTKDFURoutine conformed object. Do not create @c RTKOTADeviceInfo objects directly.
 *
 * @c RTKOTADeviceInfo provides several methods in @c ImageVerification category for check whether images is available to be upgraded, and select the appropriate images to be upgrade. You can use thoese methods to check validation and select images for upgarde, before start upgrade really.
 */
@interface RTKOTADeviceInfo : NSObject

/**
 * Return the DFU implementation version number of a device.
 */
@property (readonly) NSUInteger OTAVersion;

@property (readonly) NSUInteger securityVersion;

/**
 * Return the address value of a device.
 */
@property (readonly) BDAddressType bdAddress;

/**
 * Return the address value of a device companion.
 *
 * @discussion May return zero if the device is not a member of RWS pair.
 */
@property (readonly) BDAddressType companionBDAddress;

@property (readonly) uint16_t appVersion;
@property (readonly) uint16_t patchVersion;

/**
 * Return a string representation of the underlying ACL link key.
 */
@property (readonly) NSString *linkKey;

/**
 * Return the size in bytes of temp buffer used for upgrade.
 *
 * @discussion unit is 4k.
 */
@property (readonly) NSUInteger tempBufferSize;

/**
 * Return which bank the device current used.
 *
 * @discussion A device which could be able to be upgrade supports either "Bank Switching" or "Temp area memory" manner, can be determined by this property value. If the value is @c RTKOTABankTypeSingle, the device uses "Temp area memory". If this value is @c RTKOTABankTypeBank0 or @c RTKOTABankTypeBank1 , device uses "Bank Switching" manner. When upgrading a "Bank Switching" device, images bytes will saved at the bank current not used.
 */
@property (readonly) RTKOTABankType activeBank;

@property (readonly) NSUInteger appFreeBank;
@property (readonly) NSUInteger patchFreeBank;

/**
 * Returns a boolean value that indicating whether "Buffer Check" is supported by device.
 *
 * @discussion This is used for image bytes transmission.
 */
@property (readonly) BOOL bufferCheckEnable;

/**
 * Returns a boolean value that indicating whether "AES encryption" is supported by device.
 *
 * @discussion This is used for image bytes transmission.
 */
@property (readonly) BOOL AESEnable;

/**
 * Returns the encryption mode that control how bytes is encrypted when be send to device.
 *
 * @discussion This is used for image bytes transmission.
 */
@property (readonly) RTKOTAImageDataEncryptionMethod encryptionMode;


@property (readonly) BOOL copyImage;

/**
 * Returns a boolean value that indicating whether device can receive multiple images at a time.
 *
 * @discussion This is used for image bytes transmission.
 */
@property (readonly) BOOL updateMultiImages;

/**
 * Returns a boolean value that indicating whether device support normal OTA.
 *
 * @discussion This is used for image bytes transmission.
 */
@property (readonly) BOOL supportNormalOTA;


/**
 * Indicates whether the device can upgrade VP. (For AT)
 *
 * @discussion If this value is @c YES,  you could set  @c isVPMode.
 */
@property (nonatomic, readonly) BOOL canUpdateVP;


@property (readonly) NSUInteger maxBufferSize;

/* RWS Upgrade related properties */
/**
 * Returns a boolean value indicating whether the device is one of RWS pair.
 *
 * @discussion If this property value is @c YES , to start upgrade, you call @c -upgradeWithImagesForPrimaryBud:imagesForSecondaryBud: or @c -upgradeWithBinaryFileAtPath: with file containing images for both primary and secondary bud.
 */
@property (readonly) BOOL isRWSMember;

/**
 * Returns the bud type of a device.
 *
 * @discussion If @c isRWSMember return @c YES , the value of this property should be either @c RTKOTAEarbudPrimary or @c RTKOTAEarbudSecondary .
 */
@property (readonly) RTKOTAEarbud budType;

/**
 * Returns a boolean value Indicating whether the device is in engaged with companion device.
 *
 * @discussion If this value is @c YES , when you call upgrade methods on @c RTKDFUUpgrade object, both the pair of devices will be upgraded at a time.
 */
@property (readonly) BOOL engaged;


/**
 * Indicate whether this device have received images right now, but not be activated.
 */
@property (readonly) BOOL upgradedCurrently;


@property (readonly) RTKOTAProtocolType protocolType;

/**
 * Returns an array containing images installed in remote device.
 *
 * @discussion You can use this property to access what type and what version of images are installed at connected device.
 */
@property (readonly) NSArray <RTKOTABin*> *bins;

@end


@interface RTKOTADeviceInfo (ImageVerification)

/**
 * Check the images and returns a boolean value that indicates if those images is valid to be ugprade to device.
 *
 * @discussion This method will check if image is with older version.
 * @see -isAvailableForUpgradeOfImages:checkingImageVersion:returnError:
 */
- (BOOL)isAvailableForUpgradeOfImages:(NSArray <RTKOTAUpgradeBin*> *)images
                          returnError:(NSError **)error;

/**
 * Check the images and returns a boolean value that indicates if those images is valid to be ugprade to device.
 *
 * @param images The images to be check. The images could be returned by call @c RTKOTAUpgradeBin image extract methods.
 * @param yesOrNo Indicating whether old image is not allowed.
 * @param error A @c NSError object pointer used to return a error object if check fail.
 *
 * @return @c YES if the passed images could be upgraded, @c NO otherwise.
 * @discussion This method check each member of @c images, confirming if each image match the device and pass the version rule. If check failed, this method return @c NO, and the @c error pointer is set to a error object describing the cause.
 *
 * Before call upgrade methods to start upgrade, you can call this method to check if your images is able to be upgraded. If you call upgrade methods with unavailable images, @c RTKDFUUpgrade will report upgrade failure immediately.
 *
 * Use this method for device that is not a member of RWS pair.
 *
 * @see -isAvailableForUpgradeOfImages:returnError:
 */
- (BOOL)isAvailableForUpgradeOfImages:(NSArray <RTKOTAUpgradeBin*> *)images
                 checkingImageVersion:(BOOL)yesOrNo
                          returnError:(NSError **)error;


/**
 * Check the images and returns a boolean value that indicates if those images is valid to be ugprade to device.
 *
 * @see -isAvailableForUpgradeOfImagesForPrimaryBud:imagesForSecondaryBud:checkingImageVersion:returnError:
 */
- (BOOL)isAvailableForUpgradeOfImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary
                             imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary
                                       returnError:(NSError **)error;

/**
 * Check the images and returns a boolean value that indicates if those images is valid to be ugprade to device.
 *
 * @param imagesForPrimary The images for primary bud to be check. The images could be returned by call @c RTKOTAUpgradeBin image extract methods.
 * @param imagesForSecondary The images for secondary bud to be check. The images could be returned by call @c RTKOTAUpgradeBin image extract methods.
 * @param error A @c NSError object pointer used to return a error object if check fail.
 * @return @c YES if the passed images could be upgraded, @c NO otherwise.
 * @discussion This method check each image of @c primaryImages and @c secondaryImages , confirming if each image match the device and pass the version rule. If check failed, this method return @c NO, and the @c error pointer is set to a error object describing the cause.
 *
 * Before call upgrade methods to start upgrade, you can call this method to check if your images is able to be upgraded. If you call upgrade methods with unavailable images, @c RTKDFUUpgrade will report upgrade failure immediately.
 *
 * Use this method for device that is not a member of RWS pair.
 */
- (BOOL)isAvailableForUpgradeOfImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary
                             imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary
                              checkingImageVersion:(BOOL)yesOrNo
                                       returnError:(NSError **)error;

/**
 * Compare the bank information of the images and device, select and return the applicable images for upgrade.
 *
 * @param images The images to be select. Should pass @c -isAvailableForUpgradeOfImages: method. The images could be returned by call @c RTKOTAUpgradeBin image extract methods.
 * @discussion For a device supporting "Dual Bank" feature, and images applying to both Bank are provided, only images for current unused bank will be actually send to this device. This method return those available images.
 * For a device not supporting "Dual Bank", the images you passed should not applying to "Dual Bank" device.
 *
 * Typically, this method returns a subset of the passed @c images .
 */
- (NSArray <RTKOTAUpgradeBin*> *)applicableImagesSelectedFromImages:(NSArray <RTKOTAUpgradeBin*> *)images;

/**
 * Compare the bank information and bud type of the images and device, select and return the applicable images for upgrade.
 *
 * @param imagesForPrimary The images for primary bud to be select. Should pass @c -isAvailableForUpgradeOfImagesForPrimaryBud:imagesForSecondaryBud: method. The images could be returned by call @c RTKOTAUpgradeBin image extract methods.
 * @param imagesForSecondary The images for secondary bud to be select. Should pass @c -isAvailableForUpgradeOfImagesForPrimaryBud:imagesForSecondaryBud: method. The images could be returned by call @c RTKOTAUpgradeBin image extract methods.
 * @discussion Additional to what @c -applicableImagesSelectedFromImages: does, this method considers what bud type this device is, and return only images applying to this bud type.
 *
 * Typically, this method returns a subset of the passed @c primaryImages or @c secondaryImages .
 */
- (NSArray <RTKOTAUpgradeBin*> *)applicableImagesSelectedFromImagesForPrimaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForPrimary
                                                           imagesForSecondaryBud:(NSArray <RTKOTAUpgradeBin*> *)imagesForSecondary;

@end


NS_ASSUME_NONNULL_END
