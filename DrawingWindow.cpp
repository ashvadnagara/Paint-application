/****************************************************************
File: DrawingWindow.cpp			
Description: The base for the drawing function

Author:	Aashay Vadnagara
Class:	CSCI 120
Date:	4/5/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "DrawingWindow.h"
#include <wx/dcbuffer.h>

/**
 Parameterized constructor given the parent window control.
 @param parent parent wxWindow object
*/
DrawingWindow::DrawingWindow(wxWindow* parent)
 : wxWindow(parent, wxID_ANY) {
	corners = 0;
	x = -1;
	y = -1;
	// set size of window
	wxSize size(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetSize(size);
	// set background color
	wxColour col1;
	col1.Set(BACKGROUND_COLOR);
	SetBackgroundColour(col1);
	// default line width and colors
	lineWidth = 1;
	outlineColor = *wxBLACK;
	fillColor = *wxWHITE;	
}

/**
 Mouse event handler. 
 Constructs and stores the geometrical shapes being drawn.
 @param event wxMouseEvent object
*/
void DrawingWindow::OnMouseEvent(wxMouseEvent& event) {
	// mouse position
	x = event.GetX();
	y = event.GetY();
	x1[corners] = event.GetX();
	y1[corners] = event.GetY();
	setOutlineColor(outlineColor);
	setFillColor(fillColor);
	setLineWidth(lineWidth);

	switch(state) {
	case LINE:
		if (event.LeftDown()) {
			if (corners == 0) { // just started dragging
				// set start point
				Drawing::Line Line;
				Line.setOutlineColor(outlineColor);
				Line.setFillColor(wxTRANSPARENT);
				Line.setLineWidth(lineWidth);
				Line.setStartPoint(x, y);
				Line.setEndPoint(x, y);
				lineVector.push_back(Line);
				ShapeVector.push_back(&Line);
				corners++;
				Refresh();
			}
		}
		if (event.LeftIsDown()) { // still dragging
			if (corners > 0) {
				lineVector.at(lineVector.size() - 1).setEndPoint(x, y);
				Refresh();
			}
		}
		if (event.LeftUp()) { // done with dragging
			if (corners > 0) {
			// set end point
				lineVector.at(lineVector.size() - 1).setEndPoint(x, y);
				corners = 0;
				Refresh();
			}
		}
		
		break;
	case TRIANGLE:
		if (event.LeftDown() && corners < 3) {
                // just started dragging
                // set start point
                Drawing::Triangle Triangle;
				Triangle.setFillColor(fillColor);
				Triangle.setOutlineColor(outlineColor);
				Triangle.setLineWidth(lineWidth);
                Triangle.setStartPoint(x, y);
				Triangle.setMidPoint(x,y);
                Triangle.setEndPoint(x, y);
                TriangleVector.push_back(Triangle); //Holds new triangle positions.
				ShapeVector.push_back(&Triangle);
                corners++;
                Refresh();
            
        }
        if (corners == 1) { // still dragging
                TriangleVector.at(TriangleVector.size() - 1).setStartPoint(x, y);
                Refresh();
            
        }
        if (corners >= 2) { // dragging next point
                TriangleVector.at(TriangleVector.size() - 1).setEndPoint(x, y);
                Refresh();
        }
        if (corners >= 3) { // done dragging, forces line to finish
                TriangleVector.at(TriangleVector.size() - 1).setEndPoint(x, y);
                TriangleVector.at(TriangleVector.size() - 1) = TriangleVector.at(TriangleVector.size() - 3);
                TriangleVector.at(TriangleVector.size() - 1).setEndPoint(x, y);
				corners = 0;
                Refresh();
            
        }


		break;
	case ELLIPSE:
		if (event.LeftDown()) {// just started dragging
			 
				Drawing::Ellipse Ellipse;
				Ellipse.setFillColor(fillColor);
				Ellipse.setOutlineColor(outlineColor);
				Ellipse.setLineWidth(lineWidth);
				Ellipse.setStartPoint(x, y);
				Ellipse.setEndPoint(x, y);
				EllipseVector.push_back(Ellipse);
				ShapeVector.push_back(&Ellipse);
				Refresh();
		}
		
		if (event.LeftIsDown()) { // still dragging
			
				EllipseVector.at(EllipseVector.size() - 1).setEndPoint(x, y);
				Refresh();
			
		}
		if (event.LeftUp()) { // done with dragging
			
				// set end point
				EllipseVector.at(EllipseVector.size() - 1).setEndPoint(x, y);
				
				Refresh();
			
		}


		break;
	case RECTANGLE:
		if (event.LeftDown()) {// just started dragging
			 
				Drawing::Rectangle Rectangle;
				Rectangle.setFillColor(fillColor);
				Rectangle.setOutlineColor(outlineColor);
				Rectangle.setLineWidth(lineWidth);
				Rectangle.setStartPoint(x, y);
				Rectangle.setEndPoint(x, y);
				RectangleVector.push_back(Rectangle);
				ShapeVector.push_back(&Rectangle);
				Refresh();
		}
		
		if (event.LeftIsDown()) { // still dragging
			
				RectangleVector.at(RectangleVector.size() - 1).setEndPoint(x, y);
				Refresh();
			
		}
		if (event.LeftUp()) { // done with dragging
			
				// set end point
				RectangleVector.at(RectangleVector.size() - 1).setEndPoint(x, y);
				
				Refresh();
		}


		break;
	case FRACTAL:
		if (event.LeftDown()) {// just started dragging
			Drawing::Fractal Fractal;
			Fractal.setOutlineColor(outlineColor);
			Fractal.setFillColor(fillColor);
			Fractal.setLineWidth(lineWidth);
			Fractal.SetFractalFrames(frames);
			Fractal.setStartPoint(x, y);
			Fractal.setEndPoint(x, y);
			FractalVector.push_back(Fractal);
			ShapeVector.push_back(&Fractal);
			Refresh();
		}
		
		if (event.LeftIsDown()) { // still dragging
			FractalVector.at(FractalVector.size() - 1).setEndPoint(x, y);
			Refresh();
			
		}
		if (event.LeftUp()) { // done with dragging
			// set end point
			FractalVector.at(FractalVector.size() - 1).setEndPoint(x, y);
			Refresh();
		}
		
		break;
		
	default:
		break;
	}
}

/**
 Paints the window.
 @param event wxPaintEvent object
*/
void DrawingWindow::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);
	
	if (state != NONE) {
		// draw each line on the window
		
		for (unsigned int i = 0; i < lineVector.size(); ++i) {
			lineVector.at(i).draw(dc);
		}
		for (unsigned int i = 0; i < EllipseVector.size(); ++i) {
			EllipseVector.at(i).draw(dc);
		}
		for (unsigned int i = 0; i < RectangleVector.size(); ++i) {
			RectangleVector.at(i).draw(dc);
		}
		for (unsigned int i = 0; i < TriangleVector.size(); ++i) {
			TriangleVector.at(i).draw(dc);
		}
		for (unsigned int i = 0; i < FractalVector.size(); ++i) {
			FractalVector.at(i).draw(dc);
		}
		
	}
}

/**
 Sets the current drawing state.
 @param state DrawingState object
*/
void DrawingWindow::setState(DrawingState state) {
	this->state = state;
	if (state == NONE) {
		// clear all shapes
		lineVector.clear();
		EllipseVector.clear();
		RectangleVector.clear();
		TriangleVector.clear();
		FractalVector.clear();
		corners = 0;
		Refresh();
	}
}

/**
 Sets the current drawing line width.
 @param width new line width value (integer)
*/
void DrawingWindow::setLineWidth(int width) {
	lineWidth = width;
}

/**
 Sets the current drawing outline color.
 @param color wxColour value
*/
void DrawingWindow::setOutlineColor(wxColour color) {
	outlineColor = color;
}

/**
 Sets the current drawing fill color.
 @param color wxColour value
 */
void DrawingWindow::setFillColor(wxColour color) {
	fillColor = color;
}

void DrawingWindow::setFractalFrames(int frames){
	this->frames = frames;
}

