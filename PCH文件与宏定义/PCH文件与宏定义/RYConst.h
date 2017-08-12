//
//  RYConst.h
//  PCH文件与宏定义
//
//  Created by ZE KANG on 2017/8/12.
//  Copyright © 2017年 LRY. All rights reserved.
//

//#import <Foundation/Foundation.h>
//
//@interface RYConst : NSObject
//
//@end
//


#import <UIKit/UIKit.h>

//宏定义 直接写在 .h 文件中即可,不需要在 .m 文件中做任何操作
#define RYURL @"http://219.135.58.4:5000/Home/getVideo"


//const常量  要在 .m 文件中赋值/实现方法
UIKIT_EXTERN CGFloat const RYAge;
UIKIT_EXTERN NSString *const RYID;


