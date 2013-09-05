//
//  RBAlertView.h
//

#import <UIKit/UIKit.h>

@class RBAlertView;

/// the block type that will be passed an action sheet and a button index
typedef void (^RBAlertViewWithButtonIndexBlock)(RBAlertView * alertView, NSInteger buttonIndex);

/// the block type that will be passed an action sheet
typedef void (^RBAlertViewBlock)(RBAlertView * alertView);

/// the block type tha will be passed an action sheet and return a `BOOL`
typedef BOOL (^RBAlertViewBoolBlock)(RBAlertView * alertView);

/// Extends `UIAlertView` to handle delegation via blocks
/**
 *  @see UIAlertView
 *  @see UIAlertViewDelegate
 */
@interface RBAlertView : UIAlertView <UIAlertViewDelegate>

@property ( nonatomic, copy ) RBAlertViewWithButtonIndexBlock clickedBlock; ///< the block called on `alertView:clickedButtonAtIndex:`
@property ( nonatomic, copy ) RBAlertViewWithButtonIndexBlock willDismissBlock; ///< the block called on `alertView:willDismissWithButtonIndex:`
@property ( nonatomic, copy ) RBAlertViewWithButtonIndexBlock didDismissBlock; ///< the block called on `alertView:didDismissWithButtonIndex:`
@property ( nonatomic, copy ) RBAlertViewBlock willPresentBlock; ///< the block called on `willPresentAlertView:`
@property ( nonatomic, copy ) RBAlertViewBlock didPresentBlock; ///< the block called on `didPresentAlertView:`
@property ( nonatomic, copy ) RBAlertViewBoolBlock shouldEnableFirstOtherButtonBlock; ///< the block called on `alertViewShouldEnableFirstOtherButton:`
@property ( nonatomic, copy ) RBAlertViewBlock cancelBlock; ///< the block called on `alertViewCancel:`

- (id)      initWithTitle:(NSString *)title
                  message:(NSString *)message
        cancelButtonTitle:(NSString *)cancelButtonTitle
        otherButtonTitles:(NSArray *)otherButtonTitles
clickedButtonAtIndexBlock:(RBAlertViewWithButtonIndexBlock)clickedBlock;

/// a simple alert with title, a message, an 'OK' button
+ (RBAlertView *)alertViewWithTitle:(NSString *)title
                            message:(NSString *)message;

+ (RBAlertView *)alertViewWithTitle:(NSString *)title
                            message:(NSString *)message
                  cancelButtonTitle:(NSString *)cancelButtonTitle;

+ (RBAlertView *)alertViewWithTitle:(NSString *)title
                            message:(NSString *)message
                  cancelButtonTitle:(NSString *)cancelButtonTitle
                  otherButtonTitles:(NSArray *)otherButtonTitles
          clickedButtonAtIndexBlock:(RBAlertViewWithButtonIndexBlock)clickedBlock;

@end
