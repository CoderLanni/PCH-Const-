//
//  ViewController.m
//  PCH文件与宏定义
//
//  Created by ZE KANG on 2017/8/12.
//  Copyright © 2017年 LRY. All rights reserved.
//

#import "ViewController.h"
#import "RYConst.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.view.backgroundColor = LRRGBColor(25, 32, 222);
    
    NSLog(@"==== %@",RYID);
    NSLog(@"---------- %.2f",RYAge);
    NSLog(@"++++++ %@",RYURL);

    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
