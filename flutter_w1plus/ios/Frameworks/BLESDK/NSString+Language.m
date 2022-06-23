//
//  NSString+Language.m
//  smuu
//
//  Created by smtlink smtlink on 2020/5/19.
//  Copyright © 2020 com.smtlink.smuu. All rights reserved.
//

#import "NSString+Language.h"

@implementation NSString (Language)
+ (NSString *)localString
{
    NSString *currentLanguage = [[NSLocale preferredLanguages] firstObject];
    
    NSString *languageStr;
    if ([currentLanguage rangeOfString:@"zh-Hant"].location != NSNotFound) {
        languageStr = @"zh_TW";
    } else if([currentLanguage rangeOfString:@"zh-Hans"].location != NSNotFound) {
        languageStr = @"zh_CN";
    } else if([currentLanguage rangeOfString:@"en"].location != NSNotFound) {
        languageStr = @"en_US";
    } else if([currentLanguage rangeOfString:@"es"].location != NSNotFound) {
        languageStr = @"es_SA";//西班牙
    } else if([currentLanguage rangeOfString:@"de"].location != NSNotFound) {
        languageStr = @"de_DE";
    } else if([currentLanguage rangeOfString:@"fr"].location != NSNotFound) {
        languageStr = @"fr_FR";
    } else if([currentLanguage rangeOfString:@"pt"].location != NSNotFound) {
        languageStr = @"pt_PT";
    } else if([currentLanguage rangeOfString:@"ko"].location != NSNotFound) {
        languageStr = @"ko";//韩国语
    } else if([currentLanguage rangeOfString:@"ja"].location != NSNotFound) {
        languageStr = @"ja_JP";
    } else if([currentLanguage rangeOfString:@"ru"].location != NSNotFound) {
        languageStr = @"ru_RU";
    } else if([currentLanguage rangeOfString:@"ro"].location != NSNotFound) {
        languageStr = @"ro_RO";//罗马尼亚文
    } else if([currentLanguage rangeOfString:@"it"].location != NSNotFound) {
        languageStr = @"it_IT";
    } else if([currentLanguage rangeOfString:@"el"].location != NSNotFound) {
        languageStr = @"el_GR";//希腊语
    } else if([currentLanguage rangeOfString:@"he"].location != NSNotFound) {
        languageStr = @"iw_IL";//希伯来
    } else if([currentLanguage rangeOfString:@"nl"].location != NSNotFound) {
        languageStr = @"nl_NL";
    } else if([currentLanguage rangeOfString:@"pl"].location != NSNotFound) {
        languageStr = @"pl_PL";
    } else if([currentLanguage rangeOfString:@"tr"].location != NSNotFound) {
        languageStr = @"tr_TR";
    } else if([currentLanguage rangeOfString:@"cs"].location != NSNotFound) {
        languageStr = @"cs_CZ";
    } else if([currentLanguage rangeOfString:@"ms"].location != NSNotFound) {
        languageStr = @"ms_MY";//马来
    }else if([currentLanguage rangeOfString:@"id"].location != NSNotFound) {
        languageStr = @"id_ID";//印尼
    }else if([currentLanguage rangeOfString:@"ar"].location != NSNotFound) {
        languageStr = @"ar";//阿拉伯语阿拉伯语
    }else if([currentLanguage rangeOfString:@"th-CN"].location != NSNotFound) {
        languageStr = @"th_TH";//泰语
    }else{
        languageStr = @"en_US";
    }
    
    return languageStr;
}

+ (NSString*)getIphoneLanguage
{
    NSString *currentLanguage = [[NSLocale preferredLanguages] firstObject];
    
    NSString *languageStr = currentLanguage;
    if ([currentLanguage rangeOfString:@"zh-Hant"].location != NSNotFound) {
        languageStr = @"中文";
    } else if([currentLanguage rangeOfString:@"zh-Hans"].location != NSNotFound) {
        languageStr = @"中文";
    } else if([currentLanguage rangeOfString:@"en"].location != NSNotFound) {
        languageStr = @"英文";
    } else if([currentLanguage rangeOfString:@"es"].location != NSNotFound) {
        languageStr = @"西班牙语";
    } else if([currentLanguage rangeOfString:@"de"].location != NSNotFound) {
        languageStr = @"德语";
    } else if([currentLanguage rangeOfString:@"fr"].location != NSNotFound) {
        languageStr = @"法语";
    } else if([currentLanguage rangeOfString:@"pt"].location != NSNotFound) {
        languageStr = @"葡萄牙语";
    } else if([currentLanguage rangeOfString:@"ko"].location != NSNotFound) {
        languageStr = @"韩国语";
    } else if([currentLanguage rangeOfString:@"ja"].location != NSNotFound) {
        languageStr = @"日语";
    } else if([currentLanguage rangeOfString:@"ru"].location != NSNotFound) {
        languageStr = @"俄语";
    } else if([currentLanguage rangeOfString:@"ro"].location != NSNotFound) {
        languageStr = @"罗马尼亚文";
    } else if([currentLanguage rangeOfString:@"it"].location != NSNotFound) {
        languageStr = @"意大利语";
    } else if([currentLanguage rangeOfString:@"el"].location != NSNotFound) {
        languageStr = @"希腊语";
    } else if([currentLanguage rangeOfString:@"he"].location != NSNotFound) {
        languageStr = @"he_HE";
    } else if([currentLanguage rangeOfString:@"nl"].location != NSNotFound) {
        languageStr = @"荷兰语";
    } else if([currentLanguage rangeOfString:@"pl"].location != NSNotFound) {
        languageStr = @"波兰语";
    } else if([currentLanguage rangeOfString:@"tr"].location != NSNotFound) {
        languageStr = @"土耳其";
    } else if([currentLanguage rangeOfString:@"cs"].location != NSNotFound) {
           languageStr = @"捷克";
    } else if([currentLanguage rangeOfString:@"ms"].location != NSNotFound) {
        languageStr = @"马来";
    }else if([currentLanguage rangeOfString:@"id"].location != NSNotFound) {
        languageStr = @"印尼";
    }else if([currentLanguage rangeOfString:@"ar"].location != NSNotFound) {
        languageStr = @"阿拉伯语";
    }else if([currentLanguage rangeOfString:@"iw"].location != NSNotFound) {
        languageStr = @"希伯来文";
    }
    return languageStr;
    
}



@end
