/****************************************************************
File:				
Description:		

Author:	 Aashay Vadnagara 
Class:	 CSCI 120
Date:	 4/5/2015		

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "Line.h"

/**
	 Default constructor. Set both start and end points to (0, 0).
*/
Drawing::Line::Line() {

}

/**
	 Parameterized constructor. Set both start and end points to given parameters.
	 @param a Point object representing start point
	 @param b Point object representing end point
*/

Drawing::Line::Line(wxPoint a, wxPoint b, const wxPen &outline, const wxBrush &fill) {
		outlinePen = outline;
		fillBrush = fill;
		startPoint = a;
		endPoint = b;
}

/**
	 Draws a line on the given device context.
	 @param dc wxPaintDC object representing device context for drawing
*/
void Drawing::Line::draw(wxDC &dc) {
		dc.SetBrush(fillBrush);
		dc.SetPen(outlinePen);
		dc.DrawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
}

/**
	 Sets the start point to the given coordinates.
	 @param x int value that is the x-coordinate
	 @param y int value that is the y-coordinate
*/
void Drawing::Line::setStartPoint(int x, int y) {
		startPoint.x = x;
		startPoint.y = y;
}

/**
	 Sets the end point to the given coordinates.
	 @param x int value that is the x-coordinate
	 @param y int value that is the y-coordinate
 */
void Drawing::Line::setEndPoint(int x, int y) {
		endPoint.x = x;
		endPoint.y = y;
}


