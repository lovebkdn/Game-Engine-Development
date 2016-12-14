/******************************************************************************/
/*!
  \file   StageManager.h
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   21/8/2016
  \brief  
		Includes interface for the StageManager and enumerations for all
		available Stages.
*/
/******************************************************************************/
#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

/*! Enum of all Stage type in the game */
enum StageType{ST_NotSet, ST_MenuStage};

/*Forward declaration for the Stage class, 
  so that StageManager can have the variable with the type Stage*.*/
class Stage;

/******************************************************************************/
/*!
  \class StageManager

	Interface for the GameManager class which manages
  #1 registering and creating Window class & updating the Window of the game
	#2 updating the Stage of the game
*/
/******************************************************************************/
class StageManager
{
  public:
    StageManager();
    ~StageManager();
    
    //These public methods are called in main().
    void Init();
    void Update();
    void Shutdown();
    
    /*These methods can be called inside the methods of,
      usually the Update function, from the derived classes
      of the base class Stage.*/
    void ChangeNextStage(StageType nextStage);
		void RestartStage();
  
  private:
    void DeleteCurrentStage();
    void UpdateCurrentStage();
    
		bool m_isStart;
    bool m_isRestarting;
    bool m_isQuitting;
    StageType m_currentStage;
    StageType m_nextStage;
    Stage* m_pCurrentStage;
};

#endif