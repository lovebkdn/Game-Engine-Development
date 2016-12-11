/******************************************************************************/
/*!
  \file   Level1Stage.cpp
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   8/9/2016
  \brief  
    Implementation for the Level1Stage class methods.
*/
/******************************************************************************/
#include "Level1Stage.h"

/******************************************************************************/
/*!
  Constructor for the Level1Stage.
  Should pass pointer to the StageManager which governs this Level1Stage.
*/
/******************************************************************************/
Level1Stage::Level1Stage(StageManager* pStageManager)
: Stage(pStageManager){}

/******************************************************************************/
/*!
  Load objects needed for the Level1Stage here.
*/
/******************************************************************************/
void Level1Stage::Load()
{
  
}

/******************************************************************************/
/*!
  Initialize objects loaded in Level1Stage.
*/
/******************************************************************************/
void Level1Stage::Init()
{
  
}

/******************************************************************************/
/*!
  Any calculations needed to be reconducted real time,
  such as the objects' behavior changes should be done in this function.
*/
/******************************************************************************/
void Level1Stage::Update()
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
void Level1Stage::Shutdown()
{
  
}

/******************************************************************************/
/*!
  Unload is called when the game's Stage is changed to different kind of Stage.
*/
/******************************************************************************/
void Level1Stage::Unload()
{
  
}