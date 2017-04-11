/****************************************************************
File: DrawingFrame.cpp				
Description: Handles construction of frame and buttons

Author:	Aashay Vadnagara	 
Class: CSCI	120	
Date: 4/5/2015		

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "DrawingFrame.h"
#include "DrawingWindow.h"

/**
 Default constructor. 
 Creates controls for the drawing interface and layout controls on the frame.
*/
DrawingFrame::DrawingFrame()
: wxFrame(NULL, -1, "Drawing Frame", wxPoint(-1, -1), wxSize(FRAME_WIDTH, FRAME_HEIGHT))
{
	wxPanel *panel = new wxPanel(this, -1);
	
	// layout sizers
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);

	// buttons
	lineButton = new wxButton(panel, ID_LINE_BTN, "Line");
	ellipseButton = new wxButton(panel, ID_ELLIPSE_BTN, "Ellipse");
	triangleButton = new wxButton(panel, ID_TRIANGLE_BTN, "Triangle");
	rectButton = new wxButton(panel, ID_RECTANGLE_BTN, "Rectangle");
	fractalButton = new wxButton(panel, ID_FRACTAL_BTN, "Fractal");
	clearButton = new wxButton(panel, ID_CLEAR_BTN, "Clear Canvas");
	
	// combo box for line width
	widthComboBox = new wxComboBox(panel, ID_WIDTH_COMBO);
	widthComboBox->Append(wxT("1"));
	widthComboBox->Append(wxT("2"));
	widthComboBox->Append(wxT("3"));
	widthComboBox->Append(wxT("4"));
	widthComboBox->Append(wxT("5"));
	widthComboBox->SetSelection(0);
	widthComboBox->SetEditable(false);

	//ADDED NEW COMBOBOX FOR FRACTAL RECURSION
	fracComboBox = new wxComboBox(panel, ID_FRACTAL_FRAMES);
	fracComboBox->Append(wxT("1"));
	fracComboBox->Append(wxT("2"));
	fracComboBox->Append(wxT("3"));
	fracComboBox->Append(wxT("4"));
	fracComboBox->SetSelection(0);
	fracComboBox->SetEditable(false);

	// color pickers 
	outlineColorPicker = new wxColourPickerCtrl(panel, ID_OUTLINE_COLOR, *wxBLACK, wxDefaultPosition);
	fillColorPicker = new wxColourPickerCtrl(panel, ID_FILL_COLOR, *wxWHITE, wxDefaultPosition);

	hbox1->Add(lineButton);
	hbox1->Add(ellipseButton);
	hbox1->Add(triangleButton);
	hbox1->Add(rectButton);
	hbox1->Add(fractalButton);
	hbox1->Add(clearButton);
	hbox3->Add(new wxStaticText(panel, ID_WIDTH_LBL, wxT("Line Width:  ")), 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(widthComboBox, 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(new wxStaticText(panel, ID_OUTLINE_LBL, wxT("   Outline:  ")), 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(outlineColorPicker, 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(new wxStaticText(panel, ID_WIDTH_LBL, wxT("   Fill:  ")), 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(fillColorPicker, 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(new wxStaticText(panel, ID_WIDTH_LBL, wxT("  Fractal Recursion:  ")), 0, wxALIGN_CENTER_VERTICAL, 0);
	hbox3->Add(fracComboBox, 0, wxALIGN_CENTER_VERTICAL, 0);

	wxPanel *panel2 = new wxPanel(panel, -1);
	window = new DrawingWindow(panel2);
	window->SetFocus();
	hbox2->Add(panel2);
 
	vbox->Add(hbox1, 0, wxCENTER | wxTOP);
	vbox->Add(hbox3, 0, wxCENTER | wxTOP);
	vbox->Add(hbox2, 1, wxEXPAND);
	panel->SetSizer(vbox);

	// status bar
	CreateStatusBar(3);
	SetStatusText(wxT("Ready"), 0);
}

/**
 * Event handler for the clear button
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnClearButton(wxCommandEvent& event) {
	window->setState(NONE); 
	SetStatusText(wxT("Ready"), 0);
}

/**
 * Event handler for the line button
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnLineButton(wxCommandEvent& event) {
	window->setState(LINE); 
	SetStatusText(wxT("Line"), 0);
}

/**
 * Event handler for the ellipse button
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnEllipseButton(wxCommandEvent& event) {
	window->setState(ELLIPSE);
	SetStatusText(wxT("Ellipse"), 0);
}

/**
 * Event handler for the rectangle button
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnRectangleButton(wxCommandEvent& event) {
	window->setState(RECTANGLE);
	SetStatusText(wxT("Rectangle"), 0);
}

/**
 * Event handler for the triangle button
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnTriangleButton(wxCommandEvent& event) {
	window->setState(TRIANGLE);
	SetStatusText(wxT("Triangle"), 0);
}

/**
 * Event handler for the fractal button
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnFractalButton(wxCommandEvent& event) {
	window->setState(FRACTAL);
	SetStatusText(wxT("Fractal"), 0);
}

/**
 * Event handler for the line width combo box
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnComboBoxUpdate(wxCommandEvent& event) {
	window->setLineWidth(widthComboBox->GetSelection() + 1);
}

/**
  Event handler for the recursion combo box
  @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnComboBoxFrac(wxCommandEvent& event) {
	window->setFractalFrames(fracComboBox->GetSelection() + 1);
}
/**
 * Event handler for the outline color picker
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnOutlineColorChange(wxColourPickerEvent& event) {
	window->setOutlineColor(outlineColorPicker->GetColour());
}

/**
 * Event handler for the fill color picker
 * @param event wxCommandEvent object associated with the event
 */
void DrawingFrame::OnFillColorChange(wxColourPickerEvent& event) {
	window->setFillColor(fillColorPicker->GetColour());
}