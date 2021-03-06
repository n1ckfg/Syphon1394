//
//  IIDCCamera.h
//  SyphonIIDCServer
//
//  Created by Andrea Cremaschi on 26/05/14.
//
//

#import <Foundation/Foundation.h>

@class IIDCContext;

@interface IIDCCamera : NSObject

@property (readonly) NSString *deviceName;
@property (readonly) NSString *deviceIdentifier;

// Settings save/restore
-(void)saveSettingsInMemoryBank: (int) channel;
-(void)restoreSettingsFromMemoryBank: (int) channel;
-(BOOL)isSaving;

// Broadcast
-(void)broadcast: (void(^)())block;

// Power and reset
-(void)setPower: (BOOL) power;
-(void)reset;

-(void)resetCameraBus;

// Features and videomodes
@property (nonatomic, readonly) NSArray *videomodes;
@property (nonatomic, readwrite) NSInteger videomode;

@property (nonatomic, readonly) NSDictionary *features;

@property (nonatomic, readonly) NSArray *availableFrameRatesForCurrentVideoMode;
@property (nonatomic, readwrite) double framerate;

@property (readonly) IIDCContext *context;

- (BOOL)isCapturing;
- (BOOL)pushToAutoFeatureWithIndex:(int)f;

@end

