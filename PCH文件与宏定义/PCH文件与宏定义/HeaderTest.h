//
//  HeaderTest.h
//  PCH文件与宏定义
//
//  Created by ZE KANG on 2017/8/12.
//  Copyright © 2017年 LRY. All rights reserved.
//

#ifndef HeaderTest_h
#define HeaderTest_h


#endif /* HeaderTest_h */


//1.获取屏幕宽度与高度
//#define SCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
//#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height


//需要横屏或者竖屏，获取屏幕宽度与高度
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上

#define SCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define SCREENH_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define SCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif


//2.获取通知中心
#define LRNotificationCenter [NSNotificationCenter defaultCenter]

//3.设置随机颜色
#define LRRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

//4.设置RGB颜色/设置RGBA颜色
#define LRRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define LRRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
// clear背景颜色
#define LRClearColor [UIColor clearColor]

//5.自定义高效率的 NSLog
#ifdef DEBUG
#define LRLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define LRLog(...)

#endif

//6.弱引用/强引用
#define LRWeakSelf(type)  __weak typeof(type) weak##type = type;
#define LRStrongSelf(type)  __strong typeof(type) type = weak##type;

//7.设置 view 圆角和边框
#define LRViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//8.由角度转换弧度 由弧度转换角度
#define LRDegreesToRadian(x) (M_PI * (x) / 180.0)
#define LRRadianToDegrees(radian) (radian*180.0)/(M_PI)

//9.设置加载提示框（第三方框架：Toast）
#define LRToast(str)              CSToastStyle *style = [[CSToastStyle alloc] initWithDefaultStyle]; \
[kWindow  makeToast:str duration:0.6 position:CSToastPositionCenter style:style];\
kWindow.userInteractionEnabled = NO; \
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{\
kWindow.userInteractionEnabled = YES;\
});\

//10.设置加载提示框（第三方框架：MBProgressHUD）
// 加载
#define kShowNetworkActivityIndicator() [UIApplication sharedApplication].networkActivityIndicatorVisible = YES
// 收起加载
#define HideNetworkActivityIndicator()      [UIApplication sharedApplication].networkActivityIndicatorVisible = NO
// 设置加载
#define NetworkActivityIndicatorVisible(x)  [UIApplication sharedApplication].networkActivityIndicatorVisible = x

#define kWindow [UIApplication sharedApplication].keyWindow

#define kBackView         for (UIView *item in kWindow.subviews) { \
if(item.tag == 10000) \
{ \
[item removeFromSuperview]; \
UIView * aView = [[UIView alloc] init]; \
aView.frame = [UIScreen mainScreen].bounds; \
aView.tag = 10000; \
aView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.3]; \
[kWindow addSubview:aView]; \
} \
} \

#define kShowHUDAndActivity kBackView;[MBProgressHUD showHUDAddedTo:kWindow animated:YES];kShowNetworkActivityIndicator()


#define kHiddenHUD [MBProgressHUD hideAllHUDsForView:kWindow animated:YES]

#define kRemoveBackView         for (UIView *item in kWindow.subviews) { \
if(item.tag == 10000) \
{ \
[UIView animateWithDuration:0.4 animations:^{ \
item.alpha = 0.0; \
} completion:^(BOOL finished) { \
[item removeFromSuperview]; \
}]; \
} \
} \

#define kHiddenHUDAndAvtivity kRemoveBackView;kHiddenHUD;HideNetworkActivityIndicator()


//11.获取view的frame/图片资源
//获取view的frame（不建议使用）
//#define kGetViewWidth(view)  view.frame.size.width
//#define kGetViewHeight(view) view.frame.size.height
//#define kGetViewX(view)      view.frame.origin.x
//#define kGetViewY(view)      view.frame.origin.y

//获取图片资源
#define kGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]


//12.获取当前语言
#define LRCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//13.使用 ARC 和 MRC
#if __has_feature(objc_arc)
// ARC
#else
// MRC
#endif

//14.判断当前的iPhone设备/系统版本
//判断是否为iPhone
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

//判断是否为iPad
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是否为ipod
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

// 判断是否为 iPhone 5SE
#define iPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

// 判断是否为iPhone 6/6s
#define iPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

