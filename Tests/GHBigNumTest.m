#import <GRUnit/GRUnit.h>

#import "GHBigNum.h"

@interface GHBigNumTest : GRTestCase
@end

@implementation GHBigNumTest

- (void)testPrime {
  GHBigNum *bn = [GHBigNum generatePrime:512];
  GRAssertTrue([bn isPrime]);
  GRTestLog(@"%@", bn);
}

- (void)testModPow {
  GHBigNum *a = [GHBigNum bigNumWithDecimalString:@"3487438743234789234879"];
  GHBigNum *p = [GHBigNum bigNumWithDecimalString:@"22"];
  GHBigNum *m = [GHBigNum bigNumWithDecimalString:@"3487438743234789234880"];
  GHBigNum *r = [GHBigNum modPow:a p:p m:m];
  GRAssertEqualObjects(r, [GHBigNum bigNumWithDecimalString:@"1"]);
}

@end
