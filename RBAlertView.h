//
//  RBAlertView.h
//

#import <UIKit/UIKit.h>

@class RBAlertView;

/// the block type that will be passed an action sheet and a button index
typedef void (^RBAlertViewWithButtonIndexBlock)(RBAlertView *, NSInteger);

/// the block type that will be passed an action sheet
typedef void (^RBAlertViewBlock)(RBAlertView *);

/// the block type tha will be passed an action sheet and return a `BOOL`
typedef BOOL (^RBAlertViewBoolBlock)(RBAlertView *);

/// Extends `UIAlertView` to handle delegation via blocks
/**
 *  @see UIAlertView
 *  @see UIAlertViewDelegate
 */
@interface RBAlertView : UIAlertView <UIAlertViewDelegate>

@property ( strong, nonatomic ) RBAlertViewWithButtonIndexBlock clickedBlock; ///< the block called on `alertView:clickedButtonAtIndex:`
@property ( strong, nonatomic ) RBAlertViewWithButtonIndexBlock willDismissBlock; ///< the block called on `alertView:willDismissWithButtonIndex:`
@property ( strong, nonatomic ) RBAlertViewWithButtonIndexBlock didDismissBlock; ///< the block called on `alertView:didDismissWithButtonIndex:`
@property ( strong, nonatomic ) RBAlertViewBlock willPresentBlock; ///< the block called on `willPresentAlertView:`
@property ( strong, nonatomic ) RBAlertViewBlock didPresentBlock; ///< the block called on `didPresentAlertView:`
@property ( strong, nonatomic ) RBAlertViewBoolBlock shouldEnableFirstOtherButtonBlock; ///< the block called on `alertViewShouldEnableFirstOtherButton:`
@property ( strong, nonatomic ) RBAlertViewBlock cancelBlock; ///< the block called on `alertViewCancel:`

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
                       clickedBlock:(RBAlertViewWithButtonIndexBlock)clickedBlock;

@end
