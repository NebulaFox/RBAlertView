//
//  RBAlertView.m
//

#import "RBAlertView.h"

@implementation AppAlertView

@synthesize cancelBlock = _cancelBlock;
@synthesize clickedBlock = _clickedBlock;

- (id)initWithTitle:(NSString *)title message:(NSString *)message
  cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles
        cancelBlock:(AppAlertViewCancalBlock)cancelBlock clickedButtonAtIndexBlock:(AppAlertViewClickedBlock)clickedBlock
{
    self = [super initWithTitle:title message:message delegate:nil cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
    if ( self ) {
        for (NSString * title in otherButtonTitles) {
            [self addButtonWithTitle:title];
        }
        
        if ( clickedBlock != nil ) {
            _clickedBlock = clickedBlock;
        }
        
        if ( cancelBlock != nil ) {
            _cancelBlock = cancelBlock;
        }
        
        if ( _clickedBlock || _cancelBlock ) {
            [self setDelegate:self];
        }
    }
    return self;
}

#pragma - Delegate

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if ( _clickedBlock != NULL ) {
        _clickedBlock(self, buttonIndex);
    }
}

- (void)alertViewCancel:(UIAlertView *)alertView
{
    if ( _cancelBlock != NULL ) {
        _cancelBlock(self);
    }
}

#pragma - Static

+ (AppAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message
{
    return [[self alloc] initWithTitle:title message:message cancelButtonTitle:@"OK" otherButtonTitles:nil cancelBlock:NULL clickedButtonAtIndexBlock:NULL];
}

+ (AppAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle cancelBlock:(AppAlertViewCancalBlock)cancelBlock
{
    return [[self alloc] initWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil cancelBlock:cancelBlock clickedButtonAtIndexBlock:NULL];
}
+ (AppAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message
                   cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles
                         cancelBlock:(AppAlertViewCancalBlock)cancelBlock clickedButtonAtIndexBlock:(AppAlertViewClickedBlock)clickedBlock
{
    return [[self alloc] initWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles cancelBlock:cancelBlock clickedButtonAtIndexBlock:clickedBlock];
}

@end
