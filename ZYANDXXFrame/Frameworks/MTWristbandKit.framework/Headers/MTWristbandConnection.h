//
//  MTWristbandConnection.h
//  MTWristbandKit
//
//  Created by Minewtech on 2020/5/21.
//  Copyright © 2020 Minewtech. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, Connection) {
    Disconnected = 0,
    Connected,
    Connecting,
    Validating,
    Validated,
    ValidateFailed,
    PasswordVaildateFailed,
};
@class MTWristbandPeripheral;

typedef void(^MTPasswordBlock)(NSString *password);

typedef void(^MTCOperationBlock)(BOOL success, NSError *error);

typedef void(^WriteCompletion)(BOOL success, NSError *error);
typedef void(^ReceiveCompletion)(NSData *data);
typedef void(^ConnectionChangeCompletion)(Connection connection);

@interface MTWristbandConnection : NSObject

// macString of device
@property (nonatomic, strong) NSString *macString;

/**
 current connection status.
 */
@property (nonatomic, readonly, assign) Connection connection;
/**
 Send data to the device
 
 @param data the sending data.
 @param handler writing completion callback, success == YES means send successfully.
 */
- (void)writeData:(NSData *)data completion:(WriteCompletion)handler;

/**
 Received data from device.
 !!! this is a callback method, please listen to the block, it will execute when receiving data from device.
 @param completionHandler the receiving completion block.
 */
- (void)didReceiveData:(ReceiveCompletion)completionHandler;

/**
 listen the changes of connection.
 !!! this is a callback method, please listen to the block, it will execute when the device changes connection.
 @param completionHandler the connection changing block.
 */
- (void)didChangeConnection:(ConnectionChangeCompletion)completionHandler;

@end

NS_ASSUME_NONNULL_END
