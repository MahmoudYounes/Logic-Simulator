#pragma once
#include "Component.h"
#include "../Pins/Pin.h"
#include <vector>

class Connection : public Component
{
private:
	vector<GraphicsInfo> mPath;		// The path of the connection
	Pin* mSrcPin;					// The source pin of this connection (an output pin of a certain Component)
	Pin* mDstPin;					// The destination pin of this connection (an input pin of a certain Component)

public:
	/* Constructor */
	Connection(Output* pOut, const GraphicsInfo& gfxInfo, const vector<GraphicsInfo>& path);

	/* Sets the new path of the connection, needed in edit action */
	void SetPath(Output* pOut, const GraphicsInfo& gfxInfo, const vector<GraphicsInfo>& path);

	/* Returns the path of the connection */
	vector<GraphicsInfo> GetPath() const;

	/* Sets the source pin of the connection */
	void SetSourcePin(Pin* pSrcPin);

	/* Returns the source pin of the connection */
	Pin* GetSourcePin() const;

	/* Sets the destination pin of the connection */
	void SetDestinationPin(Pin* pDstPin);

	/* Returns the destination pin of the connection */
	Pin* GetDestinationPin() const;

	/* Calculates the output according to the inputs */
	virtual void Operate();

	/* Sets the status of the input pin number n (0-indexed) */
	virtual void SetInputPinStatus(int n, Status s);

	/* Returns the status of the input pin number n (0-indexed), if Switch returns -1 */
	virtual int GetInputPinStatus(int n) const;

	/* Returns the status of the output pin, if LED returns -1 */
	virtual int GetOutputPinStatus() const;

	/* Draws the connection */
	virtual void Draw(Output* pOut);

	/* Deletes the component */
	virtual void Delete(Output* pOut);

	/* Restores the component after being deleted */
	virtual void Restore(Output* pOut);

	/* Saves the states of the component */
	virtual void Save(ofstream& file);

	/* Returns the Add-ActionType of the component */
	virtual ActionType GetAddActionType() const;
};