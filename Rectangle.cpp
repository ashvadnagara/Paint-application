/****************************************************************
File:			Rectangle.cpp			
Description:	Rectangle function map

Author:	Aashay Vadnagara
Class:	CSCI 120 
Date:	4/5/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "Rectangle.h"


namespace Drawing {
/**
	 Default constructor. Set both start and end points to (0, 0).
*/
Rectangle::Rectangle() {
	}

/**
	 Parameterized constructor. Set both start and end points to given parameters.
	 @param a Point object representing start point
	 @param b Point object representing end point
*/
Rectangle::Rectangle(wxPoint a, wxPoint b) {
		startPoint = a;
		endPoint = b;
}

/**
	 Draws a Rectangle on the given device context.
	 @param dc wxPaintDC object representing device context for drawing
*/
void Rectangle::draw(wxDC &dc) {
		dc.SetBrush(fillBrush);
		dc.SetPen(outlinePen);
		dc.DrawRectangle(startPoint.x, startPoint.y, (endPoint.x-startPoint.x), (endPoint.y-startPoint.y));
}

/**
	 Sets the start point to the given coordinates.
	 @param x int value that is the x-coordinate
	 @param y int value that is the y-coordinate
*/
void Rectangle::setStartPoint(int x, int y) {
		startPoint.x = x;
		startPoint.y = y;
}

/**
	 Sets the end point to the given coordinates.
	 @param x int value that is the x-coordinate
	 @param y int value that is the y-coordinate
 */
void Rectangle::setEndPoint(int x, int y) {
		endPoint.x = x;
		endPoint.y = y;
}


}