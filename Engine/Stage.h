/******************************************************************************/
/*!
  \file   Stage.h
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   1/9/2016
  \brief  
    Interface for the Stage base class.
*/
/******************************************************************************/
#ifndef STAGE_H
#define STAGE_H

/*Forward declaration for the StageManager class, which is necessary
  for the Stage derived classes to call the public methods of the
  StageManager class.*/
class StageManager;

/******************************************************************************/
/*!
  \class Stage

  Stage base class.
*/
/******************************************************************************/
class Stage
{
  public:
  
    Stage(StageManager* pStageManager)
    {
      if(pStageManager)
        m_pStageManager = pStageManager;
      /*
      else
      {
        //Assert, since it's not possible to have Stage not governed by
        //any of the StageManager.
      }
      */
    };
    
    virtual ~Stage(){};
/******************************************************************************/
/*!
  Pure virtual Load function needed to be overwritten by the derived classes'
  Load function.
*/
/******************************************************************************/
    virtual void Load() = 0;
/******************************************************************************/
/*!
  Pure virtual Init function needed to be overwritten by the derived classes' 
  Init function.
*/
/******************************************************************************/
    virtual void Init() = 0;
/******************************************************************************/
/*!
  Pure virtual Update function needed to be overwritten by the derived classes' 
  Update function.
*/
/******************************************************************************/
    virtual void Update() = 0;
/******************************************************************************/
/*!
  Pure virtual Shutdown function needed to be overwritten by the derived 
  classes' Shutdown function.
*/
/******************************************************************************/
    virtual void Shutdown() = 0;
/******************************************************************************/
/*!
  Pure virtual Unload function needed to be overwritten by the derived
  classes' Unload function.
*/
/******************************************************************************/
    virtual void Unload() = 0;
  
  private:
    StageManager* m_pStageManager;
};

#endif