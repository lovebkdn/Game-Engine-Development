/******************************************************************************/
/*!
  \file   StageManager.cpp
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   21/8/2016
  \brief  
    Implementation for the StageManager class methods.
*/
/******************************************************************************/
#include "StageManager.h"

#include "MenuStage.h"

StageManager::StageManager()
{

}

StageManager::~StageManager()
{

}

/******************************************************************************/
/*!
  Initialize the StageManager.
*/
/******************************************************************************/
void StageManager::Init()
{
  m_isUpdating = false;
  m_isRestarting = false;
  m_isQuitting = false;
  
  //No current stage at the moment.
  m_currentStage = ST_Unknown;
  /*A stage the game would load up for the first time,
    is normally a menu stage; will let client decide on this in the future.*/
  m_nextStage = ST_MenuStage;
  m_pCurrentStage = 0;
}

/******************************************************************************/
/*!
  Update the StageManager.
*/
/******************************************************************************/
void StageManager::Update()
{
  //If it's start of the new Stage.
  if(!m_isRestarting)
  {
    /*Have to change what m_pCurrentStage points, 
      to a new kind of Stage.*/
    this->UpdateCurrentStage();
    m_pCurrentStage->Load();
  }
  
  //For both restart and start of the Stage.
  //We already loaded the stage before, just call Init() again.
  m_pCurrentStage->Init();
  
  m_isUpdating = true;
  
  while(m_isUpdating)
  {
    //Update Stage update function.
    m_pCurrentStage->Update();
  }
  
  //Whether it's a restart or quit, it must call Shutdown().
  m_pCurrentStage->Shutdown();
  
  if(m_isQuitting)
    m_pCurrentStage->Unload();
}

/******************************************************************************/
/*!
  Shutdown the StageManager.
*/
/******************************************************************************/
void StageManager::Shutdown()
{
  this->DeleteCurrentStage();
}

/******************************************************************************/
/*!
  Gettor for the private member variable m_isQuitting.
   
  \return - true if the game itself is quitting.
            false if the game is still running.
*/
/******************************************************************************/
bool StageManager::IsQuitting()
{
  return m_isQuitting;
}

/******************************************************************************/
/*!
  Stops running the Update function, as well as setting 
  what the next stage should be.

	\param nextStage
		enumeration telling what the next stage is
*/
/******************************************************************************/
void StageManager::ChangeNextStage(StageType nextStage)
{
  m_isUpdating = false;
  m_nextStage = nextStage;
}

/******************************************************************************/
/*!
  Delete what the current stage pointing pointer is pointing at.
*/
/******************************************************************************/
void StageManager::DeleteCurrentStage()
{
  if(m_pCurrentStage)
  {
    delete m_pCurrentStage;
    m_pCurrentStage = 0;
  }
}

/******************************************************************************/
/*!
  Delete what the current stage pointing pointer is pointing at.
*/
/******************************************************************************/
void StageManager::UpdateCurrentStage()
{
  m_currentStage = m_nextStage;
  m_nextStage = ST_Unknown;
  
  //Delete the old Stage which the pointer is currently pointing at.
  this->DeleteCurrentStage();
  
  //Two ways to implement the function.
  //First way would be by using simple switch statement.
  switch(m_currentStage)
  {
    case ST_MenuStage :
    {
      m_pCurrentStage = new MenuStage(this);
      break;
    }
    
    //No stage can have the StageType ST_Unknown, probably a call to assert.
    default :
      break;
  }
}