// 判断是否为iPhone 6Plus/6sPlus
#define iPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

//获取系统版本
#define IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))

//15.判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//16.沙盒目录文件
//获取temp
#define kPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//17.GCD 的宏定义
//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);





#pragma mark - 2




/*********************屏幕适配*********************************/
#define kScreenWidth          [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight         [[UIScreen mainScreen] bounds].size.height
#define kScreen_Frame       (CGRectMake(0, 0 ,kScreenWidth,kScreenHeight))

//#define GRJMainColor [UIColor colorWithRed: (41) / 255.0 green:(179) / 255.0 blue:(157) / 255.0 alpha:1]
#define GRJMainColor  [UIColor colorWithHexString:@"#0fc3a6"]


#define kColor(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]


#define kHostURL @"http://120.76.121.174:8080/"
//#define kHostURL @"http://mytest.tunnel.2bdata.com/"

//http://112.74.183.216:8080/medical/v1_0/user/doSendCode.do'
//#define kHostURL @"http://112.74.183.216:8080/"
//#define kHostURL @"http://mytest1.tunnel.2bdata.com/"
//#define kHostURL @"http://mytest1.tunnel.2bdata.com/"
//#define kHostURL @"http://mytest1.tunnel.2bdata.com/"
//#define kHostURL @"http://192.168.0.124/"
//http://120.76.102.30:8080/
//#define kHostURL @"http://120.76.102.30:8080/"
#define kFilePath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0] stringByAppendingPathComponent:@"account.data"]

/**********************************   *************************************/

#define RYGolbal_Green_Colcor @"#0fc3a6"
/**********************************   *************************************/

//获取系统版本
#define IOS6 ([[[UIDevice currentDevice] systemVersion] floatValue] < 7.0) ? YES : NO
#define IOS7_OR_LATER  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) ? YES : NO
#define IOS8_OR_LATER  [[[UIDevice currentDevice] systemVersion] compare:@"8.0"] != NSOrderedAscending

//判断是否是Iphone5
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

//定义宽高和尺寸
#define SCREEN_WIDTH  [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size

//定义字体大小(正常)
#define FONT_9 [UIFont systemFontOfSize:9.0f]
#define FONT_11 [UIFont systemFontOfSize:11.0f]
#define FONT_12 [UIFont systemFontOfSize:12.0f]
#define FONT_13 [UIFont systemFontOfSize:13.0f]
#define FONT_14 [UIFont systemFontOfSize:14.0f]
#define FONT_15 [UIFont systemFontOfSize:15.0f]
#define FONT_16 [UIFont systemFontOfSize:16.0f]
#define FONT_18 [UIFont systemFontOfSize:18.0f]

//定义字体大小(加粗)
#define FONT_B_11 [UIFont boldSystemFontOfSize:11.0f]
#define FONT_B_12 [UIFont boldSystemFontOfSize:12.0f]
#define FONT_B_13 [UIFont boldSystemFontOfSize:13.0f]
#define FONT_B_14 [UIFont boldSystemFontOfSize:14.0f]
#define FONT_B_15 [UIFont boldSystemFontOfSize:15.0f]
#define FONT_B_16 [UIFont boldSystemFontOfSize:16.0f]
#define FONT_B_17 [UIFont boldSystemFontOfSize:17.0f]
#define FONT_B_18 [UIFont boldSystemFontOfSize:18.0f]
#define FONT_B_19 [UIFont boldSystemFontOfSize:19.0f]

#pragma mark - font

//普通字体
#define UIFontBigX [UIFont systemFontOfSize:18]
#define UIFontBig [UIFont systemFontOfSize:16]
#define UIFontDefault [UIFont systemFontOfSize:14]
#define UIFontSmall [UIFont systemFontOfSize:12]
#define UIFontSmallX [UIFont systemFontOfSize:10]
#define UIFontSmallXX [UIFont systemFontOfSize:8]

//粗体
#define UIFontBigXBold [UIFont boldSystemFontOfSize:18]
#define UIFontBigBold [UIFont boldSystemFontOfSize:16]
#define UIFontDefaultBold [UIFont boldSystemFontOfSize:14]
#define UIFontSmallBold [UIFont boldSystemFontOfSize:12]
#define UIFontSmallXBold [UIFont boldSystemFontOfSize:10]

