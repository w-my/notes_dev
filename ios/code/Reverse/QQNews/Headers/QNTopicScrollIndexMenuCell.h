//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableTableViewCell.h"

#import "QNListCellProtocol.h"

@class NSString, QNTopicScrollIndexMenuView;

@interface QNTopicScrollIndexMenuCell : QNThemableTableViewCell <QNListCellProtocol>
{
    id <QNTopicScrollIndexMenuViewDelegate> _actionDelegate;
    QNTopicScrollIndexMenuView *_subMenuView;
}

@property(retain, nonatomic) QNTopicScrollIndexMenuView *subMenuView; // @synthesize subMenuView=_subMenuView;
@property(nonatomic) __weak id <QNTopicScrollIndexMenuViewDelegate> actionDelegate; // @synthesize actionDelegate=_actionDelegate;
- (void).cxx_destruct;
- (void)layoutWithViewModel:(id)arg1 context:(id)arg2;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
