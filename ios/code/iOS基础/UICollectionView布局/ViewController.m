//
//  ViewController.m
//  UICollectionView布局
//
//  Created by WTW on 2020/1/29.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "CustomFlowLayout.h"

#define KWIDTH [UIScreen mainScreen].bounds.size.width

@interface ViewController ()<UICollectionViewDataSource,UICollectionViewDelegate>
@property (nonatomic,strong) UICollectionView *collectionView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.collectionView];
    [self.view setNeedsUpdateConstraints];
}

- (void)viewDidLayoutSubviews {
    self.collectionView.frame = CGRectMake(0, 100,KWIDTH, 300);
}

#pragma mark - UICollectionViewDataSource

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return 10;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"cell" forIndexPath:indexPath];
    cell.backgroundColor = [UIColor colorWithRed:arc4random()%250/255.0 green:arc4random()%250/255.0 blue:arc4random()%250/255.0 alpha:1.0];
    return cell;
}

#pragma mark - UICollectionViewDelegate

- (UICollectionView *)collectionView {
    if (!_collectionView) {
        CustomFlowLayout *layout = [[CustomFlowLayout alloc] init];
        layout.itemSize = CGSizeMake(150, 150);
        layout.minimumLineSpacing = 20;
        layout.scrollDirection = UICollectionViewScrollDirectionHorizontal;
        _collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:layout];
        _collectionView.delegate = self;
        _collectionView.dataSource = self;
        _collectionView.backgroundColor = [UIColor greenColor];
        [_collectionView registerClass:NSClassFromString(@"UICollectionViewCell") forCellWithReuseIdentifier:@"cell"];
    }
    return _collectionView;
}

@end
