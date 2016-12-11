/******************************************************************************/
/*!
  \file   MenuStage.cpp
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   1/9/2016
  \brief  
    Implementation for the MenuStage class methods.
*/
/******************************************************************************/
#include "MenuStage.h"

/******************************************************************************/
/*!
  Constructor for the MenuStage.
  Should pass pointer to the StageManager which governs this MenuStage.

	\param pStageManager
		
*/
/******************************************************************************/
MenuStage::MenuStage(StageManager* pStageManager)
: Stage(pStageManager){}

/******************************************************************************/
/*!
  Load objects needed for the MenuStage here.
*/
/******************************************************************************/
void MenuStage::Load()
{
  
}

/******************************************************************************/
/*!
  Initialize objects loaded in MenuStage.
*/
/******************************************************************************/
void MenuStage::Init()
{
  
}

/******************************************************************************/
/*!
  Any calculations needed to be reconducted real time,
  such as the objects' behavior changes should be done in this function.
*/
/******************************************************************************/
void MenuStage::Update()
{
  
}

/******************************************************************************/
/*!
  When the Stage gets restarted, control flow of the game never reaches
  the Unload() of the Stage, but it has to pass by this Shutdown function.
  It delete or deallocate the objects, possibly dynamically allocated
  inside the Init function of this Stage.
*/
/******************************************************************************/
void MenuStage::Shutdown()
{
  
}

/******************************************************************************/
/*!
  Unload is called when the game's Stage is changed to different kind of Stage.
*/
/******************************************************************************/
void MenuStage::Unload()
{
  
}