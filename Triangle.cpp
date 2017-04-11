/****************************************************************
File:			Triangle.cpp		
Description:	Triangle function map

Author:	Aashay Vadnagara
Class:	CSCI 120 
Date:	4/5/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "Triangle.h"


namespace Drawing
{

	/**
		 Default constructor. Set both start and end points to (0, 0).
	*/

	Triangle::Triangle() {

	}

	/**
		 Parameterized constructor. Set both start and end points to given parameters.
		 @param a Point object representing start point
		 @param b Point object representing end point
	*/
	Triangle::Triangle(wxPoint a, wxPoint b, wxPoint c) {
			startPoint = a;
			midPoint = b;
			endPoint = c;
	}

	/**
		 Draws a Triangle on the given device context.
		 @param dc wxPaintDC object representing device context for DrawingTri
	*/
	void Triangle::draw(wxDC &dc) {
			dc.SetBrush(fillBrush);
			dc.SetPen(outlinePen);
			wxPoint PtArr[] = {startPoint, midPoint, endPoint};
			dc.wxDC::DrawPolygon(3, PtArr);
	}

	/**
		 Sets the start point to the given coordinates.
		 @param x int value that is the x-coordinate
		 @param y int value that is the y-coordinate
	*/
	void Triangle::setStartPoint(int x, int y) {
			startPoint.x = x;
			startPoint.y = y;
	}

	/**
		 Sets the end point to the given coordinates.
		 @param x int value that is the x-coordinate
		 @param y int value that is the y-coordinate
	 */
	void Triangle::setEndPoint(int x, int y) {
			endPoint.x = x;
			endPoint.y = y;
	}

	void Triangle::setMidPoint(int x, int y) {
		midPoint.x = x;
		midPoint.y = y;
	}

	wxPoint Triangle::getStart() const{
		return startPoint;
	}
	wxPoint Triangle::getMid() const{
		return midPoint;
	}
	wxPoint Triangle::getEnd() const{
		return endPoint;
	}

	int Triangle::getStartX() const{
		return startPoint.x;
	}
	int Triangle::getMidX() const{
		return midPoint.x;
	}
	int Triangle::getEndX() const{
		return endPoint.x;
	}
	int Triangle::getStartY() const{
		return startPoint.y;
	}
	int Triangle::getMidY() const{
		return midPoint.y;
	}
	int Triangle::getEndY() const{
		return endPoint.y;
	}
}
