#include <Novice.h>
#include <math.h>
#include "StageScene.h"
#include "Player.h"

StageScene::~StageScene()
{
	delete player_;
	delete enemy_;
}

void StageScene::Init()
{
	player_ = new Player({ 1280/2, 720/2 }, 16, 4);
	enemy_ = new Enemy({ 100, 300 }, 3, 16, true);
}

void StageScene::Update(char* keys, char* preKeys)
{
	player_->Update (keys, preKeys);
	
	enemy_->Update();

	float r1 = (float)enemy_->radius_;
	float r2 = (float)player_->bullet_->r_;

	float a = enemy_->pos_.x - player_->bullet_->pos_.x;
	float b = enemy_->pos_.y - player_->bullet_->pos_.y;
	float distance = sqrtf(a * a + b * b);

	//撃った弾と敵が当たったらクリア
	if (distance <= r1 + r2) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	
	/*プレイヤーの描画関数*/
	player_->Draw();
	/*敵の描画関数*/
	enemy_ -> Draw();
}
