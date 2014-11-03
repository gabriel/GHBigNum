//
//  GRUnitIOSTestViewController.h
//  GRUnit
//
//  Created by Gabriel Handford on 2/20/09.
//  Copyright 2009. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import "GRTestViewModel.h"

extern NSString *const GRUnitTestNodeKey;

@class GRUnitIOSTestViewController;

@protocol GRUnitIOSTestViewControllerDelegate
- (void)testViewController:(GRUnitIOSTestViewController *)testViewController didUpdateTestNode:(GRTestNode *)testNode;
@end

/*
 View controller for a test.
 */
@interface GRUnitIOSTestViewController : UIViewController

@property (readonly) id<GRTest> test;
@property (weak) id<GRTestRunnerDelegate> runnerDelegate;
@property (weak) id<GRUnitIOSTestViewControllerDelegate> delegate;

- (void)log:(NSString *)text;

- (void)setTestNode:(GRTestNode *)testNode runnerDelegate:(id<GRTestRunnerDelegate>)runnerDelegate;

@end
