/****************************************************************
File: DrawingFrame.h			
Description: Header file for DrawingFrame.cpp	

Author:	Aashay Vadnagara 
Class: CSCI	120	
Date: 4/5/2015			

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef DRAWINGFRAME_H
#define DRAWINGFRAME_H

#include "wx/wx.h"
#include "wx/clrpicker.h"
#include "DrawingWindow.h"

// IDs for GUI components
const int ID_CLEAR_BTN = 1;
const int ID_LINE_BTN = 2;
const int ID_ELLIPSE_BTN = 3;
const int ID_RECTANGLE_BTN = 5;
const int ID_TRIANGLE_BTN = 4;
const int ID_WIDTH_COMBO = 6;
const int ID_WIDTH_LBL = 7;
const int ID_OUTLINE_COLOR = 8;
const int ID_FILL_COLOR = 9;
const int ID_OUTLINE_LBL = 10;
const int ID_FILL_LBL = 11;
const int ID_FRACTAL_BTN = 12;
const int ID_FRACTAL_FRAMES = 13;

// frame dimensions
const int FRAME_WIDTH = 800;
const int FRAME_HEIGHT = 750;


/**
 A frame that shows the drawing program interfaces.
 */
class DrawingFrame : public wxFrame
{
public:
	// Constructs the interfaces.
	DrawingFrame();
	// Event handlers for buttons
	void OnClearButton(wxCommandEvent& event);
	void OnLineButton(wxCommandEvent& event);
	void OnEllipseButton(wxCommandEvent& event);
	void OnRectangleButton(wxCommandEvent& event);
	void OnTriangleButton(wxCommandEvent& event);
	void OnFractalButton(wxCommandEvent& event);
	// Event handler for combo box
	void OnComboBoxUpdate(wxCommandEvent& event);
	void OnComboBoxFrac(wxCommandEvent& event);
	// Event handlers for color pickers
	void OnOutlineColorChange(wxColourPickerEvent& event);
	void OnFillColorChange(wxColourPickerEvent& event);
private:
	// Drawable window
	DrawingWindow* window;
	// buttons
	wxButton* lineButton;
	wxButton* ellipseButton;
	wxButton* triangleButton;
	wxButton* rectButton;
	wxButton* clearButton;
	wxButton* fractalButton;
	// combo box
	wxComboBox* widthComboBox;
	wxComboBox* fracComboBox;
	// color pickers
	wxColourPickerCtrl* outlineColorPicker;
	wxColourPickerCtrl* fillColorPicker;

	DECLARE_EVENT_TABLE()
};




#endif