#pragma once

#include "gtest\gtest.h"
#include "ApplicationManager.h"
#include "Utilities\Defs.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Components\Component.h"
#include "Components\Gate.h"
#include "Components\Connection.h"
#include "Components\Switch.h"
#include "Components\LED.h"
#include "Components\AND.h"
#include "CMUgraphicsLib\colors.h"

#include "Actions\Action.h"
#include "Actions\AddConnection.h"
#include "Actions\AddGate.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Delete.h"
#include "Actions\Edit.h"
#include "Actions\Exit.h"
#include "Actions\Hover.h"
#include "Actions\LoadAction.h"
#include "Actions\Move.h"
#include "Actions\Paste.h"
#include "Actions\RedoAction.h"
#include "Actions\SaveAction.h"
#include "Actions\Select.h"
#include "Actions\Simulate.h"
#include "Actions\TruthTable.h"
#include "Actions\UndoAction.h"

#include "TestUtils.h"

class ApplicationManagerTest : public ::testing::Test {

};

bool compareColors(color c1, color c2){
	if (c1.ucBlue == c2.ucBlue && c1.ucGreen == c2.ucGreen && c1.ucRed == c2.ucRed)
		return true;
	return false;
}


// testing applicationmanager class
/*
 * methods that will not be tested due to it's dependency on gui purly:
 * - UpdateInterface
 * - 
 *
 *
 *
 */
//TEST(ApplicationManagerTest, TestAddComponent){
//	ApplicationManager appman;
//	GraphicsInfo g(2, 3, 4, 5);
//	
//	Component *c = new AND(appman.GetOutput(), g, 1);
//	Component **clist;
//	int x = appman.GetExistingComponentsCount();
//	appman.AddComponent(c);
//
//	ASSERT_TRUE(x + 1 == appman.GetExistingComponentsCount());
//	ASSERT_TRUE(appman.GetComponentList()[0] == c);
//}
//
//TEST(ApplicationManagerTest, TestGetExistingComponentsCount){
//	ApplicationManager a;
//	GraphicsInfo g(2, 3, 4, 5);
//
//	Component *c = new AND(a.GetOutput(), g, 1);
//	Component **clist;
//	a.AddComponent(c);
//
//	clist = a.GetComponentList();
//	clist[0]->Delete(a.GetOutput());
//	ASSERT_EQ(a.GetExistingComponentsCount(), 0);
//}
//
//TEST(ApplicationMAnagerTest, TestCountSelectedComponents){
//
//}

//TEST(ApplicationManagerTest, TestConstructor){
//	ApplicationManager appman;
//	Component** mcmp = appman.GetComponentList();
//	EXPECT_EQ(appman.GetExistingComponentsCount(), 0);
//	EXPECT_EQ(appman.GetCopiedComp(), (Component*) NULL);
//	EXPECT_TRUE(appman.GetOutput() != NULL);
//	EXPECT_TRUE(appman.GetInput() != NULL);
//}

/* Testing the get user action Function with it's sub function Input::getUserAction*/
/*TEST(ApplicationManagerTest, TestGetUserActionExit){
	cout << "Expecting exit action.\n";
	system("pause");
	ApplicationManager AppManager;
	ActionType oldAction = ActionType::HOVER, newAction;
	do {
		newAction = AppManager.GetUserAction();
		if (oldAction != newAction) break;
		oldAction = newAction;
		AppManager.UpdateInterface();
	} while (newAction != ActionType::EXIT);
	EXPECT_TRUE(newAction == ActionType::EXIT);
}
*/
//TEST(ApplicationManagerTest, TestSetGetCopiedComp){
//	ApplicationManager appman;
//	GraphicsInfo gfx;
//	
//	Component* comp = new AND(appman.GetOutput(), gfx, 1);
//	appman.SetCopiedComp(comp);
//	EXPECT_TRUE(comp == appman.GetCopiedComp());
//}


