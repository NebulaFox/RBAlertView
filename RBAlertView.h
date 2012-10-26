//
//  RBAlertView.h
//

#import <UIKit/UIKit.h>

@class AppAlertView;

typedef void (^AppAlertViewClickedBlock)(AppAlertView *, NSInteger);
typedef void (^AppAlertViewCancalBlock)(AppAlertView *);

@interface AppAlertView : UIAlertView <UIAlertViewDelegate>

@property (strong, nonatomic) AppAlertViewCancalBlock cancelBlock;
@property (strong, nonatomic) AppAlertViewClickedBlock clickedBlock;

- (id)initWithTitle:(NSString *)title message:(NSString *)message
  cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles
        cancelBlock:(AppAlertViewCancalBlock)cancelBlock clickedButtonAtIndexBlock:(AppAlertViewClickedBlock)clickedBlock;

+ (AppAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message;
+ (AppAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle cancelBlock:(AppAlertViewCancalBlock)cancelBlock;
+ (AppAlertView *)alertViewWithTitle:(NSString *)title message:(NSString *)message
                   cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles
                         cancelBlock:(AppAlertViewCancalBlock)cancelBlock clickedButtonAtIndexBlock:(AppAlertViewClickedBlock)clickedBlock;

@end
