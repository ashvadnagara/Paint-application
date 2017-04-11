/****************************************************************
File: Main.cpp				
Description: Main function map	

Author:	Aashay Vadnagara	 
Class:	CSCI 120	
Date:	4/5/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "DrawingWindow.h"
#include "DrawingFrame.h"

/**
 A drawing application for basic geometrical shapes.
 */

class DrawingApp : public wxApp
{
public:
	/**
	Constructs and shows the frame.
	@return true
	*/
	virtual bool OnInit();
private:
	DrawingFrame* frame;
};

DECLARE_APP(DrawingApp)

IMPLEMENT_APP(DrawingApp)

BEGIN_EVENT_TABLE(DrawingWindow, wxWindow)
EVT_MOUSE_EVENTS(DrawingWindow::OnMouseEvent)
EVT_PAINT(DrawingWindow::OnPaint)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(DrawingFrame, wxFrame)
	EVT_BUTTON(ID_CLEAR_BTN, DrawingFrame::OnClearButton)
	EVT_BUTTON(ID_LINE_BTN, DrawingFrame::OnLineButton)
	EVT_BUTTON(ID_ELLIPSE_BTN, DrawingFrame::OnEllipseButton)
	EVT_BUTTON(ID_RECTANGLE_BTN, DrawingFrame::OnRectangleButton)
	EVT_BUTTON(ID_TRIANGLE_BTN, DrawingFrame::OnTriangleButton)
	EVT_BUTTON(ID_FRACTAL_BTN, DrawingFrame::OnFractalButton)
	EVT_COMBOBOX(ID_WIDTH_COMBO, DrawingFrame::OnComboBoxUpdate)
	EVT_COMBOBOX(ID_FRACTAL_FRAMES, DrawingFrame::OnComboBoxFrac)
	EVT_COLOURPICKER_CHANGED(ID_OUTLINE_COLOR, DrawingFrame::OnOutlineColorChange)
	EVT_COLOURPICKER_CHANGED(ID_FILL_COLOR, DrawingFrame::OnFillColorChange)
END_EVENT_TABLE()

/**
 Constructs and shows the frame.
 @return true
 */
bool DrawingApp::OnInit()
{
	frame = new DrawingFrame();
	frame->Show(true);
	return true;
}


