/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.cpp
 * Assignment #4 Cinco
 * Seeds random generator and runs a cinco instance.
 * Code Status: Working/Tested
 */

#import <time.h>
#import <stdlib.h>
#import "Cinco.h"

main(){
	srand(time(0));
	Cinco c;
	c.start();
}