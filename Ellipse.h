/****************************************************************
File:			Ellipse.h
Description:	Ellipse Class Header

Author:	Aashay Vadnagara
Class:	CSCI 120
Date:	4/5/2015			 

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef Ellipse_H
#define Ellipse_H

#include "wx/wx.h"
#include "Shape.h"

namespace Drawing 
{
	/**
	 Represents a 2D Ellipse, with 
	 a start point that represents the top-left corner
	 and a end point on the bottom right.
	 */
	class Ellipse : public Shape
	{
	public:
		/**
		 Default constructor. Set both start and end points to (0, 0).
		 */
		Ellipse();

		/**
		 Parameterized constructor. Set both start and end points to given parameters.
		 @param a Point object representing start point
		 @param b Point object representing end point
		 */
		Ellipse(wxPoint a, wxPoint b);

		/**
		 Draws an Ellipse on the given device context.
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


