//
//  NSString+Language.h
//  smuu
//
//  Created by smtlink smtlink on 2020/5/19.
//  Copyright © 2020 com.smtlink.smuu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Language)
+ (NSString *)localString;
+ (NSString*)getIphoneLanguage;

@end

NS_ASSUME_NONNULL_END