#pragma mark - color

/* 系统控件的默认高度 */
#define StatusBarHeight   (20.f)
#define NavBarHeight      (44.f)
#define BottomBarHeight   (49.f)
#define TopBarHeight      (IOS7_OR_LATER ? StatusBarHeight + NavBarHeight : NavBarHeight)
#define ContentHeight     APP_HEIGHT - TopBarHeight - BottomBarHeight
#define TableViewCellDefaultHeight (44.f)
#define KeyboardHeightEnglish  (216.f)
#define KeyboardHeightChinese  (252.f)

//主色调
#define UIColorBlue UIColorFromRGB(0x1f9fcf)
#define UIColorBlueLight UIColorFromRGB(0x41c4f6)
#define UIColorBlueDark UIColorFromRGB(0x2f7faf)

//字体颜色
#define UIColorFontDefault UIColorFromRGB(0x515567)
#define UIColorFontGray UIColorFromRGB(0x8f8f8f)
#define UIColorFontBlue UIColorFromRGB(0x3f4f7f)
#define UIColorFontBlueLight UIColorFromRGB(0x1f9fcf)
#define UIColorFontRed UIColorFromRGB(0xaf4f3f)
#define UIColorFontGreen UIColorFromRGB(0x3fcf5f)

//背景色
#define UIColorBackground UIColorFromRGB(0xefefef)
#define UIColorBackgroundLight UIColorFromRGB(0xf7f7f7)
#define UIColorBackgroundDark UIColorFromRGB(0xcfcfcf)

#define UIColorBackgroundBlue UIColorFromRGB(0x1f9fcf)
#define UIColorBackgroundBlueLight UIColorFromRGB(0x41c4f6)
#define UIColorBackgroundBlueDark UIColorFromRGB(0x2f7faf)

#define UIColorBackgroundInfo UIColorFromRGB(0xefefef)
#define UIColorBackgroundWarn UIColorFromRGB(0xffefc7)
#define UIColorBackgroundError UIColorFromRGB(0xffe7e7)

//边框色
#define UIColorBorder UIColorFromRGB(0xcfcfcf)
#define UIColorBorderLight UIColorFromRGB(0xefefef)
#define UIColorBorderDark UIColorFromRGB(0xafafaf)

//#define RGBACOLOR(r,g,b,a)       [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
//定义cell中组的高度
#define JHGroupHeight 25

// 获得RGB颜色
#define JHColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0];

// 统一日志输出
#ifdef DEBUG  // 调试阶段
#define PCLog(...) NSLog(__VA_ARGS__)
#else // 发布阶段
#define PCLog(...)
#endif

// 通知
#define JHNotificationCenter [NSNotificationCenter defaultCenter]

// 识别真机和模拟器
#if TARGET_IPHONE_SIMULATOR
#define SIMULATOR 1
#elif TARGET_OS_IPHONE
#define SIMULATOR 0
#endif

// ios7导航栏高度
#define IOS7NavHeight  64

// 上传图片的大小
#define IMAGEXY 600

// 全局的appdelegate
#define HBDelegate  ((AppDelegate *) [[UIApplication sharedApplication] delegate])

// 判断是否为物流商
#define LOGISTICSLEVEL  ((NSString *) [[NSUserDefaults standardUserDefaults] objectForKey:IS_LOGISTICSLEVEL])

// 颜色
#define PCColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

// 随机色
#define PCRandomColor PCColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))

// 全局背景色
#define PCGlobalBg PCColor(239, 239, 239)

// cell的计算参数
// cell之间的间距
#define PCStatusCellMargin 10
// cell的内边距
#define PCStatusCellInset 10

//PNG JPG 图片路径
#define PATH_PNG(NAME)      [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"png"]
#define PATH_JPG(NAME)      [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"jpg"]
#define PATH(NAME,EXT)      [[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]

//加载图片
#define IMAGE_PNG(NAME)     [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define IMAGE_JPG(NAME)     [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define IMAGE(NAME,EXT)     [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]
#define IMAGE_NAMED(NAME)   [UIImage imageNamed:NAME]