// ============================================================================= \\
// testing output class
/*
	methods that will not be tested because of their dependency on gui which is 
	assumed to be tested and well functioning well:
	- CreateStatusBar
	- ChangeTitle
	- CreateWind
	- ClearDrawingArea
	- ClearStatusBar
	- PrintMsg
	- UpdateScreen
	- StoreImage
	- DrawImage
	- DrawPNG
	- DrawLabel
	- DrawSelectionRectangle
	- Draw* ~ DrawSwitch

*/
//TEST(OutputTest, TestOutputConstructor){
//	Output* o = new Output();
//	
//	EXPECT_TRUE(UI.AppMode == Mode::DESIGN);
//	
//	EXPECT_TRUE(compareColors(UI.BackgroundColor, color(117, 117, 117)));
//	EXPECT_TRUE(compareColors(UI.DarkColor, color(66, 66, 66)));
//	EXPECT_TRUE(compareColors(UI.SelectionColor, color(255, 193, 7)));
//	EXPECT_TRUE(compareColors(UI.InvalidColor, color(213, 0, 0)));
//	EXPECT_TRUE(compareColors(UI.MsgColor, WHITE));
//	EXPECT_TRUE(compareColors(UI.ConnectionColor, BLACK));
//	EXPECT_TRUE(compareColors(UI.ConnectionOnColor, color(139, 195, 74)));
//
//	EXPECT_TRUE(o->GetCurrentWindow() != NULL);
//}
//
//TEST(OutputTest, TestCreateInput){
//	Output *out = new Output();
//	ASSERT_TRUE(out->CreateInput() != NULL);
//}
//
//TEST(OutputTest, TestGetCurrentWindow){
//	Output *out = new Output();
//	ASSERT_TRUE(out->GetCurrentWindow() != NULL);
//}

/*
TEST(OutputTest, TestCreateToolBar){
	// need 2 testcases to test this function to achieve edge coverage.
	Output *out = new Output();
	UI.AppMode = Mode::DESIGN;
	out->CreateToolBar();
	out->UpdateScreen();
	system("pause");
	
	UI.AppMode = Mode::SIMULATION;
	out->CreateToolBar();
	out->UpdateScreen();
	system("pause");

	// should test the screen by eye or tool. 
}
*/
/*
TEST(OutputTest, TestCreateGateBar){
	Output *out = new Output();
	UI.AppMode = Mode::DESIGN;
	out->CreateGateBar();
	out->UpdateScreen();
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->CreateGateBar();
	out->UpdateScreen();
	system("pause");
}
*/
/*
TEST(OutputTest, TestDrawSwitch){
	/* 
	 * what will be tested:
	 * 1st Testcase:
	 * gfxInfo.x1 == gfxInfo.x2 == gfxInfo.y1 == gfxInfo.y2 = 0
	 * mode design mode simulation
	 * Selected   on
	 *  T		  T
	 *  T		  F
	 *  F		  T
	 *  F		  F
	 * 2nd testcase:
	 * gfxinfo x1,y1 > 0
	 *
	 *
	 *
	Output *out = new Output();
	
	GraphicsInfo gfxInfo;
	gfxInfo.x1 = 0;
	gfxInfo.x2 = 0;
	gfxInfo.y1 = 0;
	gfxInfo.y2 = 0;


	UI.AppMode = Mode::DESIGN;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");
	
	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");


	gfxInfo.x1 = 5;
	gfxInfo.x2 = 0;
	gfxInfo.y1 = 5;
	gfxInfo.y2 = 0;

	UI.AppMode = Mode::DESIGN;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");



	
	gfxInfo.x1 = 0;
	gfxInfo.x2 = 5;
	gfxInfo.y1 = 0;
	gfxInfo.y2 = 5;


	UI.AppMode = Mode::DESIGN;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");


	gfxInfo.x1 = -5;
	gfxInfo.x2 = 5;
	gfxInfo.y1 = -5;
	gfxInfo.y2 = 5;


	UI.AppMode = Mode::DESIGN;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	gfxInfo.x1 = -5;
	gfxInfo.x2 = 0;
	gfxInfo.y1 = -5;
	gfxInfo.y2 = 0;

	UI.AppMode = Mode::DESIGN;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	gfxInfo.x1 = 0;
	gfxInfo.x2 = -5;
	gfxInfo.y1 = 0;
	gfxInfo.y2 = -5;

	UI.AppMode = Mode::DESIGN;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");

	UI.AppMode = Mode::SIMULATION;
	out->DrawSwitch(gfxInfo, true, true);
	system("pause");

	out->DrawSwitch(gfxInfo, true, false);
	system("pause");

	out->DrawSwitch(gfxInfo, false, true);
	system("pause");

	out->DrawSwitch(gfxInfo, false, false);
	system("pause");
}*/

