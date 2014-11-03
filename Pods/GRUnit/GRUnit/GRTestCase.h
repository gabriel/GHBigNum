//
//  GRTestCase.h
//  GRUnit
//
//  Created by Gabriel Handford on 1/21/09.
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

//
// Portions of this file fall under the following license, marked with:
// GTM_BEGIN : GTM_END
//
//  Copyright 2008 Google Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not
//  use this file except in compliance with the License.  You may obtain a copy
//  of the License at
// 
//  http://www.apache.org/licenses/LICENSE-2.0
// 
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
//  License for the specific language governing permissions and limitations under
//  the License.
//

#import "GRTestMacros.h"
#import "GRTest.h"

/*!
 Log to your test case logger. For example,

    GRTestLog(@"Some debug info, %@", obj);

 */
#define GRTestLog(...) [self log:[NSString stringWithFormat:__VA_ARGS__, nil]]

/*!
 For when you need a weak reference of an object, example: `GHWeakObject(obj) wobj = obj;`
 */
#define GRWeakObject(o) __typeof__(o) __weak

/*!
 For when you need a weak reference to self, example: `GHWeakSelf wself = self;`
 */
#define GRWeakSelf GRWeakObject(self)

#define GRErrorHandler (^(NSError *error) { GRFail(@"Error: %@", error); })

/*!
 The base class for a test case. 
 
     @interface MyTest : GRTestCase {}
     @end
     
     @implementation MyTest
     
     // Run before each test method
     - (void)setUp { }

     // Run after each test method
     - (void)tearDown { }

     // Tests are prefixed by 'test' and contain no arguments and no return value
     - (void)testA { 
       GRTestLog(@"Log with a test with the GRTestLog(...) for test specific logging.");
     }

     // Another test; Tests are run in lexical order
     - (void)testB { }
          
     @end

 */
@interface GRTestCase : NSObject

@property SEL currentSelector;
@property (weak) id<GRTestCaseLogWriter> logWriter;
@property (readonly, getter=isCancelling) BOOL cancelling;

//! Run before each test method
- (void)setUp;

//! Set up async
- (void)setUp:(dispatch_block_t)completion;

//! Run after each test method
- (void)tearDown;

- (void)tearDown:(dispatch_block_t)completion;

/*!
 Log a message, which notifies the log delegate.
 This is not meant to be used directly, see GRTestLog(...) macro.

 @param message Message to log
 */
- (void)log:(NSString *)message;

/*!
 Set test case cancelling.
 */
- (void)cancel;

/*!
 Whether the test class should be run as a part of command line tests.
 By default this is NO. Subclasses can override this method to disable
 test classes that are problematic at the command line.

 @result YES if this test class is disabled for command line tests
 */
- (BOOL)isCLIDisabled;

/*!
 @result Defaults to NO; YES if we should run this test case on the main thread (queue).
 */
- (BOOL)shouldRunOnMainThread;

@end
