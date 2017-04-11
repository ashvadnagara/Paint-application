/****************************************************************
File: Fractal.h			
Description: Header file for Fractal.cpp		

Author:	Aashay Vadnagara	 
Class: CSCI	120	
Date: 4/5/2015		

I hereby certify that this program is entirely my own work.
*****************************************************************/
#ifndef FRACTAL_H
#define FRACTAL_H

#include "wx/wx.h"
#include "Shape.h"



namespace Drawing {
	class Fractal: public Drawing::Shape {
	public:
		/**
		 Default constructor. Set both start and end points to (0, 0).
		 */
		Fractal();
		
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
		void setEndPoint(int x, int y);

		/**
		Recursive function that creates as many boxes as needed
		@param dc - drawing board
		@param x/y - used to determine x/y coordinates of new box points
		@param width/height of boxes, respectively.
		@param frame - how many times the function should call itself.
		*/
		void DrawBoxFractal(wxDC &dc, wxCoord x, wxCoord y,wxCoord width, wxCoord height, int frames); 
		void SetFractalFrames (int frames);
	protected:
		wxPoint startPoint;
		wxPoint endPoint;
		int frames;
		int fractalFrames;
	};

	

}

#endif