// should test DrawConnection, DrawLED
//
//TEST(TestOutput, TestIsDrawingArea){
//	// there is good coverage application in this function.
//	// there is a good line here to remove to prove mistake. 
//	Output *out = new Output();
//	
//	ASSERT_FALSE(out->IsDrawingArea(0, 0));
//
//	ASSERT_FALSE(out->IsDrawingArea(0, UI.Height));
//	ASSERT_FALSE(out->IsDrawingArea(0, -UI.Height));
//
//	ASSERT_FALSE(out->IsDrawingArea(UI.Width, 0));
//	ASSERT_FALSE(out->IsDrawingArea(-UI.Width, 0));
//
//	ASSERT_FALSE(out->IsDrawingArea(UI.Width, UI.Height));
//	ASSERT_FALSE(out->IsDrawingArea(-UI.Width, -UI.Height));
//
//	ASSERT_FALSE(out->IsDrawingArea(0, UI.ToolBarHeight + UI.GateBarHeight)); // should be false, should fail
//	ASSERT_FALSE(out->IsDrawingArea(0, UI.Height - UI.StatusBarHeight)); 
//
//	ASSERT_TRUE(0, UI.ToolBarHeight + UI.GateBarHeight + 10);
//}
//
//TEST(TestOutput, TestMarkPins){
//	Output *out = new Output();
//	GraphicsInfo g;
//	g.x1 = 10;
//	g.y1 = UI.GateBarHeight + UI.ToolBarHeight + 10;
//
//	g.x2 = 10 + UI.PinOffset;
//	g.y2 = UI.GateBarHeight + UI.ToolBarHeight + 10 + UI.PinOffset;
//
//	Component *c = new AND(out, g, 1);
//	out->MarkPins(g, PinType::GATE, c);
//	ASSERT_TRUE(out->GetComponentAtPin(10, UI.GateBarHeight + UI.ToolBarHeight + 10) == c);
//
//}
//
//
//
//TEST(TestOutput, TestIsEmptyArea){
//	GraphicsInfo g;
//	Output *out = new Output();
//	g.x1 = 10;
//	g.y1 = UI.GateBarHeight + UI.ToolBarHeight + 10;
//	g.x2 = 10 + UI.PinOffset;
//	g.y2 = UI.GateBarHeight + UI.ToolBarHeight + 10 + UI.PinOffset;
//	Component *c = new AND(out, g, 1);
//	out->MarkPins(g, PinType::GATE, c);
//	ASSERT_FALSE(out->IsEmptyArea(g));
//
//	g.x1 = 100;
//	g.y1 = UI.GateBarHeight + UI.ToolBarHeight + 100;
//	g.x2 = 100 + UI.PinOffset;
//	g.y2 = UI.GateBarHeight + UI.ToolBarHeight + 100 + UI.PinOffset;
//	ASSERT_TRUE(out->IsEmptyArea(g));
//
//	g.x1 = -UI.PinOffset;
//	g.y1 = -UI.PinOffset;
//	g.x2 = -UI.PinOffset;
//	g.y2 = -UI.PinOffset;
//	ASSERT_FALSE(out->IsEmptyArea(g));
//
//	g.x1 = UI.Width;
//	g.y1 = UI.Height;
//	g.x2 = UI.Width + UI.PinOffset;
//	g.y2 = UI.Height + UI.PinOffset;
//	ASSERT_FALSE(out->IsEmptyArea(g));
//
//	g.x1 = UI.HorPinsCount;
//	g.y1 = UI.VerPinsCount;
//	g.x2 = UI.HorPinsCount + UI.PinOffset;
//	g.y2 = UI.VerPinsCount + UI.PinOffset;
//	ASSERT_FALSE(out->IsEmptyArea(g));
//}
//
//TEST(TestOutput, TestMarkConnectionPins){
//	Output *out = new Output();
//	vector<GraphicsInfo> vec;
//	GraphicsInfo g1, g2;
//	Component *c;
//	g1.x1 = 0;
//	g1.y1 = UI.ToolBarHeight + UI.GateBarHeight;
//	g1.x2 = UI.PinOffset;
//	g1.y2 = UI.ToolBarHeight + UI.GateBarHeight + UI.PinOffset;
//
//	g2.x1 = 0;
//	g2.y1 = UI.ToolBarHeight + UI.GateBarHeight + 10;
//	g2.x2 = UI.PinOffset + 10;
//	g2.y2 = UI.ToolBarHeight + UI.GateBarHeight + UI.PinOffset + 10;
//
//	c = new AND(out, g1, 1);
//	vec.push_back(g1);
//	out->MarkConnectionPins(vec, c);
//	ASSERT_FALSE(out->IsEmptyArea(g1));
//	ASSERT_TRUE(out->GetComponentAtPin(g1.x1, g1.y1) != NULL);
//	ASSERT_FALSE(out->GetComponentAtPin(g1.x1, g1.x2) == c);
//	
//	delete out;
//	out = new Output();
//	vec.push_back(g2);
//	out->MarkConnectionPins(vec, c);
//	EXPECT_FALSE(out->IsEmptyArea(g2));
//	EXPECT_TRUE(out->GetComponentAtPin(g2.x1, g2.y1) != NULL);
//	EXPECT_FALSE(out->GetComponentAtPin(g2.x1, g2.x2) == c);
//}
//
//TEST(TestOutput, TestClearConnectionPins){
//	Output *out = new Output();
//	vector<GraphicsInfo> vec;
//	GraphicsInfo g1, g2;
//	Component *c;
//	g1.x1 = 0;
//	g1.y1 = UI.ToolBarHeight + UI.GateBarHeight;
//	g1.x2 = UI.PinOffset;
//	g1.y2 = UI.ToolBarHeight + UI.GateBarHeight + UI.PinOffset;
//
//	g2.x1 = 0;
//	g2.y1 = UI.ToolBarHeight + UI.GateBarHeight + 10;
//	g2.x2 = UI.PinOffset + 10;
//	g2.y2 = UI.ToolBarHeight + UI.GateBarHeight + UI.PinOffset + 10;
//
//	c = new AND(out, g1, 1);
//	vec.push_back(g1);
//	out->MarkConnectionPins(vec, c);
//	out->ClearConnectionPins(vec);
//	ASSERT_FALSE(out->IsEmptyArea(g1));
//	ASSERT_TRUE(out->GetComponentAtPin(g1.x1, g1.y1) != NULL);
//	ASSERT_FALSE(out->GetComponentAtPin(g1.x1, g1.x2) == c);
//	out->ClearConnectionPins(vec);
//	ASSERT_TRUE(out->IsEmptyArea(g1));
//	ASSERT_FALSE(out->GetComponentAtPin(g1.x1, g1.y1) != NULL);
//	ASSERT_FALSE(out->GetComponentAtPin(g1.x1, g1.x2) == c);
//
//
//	delete out;
//	out = new Output();
//	vec.push_back(g2);
//	out->MarkConnectionPins(vec, c);
//	EXPECT_FALSE(out->IsEmptyArea(g2));
//	EXPECT_TRUE(out->GetComponentAtPin(g2.x1, g2.y1) != NULL);
//	EXPECT_FALSE(out->GetComponentAtPin(g2.x1, g2.x2) == c);
//	out->ClearConnectionPins(vec);
//	ASSERT_TRUE(out->IsEmptyArea(g1));
//	ASSERT_FALSE(out->GetComponentAtPin(g1.x1, g1.y1) != NULL);
//	ASSERT_FALSE(out->GetComponentAtPin(g1.x1, g1.x2) == c);
//}
//
//TEST(TestOutput, TestGetComponentAtPin){
//	Output *out = new Output();
//	GraphicsInfo g;
//	g.x1 = 10;
//	g.y1 = UI.GateBarHeight + UI.ToolBarHeight + 10;
//	g.x2 = 10 + UI.PinOffset;
//	g.y2 = UI.GateBarHeight + UI.ToolBarHeight + 10 + UI.PinOffset;
//	Component *c = new AND(out, g, 1);
//	out->MarkPins(g, PinType::GATE, c);
//	ASSERT_FALSE(out->IsEmptyArea(g));
//	ASSERT_TRUE(out->GetComponentAtPin(g.x1, g.y1) != NULL);
//	ASSERT_TRUE(out->GetComponentAtPin(g.x1, g.y1) == c);
//
//	EXPECT_TRUE(out->GetComponentAtPin(-1, -1) == NULL);
//	EXPECT_TRUE(out->GetComponentAtPin(-1, UI.VerPinsCount) == NULL);
//	EXPECT_TRUE(out->GetComponentAtPin(UI.HorPinsCount, -1) == NULL);
//	EXPECT_TRUE(out->GetComponentAtPin(UI.HorPinsCount, UI.VerPinsCount) == NULL);
//}
//
//TEST(TestOutput, TestGetConnectionPath){
//
//}

