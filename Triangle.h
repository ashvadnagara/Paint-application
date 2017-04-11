/****************************************************************
File: Triangle.h		
Description: Triangle Class Header		

Author:	Aashay Vadnagara 
Class:	CSCI 120 
Date:	4/5/2015		 

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef TRI_H
#define TRI_H

#include "wx/wx.h"
#include "Shape.h"

namespace Drawing {
	/**
	 Represents a 2D Triangle
	 It has a start point
	 And a mid point.
	 The line that finishes the triangle is defined in DrawingWindow.cpp
	 */
	class Triangle : public Shape
	{
	public:
		/**
		 Default constructor. Set both start and end points to (0, 0).
		 */
		Triangle();

		/**
		 Parameterized constructor. Set both start and end points to given parameters.
		 @param a Point object representing start point
		 @param b Point object representing end point
		 */
		Triangle(wxPoint a, wxPoint b, wxPoint c);

		/**
		 Draws a Triangle on the given device context.
		 @param dc wxPaintDC object representing device context for drawing
		*/
		void draw(wxDC &dc); 

		/**
		 Sets the start point to the given coordinates.
		 @param x int value that is the x-coordinate
		 @param y int value that is the y-coordinate
		 */
		void setStartPoint(int x, int y);

		/**
		 Sets the end point to the given coordinates.
		 @param x int value that is the x-coordinate
		 @param y int value that is the y-coordinate
		 */
		void setEndPoint(int x, int y);
		void setMidPoint(int x, int y);
		
		wxPoint getStart() const;
		wxPoint getMid() const;
		wxPoint getEnd() const;

		int getStartX() const;
		int getMidX() const;
		int getEndX() const;
		int getStartY() const;
		int getMidY() const;
		int getEndY() const;

	private:
		wxPoint startPoint, midPoint, endPoint;
	};
}

#endif


