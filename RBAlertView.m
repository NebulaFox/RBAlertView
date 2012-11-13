//
//  RBAlertView.m
//

#import "RBAlertView.h"

@implementation RBAlertView

- (id)initWithTitle:(NSString *)title message:(NSString *)message
  cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles clickedButtonAtIndexBlock:(RBAlertViewWithButtonIndexBlock)clickedBlock
{
    self = [super initWithTitle:title message:message delegate:nil cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil];
    if ( self ) {
        for (NSString * title in otherButtonTitles) {
            [self addButtonWithTitle:title];
        }
        
        self.clickedBlock = clickedBlock;
        self.delegate = self;
    }
    return self;
}

- (BOOL)respondsToSelector:(SEL)aSelector
{
    if ( [super respondsToSelector:aSelector] )
    {
        return YES;
    }
    else
    {
        if ( aSelector == @selector(alertViewCancel:) && self.cancelBlock != nil )
        {
            return YES;
        }
        else if ( aSelector == @selector(alertViewShouldEnableFirstOtherButton:) && self.shouldEnableFirstOtherButtonBlock != nil )
        {
            return YES;
        }
    }
    
    return NO;
}

#pragma - Delegate

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if ( self.clickedBlock != nil )
    {
        self.clickedBlock( self, buttonIndex );
    }
}

- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if ( self.willDismissBlock != nil )
    {
        self.willDismissBlock( self, buttonIndex );
    }
}

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if ( self.didDismissBlock != nil )
    {
        self.didDismissBlock( self, buttonIndex );
    }
}

- (void)willPresentAlertView:(UIAlertView *)alertView
{
    if ( self.willPresentBlock != nil )
    {
        self.willPresentBlock( self );
    }
}

- (void)didPresentAlertView:(UIAlertView *)alertView
{
    if ( self.didPresentBlock != nil )
    {
        self.didPresentBlock( self );
    }
}

- (BOOL)alertViewShouldEnableFirstOtherButton:(UIAlertView *)alertView
{
    // there is no checking if shouldEnableFirstOtheButtonBlock is nil
    // because it will be handled by `respondToSelector:`
    // the reason is to make life easier
    return self.shouldEnableFirstOtherButtonBlock( self );
}

- (void)alertViewCancel:(UIAlertView *)alertView
{
    // there is no checking if cancel block is nil
    // because it will be handled by `respondToSelector:`
    // the reason is action sheet will react differently
    // if this method is defined
    self.cancelBlock( self );
}

#pragma - Static

+ (RBAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message
{
    return [[self alloc] initWithTitle:title message:message cancelButtonTitle:@"OK" otherButtonTitles:nil clickedButtonAtIndexBlock:nil];
}

+ (RBAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle
{
    return [[self alloc] initWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitles:nil clickedButtonAtIndexBlock:nil];
}
+ (RBAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message
                   cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles
                         clickedButtonAtIndexBlock:(RBAlertViewWithButtonIndexBlock)clickedBlock
{
    return [[self alloc] initWithTitle:title message:message cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles clickedButtonAtIndexBlock:clickedBlock];
}

@end