// ================================================================================= \\

// testing Actions
TEST(TestActions, TestAddConnection){
	ApplicationManager apm;
	GraphicsInfo g1;
	g1.x1 = 15;
	g1.y1 = UI.GateBarHeight + UI.ToolBarHeight + 15;
	g1.x2 = 15 + UI.PinOffset;
	g1.y2 = UI.GateBarHeight + UI.ToolBarHeight + 15 + UI.PinOffset;

	GraphicsInfo g2;
	g2.x1 = 30;
	g2.y1 = UI.GateBarHeight + UI.ToolBarHeight + 30;
	g2.x2 = 30 + UI.PinOffset;
	g2.y2 = UI.GateBarHeight + UI.ToolBarHeight + 30 + UI.PinOffset;


	Data *dm = new Data();
	dm->GfxInfo = g1;
	dm->Label = "test";
	Component *c1 = new AND(apm.GetOutput(), g1, 1);
	Component *c2 = new AND(apm.GetOutput(), g2, 1);
	apm.AddComponent(c1);
	apm.AddComponent(c2);
	Action *a = new AddConnection(&apm, NULL);
	ASSERT_TRUE(a != NULL);
	ASSERT_TRUE(a->ReadActionParameters());
	Component **clist = apm.GetComponentList();
	
	delete clist[0];
	delete c1;
	ASSERT_FALSE(a->ReadActionParameters());
	delete clist[1];
	delete c2;
	ASSERT_FALSE(a->ReadActionParameters());

	Action *b = new AddConnection(&apm, dm);
	ASSERT_TRUE(b != NULL);
	ASSERT_TRUE(b->ReadActionParameters());

	///////////////////////////////
	c1 = new AND(apm.GetOutput(), g1, 1);
	c2 = new AND(apm.GetOutput(), g2, 1);
	apm.AddComponent(c1);
	ASSERT_FALSE(a->Execute());

	apm.AddComponent(c2);
	ASSERT_TRUE(a->Execute());
}

TEST(TestActions, Test){

}


