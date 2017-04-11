#ifndef SHAPE_H
#define SHAPE_H

#include "wx/wx.h"
#include "wx/brush.h"
#include "wx/pen.h"

namespace Drawing {

/**
 Represents a 2D shape.
 */
class Shape
{
public:
	/**
	 Default constructor. Sets outline color to black and fill color to transparent.
	 */
	Shape() {
		setOutlineColor(*wxBLACK);
		setFillColor(*wxWHITE);
	}

	/**
	 Parameterized constructor. Set the outline pen and fill brush to the given parameters.
	 @param outline wxPen representing the outline pen
	 @param fill wxBrush representing the fill brush
	 */
	Shape(const wxPen &outline, const wxBrush &fill) {
		outlinePen = outline;
		fillBrush = fill;
	}

	/**
	 Sets the pen to member outlinePen and the brush to member fillBrush.
	 Draws the shape on the given device context.
	 @param dc wxPaintDC object representing device context for drawing
	*/
	virtual void draw(wxDC &dc) {
		dc.SetBrush(fillBrush);
		dc.SetPen(outlinePen);
	}

	/**
	 Sets the outline color to the given color.
	 @param color wxColour object 
	 */
	void setOutlineColor(wxColour color) {
		outlinePen.SetColour(color);
	}

	/**
	 Sets the fill color to the given color.
	 @param color wxColour object 
	 */
	void setFillColor(wxColour color) {
		fillBrush.SetColour(color);
	}

	/**
	 Sets the outline width to the given color.
	 @param width int value 
	 */
	void setLineWidth(int width) {
		outlinePen.SetWidth(width);
	}

protected:
	wxPen outlinePen;
	wxBrush fillBrush;
};
} // end namespace

#endif