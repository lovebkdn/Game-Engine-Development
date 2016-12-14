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
	m_isStart = true;
  m_isRestarting = false;
  m_isQuitting = false;
  
  //No current stage at the moment.
	m_currentStage = ST_NotSet;
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
	if (m_isStart)
	{
		/*
			Have to change what m_pCurrentStage points,
			to a new kind of Stage.
		*/
		this->UpdateCurrentStage();
		m_pCurrentStage->Load();
		m_pCurrentStage->Init();
		m_isStart = false;
	}
	//We already loaded the stage before, just call Init() again.
	else if (m_isRestarting)
	{
		m_pCurrentStage->Init();
		m_isRestarting = false;
	}
  
	//Update Stage
  m_pCurrentStage->Update();

	//Whether it's a restart or quit, it must call Shutdown().
	if (m_isRestarting)
		m_pCurrentStage->Shutdown();
	else if (m_isQuitting)
	{
		m_pCurrentStage->Shutdown();
		m_pCurrentStage->Unload();
	}
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
  Set what will be the next stage.
	Setting the nextStage to 
	#1 ST_NotSet will do nothing.
	#2 same stage as the current one will do nothing.

	\param nextStage
		enumeration telling what the next stage is
*/
/******************************************************************************/
void StageManager::ChangeNextStage(StageType nextStage)
{
	if ((nextStage != ST_NotSet) &&
			(nextStage != m_currentStage))
	{
		m_nextStage = nextStage;
		m_isQuitting = true;
		m_isStart = true;
	}
}

void StageManager::RestartStage()
{
	m_isRestarting = true;
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
	if (m_nextStage != ST_NotSet)
	{
		m_currentStage = m_nextStage;
		m_nextStage = ST_NotSet;

		//Delete the old Stage which the pointer is currently pointing at.
		this->DeleteCurrentStage();

		//Two ways to implement the function.
		//First way would be by using simple switch statement.
		switch (m_currentStage)
		{
			case ST_MenuStage:
			{
				m_pCurrentStage = new MenuStage(this);
				break;
		}

			//No stage can have the StageType ST_NotSet, probably a call to assert.
			default:
				break;
		}
	}
}