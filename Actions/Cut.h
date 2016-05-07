#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include <vector>

class Cut : public Action
{
private:
	vector<Component*> mCutComps;

public:
	/* Constructor */
	Cut(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual bool ReadActionParameters();

	/* Executes action */
	virtual bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Cut();
};

