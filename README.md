# FOODSPAN Display Code

This is the code for the entire console for FoodSpan.

This includes code for the buttons, display, NFC tagging system, LED error lights and wifi shield.

Please note : 

In the display.io file the images were converted to a byte array which is an unsigned long long []. Unfortunately, Arduino does not support unsigned long long so I had to re-write some of the directories. 

Make sure to look at the RA8875 drivers in order to use the code above. A tri-state buffer needs to provided in order to make the TFT work.

For more information about our product please visit : www.foodspan.ca

![Screenshot](model.png)

## We are still in prototyping! Check out our newest prototype!
![Screenshot](received_363780517354610.jpeg)
