// BPHelpAnnotation.h
//
// Copyright (c) 2014 Britton Mobile Development (http://brittonmobile.com/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

typedef enum _BPHelpAnnotationDirection
{
	BPHelpAnnotationDirectionNone = 0,
	BPHelpAnnotationDirectionTop,
	BPHelpAnnotationDirectionLeft,
	BPHelpAnnotationDirectionBottom,
	BPHelpAnnotationDirectionRight
} BPHelpAnnotationDirection;

typedef void (^BPHelpAnnotationTapBlock)();

@class BPHelpAnnotationView;

@protocol BPHelpAnnotation <NSObject>

- (BPHelpAnnotationDirection)direction;
- (CGPoint)landscapeAnchorPoint;
- (CGPoint)portraitAnchorPoint;
- (UIView *)anchorView;
- (CGSize)contentOffset;
- (NSString *)text;
- (UIColor *)annotationColor;
- (BOOL)inBlinkingMode;
- (BPHelpAnnotationTapBlock)tapBlock;

- (BPHelpAnnotationView *)view;
- (UIAccessibilityElement *)accessibilityElementInContainer:(id)container;

@end

@interface BPHelpAnnotation : NSObject <BPHelpAnnotation>

@property (nonatomic, readonly) BPHelpAnnotationDirection direction;
@property (nonatomic, readonly) CGPoint landscapeAnchorPoint;
@property (nonatomic, readonly) CGPoint portraitAnchorPoint;
@property (nonatomic, readonly) UIView *anchorView;
@property (nonatomic, readonly) CGSize contentOffset;
@property (nonatomic, readonly) NSString *text;
@property (nonatomic, readonly) UIColor *annotationColor;
@property (nonatomic, readonly) BOOL inBlinkingMode;
@property (nonatomic, copy) BPHelpAnnotationTapBlock tapBlock;

- (id)initWithDirection:(BPHelpAnnotationDirection)direction anchorView:(UIView *)anchorView contentOffset:(CGSize)contentOffset andText:(NSString *)text;
- (id)initWithDirection:(BPHelpAnnotationDirection)direction anchorView:(UIView *)anchorView contentOffset:(CGSize)contentOffset andText:(NSString *)text withAnnotationColor:(UIColor*)color withBlinkingMode:(BOOL)blinkingMode;
- (id)initWithDirection:(BPHelpAnnotationDirection)direction landscapeAnchorPoint:(CGPoint)landscapeAnchorPoint portraitAnchorPoint:(CGPoint)portraitAnchorPoint contentOffset:(CGSize)contentOffset andText:(NSString *)text;
- (id)initWithDirection:(BPHelpAnnotationDirection)direction landscapeAnchorPoint:(CGPoint)landscapeAnchorPoint portraitAnchorPoint:(CGPoint)portraitAnchorPoint contentOffset:(CGSize)contentOffset andText:(NSString *)text tapBlock:(BPHelpAnnotationTapBlock)tapBlock;

@end
