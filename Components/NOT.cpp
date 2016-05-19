#include "NOT.h"

/* Constructor */
NOT::NOT(Output* pOut, const GraphicsInfo& gfxInfo, int fanOut) : LogicGate(pOut, gfxInfo, 1, fanOut) {
	mLabel = "NOT";
}

/* Calculates the output of the NOT gate */
void NOT::Operate() {
	mOutputPin.SetStatus(mInputPins[0].GetStatus() == Status::LOW ? Status::HIGH : Status::LOW);
}

/* Draws the NOT gate */
void NOT::Draw(Output* pOut) {
	if (!mDeleted) {
		pOut->DrawNOT(mGfxInfo, mSelected);
	}
}

/* Saves the states of the component*/
void NOT::Save(ofstream& file) {
	file << "NOT " << mID << " " << mLabel << " " << (mGfxInfo.x1 + mGfxInfo.x2) / 2 << " " << (mGfxInfo.y1 + mGfxInfo.y2) / 2 << endl;
}

/* Returns the Add-ActionType of the component */
ActionType NOT::GetAddActionType() const {
	return ActionType::ADD_GATE_NOT;
}