/****************************************************************
File: Fractal.cpp				
Description: Handles initialization and drawing of Box fractals.

Author:	Aashay Vadnagara	 
Class: CSCI	120	
Date: 4/5/2015	

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "Fractal.h"
#include <vector>

namespace Drawing {
	/**
		 Default constructor. Set both start and end points to (0, 0).
	*/
	Fractal::Fractal() {}

	void Fractal::draw(wxDC &dc) {
		if (frames == 1)
			dc.DrawRectangle(startPoint.x, startPoint.y, (endPoint.x-startPoint.x), (endPoint.y-startPoint.y));
		else if (frames > 1){
			dc.SetBrush(fillBrush);
			dc.SetPen(outlinePen);
			DrawBoxFractal(dc, (startPoint.x), startPoint.y, endPoint.x-startPoint.x, endPoint.y-startPoint.y, frames-1);
		}
	}

	void Fractal::DrawBoxFractal(wxDC &dc, wxCoord x, wxCoord y, wxCoord width, wxCoord height, int frames){
		if(frames == 0){
			dc.DrawRectangle(x, y,width, height);
		
		}
		if (frames > 0){
			DrawBoxFractal(dc,x, y, width/3 , height/3,frames - 1);
			DrawBoxFractal(dc,x, y + 2*(height/3), width/3 , height/3,frames - 1);
			DrawBoxFractal(dc,x + width/3, y + height/3, width/3 , height/3,frames - 1);
			DrawBoxFractal(dc,x +2*(width/3), y , width/3 , height/3,frames - 1);
			DrawBoxFractal(dc,x + 2*(width/3), y+ 2*(height/3), width/3 , height/3,frames - 1);
		}
 	}
	
	void Fractal::setStartPoint(int x, int y){
		startPoint.x = x;
		startPoint.y = y;
	}
	void Fractal::setEndPoint(int x, int y){
		endPoint.x = x;
		endPoint.y = y;
	}

	void Fractal::SetFractalFrames(int frames){
		this->frames = frames;
	}

}