//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSArray, QMapContext, QMediator, TBOrderedSafeDictionary;

@interface QAnnotationContainerView : UIView
{
    QMediator *_mediator;
    QMapContext *_mapContext;
    id <QAnnotationContainerViewDelegate> _delegate;
    TBOrderedSafeDictionary *_annotationStorage;
}

@property(retain, nonatomic) TBOrderedSafeDictionary *annotationStorage; // @synthesize annotationStorage=_annotationStorage;
@property(nonatomic) __weak id <QAnnotationContainerViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) __weak QMapContext *mapContext; // @synthesize mapContext=_mapContext;
@property(nonatomic) __weak QMediator *mediator; // @synthesize mediator=_mediator;
- (void).cxx_destruct;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)setupSelf;
- (id)calloutViewForAnnotation:(id)arg1;
- (void)didAddSubview:(id)arg1;
- (void)deselectAnnotation:(id)arg1 animated:(_Bool)arg2;
- (void)selectAnnotation:(id)arg1 animated:(_Bool)arg2;
- (void)bringAnnotationToFront:(id)arg1;
- (id)dequeueReusableAnnotationViewWithIdentifier:(id)arg1;
- (id)viewForAnnotation:(id)arg1;
- (void)removeAnnotations:(id)arg1;
- (void)removeAnnotation:(id)arg1;
- (void)addAnnotations:(id)arg1;
- (void)addAnnotation:(id)arg1;
@property(readonly, nonatomic) NSArray *selectedAnnotations;
@property(readonly, nonatomic) NSArray *annotations;
- (void)notifyAnnotationView:(id)arg1 calloutAccessoryControlTapped:(id)arg2;
- (void)notifyAnnotationViewCalloutTapped:(id)arg1;
- (void)notifyAnnotationView:(id)arg1 didChangeDragState:(int)arg2 fromOldState:(int)arg3;
- (void)notifyAnnotationViewDidDeselect:(id)arg1;
- (void)notifyAnnotationViewDidSelect:(id)arg1;
- (id)notifyCustomCalloutForAnnotationView:(id)arg1;
- (void)adjustOrderOfAnnotationView:(id)arg1;
- (void)scrollMapToCoordinate:(struct CLLocationCoordinate2D)arg1 animated:(_Bool)arg2 duration:(double)arg3;
- (struct CLLocationCoordinate2D)coordinateForPoint:(struct CGPoint)arg1;
- (struct CGPoint)pointForCoordinate:(struct CLLocationCoordinate2D)arg1;
- (void)callDelegateAnnotationView:(id)arg1 calloutAccessoryControlTapped:(id)arg2;
- (void)callDelegateAnnotationViewCalloutTapped:(id)arg1;
- (void)callDelegateAnnotationView:(id)arg1 didChangeDragState:(int)arg2 fromOldState:(int)arg3;
- (void)callDelegateAnnotationViewDidDeselect:(id)arg1;
- (void)callDelegateAnnotationViewDidSelect:(id)arg1;
- (id)callDelegateCustomCalloutForAnnotationView:(id)arg1;
- (void)callDelegateDidAddAnnotationViews:(id)arg1;
- (id)callDelegateViewForAnnotation:(id)arg1;
- (struct CGPoint)pointForAnnotationView:(id)arg1;
- (void)updateVisibilityForAnnotationView:(id)arg1;
- (void)updateAnnotationView:(id)arg1;
- (void)updateAllAnnotations;
- (void)mapContextDidMapStatusChangedAfterDraw:(id)arg1;

@end
