/****************************************************************
File:			Ellipse.cpp		
Description:	Ellipse function map

Author:	Aashay Vadnagara 
Class:	CSCI 120 
Date:	4/5/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "Ellipse.h"


namespace Drawing {
/**
	 Default constructor. Set both start and end points to (0, 0).
*/
Ellipse::Ellipse() {

}

/**
	 Parameterized constructor. Set both start and end points to given parameters.
	 @param a Point object representing start point
	 @param b Point object representing end point
*/
Ellipse::Ellipse(wxPoint a, wxPoint b) {
		startPoint = a;
		endPoint = b;
}

/**
	 Draws a Ellipse on the given device context.
	 @param dc wxPaintDC object representing device context for drawing
*/
void Ellipse::draw(wxDC &dc) {
		dc.SetBrush(fillBrush);
		dc.SetPen(outlinePen);
		dc.DrawEllipse(startPoint.x, startPoint.y, (endPoint.x-startPoint.x), (endPoint.y-startPoint.y));
}

/**
	 Sets the start point to the given coordinates.
	 @param x int value that is the x-coordinate
	 @param y int value that is the y-coordinate
*/
void Ellipse::setStartPoint(int x, int y) {
		startPoint.x = x;
		startPoint.y = y;
}

/**
	 Sets the end point to the given coordinates.
	 @param x int value that is the x-coordinate
	 @param y int value that is the y-coordinate
 */
void Ellipse::setEndPoint(int x, int y) {
		endPoint.x = x;
		endPoint.y = y;
}


}