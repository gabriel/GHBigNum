//
//  KBListView.m
//  Keybase
//
//  Created by Gabriel on 2/2/15.
//  Copyright (c) 2015 Gabriel Handford. All rights reserved.
//

#import <XCTest/XCTest.h>

#import <GHBigNum/GHBigNum.h>

@interface GHBigNumTest : XCTestCase
@end

@implementation GHBigNumTest

- (void)testPrime {
  GHBigNum *bn = [GHBigNum generatePrime:512];
  XCTAssertTrue([bn isPrime]);
  NSLog(@"%@", bn);
}

- (void)testModPow {
  GHBigNum *a = [GHBigNum bigNumWithDecimalString:@"3487438743234789234879"];
  GHBigNum *p = [GHBigNum bigNumWithDecimalString:@"22"];
  GHBigNum *m = [GHBigNum bigNumWithDecimalString:@"3487438743234789234880"];
  GHBigNum *r = [GHBigNum modPow:a p:p m:m];
  XCTAssertEqualObjects(r, [GHBigNum bigNumWithDecimalString:@"1"]);
}

@end
