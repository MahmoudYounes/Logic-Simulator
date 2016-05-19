#include "Input.h"
#include "Output.h"

/* Constructor */
Input::Input(window* pW) {
	pWind = pW;
}

/* Get the user's mouse click coordinate */
void Input::GetPointClicked(int& x, int& y) const {
	pWind->WaitMouseClick(x, y);
}

/* Returns the last point clicked by the user */
void Input::GetLastPointClicked(int& x, int& y) const {
	x = mLastX;
	y = mLastY;
}

/* Returns the string entered by the user and reflect it on the status bar */
string Input::GetSrting(Output* pOut, string msg, string str) const {
	// ASCII Codes
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;

	char c;
	string s = str;

	do {
		pOut->PrintMsg(msg + " " + s);
		pWind->WaitKeyPress(c);
		
		switch (c) {
		case BACKSPACE:
			if (!s.empty()) s.pop_back();
			break;
		case ESCAPE:
			s.clear();
			break;
		case ENTER:
			// Nothing to be done here
			break;
		default:
			s.push_back(c);
			break;
		}

	} while (c != ESCAPE && c != ENTER);

	return s;
}

/* Reads the user's selection and determine the desired action */
ActionType Input::GetUserAction(Output* pOut) {

	int x = 0, y = 0;
	clicktype Click = NO_CLICK;

	/* Reads the Mouse Input */
	while (Click == NO_CLICK) {
		if (pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN) {
			mLastX = x;
			mLastY = y;
			// User clicks on the drawing area
			if (y >= UI.ToolBarHeight + UI.GateBarHeight && y < UI.Height - UI.StatusBarHeight) {
				if (pOut->GetComponentAtPin(x, y) != NULL) {
					int OldX = x, OldY = y;
					while (pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN) {
						if (OldX != x || OldY != y)
							return ActionType::MOVE;
					}
				}
				return ActionType::SELECT;
			}
			Click = pWind->WaitMouseClick(x,y);
		}
		else if (pWind->GetButtonState(RIGHT_BUTTON, x, y) == BUTTON_UP) {
			return ActionType::HOVER;
		}
	}

	mLastX = x;
	mLastY = y;
	// User clicks on the tool bar
	if (y >= 0 && y < UI.ToolBarHeight) {
		int clickedItemOrder = x / UI.ToolItemWidth;

		if (UI.AppMode == Mode::DESIGN) {
			switch (clickedItemOrder) {
			case ToolBarItem::ITEM_EDIT:
				return ActionType::EDIT;
			case ToolBarItem::ITEM_DELETE:
				return ActionType::DEL;
			case ToolBarItem::ITEM_COPY:
				return ActionType::COPY;
			case ToolBarItem::ITEM_CUT:
				return ActionType::CUT;
			case ToolBarItem::ITEM_PASTE:
				return ActionType::PASTE;
			case ToolBarItem::ITEM_UNDO:
				return ActionType::UNDO;
			case ToolBarItem::ITEM_REDO:
				return ActionType::REDO;
			case ToolBarItem::ITEM_PLAY:
				return ActionType::SIMULATION_MODE;
			case ToolBarItem::ITEM_SAVE:
				return ActionType::SAVE;
			case ToolBarItem::ITEM_LOAD:
				return ActionType::LOAD;
			case ToolBarItem::ITEM_EXIT:
				return ActionType::EXIT;
			default:
				return ActionType::TOOL_BAR;
			}
		}
		else {
			switch (clickedItemOrder) {
			case ToolBarItem::ITEM_PAUSE:
				return ActionType::DESIGN_MODE;
			case ToolBarItem::ITEM_TRUTHTABLE:
				return ActionType::CREATE_TRUTH_TABLE;
			case ToolBarItem::ITEM_EXIT:
				return ActionType::EXIT;
			default:
				return ActionType::TOOL_BAR;
			}
		}
	}
	// User clicks on the gate bar
	else if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight + UI.GateBarHeight) {
		int clickedItemOrder = x / UI.GateItemWidth;

		if (UI.AppMode == Mode::DESIGN) {
			switch (clickedItemOrder) {
			case GateBarItem::ITEM_AND:
				return ActionType::ADD_GATE_AND;
			case GateBarItem::ITEM_NAND:
				return ActionType::ADD_GATE_NAND;
			case GateBarItem::ITEM_AND3:
				return ActionType::ADD_GATE_AND3;
			case GateBarItem::ITEM_OR:
				return ActionType::ADD_GATE_OR;
			case GateBarItem::ITEM_NOR:
				return ActionType::ADD_GATE_NOR;
			case GateBarItem::ITEM_NOR3:
				return ActionType::ADD_GATE_NOR3;
			case GateBarItem::ITEM_XOR:
				return ActionType::ADD_GATE_XOR;
			case GateBarItem::ITEM_XNOR:
				return ActionType::ADD_GATE_XNOR;
			case GateBarItem::ITEM_XOR3:
				return ActionType::ADD_GATE_XOR3;
			case GateBarItem::ITEM_BUFFER:
				return ActionType::ADD_GATE_BUFFER;
			case GateBarItem::ITEM_NOT:
				return ActionType::ADD_GATE_NOT;
			case GateBarItem::ITEM_CONNECTION:
				return ActionType::ADD_CONNECTION;
			case GateBarItem::ITEM_SWITCH:
				return ActionType::ADD_SWITCH;
			case GateBarItem::ITEM_LED:
				return ActionType::ADD_LED;
			default:
				return ActionType::GATE_BAR;
			}
		}
		else {
			return ActionType::GATE_BAR;
		}
	}
	// User clicks on the status bar
	else {
		return ActionType::STATUS_BAR;
	}	
}

/* Destructor */
Input::~Input() {

}