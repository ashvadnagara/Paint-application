/****************************************************************
File:	Drawing window			
Description:	DrawingWindow Header (added to private variables)		

Author:	Aashay Vadnagara 
Class:	CSCI 120 
Date:	4/5/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef DRAWINGWINDOW_H
#define DRAWINGWINDOW_H

#include <wx/wx.h>
#include "Line.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"
#include "Fractal.h"
#include <vector>

const int WINDOW_WIDTH = 800; // window width
const int WINDOW_HEIGHT = 600; // window height
const wxString BACKGROUND_COLOR = "#ffffff"; // window background color

/**
 Enumerated type representing the modes of geometrical drawing.
*/
enum DrawingState {NONE, LINE, ELLIPSE, RECTANGLE, TRIANGLE, FRACTAL};

/**
 A window that shows the drawing program interface,
 with an area on which the user can draw lines and shapes.
 */
class DrawingWindow : public wxWindow
{
public:
	/**
	Initializes the base class.
	@param parent the parent window
	*/
	DrawingWindow(wxWindow* parent);

	/**
	Paints the lines and shapes that have already been
	entered.
	@param event the event descriptor
	*/
	void OnPaint(wxPaintEvent& event);

	/**
	Responds to mouse event by storing relevant
	information about the current line/shape being drawn.
	@param event the event descriptor
	*/
	void OnMouseEvent(wxMouseEvent& event);
	/**
	 Sets the current drawing state.
	 @param state new DrawingState value
	*/
	void setState(DrawingState state);
	/**
	 Sets the current drawing line width.
	 @param width new line width value (integer)
	*/
	void setLineWidth(int width);
	/**
	 Sets the current drawing outline color.
	 @param color wxColour value
	*/
	void setOutlineColor(wxColour color);
	/**
	 Sets the current drawing fill color.
	 @param color wxColour value
	*/
	void setFillColor(wxColour color);

	void setFractalFrames(int frames);

private:
	int corners; // number of corners of the current shape being drawn
	std::vector<Drawing::Line> lineVector;
	std::vector<Drawing::Ellipse> EllipseVector;
	std::vector<Drawing::Rectangle> RectangleVector;// vector of Line objects in the drawing window
	std::vector<Drawing::Triangle> TriangleVector;
	std::vector<Drawing::Fractal> FractalVector;
	std::vector<Drawing::Shape*> ShapeVector;
	DrawingState state; // current state of drawing 
	int x; // current x-coordinate of mouse pointer
	int y; // current x-coordinate of mouse pointer
	int x1[3];
	int y1[3];
	int lineWidth; // line width for drawing
	wxColour outlineColor; // outline color for drawing
	wxColour fillColor; // fill color for drawing
	int frames; //fractal depth

	DECLARE_EVENT_TABLE()
 };

#endif


