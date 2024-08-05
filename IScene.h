#pragma once

enum SCENE { 
	TITLE, //タイトル
	STAGE, //ゲームシーン
	CLEAR //クリア
};

class IScene {
protected: 

	static int sceneNo;
public: 
  
	virtual void Init()=0;
	virtual void Update(char* keys, char* preKeys)=0;
	virtual void Draw()=0;

	virtual ~IScene();

	int GetSceneNo();
};
