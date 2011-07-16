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
#include "wOutputMgr.hpp"

#include "types.hpp"

#include "net/connection.hpp"
#include "log.hpp"
#include "winOutputs.hpp"

#include <windows.h>

using namespace std;
using namespace droidpad;

OutputManager::OutputManager(const int type, const int numAxes, const int numButtons) :
	IOutputManager(type, numAxes, numButtons)
{

}

OutputManager::~OutputManager() {
}

void OutputManager::SendJSData(const DPJSData& data) {
}

void OutputManager::SendMouseData(const DPMouseData& data)
{
	if(!droidpad::win32::WinOutputs::SendMouseEvent(data.x / 400, -data.y / 400, data.bLeft, data.bMiddle, data.bRight, data.scrollDelta)) // TODO: Customise scale factors?
	{
		LOGWwx(wxT("SendInput failed") + GetLastError());
	}
}

void OutputManager::SendSlideData(const DPSlideData& data)
{
}

