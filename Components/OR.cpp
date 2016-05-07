#include "OR.h"

/* Constructor */
OR::OR(Output* pOut, const GraphicsInfo& gfxInfo, int fanOut) : LogicGate(pOut, gfxInfo, 2, fanOut) {
	mLabel = "OR";
}

/* Calculates the output of the OR gate */
void OR::Operate() {
	bool out = 0;

	for (int i = 0; i < mInputsCount; i++) {
		out = out || (mInputPins[i].GetStatus() == Status::HIGH ? 1 : 0);
	}

	mOutputPin.SetStatus(out ? Status::HIGH : Status::LOW);
}

/* Draws the OR gate */
void OR::Draw(Output* pOut) {
	if (!mDeleted) {
		pOut->DrawOR(mGfxInfo, mSelected);
	}
}

/* Saves the states of the component*/
void OR::Save(ofstream& file) {
	file << "OR " << mID << " " << mLabel << " " << (mGfxInfo.x1 + mGfxInfo.x2) / 2 << " " << (mGfxInfo.y1 + mGfxInfo.y2) / 2 << endl;
}

/* Returns the Add-ActionType of the component */
ActionType OR::GetAddActionType() const {
	return ActionType::ADD_GATE_OR;
}