/*
 * This file is part of DroidPad.
 * DroidPad lets you use an Android mobile to control a joystick or mouse
 * on a Windows or Linux computer.
 *
 * DroidPad is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DroidPad is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DroidPad, in the file COPYING.
 * If not, see <http://www.gnu.org/licenses/>.
 */

// Based on http://wiki.wxwidgets.org/An_image_panel

#ifndef WX_QR_PANEL_H
#define WX_QR_PANEL_H

#include <wx/panel.h>
#include <wx/bitmap.h>

#include <qrencode.h>

class qrPanel : public wxPanel
{
	public:
		qrPanel(wxWindow *parent, wxString text);
		virtual ~qrPanel();

		void setContent(wxString text);

	protected:
		void paintEvent(wxPaintEvent & evt);
		void paintNow();

		void render(wxDC& dc);

		QRcode *createQrData(wxString text);

	private:
		QRcode *code;

		DECLARE_EVENT_TABLE()
};
#endif
