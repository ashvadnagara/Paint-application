/****************************************************************
File:	Rectangle.h
Description:	Rectangle Class Header

Author:	Aashay Vadnagara
Class:	CSCI 120 
Date:	4/5/2015			 

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef Rectangle_H
#define Rectangle_H

#include "wx/wx.h"
#include "Shape.h"

namespace Drawing 
{
	/**
	 Represents a 2D Rectangle with 2 corners
	 */
	class Rectangle : public Shape
	{
	public:
		/**
		 Default constructor. Set both start and end points to (0, 0).
		 */
		Rectangle();

		/**
		 Parameterized constructor. Set both start and end points to given parameters.
		 @param a Point object representing start point
		 @param b Point object representing end point
		 */
		Rectangle(wxPoint a, wxPoint b);

		/**
		 Draws a Rectangle on the given device context.
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

	private:
		wxPoint startPoint;
		wxPoint endPoint;
	};
}

#endif


