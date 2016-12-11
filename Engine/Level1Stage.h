/******************************************************************************/
/*!
  \file   Level1Stage.h
  \author Matt Casanova
  \par    email: mcasanov\@digipen.edu
  \date   27/12/2011
  \author Yunhyeok Choi
  \par    email: yunhyeokchoi.digipen\@gmail.com
  \date   9/9/2016
  \brief  
    Interface for the Level1Stage.
*/
/******************************************************************************/
#ifndef LEVEL1STAGE_H
#define LEVEL1STAGE_H

#include "Stage.h"

/******************************************************************************/
/*!
  \class Level1Stage

  Level1Stage inherited from the Stage base class.
*/
/******************************************************************************/
class Level1Stage : public Stage
{
  public:
    Level1Stage(StageManager* pStageManager);
    virtual void Load();
    virtual void Init();
    virtual void Update();
    virtual void Shutdown();
    virtual void Unload();
  
  private:
};

#endif