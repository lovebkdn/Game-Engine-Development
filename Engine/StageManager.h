/******************************************************************************/
/*!
  \file   StageManager.h
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   21/8/2016
  \brief  
    Interface for the StageManager class which manage all stages in the game,
    based on the prompted information from the player.
*/
/******************************************************************************/
#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

/*! Enum of all Stage type in the game */
enum StageType{ST_Unknown, ST_MenuStage};

/*Forward declaration for the Stage class, 
  so that StageManager can have the variable with the type Stage*.*/
class Stage;

/******************************************************************************/
/*!
  \class StageManager

  Class used to manage all stages in the game.  
  Allows users to set the next stage, restart or quit.
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
    
    bool IsQuitting();
    
    /*These methods can be called inside the methods of,
      usually the Update function, from the derived classes
      of the base class Stage.*/
    void ChangeNextStage(StageType nextStage);
  
  private:
    void DeleteCurrentStage();
    void UpdateCurrentStage();
    
    bool m_isUpdating;
    bool m_isRestarting;
    bool m_isQuitting;
    StageType m_currentStage;
    StageType m_nextStage;
    Stage* m_pCurrentStage;
};

#endif