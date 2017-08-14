# PCH-Const-
PCH&amp;Const的宏定义与常量使用

详情请查看:
[ pch文件的使用, 头文件使用, 常量(const)的定义，以及一些常用的宏定义](http://blog.csdn.net/qq_19678579/article/details/77113286)

[TOC]


# 一. pch文件的创建

## 1. 右击选择 New File,出现下面界面，选择 iOS ->other->PCH File->next 
![创建](http://img.blog.csdn.net/20170812113025908?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)



##  2. 点击create,就会生成一个pch文件
![这里写图片描述](http://img.blog.csdn.net/20170812113138687?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)




## 3. 点击左侧栏中的工程名，显示如下界面，然后通过在搜索栏里查找Prefix Header文件，快速定位到pch,然后按照下面方式操作

![这里写图片描述](http://img.blog.csdn.net/20170812113209984?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 4. 填写路径

> 将pch文件拖进第三步弹出的框里面，pch的文件路径就会被填进去，但是这是绝对路径，如果你把项目移到另外一个地方，就会报错，找不到pch文件，所以需要把它转为相对路径，绝对路径格式：/Users/lixue/Desktop/项目名/项目名/PrefixHeader.pch，转化为相对路径
> 如下格式:  &emsp;<font color=red> $(SRCROOT)</font>  /项目名称/pch文件名（注意这里只有一个项目名） 
> 
![这里写图片描述](http://img.blog.csdn.net/20170812113554437?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)



## 5. 将下面的属性设置为yes 
![这里写图片描述](http://img.blog.csdn.net/20170812113728308?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


## 6. 完成
添加完成后 就可以在pch文件中定义宏等  添加完成以后 command + b 预编译就好了；

      预编译后的pch文件会被缓存起来，可以提高编译速度

![这里写图片描述](http://img.blog.csdn.net/20170812114056165?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)



<tr>
<tr>
<tr>
<tr>

----------


----------


----------




# 二. 头文件 ( Headerfile.h )

> 为了简洁代码,主要放一些 宏定义 :
> `#define LOADING_STR @"正在加载"`

## 1. 右击选择 New File,出现下面界面，选择 iOS ->Source->Header File->next 
![这里写图片描述](http://img.blog.csdn.net/20170812144537921?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


##  2. 点击create,就会生成一个.h文件
![这里写图片描述](http://img.blog.csdn.net/20170812144720675?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


## 3. 在 .h 文件中写宏定义代码
![这里写图片描述](http://img.blog.csdn.net/20170812144956943?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 4. 在 .pch 文件中导入头文件使用即可
![这里写图片描述](http://img.blog.csdn.net/20170812145142206?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


<tr>
<tr>
<tr>
<tr>

----------


----------


----------



# 三. 贯穿整个工程的全局常量定义( const )
>- 继承于NSObject的类
> - 一般来说总会有用到常量定义的地方，比如一个公共的url头，一个固定的id。定义好常量，便于随时修改，可以让代码更整洁。

1. 右击选择 New File,出现下面界面，选择 iOS ->Source->Header File->next 
![这里写图片描述](http://img.blog.csdn.net/20170812163646550?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 2. 选择 NSObject 类型
![这里写图片描述](http://img.blog.csdn.net/20170812163703074?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 3. 修改 .h 文件代码
![这里写图片描述](http://img.blog.csdn.net/20170812163716894?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 4. 修改 .m 文件代码
![这里写图片描述](http://img.blog.csdn.net/20170812163846991?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 5. import 进 .pch 文件中,或者在需要使用的 VC 中 import ,然后使用即可

![这里写图片描述](http://img.blog.csdn.net/20170812164257533?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMTk2Nzg1Nzk=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)


****
>- 可以直接用define来定义，也可以用extern关键字来定义，这样利于NSString的使用
>- define是不需要.m文件的，在头文件里定义好了就可以直接用，头文件中用extern定义的常量需要在.m文件中定义具体代表什么字符串

## 6. 优点

> - 使用const修饰的，在内存中就只有一份，那么无论你在项目中的哪里使用，都是这一份，所以强烈推荐使用
>- 使用宏的话：宏是在编译的时候 将我们定义的宏的内容，直接编译成我们写的字符串，那么可能存在多次创建，多次调用的。
 

**注意** 
有些时候，const还是不能替代宏的,因为const后面接的内容不能是通过一些计算出来的结果，而是一些死的东西，比如：

```
// RGB颜色
#define ZYColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

// 随机色
#define ZYRandomColor HWColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
```


<tr>
<tr>
<tr>
<tr>

----------


----------


----------








# 四. 宏与const的区别
- 编译时刻:  &emsp;宏是预编译（编译之前处理），const是编译阶段。
- 编译检查:&emsp;宏不做检查，不会报编译错误，只是替换，const会编译检查，会报编译错误。
- 宏的好处:&emsp;宏能定义一些函数，方法。 const不能。
- 宏的坏处:&emsp;使用大量宏，容易造成编译时间久，每次都需要重新替换。

>注意:很多Blog都说使用宏，会消耗很多内存，但是并不会生成很多内存，宏定义的是常量，常量都放在常量区，只会生成一份内存。



