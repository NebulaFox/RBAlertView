# RBAlertView

`RBAlertView` is an extension of `UIAlertView` that uses blocks instead of a delegate.
The code compiles under Apple LLVM compiler 4.0 and above. It also requires the base SDK of iOS 5.0.

## Examples

- Create a simple alert view with a title, a message and an OK dismiss button
```objc
[[RBAlertView alertViewWithTitle:@"An Awesome Alert Title" message:@"An awesome message for an awesome alert"] show];
```

- Create a simple alert view with a title, a message and a (Awesome) cancel button
```objc
[[RBAlertView alertViewWithTitle:@"An Awesome Alert Title" message:@"An awesome message for an awesome alert" cancelButtonTitle:@"Awesome"] show];
```

- Create a mora elaborate alert view
```objc
[[RBAlertView alertViewWithTitle:@"An Elaborate Alert"
                         message:@"An elaborate message should go here"
               cancelButtonTitle:@"Awesome"
               otherButtonTitles:@[ @"Eleborate", @"Expand", @"Expelliarmus" ] // an array literal
                    clickedBlock:^( RBAlertView *alert, NSInterger buttonIndex )
                                 {
                                     switch ( buttonIndex )
                                     {
                                         case 0: // Awesome // cancel button
                                             NSLog( @"Awesome" ); break;
                                         case 1:
                                             NSLog( @"Eleborate" ); break;
                                         case 2:
                                         	 NSLog( @"Expand" ); break;
                                         case 3:
                                             NSLog( @"Expelliarmus" ); break;
                                     }
                                 }
] show];
```