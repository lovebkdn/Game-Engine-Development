/******************************************************************************/
/*!
  \file   MenuStage.h
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   1/9/2016
  \brief  
    Interface for the MenuStage.
*/
/******************************************************************************/
#ifndef MENUSTAGE_H
#define MENUSTAGE_H

#include "Stage.h"

/******************************************************************************/
/*!
  \class MenuStage

  MenuStage inherited from the Stage base class.
*/
/******************************************************************************/
class MenuStage : public Stage
{
  public:
    MenuStage(StageManager* pStageManager);
    virtual void Load();
    virtual void Init();
    virtual void Update();
    virtual void Shutdown();
    virtual void Unload();
  
  private:
};

#endif